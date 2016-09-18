--- amdgpu/amdgpu_vamgr.c.orig	2016-09-18 17:02:13.553233000 +0200
+++ amdgpu/amdgpu_vamgr.c	2016-09-18 17:04:51.845054000 +0200
@@ -57,7 +57,7 @@ drm_private void amdgpu_vamgr_init(struc
 
 drm_private void amdgpu_vamgr_deinit(struct amdgpu_bo_va_mgr *mgr)
 {
-	struct amdgpu_bo_va_hole *hole, *tmp;
+	struct amdgpu_bo_va_hole *hole = NULL, *tmp;
 	LIST_FOR_EACH_ENTRY_SAFE(hole, tmp, &mgr->va_holes, list) {
 		list_del(&hole->list);
 		free(hole);
@@ -69,7 +69,7 @@ drm_private uint64_t
 amdgpu_vamgr_find_va(struct amdgpu_bo_va_mgr *mgr, uint64_t size,
 		     uint64_t alignment, uint64_t base_required)
 {
-	struct amdgpu_bo_va_hole *hole, *n;
+	struct amdgpu_bo_va_hole *hole = NULL, *n;
 	uint64_t offset = 0, waste = 0;
 
 	alignment = MAX2(alignment, mgr->va_alignment);
@@ -157,7 +157,7 @@ amdgpu_vamgr_find_va(struct amdgpu_bo_va
 drm_private void
 amdgpu_vamgr_free_va(struct amdgpu_bo_va_mgr *mgr, uint64_t va, uint64_t size)
 {
-	struct amdgpu_bo_va_hole *hole;
+	struct amdgpu_bo_va_hole *hole = NULL;
 
 	if (va == AMDGPU_INVALID_VA_ADDRESS)
 		return;
@@ -177,7 +177,7 @@ amdgpu_vamgr_free_va(struct amdgpu_bo_va
 			}
 		}
 	} else {
-		struct amdgpu_bo_va_hole *next;
+		struct amdgpu_bo_va_hole *next = NULL;
 
 		hole = container_of(&mgr->va_holes, hole, list);
 		LIST_FOR_EACH_ENTRY(next, &mgr->va_holes, list) {
