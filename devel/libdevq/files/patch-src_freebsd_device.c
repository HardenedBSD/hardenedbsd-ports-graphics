--- src/freebsd/device.c.orig	2016-07-09 18:40:13.000000000 +0200
+++ src/freebsd/device.c	2016-07-28 12:31:40.656295000 +0200
@@ -401,9 +401,9 @@ devq_device_get_pciid_full_from_fd(int f
 	if (ret != 0)
 		return (-1);
 
-	ret = sscanf(sysctl_value, "vendor=0x%04x device=0x%04x subversion=0x%04x subdevice=0x%04x",
+	ret = sscanf(sysctl_value, "vendor=0x%04x device=0x%04x subvendor=0x%04x subdevice=0x%04x",
 	    vendor_id, device_id, subvendor_id, subdevice_id);
-	if (ret != 2) {
+	if (ret != 4) {
 		errno = EINVAL;
 		return (-1);
 	}
@@ -418,10 +418,10 @@ int
 devq_device_get_pciid_from_fd(int fd,
     int *vendor_id, int *device_id)
 {
-	int *subvendor_id, *subdevice_id, *revision_id;
+	int subvendor_id, subdevice_id, revision_id;
 
 	return devq_device_get_pciid_full_from_fd(fd,
-		vendor_id, device_id, subvendor_id,
-		subdevice_id, revision_id);
+		vendor_id, device_id, &subvendor_id,
+		&subdevice_id, &revision_id);
 }
 
