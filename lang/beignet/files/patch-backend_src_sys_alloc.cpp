--- backend/src/sys/alloc.cpp.orig	2014-11-13 02:11:32.000000000 +0100
+++ backend/src/sys/alloc.cpp	2015-01-30 01:03:17.269890206 +0100
@@ -69,7 +69,7 @@
     /*! Total number of allocations done */
     volatile intptr_t allocNum;
     /*! Sorts the file name and function name strings */
-    std::tr1::unordered_map<const char*, int> staticStringMap;
+    std::unordered_map<const char*, int> staticStringMap;
     /*! Each element contains the actual string */
     std::vector<const char*> staticStringVector;
     std::map<uintptr_t, AllocData> allocMap;
@@ -291,6 +291,29 @@
   void alignedFree(void *ptr) { if (ptr) std::free(ptr); }
 } /* namespace gbe */
 
+#elif defined(__FreeBSD__)
+
+#include <unistd.h>
+#include <sys/mman.h>
+#include <fcntl.h>
+#include <stdlib.h>
+#include <malloc_np.h>
+#include <iostream>
+
+namespace gbe
+{
+  void* alignedMalloc(size_t size, size_t align) {
+    void* ptr;
+    const int err = posix_memalign(&ptr,align,size);
+    FATAL_IF ((err != 0), "memory allocation failed");
+    MemDebuggerInitializeMem(ptr, size);
+    return ptr;
+  }
+
+  void alignedFree(void *ptr) { if (ptr) std::free(ptr); }
+} /* namespace gbe */
+
+
 #else
 #error "Unsupported platform"
 #endif /* __LINUX__ */
