--- ffi/build.py.orig	2021-02-26 12:43:25 UTC
+++ ffi/build.py
@@ -163,7 +163,7 @@ def main_posix(kind, library_ext):
         print(warning + '\n')
     else:
 
-        if not (out.startswith('10.0.') or out.startswith('9.0')):
+        if not (out.startswith('11.0.') or out.startswith('10.0.') or out.startswith('9.0')):
             msg = ("Building llvmlite requires LLVM 10.0.x or 9.0.x, got "
                    "{!r}. Be sure to set LLVM_CONFIG to the right executable "
                    "path.\nRead the documentation at "
