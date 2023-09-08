From 72c2eeb3980ed0dc530de9241e25b247517de018 Mon Sep 17 00:00:00 2001
From: Klemens Morgenstern <klemens.d.morgenstern@gmail.com>
Date: Fri, 12 May 2023 22:40:31 +0800
Subject: [PATCH] ssl_stream doesn't use BOOST_BEAST_ASYNC_TPARAM1 due to clang
 errors.

Closes #2661
---
 boost/beast/ssl/ssl_stream.hpp | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git boost/beast/ssl/ssl_stream.hpp boost/beast/ssl/ssl_stream.hpp
index 7c4183a525..452320b722 100644
--- boost/beast/ssl/ssl_stream.hpp
+++ boost/beast/ssl/ssl_stream.hpp
@@ -673,7 +673,7 @@ class ssl_stream
         ssl_stream<SyncStream>& stream,
         boost::system::error_code& ec);
 
-    template<class AsyncStream, BOOST_BEAST_ASYNC_TPARAM1 TeardownHandler>
+    template<class AsyncStream, typename TeardownHandler>
     friend
     void
     async_teardown(
@@ -697,7 +697,7 @@ teardown(
 }
 
 template<class AsyncStream,
-        BOOST_BEAST_ASYNC_TPARAM1 TeardownHandler = net::default_completion_token_t<beast::executor_type<AsyncStream>>>
+        typename TeardownHandler = net::default_completion_token_t<beast::executor_type<AsyncStream>>>
 void
 async_teardown(
     boost::beast::role_type role,
