--- include/list.h.orig	2015-08-03 16:44:08.000000000 +0200
+++ include/list.h	2016-01-06 13:22:01.452129000 +0100
@@ -304,8 +304,9 @@
  * @param member Member name of the struct xorg_list in the list elements.
  *
  */
-#define xorg_list_for_each_entry(pos, head, member)				\
-    for (pos = __container_of((head)->next, pos, member);		\
+#define xorg_list_for_each_entry(pos, head, member)			\
+    for (pos = NULL,							\
+	 pos = __container_of((head)->next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = __container_of(pos->member.next, pos, member))
 
@@ -317,7 +318,8 @@
  * See xorg_list_for_each_entry for more details.
  */
 #define xorg_list_for_each_entry_safe(pos, tmp, head, member)		\
-    for (pos = __container_of((head)->next, pos, member),		\
+    for (pos = NULL,							\
+	 pos = __container_of((head)->next, pos, member),		\
 	 tmp = __container_of(pos->member.next, pos, member);		\
 	 &pos->member != (head);					\
 	 pos = tmp, tmp = __container_of(pos->member.next, tmp, member))
