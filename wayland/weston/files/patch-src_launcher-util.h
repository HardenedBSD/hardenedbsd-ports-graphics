--- src/launcher-util.h.orig	2016-08-18 19:51:23 UTC
+++ src/launcher-util.h
@@ -55,4 +55,7 @@ weston_launcher_restore(struct weston_la
 void
 weston_setup_vt_switch_bindings(struct weston_compositor *compositor);
 
+int
+weston_launcher_ttyfd(struct weston_launcher *launcher);
+
 #endif
