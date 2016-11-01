--- include/hsakmttypes.h.orig	2016-09-25 20:45:23 UTC
+++ include/hsakmttypes.h
@@ -51,7 +51,7 @@ extern "C" {
     typedef signed __int64     HSAint64;
     typedef unsigned __int64   HSAuint64;
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 #include <stdbool.h>
 #include <stdint.h>
