--- include/linux/kfd_ioctl.h.orig	2016-09-25 20:45:23 UTC
+++ include/linux/kfd_ioctl.h
@@ -23,8 +23,9 @@
 #ifndef KFD_IOCTL_H_INCLUDED
 #define KFD_IOCTL_H_INCLUDED
 
-#include <linux/types.h>
-#include <linux/ioctl.h>
+#include <sys/types.h>
+#include <sys/ioccom.h>
+#include <sys/mman.h>
 
 #define KFD_IOCTL_MAJOR_VERSION 1
 #define KFD_IOCTL_MINOR_VERSION 2
