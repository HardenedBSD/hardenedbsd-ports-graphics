--- cmake/Modules/WaffleFindDependencies.cmake.orig	2015-08-25 21:05:10 UTC
+++ cmake/Modules/WaffleFindDependencies.cmake
@@ -62,7 +62,7 @@ if(waffle_on_mac)
 endif()
 
 
-if(waffle_on_linux)
+if(waffle_on_linux OR waffle_on_freebsd)
     # waffle_has_egl
     waffle_pkg_config(egl egl)
 
