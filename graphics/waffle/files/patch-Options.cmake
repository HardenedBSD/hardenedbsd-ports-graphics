--- Options.cmake.orig	2015-08-25 21:05:10 UTC
+++ Options.cmake
@@ -1,4 +1,4 @@
-if(waffle_on_linux)
+if(waffle_on_linux OR waffle_on_freebsd)
     if(gl_FOUND AND x11-xcb_FOUND)
         set(glx_default ON)
     else()
