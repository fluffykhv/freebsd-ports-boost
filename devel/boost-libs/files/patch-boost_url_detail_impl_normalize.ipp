--- boost/url/detail/impl/normalize.ipp.orig	2022-12-08 01:02:49 UTC
+++ boost/url/detail/impl/normalize.ipp
@@ -650,11 +650,13 @@ normalized_path_digest(
     while (!s.empty());
 }
 
+// compare segments as if there were a normalized
 int
 segments_compare(
     segments_encoded_view seg0,
     segments_encoded_view seg1) noexcept
 {
+    // calculate path size as if it were normalized
     auto normalized_size =
         [](segments_encoded_view seg) -> std::size_t
     {
@@ -683,11 +685,14 @@ segments_compare(
         n -= !seg.is_absolute();
         return n;
     };
+
+    // find the normalized size for the comparison
     std::size_t n0 = normalized_size(seg0);
     std::size_t n1 = normalized_size(seg1);
     std::size_t n00 = n0;
     std::size_t n10 = n1;
 
+    // consume the last char from a segment range
     auto consume_last =
         [](
             std::size_t& n,
@@ -700,61 +705,87 @@ segments_compare(
     {
         if (cit != dseg.begin())
         {
+            // return last char from current segment
             at_slash = false;
             --cit;
             --n;
             return *cit;
         }
-        else
+
+        if (!at_slash)
         {
-            if (!at_slash || dseg.empty())
+            // current segment dseg is over and
+            // previous char was not a slash
+            // so we output one
+            at_slash = true;
+            --n;
+            return '/';
+        }
+
+        // current segment dseg is over and
+        // last char was already the slash
+        // between segments, so take the
+        // next final segment to consume
+        at_slash = false;
+        while (cit == dseg.begin())
+        {
+            // take next segment
+            if (it != begin)
+                --it;
+            else
+                break;
+            if (**it == "..")
             {
-                at_slash = true;
-                --n;
-                return '/';
+                // skip next if this is ".."
+                ++skip;
             }
-            at_slash = false;
-            while (cit == dseg.begin())
+            else if (**it != ".")
             {
-                if (it != begin)
-                    --it;
-                else
-                    break;
-                if (**it == "..")
+                if (skip)
                 {
-                    ++skip;
+                    // discount skips
+                    --skip;
                 }
-                else if (**it != ".")
+                else
                 {
-                    if (skip)
-                    {
-                        --skip;
-                    }
-                    else
-                    {
-                        dseg = **it;
-                        cit = dseg.end();
-                    }
+                    // or update current seg
+                    dseg = **it;
+                    cit = dseg.end();
+                    break;
                 }
             }
-            --n;
-            if (it == begin)
-            {
-                return "/.."[n];
-            }
-            if (cit == dseg.begin())
-            {
-                at_slash = true;
-                return '/';
-            }
-            else
-            {
-                --cit;
-                return *cit;
-            }
         }
+        // consume from the new current
+        // segment
+        --n;
+        if (cit != dseg.begin())
+        {
+            // in the general case, we consume
+            // one more character from the end
+            --cit;
+            return *cit;
+        }
+
+        // nothing left to consume in the
+        // current and new segment
+        if (it == begin)
+        {
+            // if this is the first
+            // segment, the segments are
+            // over and there can only
+            // be repetitions of "../" to
+            // output
+            return "/.."[n % 3];
+        }
+        // at other segments, we need
+        // a slash to transition to the
+        // next segment
+        at_slash = true;
+        return '/';
     };
 
+    // consume final segments from seg0 that
+    // should not influence the comparison
     auto begin0 = seg0.begin();
     auto it0 = seg0.end();
     decode_view dseg0;
@@ -768,9 +799,11 @@ segments_compare(
     bool at_slash0 = true;
     while (n0 > n1)
     {
-        consume_last(n0, dseg0, begin0,it0, cit0, skip0, at_slash0);
+        consume_last(n0, dseg0, begin0, it0, cit0, skip0, at_slash0);
     }
 
+    // consume final segments from seg1 that
+    // should not influence the comparison
     auto begin1 = seg1.begin();
     auto it1 = seg1.end();
     decode_view dseg1;
@@ -784,7 +817,7 @@ segments_compare(
     bool at_slash1 = true;
     while (n1 > n0)
     {
-        consume_last(n1, dseg1, begin1,it1, cit1, skip1, at_slash1);
+        consume_last(n1, dseg1, begin1, it1, cit1, skip1, at_slash1);
     }
 
     int cmp = 0;
