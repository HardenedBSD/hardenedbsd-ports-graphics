--- hw/xfree86/common/xf86Xinput.c.orig	2015-10-28 19:15:36.000000000 +0100
+++ hw/xfree86/common/xf86Xinput.c	2015-11-18 23:51:11.993397000 +0100
@@ -841,7 +841,7 @@ xf86NewInputDevice(InputInfoPtr pInfo, D
 {
     InputDriverPtr drv = NULL;
     DeviceIntPtr dev = NULL;
-    Bool paused;
+    Bool paused = 0;
     int rval;
     const char *path;
 
@@ -993,6 +993,7 @@ NewInputDeviceRequest(InputOption *optio
         if (strcmp(key, "_source") == 0 &&
             (strcmp(value, "server/hal") == 0 ||
              strcmp(value, "server/udev") == 0 ||
+             strcmp(value, "server/devd") == 0 ||
              strcmp(value, "server/wscons") == 0)) {
             is_auto = 1;
             if (!xf86Info.autoAddDevices) {
