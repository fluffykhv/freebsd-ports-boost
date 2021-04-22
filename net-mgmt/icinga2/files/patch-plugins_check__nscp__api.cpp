--- plugins/check_nscp_api.cpp.orig	2020-12-15 11:30:19 UTC
+++ plugins/check_nscp_api.cpp
@@ -16,6 +16,7 @@
 #include "base/tcpsocket.hpp" /* include global icinga::Connect */
 #include "base/tlsstream.hpp"
 #include "base/base64.hpp"
+#include "remote/httputility.hpp"
 #include "remote/url.hpp"
 #include <remote/url-characters.hpp>
 #include <boost/program_options.hpp>
@@ -365,11 +366,11 @@ static Dictionary::Ptr FetchData(const String& host, c
 
 	http::request<http::string_body> request (http::verb::get, std::string(url->Format(true)), 10);
 
-	request.set(http::field::user_agent, "Icinga/check_nscp_api/" + String(VERSION));
-	request.set(http::field::host, host + ":" + port);
+	HttpUtility::Set(request, http::field::user_agent, "Icinga/check_nscp_api/" + String(VERSION));
+	HttpUtility::Set(request, http::field::host, host + ":" + port);
 
-	request.set(http::field::accept, "application/json");
-	request.set("password", password);
+	HttpUtility::Set(request, http::field::accept, "application/json");
+	HttpUtility::Set(request, "password", password);
 
 	if (l_Debug) {
 		std::cout << "Sending request to " << url->Format(false, false) << "'.\n";
