--- src/libhsakmt.h.orig	2016-09-25 20:45:23 UTC
+++ src/libhsakmt.h
@@ -30,6 +30,7 @@
 #include <pthread.h>
 #include <stdint.h>
 #include <limits.h>
+#include <sys/mman.h>
 
 extern int kfd_fd;
 extern unsigned long kfd_open_count;
