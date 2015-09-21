Fix the build on FreeBSD 9.3

--- xf86drmMode.c.orig	2015-08-21 16:50:01.000000000 +0200
+++ xf86drmMode.c	2015-09-21 17:44:02.000000000 +0200
@@ -47,6 +47,7 @@
 #include <stdlib.h>
 #include <sys/ioctl.h>
 #ifdef HAVE_SYS_SYSCTL_H
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
 #include <stdio.h>
