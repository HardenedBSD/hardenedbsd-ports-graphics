--- src/gallium/state_trackers/clover/llvm/invocation.cpp.orig	2016-09-15 20:57:14.515073000 -0400
+++ src/gallium/state_trackers/clover/llvm/invocation.cpp	2016-09-15 21:09:40.692101000 -0400
@@ -208,6 +208,7 @@
       c.getInvocation().setLangDefaults(c.getLangOpts(), clang::IK_OpenCL,
 #if HAVE_LLVM >= 0x0309
                                         llvm::Triple(triple),
+                                        c.getPreprocessorOpts(),
 #endif
                                         clang::LangStandard::lang_opencl11);
       c.createDiagnostics(
