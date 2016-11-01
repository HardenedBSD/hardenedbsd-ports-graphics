--- src/fmm.c.orig	2016-09-25 20:45:23 UTC
+++ src/fmm.c
@@ -962,7 +962,7 @@ static void __fmm_release(void *address,
 	    address <= dgpu_shared_aperture_limit) {
 		/* Remove any CPU mapping, but keep the address range reserved */
 		mmap(address, object->size, PROT_NONE,
-		     MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE | MAP_FIXED, -1, 0);
+		     MAP_ANONYMOUS | MAP_RESERVED0040 | MAP_PRIVATE | MAP_FIXED, -1, 0);
 	}
 
 	args.handle = object->handle;
@@ -1773,7 +1773,7 @@ static void *reserve_address(void *addr,
 		return NULL;
 
 	ret_addr = mmap(addr, len, PROT_NONE,
-				 MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE, -1, 0);
+				 MAP_ANONYMOUS | MAP_RESERVED0040 | MAP_PRIVATE, -1, 0);
 	if (addr == MAP_FAILED)
 		return NULL;
 
