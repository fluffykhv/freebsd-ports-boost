pcrecpp.h used to expose std::string, which is no longer the case
starting with pcre-8.41.

Index: src/mongo/db/repl/master_slave.cpp
--- src/mongo/db/repl/master_slave.cpp.orig	2021-02-16 18:32:42 UTC
+++ src/mongo/db/repl/master_slave.cpp
@@ -83,6 +83,7 @@ using std::set;
 using std::max;
 using std::min;
 using std::set;
+using std::string;
 using std::stringstream;
 using std::unique_ptr;
 using std::vector;
