--- src/radeon_kms.c.orig	2014-10-02 03:31:27 UTC
+++ src/radeon_kms.c
@@ -30,6 +30,8 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/linker.h>
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_reg.h"
@@ -269,7 +271,11 @@ redisplay_dirty(ScreenPtr screen, Pixmap
 
 	PixmapRegionInit(&pixregion, dirty->slave_dst);
 	DamageRegionAppend(&dirty->slave_dst->drawable, &pixregion);
+#ifdef HAS_DIRTYTRACKING_ROTATION
+	PixmapSyncDirtyHelper(dirty);
+#else
 	PixmapSyncDirtyHelper(dirty, &pixregion);
+#endif
 
 	radeon_cs_flush_indirect(pScrn);
 	DamageRegionProcessPending(&dirty->slave_dst->drawable);
@@ -280,7 +286,7 @@ static void
 radeon_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
@@ -589,7 +595,7 @@ static int radeon_get_drm_master_fd(Scrn
 #endif
     struct pci_device *dev = info->PciInfo;
     char *busid;
-    int fd;
+    int fd, err;
 
 #ifdef XF86_PDEV_SERVER_FD
     if (pRADEONEnt->platform_dev) {
@@ -608,6 +614,15 @@ static int radeon_get_drm_master_fd(Scrn
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
