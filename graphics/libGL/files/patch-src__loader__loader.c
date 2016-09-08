--- src/loader/loader.c.orig	2016-06-21 18:26:10.000000000 +0200
+++ src/loader/loader.c	2016-09-08 21:04:02.301424000 +0200
@@ -70,11 +70,12 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
-#ifdef HAVE_LIBUDEV
+#if defined(HAVE_LIBUDEV) || defined(HAVE_LIBDEVQ)
 #include <assert.h>
 #include <dlfcn.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <limits.h>
 #ifdef USE_DRICONF
 #include "xmlconfig.h"
 #include "xmlpool.h"
@@ -104,16 +105,60 @@ static void default_logger(int level, co
 
 static void (*log_)(int level, const char *fmt, ...) = default_logger;
 
+/*
+ * XXX temporary workaround, because FreeBSD doesn't provide 
+ * pcibus device sysctl trees for renderD and controlD nodes (yet)
+ * Copied from our patch in libdrm.
+ */
+static char *
+drmBSDDeviceNameHack(const char *path)
+{
+  int i, size;
+  long val;
+  char *hacked_path;
+
+  for (i = 0; i < strlen(path); i++)
+  {
+    val = strtol(&path[i], NULL, 10);
+
+    if (val != 0)
+      break;
+  }
+
+
+  if (val >= 64 && val < 128) // controlD node
+  {
+    val = val - 64;
+  }else if (val >= 128 && val < 256) // renderD node
+  {
+    val = val - 128;
+  }
+
+  size = sizeof(DRM_DIR_NAME) + sizeof("/card") + sizeof(val);
+  hacked_path = malloc(size);
+
+  snprintf(hacked_path, size, DRM_DIR_NAME "/card%li", val);
+
+//  printf("path: %s, hacked_path: %s, val: %li\n", path, hacked_path, val);
+
+  return hacked_path;
+}
+
+
 int
 loader_open_device(const char *device_name)
 {
    int fd;
+   char hacked_name[PATH_MAX + 1];
+
+   snprintf(hacked_name, PATH_MAX, "%s", drmBSDDeviceNameHack(device_name));
+
 #ifdef O_CLOEXEC
-   fd = open(device_name, O_RDWR | O_CLOEXEC);
+   fd = open(hacked_name, O_RDWR | O_CLOEXEC);
    if (fd == -1 && errno == EINVAL)
 #endif
    {
-      fd = open(device_name, O_RDWR);
+      fd = open(hacked_name, O_RDWR);
       if (fd != -1)
          fcntl(fd, F_SETFD, fcntl(fd, F_GETFD) | FD_CLOEXEC);
    }
@@ -507,6 +552,54 @@ sysfs_get_pci_id_for_fd(int fd, int *ven
 }
 #endif
 
+#if defined(HAVE_LIBDEVQ)
+#include <libdevq.h>
+
+static void *devq_handle = NULL;
+
+static void *
+devq_dlopen_handle(void)
+{
+   if (!devq_handle) {
+      devq_handle = dlopen("libdevq.so.0", RTLD_LOCAL | RTLD_LAZY);
+   }
+
+   return devq_handle;
+}
+
+static void *
+asserted_dlsym(void *dlopen_handle, const char *name)
+{
+   void *result = dlsym(dlopen_handle, name);
+   assert(result);
+   return result;
+}
+
+#define DEVQ_SYMBOL(ret, name, args) \
+   ret (*name) args = asserted_dlsym(devq_dlopen_handle(), #name);
+
+static int
+devq_get_pci_id_from_fd(int fd, int *vendor_id, int *chip_id)
+{
+   int ret;
+   DEVQ_SYMBOL(int, devq_device_get_pciid_from_fd,
+               (int fd, int *vendor_id, int *chip_id));
+
+   *chip_id = -1;
+
+   ret = devq_device_get_pciid_from_fd(fd, vendor_id, chip_id);
+   if (ret < 0) {
+      log_(_LOADER_WARNING, "MESA-LOADER: could not get PCI ID\n");
+      goto out;
+   }
+
+out:
+   return (*chip_id >= 0);
+}
+
+#endif
+
+
 #if defined(HAVE_LIBDRM)
 /* for i915 */
 #include <i915_drm.h>
@@ -590,6 +683,10 @@ loader_get_pci_id_for_fd(int fd, int *ve
    if (sysfs_get_pci_id_for_fd(fd, vendor_id, chip_id))
       return 1;
 #endif
+#if HAVE_LIBDEVQ
+   if (devq_get_pci_id_from_fd(fd, vendor_id, chip_id))
+      return 1;
+#endif
 #if HAVE_LIBDRM
    if (drm_get_pci_id_for_fd(fd, vendor_id, chip_id))
       return 1;
@@ -709,6 +806,13 @@ loader_get_device_name_for_fd(int fd)
    if ((result = drm_get_device_name_for_fd(fd)))
       return result;
 #endif
+#if HAVE_LIBDEVQ
+#if 0
+/* XXX implement this function in libdevq */
+   if ((result = devq_device_get_name_for_fd(fd)))
+      return result;
+#endif
+#endif
    return result;
 }
 
