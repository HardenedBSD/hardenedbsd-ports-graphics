--- src/topology.c.orig	2016-09-25 20:45:23 UTC
+++ src/topology.c
@@ -28,12 +28,14 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <dirent.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <ctype.h>
 #include <sched.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
 
 #include "libhsakmt.h"
 #include "fmm.h"
@@ -273,11 +275,12 @@ static void cpuid_count(uint32_t op, int
 /* Lock current process to the specified processor */
 static int lock_to_processor(int processor)
 {
-	cpu_set_t cpuset;
+	return 0;
+/*	cpu_set_t cpuset;
 	memset(&cpuset, 0, sizeof(cpu_set_t));
 	CPU_SET(processor, &cpuset);
 	/* 0: this process */
-	return sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);
+	/*return sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);*/
 }
 
 /* Get count's order of 2. In other words, 2^rtn_value = count
@@ -878,7 +881,7 @@ topology_create_temp_cpu_cache_list(void
 	HSAKMT_STATUS ret = HSAKMT_STATUS_SUCCESS;
 	void *p_temp_cpu_ci_list;
 	int procs_online;
-	cpu_set_t orig_cpuset;
+	/*cpu_set_t orig_cpuset;*/
 	int i;
 	uint32_t cpuid_op_cache;
 	uint32_t eax, ebx, ecx = 0, edx; /* cpuid registers */
@@ -913,13 +916,13 @@ topology_create_temp_cpu_cache_list(void
 	/* lock_to_processor() changes the affinity. Save the current affinity
 	 * so we can restore it after cpuid is done.
 	 */
-	CPU_ZERO(&orig_cpuset);
-	if (sched_getaffinity(0, sizeof(cpu_set_t), &orig_cpuset) != 0) {
+	/*CPU_ZERO(&orig_cpuset);*/
+/*	if (sched_getaffinity(0, sizeof(cpu_set_t), &orig_cpuset) != 0) {
 		printf("Failed to get CPU affinity\n");
 		free(p_temp_cpu_ci_list);
 		ret = HSAKMT_STATUS_ERROR;
 		goto exit;
-	}
+	}*/
 
 	for (i = 0; i < procs_online; i++) {
 		this_cpu = cpu_ci_list + i;
@@ -945,7 +948,7 @@ topology_create_temp_cpu_cache_list(void
 
 err:
 	/* restore affinity to original */
-	sched_setaffinity(0, sizeof(cpu_set_t), &orig_cpuset);
+	/*sched_setaffinity(0, sizeof(cpu_set_t), &orig_cpuset);*/
 exit:
 	if (ret != HSAKMT_STATUS_SUCCESS)
 		topology_destroy_temp_cpu_cache_list(&temp_cpu_ci_list);
