--- src/libbacklight.c.orig	2015-10-24 00:02:43 UTC
+++ src/libbacklight.c
@@ -39,7 +39,9 @@
 #include <dirent.h>
 #include <drm.h>
 #include <fcntl.h>
+#if !defined(__FreeBSD__)
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <errno.h>
 
