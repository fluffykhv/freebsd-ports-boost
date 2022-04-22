from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224090

Index: src/mongo/db/repl/oplog_fetcher.cpp
--- src/mongo/db/repl/oplog_fetcher.cpp.orig	2021-02-16 18:32:42 UTC
+++ src/mongo/db/repl/oplog_fetcher.cpp
@@ -251,7 +251,7 @@ StatusWith<boost::optional<rpc::OplogQueryMetadata>> p
         if (!metadataResult.isOK()) {
             return metadataResult.getStatus();
         }
-        oqMetadata = boost::make_optional(metadataResult.getValue());
+        oqMetadata = boost::optional<rpc::OplogQueryMetadata>(metadataResult.getValue());
     }
     return oqMetadata;
 }
