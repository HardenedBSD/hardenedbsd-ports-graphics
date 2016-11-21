--- src/radeon_kms.c.orig	2016-09-15 10:52:47.000000000 +0200
+++ src/radeon_kms.c	2016-09-21 18:12:30.817337000 +0200
@@ -30,6 +30,8 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/linker.h>
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_drm_queue.h"
@@ -321,7 +323,7 @@ static void
 radeon_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
@@ -914,7 +916,7 @@ static int radeon_get_drm_master_fd(Scrn
 #endif
     struct pci_device *dev = info->PciInfo;
     char *busid;
-    int fd;
+    int fd, err;
 
 #ifdef XF86_PDEV_SERVER_FD
     if (pRADEONEnt->platform_dev) {
@@ -933,6 +935,15 @@ static int radeon_get_drm_master_fd(Scrn
 		      dev->domain, dev->bus, dev->dev, dev->func);
 #endif
 
+    err = kldload("radeonkms");
+    if (err == -1 && errno != EEXIST) {
+	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+		   "[drm] Failed to load kernel module for %s: %s\n",
+		   busid, strerror(errno));
+	free(busid);
+	return -1;
+    }
+
     fd = drmOpen(NULL, busid);
     if (fd == -1)
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
