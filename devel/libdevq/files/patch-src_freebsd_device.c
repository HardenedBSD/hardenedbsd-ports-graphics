--- src/freebsd/device.c.orig	2016-07-09 18:40:13.000000000 +0200
+++ src/freebsd/device.c	2016-07-17 15:15:48.000237000 +0200
@@ -401,9 +401,9 @@
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
