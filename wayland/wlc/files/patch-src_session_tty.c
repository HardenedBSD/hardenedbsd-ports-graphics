--- src/session/tty.c.orig	2016-08-19 13:28:50 UTC
+++ src/session/tty.c
@@ -9,31 +9,25 @@
 #include "internal.h"
 #include "tty.h"
 
-#if defined(__linux__)
-#  define TTY_BASENAME "/dev/tty"
-#  define TTY_0        "/dev/tty0"
-#  include <linux/kd.h>
-#  include <linux/major.h>
-#  include <linux/vt.h>
-#elif defined(__FreeBSD__)
+#if defined(__FreeBSD__)
+#  include <termios.h>
 #  include <sys/consio.h>
 #  include <sys/kbio.h>
 #  define TTY_BASENAME    "/dev/ttyv"
 #  define TTY_0           "/dev/ttyv0"
 #  define TTY_MAJOR       0
-#  define VT_GETSTATE	  0x5603
-#  define VT_ACTIVATE	  0x5606
-#  define K_UNICODE       0x03
-#  define K_OFF           0x04
-struct vt_stat {
-    unsigned short v_active;    /* active vt */
-    unsigned short v_signal;	/* signal to send */
-    unsigned short v_state;	/* vt bitmask */
-};
+#else
+#  define TTY_BASENAME "/dev/tty"
+#  define TTY_0        "/dev/tty0"
+#  include <linux/kd.h>
+#  include <linux/major.h>
+#  include <linux/vt.h>
 #endif
 
-#ifndef KDSKBMUTE
-#  define KDSKBMUTE 0x4B51
+#if !defined(__FreeBSD__)
+#  ifndef KDSKBMUTE
+#    define KDSKBMUTE 0x4B51
+#  endif
 #endif
 
 /**
@@ -52,6 +46,26 @@ static struct {
    .vt = 0,
 };
 
+static bool
+activate_vt(int fd, int vt) {
+#if defined(__FreeBSD__)
+	ioctl(fd, VT_ACTIVATE, vt);
+	return true;
+#else
+	return ioctl(fd, VT_ACTIVATE, wlc.vt) != -1;
+#endif
+}
+
+static bool
+waitactive_vt(int fd, int vt) {
+#if defined(__FreeBSD__)
+	ioctl(fd, VT_WAITACTIVE, vt);
+	return true;
+#else
+	return ioctl(fd, VT_WAITACTIVE, wlc.vt) != -1;
+#endif
+}
+
 static int
 find_vt(const char *vt_string, bool *out_replace_vt)
 {
@@ -82,94 +96,107 @@ find_vt(const char *vt_string, bool *out
 static int
 open_tty(int vt)
 {
-   char tty_name[64];
-   snprintf(tty_name, sizeof tty_name, "%s%d", TTY_BASENAME, vt);
+	char tty_name[64];
+	snprintf(tty_name, sizeof tty_name, "%s%d", TTY_BASENAME, vt);
 
-   /* check if we are running on the desired vt */
-   if (ttyname(STDIN_FILENO) && chck_cstreq(tty_name, ttyname(STDIN_FILENO))) {
-      wlc_log(WLC_LOG_INFO, "Running on vt %d (fd %d)", vt, STDIN_FILENO);
-      return STDIN_FILENO;
-   }
+	/* check if we are running on the desired vt */
+	if (ttyname(STDIN_FILENO) && chck_cstreq(tty_name, ttyname(STDIN_FILENO))) {
+		wlc_log(WLC_LOG_INFO, "Running on vt %d (fd %d)", vt, STDIN_FILENO);
+		return STDIN_FILENO;
+	}
 
-   int fd;
-   if ((fd = open(tty_name, O_RDWR | O_NOCTTY | O_CLOEXEC)) < 0)
-      die("Could not open %s", tty_name);
+	int fd;
+	if ((fd = open(tty_name, O_RDWR | O_NOCTTY | O_CLOEXEC)) < 0)
+		die("Could not open %s", tty_name);
 
-   wlc_log(WLC_LOG_INFO, "Running on vt %d (fd %d)", vt, fd);
-   return fd;
+	wlc_log(WLC_LOG_INFO, "Running on vt %d (fd %d)", vt, fd);
+	return fd;
 }
 
 static bool
 setup_tty(int fd, bool replace_vt)
 {
-   if (fd < 0)
-      return false;
+	if (fd < 0)
+		return false;
 
-   struct stat st;
-   if (fstat(fd, &st) == -1)
-      die("Could not stat tty fd");
+	struct stat st;
+	if (fstat(fd, &st) == -1)
+		die("Could not stat tty fd");
 
-   wlc.vt = minor(st.st_rdev);
+	wlc.vt = minor(st.st_rdev);
 
-   if (major(st.st_rdev) != TTY_MAJOR || wlc.vt == 0)
-      die("Not a valid vt");
+	if (major(st.st_rdev) != TTY_MAJOR || wlc.vt == 0)
+		die("Not a valid vt");
 
-/* FreeBSD's new vt is still missing some bits */
-#if defined(__linux__)
-   if (!replace_vt) {
-      int kd_mode;
-      if (ioctl(fd, KDGETMODE, &kd_mode) == -1)
-         die("Could not get vt%d mode", wlc.vt);
+#if !defined(__FreeBSD__) /* KDGETMODE missing impl in vt */
+	if (!replace_vt) {
+		int kd_mode;
+		if (ioctl(fd, KDGETMODE, &kd_mode) == -1)
+			die("Could not get vt%d mode", wlc.vt);
 
-      if (kd_mode != KD_TEXT)
-         die("vt%d is already in graphics mode (%d). Is another display server running?", wlc.vt, kd_mode);
-   }
+		if (kd_mode != KD_TEXT)
+			die("vt%d is already in graphics mode (%d). Is another display server running?", wlc.vt, kd_mode);
+	}
 
-   struct vt_stat state;
-   if (ioctl(fd, VT_GETSTATE, &state) == -1)
-      die("Could not get current vt");
+	struct vt_stat state;
+	if (ioctl(fd, VT_GETSTATE, &state) == -1)
+		die("Could not get current vt");
 
-   wlc.old_state.vt = state.v_active;
+	wlc.old_state.vt = state.v_active;
+#endif
 
-   if (ioctl(fd, VT_ACTIVATE, wlc.vt) == -1)
+   if (!activate_vt(fd, wlc.vt))
       die("Could not activate vt%d", wlc.vt);
 
-   if (ioctl(fd, VT_WAITACTIVE, wlc.vt) == -1)
+   if (!waitactive_vt(fd, wlc.vt))
       die("Could not wait for vt%d to become active", wlc.vt);
-#endif
 
-   if (ioctl(fd, KDGKBMODE, &wlc.old_state.kb_mode) == -1)
-      die("Could not get keyboard mode");
+	if (ioctl(fd, KDGKBMODE, &wlc.old_state.kb_mode) == -1)
+		die("Could not get keyboard mode");
 
-   // vt will be restored from now on
-   wlc.tty = fd;
+	// vt will be restored from now on
+	wlc.tty = fd;
 
-#if defined(__linux__)
-   if (ioctl(fd, KDSKBMUTE, 1) == -1 && ioctl(fd, KDSKBMODE, K_OFF) == -1) {
-      wlc_tty_terminate();
-      die("Could not set keyboard mode to K_OFF");
-   }
+#if defined(__FreeBSD__)
+	if (ioctl(fd, KDSKBMODE, K_CODE) == -1) {
+		wlc_tty_terminate();
+		die("Could not set keyboard mode to K_CODE");
+	}
+#else
+	if (ioctl(fd, KDSKBMUTE, 1) == -1 && ioctl(fd, KDSKBMODE, K_OFF) == -1) {
+		wlc_tty_terminate();
+		die("Could not set keyboard mode to K_OFF");
+	}
 #endif
 
-   if (ioctl(fd, KDSETMODE, KD_GRAPHICS) == -1) {
-      wlc_tty_terminate();
-      die("Could not set console mode to KD_GRAPHICS");
-   }
+	if (ioctl(fd, KDSETMODE, KD_GRAPHICS) == -1) {
+		wlc_tty_terminate();
+		die("Could not set console mode to KD_GRAPHICS");
+	}
 
-#if defined(__linux__)
-   struct vt_mode mode = {
-      .mode = VT_PROCESS,
-      .relsig = SIGUSR1,
-      .acqsig = SIGUSR2
-   };
+#if defined(__FreeBSD__)
+	/* Put the tty into raw mode */
+	struct termios tios;
+	tcgetattr(fd, &tios);
+	cfmakeraw(&tios);
+	tcsetattr(fd, TCSAFLUSH, &tios);
+#endif
 
-   if (ioctl(fd, VT_SETMODE, &mode) == -1) {
-      wlc_tty_terminate();
-      die("Could not set vt%d mode", wlc.vt);
-   }
+	struct vt_mode mode = {
+		.mode = VT_PROCESS,
+		.relsig = SIGUSR1,
+		.acqsig = SIGUSR2
+	};
+#if defined(__FreeBSD__)
+	mode.frsig = SIGIO; /* not used, but has to be set anyway */
 #endif
 
-   return true;
+	if (ioctl(fd, VT_SETMODE, &mode) == -1) {
+		wlc_tty_terminate();
+		die("Could not set vt%d mode", wlc.vt);
+	}
+
+	return true;
 }
 
 static void
@@ -214,7 +241,7 @@ wlc_tty_activate_vt(int vt)
       return false;
 
    wlc_log(WLC_LOG_INFO, "Activate vt: %d", vt);
-   return (ioctl(wlc.tty, VT_ACTIVATE, vt) != -1);
+   return activate_vt(wlc.tty, vt);
 }
 
 WLC_PURE int
@@ -230,12 +257,18 @@ wlc_tty_terminate(void)
       // The ACTIVATE / WAITACTIVE may be potentially bad here.
       // However, we need to make sure the vt we initially opened is also active on cleanup.
       // We can't make sure this is synchronized due to unclean exits.
-      if (ioctl(wlc.tty, VT_ACTIVATE, wlc.vt) != -1 && ioctl(wlc.tty, VT_WAITACTIVE, wlc.vt) != -1) {
+
+	   if (activate_vt(wlc.tty, wlc.vt) && waitactive_vt(wlc.tty, wlc.vt)) {
          wlc_log(WLC_LOG_INFO, "Restoring vt %d (0x%lx) (fd %d)", wlc.vt, wlc.old_state.kb_mode, wlc.tty);
 
-         if (ioctl(wlc.tty, KDSKBMUTE, 0) == -1 &&
-             ioctl(wlc.tty, KDSKBMODE, wlc.old_state.kb_mode) == -1 &&
+#if defined(__FreeBSD__)
+		 if (ioctl(wlc.tty, KDSKBMODE, wlc.old_state.kb_mode) == -1 &&
+             ioctl(wlc.tty, KDSKBMODE, K_XLATE) == -1)
+#else
+		 if (ioctl(wlc.tty, KDSKBMUTE, 0) == -1 &&
+			 ioctl(wlc.tty, KDSKBMODE, wlc.old_state.kb_mode) == -1 &&
              ioctl(wlc.tty, KDSKBMODE, K_UNICODE) == -1)
+#endif
             wlc_log(WLC_LOG_ERROR, "Failed to restore vt%d KDSKMODE", wlc.vt);
 
          if (ioctl(wlc.tty, KDSETMODE, KD_TEXT) == -1)
@@ -248,7 +281,7 @@ wlc_tty_terminate(void)
          wlc_log(WLC_LOG_ERROR, "Failed to activate vt%d for restoration", wlc.vt);
       }
 
-      if (ioctl(wlc.tty, VT_ACTIVATE, wlc.old_state.vt) == -1)
+      if (!activate_vt(wlc.tty, wlc.old_state.vt))
          wlc_log(WLC_LOG_ERROR, "Failed to switch back to vt%d", wlc.old_state.vt);
 
       close(wlc.tty);
