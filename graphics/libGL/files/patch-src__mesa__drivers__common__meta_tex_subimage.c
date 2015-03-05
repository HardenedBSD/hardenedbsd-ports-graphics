From b1ab02d9c0cc11ba8ef4efaba9452d644b6a0811 Mon Sep 17 00:00:00 2001
From: Jason Ekstrand <jason.ekstrand@intel.com>
Date: Fri, 27 Feb 2015 12:29:03 -0800
Subject: meta/TexSubImage: Stash everything other than PIXEL_TRANSFER/store in
 meta_begin

Previously, there were bugs where if the app set a scissor it could affect
the area of the texture that was downloaded.  There was also potential that
the framebuffer SRGB state could affect downloads.  This ensures that those
will get saved/restored and can't affect the texture download.

Cc: 10.5 <mesa-stable@lists.freedesktop.org>
Bugzilla: https://bugs.freedesktop.org/show_bug.cgi?id=89292
Reviewed-by: Neil Roberts <neil@linux.intel.com>

diff --git a/src/mesa/drivers/common/meta_tex_subimage.c b/src/mesa/drivers/common/meta_tex_subimage.c
index bba2b4f..971ed59 100644
--- src/mesa/drivers/common/meta_tex_subimage.c
+++ src/mesa/drivers/common/meta_tex_subimage.c
@@ -193,8 +193,8 @@ _mesa_meta_pbo_TexSubImage(struct gl_context *ctx, GLuint dims,
    if (allocate_storage)
       ctx->Driver.AllocTextureImageBuffer(ctx, tex_image);
 
-   /* Only stash the current FBO */
-   _mesa_meta_begin(ctx, 0);
+   _mesa_meta_begin(ctx, ~(MESA_META_PIXEL_TRANSFER |
+                           MESA_META_PIXEL_STORE));
 
    _mesa_GenFramebuffers(2, fbos);
    _mesa_BindFramebuffer(GL_READ_FRAMEBUFFER, fbos[0]);
@@ -312,8 +312,8 @@ _mesa_meta_pbo_GetTexSubImage(struct gl_context *ctx, GLuint dims,
    if (!pbo_tex_image)
       return false;
 
-   /* Only stash the current FBO */
-   _mesa_meta_begin(ctx, 0);
+   _mesa_meta_begin(ctx, ~(MESA_META_PIXEL_TRANSFER |
+                           MESA_META_PIXEL_STORE));
 
    _mesa_GenFramebuffers(2, fbos);
 
-- 
cgit v0.10.2

