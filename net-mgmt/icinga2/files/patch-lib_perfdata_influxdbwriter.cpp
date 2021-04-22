--- lib/perfdata/influxdbwriter.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/perfdata/influxdbwriter.cpp
@@ -2,6 +2,7 @@
 
 #include "perfdata/influxdbwriter.hpp"
 #include "perfdata/influxdbwriter-ti.cpp"
+#include "remote/httputility.hpp"
 #include "remote/url.hpp"
 #include "icinga/service.hpp"
 #include "icinga/macroprocessor.hpp"
@@ -501,11 +502,11 @@ void InfluxdbWriter::Flush()
 
 	http::request<http::string_body> request (http::verb::post, std::string(url->Format(true)), 10);
 
-	request.set(http::field::user_agent, "Icinga/" + Application::GetAppVersion());
-	request.set(http::field::host, url->GetHost() + ":" + url->GetPort());
+	HttpUtility::Set(request, http::field::user_agent, "Icinga/" + Application::GetAppVersion());
+	HttpUtility::Set(request, http::field::host, url->GetHost() + ":" + url->GetPort());
 
 	request.body() = body;
-	request.set(http::field::content_length, request.body().size());
+	HttpUtility::Set(request, http::field::content_length, request.body().size());
 
 	try {
 		if (stream.first) {
