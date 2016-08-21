These functions are copied from the xorg-server.
http://lists.x.org/archives/xorg-devel/2016-January/048421.html

--- src/intel_list.h.orig	2014-08-29 11:33:11.000000000 +0200
+++ src/intel_list.h	2016-01-06 14:03:26.792064000 +0100
@@ -326,12 +326,14 @@
  *
  */
 #define list_for_each_entry(pos, head, member)				\
-    for (pos = __container_of((head)->next, pos, member);		\
+    for (pos = NULL,							\
+	 pos = __container_of((head)->next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = __container_of(pos->member.next, pos, member))
 
-#define list_for_each_entry_reverse(pos, head, member)				\
-    for (pos = __container_of((head)->prev, pos, member);		\
+#define list_for_each_entry_reverse(pos, head, member)			\
+    for (pos = NULL,							\
+	 pos = __container_of((head)->prev, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = __container_of(pos->member.prev, pos, member))
 
@@ -343,7 +345,8 @@
  * See list_for_each_entry for more details.
  */
 #define list_for_each_entry_safe(pos, tmp, head, member)		\
-    for (pos = __container_of((head)->next, pos, member),		\
+    for (pos = NULL,							\
+	 pos = __container_of((head)->next, pos, member),		\
 	 tmp = __container_of(pos->member.next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = tmp, tmp = __container_of(pos->member.next, tmp, member))
