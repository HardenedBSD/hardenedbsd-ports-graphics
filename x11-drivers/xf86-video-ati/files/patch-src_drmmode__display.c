--- src/drmmode_display.c.orig	2014-08-06 16:17:30 UTC
+++ src/drmmode_display.c
@@ -794,7 +794,9 @@ drmmode_set_scanout_pixmap(xf86CrtcPtr c
 		screen->height = screenpix->drawable.height = max_height;
 	}
 	drmmode_crtc->scanout_pixmap_x = this_x;
-#ifdef HAS_DIRTYTRACKING2
+#ifdef HAS_DIRTYTRACKING_ROTATION
+	PixmapStartDirtyTracking(ppix, screenpix, 0, 0, this_x, 0, RR_Rotate_0);
+#elif defined(HAS_DIRTYTRACKING2)
 	PixmapStartDirtyTracking2(ppix, screenpix, 0, 0, this_x, 0);
 #else
 	PixmapStartDirtyTracking(ppix, screenpix, 0, 0);
