--- boost/url/url_view.hpp.orig	2022-12-08 01:02:49 UTC
+++ boost/url/url_view.hpp
@@ -196,8 +196,25 @@ class BOOST_SYMBOL_VISIBLE url_view (public)
             @ref parse_uri_reference.
     */
     BOOST_URL_DECL
-    explicit
     url_view(string_view s);
+
+    /// @copydoc url_view(string_view)
+    template<
+        class String
+#ifndef BOOST_URL_DOCS
+        , class = typename std::enable_if<
+            std::is_convertible<
+                String,
+                string_view
+                    >::value>::type
+#endif
+    >
+    url_view(
+        String const& s)
+        : url_view(
+            string_view(s))
+    {
+    }
 
     /** Constructor
 
