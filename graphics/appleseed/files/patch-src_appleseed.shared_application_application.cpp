--- src/appleseed.shared/application/application.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed.shared/application/application.cpp
@@ -39,6 +39,9 @@
 #include "foundation/utility/settings.h"
 #include "foundation/utility/string.h"
 
+// Boost headers.
+#include "boost/filesystem/exception.hpp"
+
 // Standard headers.
 #include <cstring>
 #include <string>
