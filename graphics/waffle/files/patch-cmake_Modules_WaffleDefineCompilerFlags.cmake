--- cmake/Modules/WaffleDefineCompilerFlags.cmake.orig	2015-08-25 21:05:10 UTC
+++ cmake/Modules/WaffleDefineCompilerFlags.cmake
@@ -50,7 +50,7 @@ if (NOT MSVC)
     waffle_add_c_flag("-Werror=int-conversion" WERROR_INT_CONVERSION)
     waffle_add_c_flag("-fvisibility=hidden" WITH_VISIBILITY_HIDDEN)
 
-    if(waffle_on_linux)
+    if(waffle_on_linux OR waffle_on_freebsd)
         # On MacOS, the SSE2 headers trigger this error.
         waffle_add_c_flag("-Werror=missing-prototypes" WERROR_MISSING_PROTOTYPES)
     endif()
@@ -97,7 +97,7 @@ if(waffle_on_mac)
     add_definitions(-DWAFFLE_HAS_CGL)
 endif()
 
-if(waffle_on_linux)
+if(waffle_on_linux OR waffle_on_freebsd)
     if(waffle_has_glx)
         add_definitions(-DWAFFLE_HAS_GLX)
     endif()
@@ -122,7 +122,7 @@ if(waffle_on_linux)
         add_definitions(-DWAFFLE_HAS_TLS_MODEL_INITIAL_EXEC)
     endif()
 
-    add_definitions(-D_XOPEN_SOURCE=600)
+    add_definitions(-D_XOPEN_SOURCE=700)
 endif()
 
 if(waffle_on_windows)
