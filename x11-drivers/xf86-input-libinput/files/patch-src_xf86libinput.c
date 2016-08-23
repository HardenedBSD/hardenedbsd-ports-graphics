--- src/xf86libinput.c.orig	2016-08-23 20:55:27 UTC
+++ src/xf86libinput.c
@@ -1365,7 +1365,7 @@ xf86libinput_handle_tablet_axis(InputInf
 	}
 
 	if (libinput_tablet_tool_has_rotation(tool)) {
-		int valuator;
+		int valuator = 0;
 
 		value = libinput_event_tablet_tool_get_rotation(event);
 		value *= TABLET_AXIS_MAX;
