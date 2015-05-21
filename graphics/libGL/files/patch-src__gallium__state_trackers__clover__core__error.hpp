--- ./src/gallium/state_trackers/clover/core/error.hpp.orig	2015-05-21 14:53:51.631886000 +0200
+++ ./src/gallium/state_trackers/clover/core/error.hpp	2015-05-21 14:54:08.005497000 +0200
@@ -26,6 +26,7 @@
 #include "CL/cl.h"
 
 #include <stdexcept>
+#include <string>
 
 namespace clover {
    class command_queue;
