--- lib/perfdata/elasticsearchwriter.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/perfdata/elasticsearchwriter.cpp
@@ -2,6 +2,7 @@
 
 #include "perfdata/elasticsearchwriter.hpp"
 #include "perfdata/elasticsearchwriter-ti.cpp"
+#include "remote/httputility.hpp"
 #include "remote/url.hpp"
 #include "icinga/compatutility.hpp"
 #include "icinga/service.hpp"
@@ -474,27 +475,27 @@ void ElasticsearchWriter::SendRequest(const String& bo
 
 	http::request<http::string_body> request (http::verb::post, std::string(url->Format(true)), 10);
 
-	request.set(http::field::user_agent, "Icinga/" + Application::GetAppVersion());
-	request.set(http::field::host, url->GetHost() + ":" + url->GetPort());
+	HttpUtility::Set(request, http::field::user_agent, "Icinga/" + Application::GetAppVersion());
+	HttpUtility::Set(request, http::field::host, url->GetHost() + ":" + url->GetPort());
 
 	/* Specify required headers by Elasticsearch. */
-	request.set(http::field::accept, "application/json");
+	HttpUtility::Set(request, http::field::accept, "application/json");
 
 	/* Use application/x-ndjson for bulk streams. While ES
 	 * is able to handle application/json, the newline separator
 	 * causes problems with Logstash (#6609).
 	 */
-	request.set(http::field::content_type, "application/x-ndjson");
+	HttpUtility::Set(request, http::field::content_type, "application/x-ndjson");
 
 	/* Send authentication if configured. */
 	String username = GetUsername();
 	String password = GetPassword();
 
 	if (!username.IsEmpty() && !password.IsEmpty())
-		request.set(http::field::authorization, "Basic " + Base64::Encode(username + ":" + password));
+		HttpUtility::Set(request, http::field::authorization, "Basic " + Base64::Encode(username + ":" + password));
 
 	request.body() = body;
-	request.set(http::field::content_length, request.body().size());
+	HttpUtility::Set(request, http::field::content_length, request.body().size());
 
 	/* Don't log the request body to debug log, this is already done above. */
 	Log(LogDebug, "ElasticsearchWriter")
