--- src/sna/sna_accel.c.orig	2013-08-20 22:26:26.000000000 +0200
+++ src/sna/sna_accel.c	2015-02-13 00:18:17.902055000 +0100
@@ -14830,7 +14830,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == sna->front);
@@ -14987,7 +14987,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 	bool flush = false;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
@@ -15216,14 +15216,14 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = old_front->drawable.pScreen;
-	PixmapDirtyUpdatePtr dirty, safe;
+	PixmapDirtyUpdatePtr dirty = NULL, safe;
 
 	xorg_list_for_each_entry_safe(dirty, safe, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == old_front);
 		if (dirty->src != old_front)
 			continue;
 
-		DamageUnregister(&dirty->src->drawable, dirty->damage);
+		DamageUnregister(dirty->damage);
 		DamageDestroy(dirty->damage);
 
 		dirty->damage = DamageCreate(NULL, NULL,
