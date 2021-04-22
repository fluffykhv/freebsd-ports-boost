--- lib/remote/httputility.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/remote/httputility.cpp
@@ -56,9 +56,9 @@ void HttpUtility::SendJsonBody(boost::beast::http::res
 {
 	namespace http = boost::beast::http;
 
-	response.set(http::field::content_type, "application/json");
+	HttpUtility::Set(response, http::field::content_type, "application/json");
 	response.body() = JsonEncode(val, params && GetLastParameter(params, "pretty"));
-	response.set(http::field::content_length, response.body().size());
+	HttpUtility::Set(response, http::field::content_length, response.body().size());
 }
 
 void HttpUtility::SendJsonError(boost::beast::http::response<boost::beast::http::string_body>& response,
