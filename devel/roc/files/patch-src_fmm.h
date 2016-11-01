--- src/fmm.h.orig	2016-09-25 20:45:23 UTC
+++ src/fmm.h
@@ -28,6 +28,7 @@
 
 #include "hsakmttypes.h"
 #include <stddef.h>
+#include <sys/mman.h>
 
 typedef enum {
 	FMM_FIRST_APERTURE_TYPE = 0,
