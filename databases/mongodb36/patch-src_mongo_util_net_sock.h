Index: src/mongo/util/net/sock.h
--- src/mongo/util/net/sock.h.orig	2021-02-16 18:32:42 UTC
+++ src/mongo/util/net/sock.h
@@ -40,6 +40,7 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#include <unistd.h>
 
 #ifdef __OpenBSD__
 #include <sys/uio.h>
