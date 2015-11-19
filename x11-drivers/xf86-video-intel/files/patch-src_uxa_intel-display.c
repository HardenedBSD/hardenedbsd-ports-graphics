--- ./src/uxa/intel_display.c.orig	2014-12-21 20:32:16.075121123 +0100
+++ ./src/uxa/intel_display.c	2014-12-21 20:33:07.975185579 +0100
@@ -1826,7 +1826,7 @@
 void
 intel_drm_abort(ScrnInfoPtr scrn, Bool (*match)(void *data, void *match_data), void *match_data)
 {
-	struct intel_drm_queue *q;
+	struct intel_drm_queue *q = NULL;
 
 	list_for_each_entry(q, &intel_drm_queue, list) {
 		if (match(q->data, match_data)) {
@@ -1842,7 +1842,7 @@
 static void
 intel_drm_abort_seq(ScrnInfoPtr scrn, uint32_t seq)
 {
-	struct intel_drm_queue *q;
+	struct intel_drm_queue *q = NULL;
 
 	list_for_each_entry(q, &intel_drm_queue, list) {
 		if (q->seq == seq) {
@@ -1859,7 +1859,7 @@
 static void
 intel_drm_abort_scrn(ScrnInfoPtr scrn)
 {
-	struct intel_drm_queue *q, *tmp;
+	struct intel_drm_queue *q = NULL, *tmp;
 
 	list_for_each_entry_safe(q, tmp, &intel_drm_queue, list) {
 		if (q->scrn == scrn)
@@ -1976,7 +1976,7 @@
 intel_drm_handler(int fd, uint32_t frame, uint32_t sec, uint32_t usec, void *user_ptr)
 {
 	uint32_t user_data = (intptr_t)user_ptr;
-	struct intel_drm_queue *q;
+	struct intel_drm_queue *q = NULL;
 
 	list_for_each_entry(q, &intel_drm_queue, list) {
 		if (q->seq == user_data) {
