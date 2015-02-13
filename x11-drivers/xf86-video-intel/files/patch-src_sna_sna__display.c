--- src/sna/sna_display.c.orig	2015-02-13 11:00:50.868952000 +0100
+++ src/sna/sna_display.c	2015-02-13 11:01:06.994493000 +0100
@@ -847,7 +847,7 @@ static void sna_mode_disable_shadow(stru
 
 	DBG(("%s\n", __FUNCTION__));
 
-	DamageUnregister(&sna->front->drawable, sna->mode.shadow_damage);
+	DamageUnregister(sna->mode.shadow_damage);
 	DamageDestroy(sna->mode.shadow_damage);
 	sna->mode.shadow_damage = NULL;
 
