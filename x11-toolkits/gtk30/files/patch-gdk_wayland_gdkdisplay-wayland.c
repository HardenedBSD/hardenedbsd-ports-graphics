--- gdk/wayland/gdkdisplay-wayland.c.orig	2016-01-28 03:17:30 UTC
+++ gdk/wayland/gdkdisplay-wayland.c
@@ -22,7 +22,9 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
+#if HAVE_MEMFD_CREATE
 #include <linux/memfd.h>
+#endif
 #include <sys/mman.h>
 #include <sys/syscall.h>
 
@@ -982,11 +984,15 @@ create_shm_pool (struct wl_shm  *shm,
                  void          **data_out)
 {
   struct wl_shm_pool *pool;
-  int ret, fd;
+  int ret = -1, fd;
   void *data;
 
+#if HAVE_MEMFD_CREATE
   ret = syscall (__NR_memfd_create, "gdk-wayland", MFD_CLOEXEC);
-
+#else
+  char template[] = "/tmp/gdk-wayland-XXXXXX";
+  ret = mkostemp(template, O_CLOEXEC);
+#endif
   if (ret < 0)
     {
       g_critical (G_STRLOC ": creating shared memory file failed: %s",
