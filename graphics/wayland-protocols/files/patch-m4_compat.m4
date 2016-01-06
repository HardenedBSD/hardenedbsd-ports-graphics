diff --git a/m4/compat.m4.orig b/m4/compat.m4
index 290ef03..b418dad 100644
--- m4/compat.m4.orig
+++ m4/compat.m4
@@ -7,6 +7,6 @@ dnl a Launchpad PPA.  14.04 is a Long Term Support distro release, which
 dnl will reach EOL April 2019, however the Wayland PPA may stop targeting
 dnl it some time after the next LTS release (April 2016).
 m4_ifndef([PKG_NOARCH_INSTALLDIR], [AC_DEFUN([PKG_NOARCH_INSTALLDIR], [
-    noarch_pkgconfigdir='${datadir}'/pkgconfig
+    noarch_pkgconfigdir='${prefix}'/libdata/pkgconfig
     AC_SUBST([noarch_pkgconfigdir])
 ])])
