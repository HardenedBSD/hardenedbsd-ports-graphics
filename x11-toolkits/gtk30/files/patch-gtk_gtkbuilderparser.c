--- gtk/gtkbuilderparser.c.orig	2016-01-07 03:25:56 UTC
+++ gtk/gtkbuilderparser.c
@@ -1146,7 +1146,7 @@ end_element (GMarkupParseContext  *conte
 /* Called for character data */
 /* text is not nul-terminated */
 static void
-text (GMarkupParseContext  *context,
+XXXtext (GMarkupParseContext  *context,
       const gchar          *text,
       gsize                 text_len,
       gpointer              user_data,
@@ -1204,7 +1204,7 @@ free_info (CommonInfo *info)
 static const GMarkupParser parser = {
   start_element,
   end_element,
-  text,
+  XXXtext,
   NULL,
 };
 
