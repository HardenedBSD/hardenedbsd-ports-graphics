--- CMake/FindLLVM.cmake.orig	2015-01-16 10:24:13 UTC
+++ CMake/FindLLVM.cmake
@@ -8,12 +8,12 @@
 # LLVM_FOUND       - True if llvm found.
 if (LLVM_INSTALL_DIR)
   find_program(LLVM_CONFIG_EXECUTABLE
-               NAMES llvm-config-33 llvm-config-3.3 llvm-config-35 llvm-config-3.5 llvm-config-34 llvm-config-3.4 llvm-config
+               NAMES llvm-config-33 llvm-config-3.3 llvm-config-35 llvm-config-3.5 llvm-config-34 llvm-config-3.4 llvm-config llvm-config34 llvm-config35
                DOC "llvm-config executable"
                PATHS ${LLVM_INSTALL_DIR} NO_DEFAULT_PATH)
 else (LLVM_INSTALL_DIR)
   find_program(LLVM_CONFIG_EXECUTABLE
-               NAMES llvm-config-33 llvm-config-3.3 llvm-config-35 llvm-config-3.5 llvm-config-34 llvm-config-3.4 llvm-config
+               NAMES llvm-config-33 llvm-config-3.3 llvm-config-35 llvm-config-3.5 llvm-config-34 llvm-config-3.4 llvm-config llvm-config34 llvm-config35
                DOC "llvm-config executable")
 endif (LLVM_INSTALL_DIR)
 
