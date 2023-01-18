--- boost/url/url_view_base.hpp.orig	2022-12-08 01:02:49 UTC
+++ boost/url/url_view_base.hpp
@@ -240,6 +240,20 @@ class BOOST_SYMBOL_VISIBLE (public)
             data(), size());
     }
 
+    /** Return the URL as a string_view
+
+        @par Complexity
+        Constant.
+
+        @par Exception Safety
+        Throws nothing.
+
+    */
+    operator string_view() const noexcept
+    {
+        return buffer();
+    }
+
     /** Return a shared, persistent copy of the url
 
         This function returns a read-only copy of
