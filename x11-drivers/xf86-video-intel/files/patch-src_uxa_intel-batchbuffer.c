--- src/uxa/intel_batchbuffer.c.orig	2014-12-21 20:30:07.602128859 +0100
+++ src/uxa/intel_batchbuffer.c	2014-12-21 20:30:26.672149345 +0100
@@ -142,7 +142,7 @@
 static void intel_batch_do_flush(ScrnInfoPtr scrn)
 {
 	intel_screen_private *intel = intel_get_screen_private(scrn);
-	struct intel_uxa_pixmap *priv;
+	struct intel_uxa_pixmap *priv = NULL;
 
 	list_for_each_entry(priv, &intel->batch_pixmaps, batch)
 		priv->dirty = 0;
