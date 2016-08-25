--- dix/Xserver.d.orig	2016-07-15 16:18:11 UTC
+++ dix/Xserver.d
@@ -23,13 +23,8 @@
 /*
  * Xserver dtrace provider definition
  */
-#ifdef __APPLE__
-#define string char *
-#define pid_t uint32_t
-#define zoneid_t uint32_t
-#else
 #include <sys/types.h>
-#endif
+#include <stdarg.h>
 
 typedef const uint8_t *const_uint8_p;
 typedef const double *const_double_p;
@@ -60,4 +55,3 @@ provider Xserver {
 #pragma D attributes Private/Private/Unknown  provider Xserver function
 #pragma D attributes Unstable/Unstable/Common provider Xserver name
 #pragma D attributes Unstable/Unstable/Common provider Xserver args
-
