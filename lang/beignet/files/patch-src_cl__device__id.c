--- src/cl_device_id.c.orig	2015-02-02 21:01:26.000000000 +0100
+++ src/cl_device_id.c	2015-02-03 16:57:36.570799000 +0100
@@ -33,7 +33,12 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <sys/sysinfo.h>
+#else
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
 #ifndef CL_VERSION_1_2
 #define CL_DEVICE_BUILT_IN_KERNELS 0x103F
@@ -505,6 +510,10 @@ skl_gt4_break:
     }
   }
 
+  /* No supported GPU found */
+  if (ret == NULL)
+    return ret;
+
 #ifdef HAS_USERPTR
   cl_driver dummy = cl_driver_new(NULL);
   cl_buffer_mgr bufmgr = cl_driver_get_bufmgr(dummy);
@@ -524,6 +533,7 @@ skl_gt4_break:
   cl_driver_delete(dummy);
 #endif
 
+#ifndef __FreeBSD__
   struct sysinfo info;
   if (sysinfo(&info) == 0) {
     uint64_t two_gb = 2 * 1024 * 1024 * 1024ul; 
@@ -532,6 +542,22 @@ skl_gt4_break:
                             two_gb : info.totalram;
     ret->max_mem_alloc_size = ret->global_mem_size / 2;
   }
+#else
+  int mib[2];
+
+  mib[0] = CTL_HW;
+  mib[1] = HW_USERMEM;
+
+  uint64_t totalram;
+  size_t len;
+  len = sizeof(totalram);
+  sysctl(mib, 2, &totalram, &len, NULL, 0);
+
+  uint64_t two_gb = 2 * 1024 * 1024 * 1024ul;
+  ret->global_mem_size = (totalram > two_gb) ?
+                            two_gb : totalram;
+  ret->max_mem_alloc_size = ret->global_mem_size / 2;
+#endif
 
   return ret;
 }
