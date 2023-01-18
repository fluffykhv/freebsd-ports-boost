--- libs/url/test/unit/url.cpp.orig	2022-12-08 01:02:49 UTC
+++ libs/url/test/unit/url.cpp
@@ -964,6 +964,8 @@ struct url_test
                   "http://cppalliance.org/g");
             check("http://cppalliance.org/a/b/../../../g",
                   "http://cppalliance.org/../g");
+            check("http://cppalliance.org/a/b/../../../../g",
+                  "http://cppalliance.org/../../g");
             check("http://cppalliance.org/..",
                   "http://cppalliance.org/..");
             check("http://cppalliance.org?%61=b",
@@ -1080,6 +1082,9 @@ struct url_test
             check("http://cppalliance.org#frag", "http://cppalliance.org#glob", -1);
             check("http://cppalliance.org#fra", "http://cppalliance.org#frag", -1);
             check("http://cppalliance.org#frag", "http://cppalliance.org#fra", 1);
+            // issue 653
+            check("http://httpbin.org/redirect/10", "http://httpbin.org/get", +1);
+            check("http://httpbin.org/redirect/10//10", "http://httpbin.org/11/../get", +1);
         }
 
         // path inequality
