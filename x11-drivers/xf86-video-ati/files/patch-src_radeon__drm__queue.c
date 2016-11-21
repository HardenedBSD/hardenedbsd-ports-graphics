--- src/radeon_drm_queue.c.orig	2016-09-21 18:10:33.937954000 +0200
+++ src/radeon_drm_queue.c	2016-09-21 18:11:43.894010000 +0200
@@ -61,7 +61,7 @@ radeon_drm_queue_handler(int fd, unsigne
 			 unsigned int usec, void *user_ptr)
 {
 	uintptr_t seq = (uintptr_t)user_ptr;
-	struct radeon_drm_queue_entry *e, *tmp;
+	struct radeon_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 		if (e->seq == seq) {
@@ -132,7 +132,7 @@ radeon_drm_abort_one(struct radeon_drm_q
 void
 radeon_drm_abort_client(ClientPtr client)
 {
-    struct radeon_drm_queue_entry *e;
+    struct radeon_drm_queue_entry *e = NULL;
 
     xorg_list_for_each_entry(e, &radeon_drm_queue, list) {
 	if (e->client == client)
@@ -146,7 +146,7 @@ radeon_drm_abort_client(ClientPtr client
 void
 radeon_drm_abort_entry(uintptr_t seq)
 {
-    struct radeon_drm_queue_entry *e, *tmp;
+    struct radeon_drm_queue_entry *e = NULL, *tmp;
 
     xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 	if (e->seq == seq) {
@@ -162,7 +162,7 @@ radeon_drm_abort_entry(uintptr_t seq)
 void
 radeon_drm_abort_id(uint64_t id)
 {
-    struct radeon_drm_queue_entry *e, *tmp;
+    struct radeon_drm_queue_entry *e = NULL, *tmp;
 
     xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 	if (e->id == id) {
@@ -190,7 +190,7 @@ radeon_drm_queue_init()
 void
 radeon_drm_queue_close(ScrnInfoPtr scrn)
 {
-    struct radeon_drm_queue_entry *e, *tmp;
+    struct radeon_drm_queue_entry *e = NULL, *tmp;
 
     xorg_list_for_each_entry_safe(e, tmp, &radeon_drm_queue, list) {
 	if (e->crtc->scrn == scrn)
