--- tools/lsdri/lsdri.c.orig	2016-07-09 18:40:13.000000000 +0200
+++ tools/lsdri/lsdri.c	2016-07-17 15:20:26.285606000 +0200
@@ -41,7 +41,7 @@
 print_drm_info(int fd)
 {
 	int ret;
-	int vendor_id, device_id;
+	int vendor_id, device_id, subvendor_id, subdevice_id, revision_id;
 	char *device_path, *driver_name;
 	size_t device_path_len, driver_name_len;
 
@@ -82,14 +82,16 @@
 	free(driver_name);
 	driver_name = NULL;
 
-	ret = devq_device_get_pciid_from_fd(fd, &vendor_id, &device_id);
+	ret = devq_device_get_pciid_full_from_fd(fd, &vendor_id, &device_id,
+				&subvendor_id, &subdevice_id, &revision_id);
 	if (ret < 0) {
 		fprintf(stderr, "Warning: Unable to determine vendor and device ID\n");
 		return (-1);
 	}
 
-	printf("    PCI vendor ID: 0x%04x\n", vendor_id);
-	printf("    PCI device ID: 0x%04x\n", device_id);
+	printf("    PCI vendor ID: 0x%04x subvendor ID: 0x%04x\n", vendor_id, subvendor_id);
+	printf("    PCI device ID: 0x%04x subdevice ID: 0x%04x\n", device_id, subdevice_id);
+	printf("    PCI revision ID: 0x%04x\n", revision_id);
 
 	return (0);
 }
