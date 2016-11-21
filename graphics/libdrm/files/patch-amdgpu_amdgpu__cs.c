--- amdgpu/amdgpu_cs.c.orig	2016-09-18 17:02:04.534919000 +0200
+++ amdgpu/amdgpu_cs.c	2016-09-18 17:03:49.141704000 +0200
@@ -124,7 +124,7 @@ int amdgpu_cs_ctx_free(amdgpu_context_ha
 	for (i = 0; i < AMDGPU_HW_IP_NUM; i++) {
 		for (j = 0; j < AMDGPU_HW_IP_INSTANCE_MAX_COUNT; j++) {
 			for (k = 0; k < AMDGPU_CS_MAX_RINGS; k++) {
-				amdgpu_semaphore_handle sem;
+				amdgpu_semaphore_handle sem = NULL;
 				LIST_FOR_EACH_ENTRY(sem, &context->sem_list[i][j][k], list) {
 					list_del(&sem->list);
 					amdgpu_cs_reset_sem(sem);
@@ -179,7 +179,7 @@ static int amdgpu_cs_submit_one(amdgpu_c
 	struct drm_amdgpu_cs_chunk_dep *dependencies = NULL;
 	struct drm_amdgpu_cs_chunk_dep *sem_dependencies = NULL;
 	struct list_head *sem_list;
-	amdgpu_semaphore_handle sem, tmp;
+	amdgpu_semaphore_handle sem = NULL, tmp;
 	uint32_t i, size, sem_count = 0;
 	bool user_fence;
 	int r = 0;
