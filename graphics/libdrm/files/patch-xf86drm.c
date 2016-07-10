--- xf86drm.c.orig	2016-07-09 15:25:51.247259000 +0200
+++ xf86drm.c	2016-07-09 18:21:32.066963000 +0200
@@ -59,6 +59,10 @@
 #endif
 #include <math.h>
 
+#ifdef HAVE_LIBDEVQ
+#include "libdevq.h"
+#endif
+
 /* Not all systems have MAP_FAILED defined */
 #ifndef MAP_FAILED
 #define MAP_FAILED ((void *)-1)
@@ -79,8 +83,12 @@
 #define DRM_RENDER_MINOR_NAME	"renderD"
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#define DRM_MAJOR 145
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#define DRM_MAJOR 0
+#endif
+
+#if defined(__DragonFly__)
+#define DRM_MAJOR 65 /* was 154 XXX needs checking */
 #endif
 
 #ifdef __NetBSD__
@@ -529,6 +537,7 @@ static int drmGetMinorType(int minor)
     }
 }
 
+#if !defined(__FreeBSD__)
 static const char *drmGetMinorName(int type)
 {
     switch (type) {
@@ -542,6 +551,7 @@ static const char *drmGetMinorName(int t
         return NULL;
     }
 }
+#endif
 
 /**
  * Open the device by bus ID.
@@ -2816,6 +2826,16 @@ static char *drmGetMinorNameForFD(int fd
 
 out_close_dir:
 	closedir(sysdir);
+
+#elif defined(__FreeBSD__)
+	struct stat buf;
+	char name[64];
+
+	fstat(fd, &buf);
+	snprintf(name, sizeof(name), "/dev/%s",
+		 devname(buf.st_rdev, S_IFCHR));
+
+	return strdup(name);
 #else
 #warning "Missing implementation of drmGetMinorNameForFD"
 #endif
@@ -2853,12 +2873,19 @@ static int drmParseSubsystemType(int maj
         return DRM_BUS_PCI;
 
     return -EINVAL;
+#elif defined(__FreeBSD__)
+    /* XXX: Don't know how to get the subsystem type, hardcode for now.
+     * The code following the call to this function needs depends on
+     * information provided by the /pci subsystem on linux. No replacement
+     * found yet for FreeBSD. */
+    return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
     return -EINVAL;
 #endif
 }
 
+#if !defined(__FreeBSD__)
 static int drmParsePciBusInfo(int maj, int min, drmPciBusInfoPtr info)
 {
 #ifdef __linux__
@@ -2900,6 +2927,57 @@ static int drmParsePciBusInfo(int maj, i
     return -EINVAL;
 #endif
 }
+#else
+static int
+drmParsePciBusInfoBSD(const char *path, drmPciBusInfoPtr info)
+{
+    int fd, ret;
+    int domain = 0, bus = 0, slot = 0, function = 0;
+
+    /*
+     * XXX temporary workaround, because FreeBSD doesn't provide 
+     * pcibus device sysctl trees for renderD and controlD nodes (yet)
+     */
+    int start;
+    const char *errstr;
+    int number;
+    char hacked_path[PATH_MAX + 1];
+
+    snprintf(hacked_path, PATH_MAX, "%s", path);
+
+    if (strcmp(path, DRM_DIR_NAME "/controlD") > 0) 
+    {
+      start = 17;
+      number = strtonum(&path[start], 0, 256, &errstr) - 64;
+      sprintf(hacked_path, DRM_DIR_NAME "/card%i", number);
+    }else if (strcmp(path, DRM_DIR_NAME "/renderD") > 0)
+    {
+      start = 16;
+      number = strtonum(&path[start], 0, 256, &errstr) - 128;
+      sprintf(hacked_path, DRM_DIR_NAME "/card%i", number);
+    }
+    /* the end of the workaround */
+
+    fd = open(hacked_path, O_RDONLY);
+
+    if (fd < 0)
+      return -errno;
+
+    ret = devq_device_get_pcibusaddr(fd, &domain, &bus, &slot, &function);
+
+    if (ret < 0)
+      return -1;
+
+    info->domain = (uint16_t) domain;
+    info->bus = (uint8_t) bus;
+    info->dev = (uint8_t) slot;
+    info->func = (uint8_t) function;
+
+    close(fd);
+
+    return 0;
+}
+#endif
 
 static int drmCompareBusInfo(drmDevicePtr a, drmDevicePtr b)
 {
@@ -2945,6 +3023,7 @@ static int drmGetMaxNodeName(void)
            3 /* length of the node number */;
 }
 
+//YYYY
 static int drmParsePciDeviceInfo(const char *d_name,
                                  drmPciDeviceInfoPtr device)
 {
@@ -2970,6 +3049,27 @@ static int drmParsePciDeviceInfo(const c
     device->subdevice_id = config[46] | (config[47] << 8);
 
     return 0;
+#elif defined(__FreeBSD__)
+    int fd, vendor_id = 0, device_id = 0, subvendor_id = 0, 
+	subdevice_id = 0, revision_id = 0;
+    char path[PATH_MAX + 1];
+
+    snprintf(path, PATH_MAX, DRM_DIR_NAME "/%s", d_name);
+    fd = open(path, O_RDONLY);
+
+    if (fd < 0)
+        return -errno;
+
+    devq_device_get_pciid_full_from_fd(fd, &vendor_id, &device_id,
+	&subvendor_id, &subdevice_id, &revision_id);
+
+    device->vendor_id = (uint16_t) vendor_id;
+    device->device_id = (uint16_t) device_id;
+    device->revision_id = (uint16_t) revision_id;
+    device->subvendor_id = (uint16_t) subvendor_id;
+    device->subdevice_id = (uint8_t) subdevice_id;
+
+    return 0;
 #else
 #warning "Missing implementation of drmParsePciDeviceInfo"
     return -EINVAL;
@@ -3028,7 +3128,12 @@ static int drmProcessPciDevice(drmDevice
 
     (*device)->businfo.pci = (drmPciBusInfoPtr)addr;
 
+#if defined(__FreeBSD__)
+    ret = drmParsePciBusInfoBSD(node, (*device)->businfo.pci);
+#else
     ret = drmParsePciBusInfo(maj, min, (*device)->businfo.pci);
+#endif
+
     if (ret)
         goto free_device;
 
@@ -3038,6 +3143,7 @@ static int drmProcessPciDevice(drmDevice
         (*device)->deviceinfo.pci = (drmPciDeviceInfoPtr)addr;
 
         ret = drmParsePciDeviceInfo(d_name, (*device)->deviceinfo.pci);
+
         if (ret)
             goto free_device;
     }
@@ -3135,6 +3241,12 @@ int drmGetDevice(int fd, drmDevicePtr *d
         case DRM_BUS_PCI:
             ret = drmProcessPciDevice(&d, dent->d_name, node, node_type,
                                       maj, min, true);
+
+printf("YYY drmGetDevice() #1 - node: %s, dev: %i, vendor_id: %04x\n", 
+	node,
+	d[0].businfo.pci->dev,
+	d[0].deviceinfo.pci->vendor_id);
+
             if (ret)
                 goto free_devices;
 
@@ -3163,6 +3275,12 @@ int drmGetDevice(int fd, drmDevicePtr *d
     drmFoldDuplicatedDevices(local_devices, node_count);
 
     *device = local_devices[0];
+
+/*printf("YYY drmGetDevice() #2 - dev: %i, vendor_id: %04x\n", 
+	d[0].businfo.pci->dev,
+	d[0].deviceinfo.pci->vendor_id);
+*/
+
     for (i = 1; i < node_count && local_devices[i]; i++)
             drmFreeDevice(&local_devices[i]);
 
@@ -3239,6 +3357,12 @@ int drmGetDevices(drmDevicePtr devices[]
         case DRM_BUS_PCI:
             ret = drmProcessPciDevice(&device, dent->d_name, node, node_type,
                                       maj, min, devices != NULL);
+printf("YYY drmGetDevices() - node: %s\n", node);
+/*
+printf("YYY drmGetDevices() #1 - dev: %i, vendor_id: %04x\n", 
+	device[0].businfo.pci->dev,
+	device[0].deviceinfo.pci->vendor_id);
+*/
             if (ret)
                 goto free_devices;
 
@@ -3275,7 +3399,12 @@ int drmGetDevices(drmDevicePtr devices[]
 
         device_count++;
     }
-
+printf("YYY drmGetDevices() - Fold()\n");
+/*
+printf("YYY drmGetDevices() #2 - dev: %i, vendor_id: %04x\n", 
+	device[0].businfo.pci->dev,
+	device[0].deviceinfo.pci->vendor_id);
+*/
     closedir(sysdir);
     free(local_devices);
     return device_count;
