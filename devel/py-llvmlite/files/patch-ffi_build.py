--- ffi/build.py.orig	2022-01-13 16:47:16 UTC
+++ ffi/build.py
@@ -163,7 +163,7 @@ def main_posix(kind, library_ext):
         print(warning + '\n')
     else:
 
-        if not out.startswith('11'):
+        if not (out.startswith('14') or out.startswith('13') or out.startswith('12') or out.startswith('11')):
             msg = ("Building llvmlite requires LLVM 11.x.x, got "
                    "{!r}. Be sure to set LLVM_CONFIG to the right executable "
                    "path.\nRead the documentation at "
