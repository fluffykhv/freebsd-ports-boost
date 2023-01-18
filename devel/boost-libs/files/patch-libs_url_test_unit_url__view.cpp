--- libs/url/test/unit/url_view.cpp.orig	2022-12-08 01:02:49 UTC
+++ libs/url/test/unit/url_view.cpp
@@ -90,6 +90,24 @@ class url_view_test (public)
             BOOST_TEST_THROWS(url_view("{}"),
                 std::exception);
         }
+
+        // url_view(string_view) no ambiguous
+        {
+            string_view s = "";
+            BOOST_TEST_NO_THROW(url_view( s ));
+        }
+
+        // implicit url_view(string_view)
+        {
+            auto const f = []( url_view ) {};
+            f( "x" );
+        }
+
+        // implicit url_view(String)
+        {
+            auto const f = []( url_view ) {};
+            f( "x" );
+        }
     }
 
     void
@@ -123,8 +141,8 @@ class url_view_test (public)
         {
             string_view s = "/index.htm";
             url_view u = parse_relative_ref(s).value();
-            BOOST_TEST_EQ(u.buffer(), s);
-            BOOST_TEST_EQ(u.buffer().data(), s.data());
+            BOOST_TEST_EQ(u, s);
+            BOOST_TEST_EQ(u.data(), s.data());
         }
 
         // persist()
@@ -145,6 +163,13 @@ class url_view_test (public)
             // becomes invalid, but sp remains valid.
         }
         }
+
+        // operator string_view()
+        {
+            auto const f = []( string_view ) {};
+            f( url_view("x") );
+        }
+
     }
 
     void
