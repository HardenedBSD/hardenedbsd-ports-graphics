--- src/amdgpu_kms.c.orig	2016-09-21 22:32:09 UTC
+++ src/amdgpu_kms.c
@@ -238,7 +238,7 @@ static void redisplay_dirty(ScreenPtr sc
 static void amdgpu_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
