--- lib/cli/consolecommand.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/cli/consolecommand.cpp
@@ -3,6 +3,7 @@
 #include "cli/consolecommand.hpp"
 #include "config/configcompiler.hpp"
 #include "remote/consolehandler.hpp"
+#include "remote/httputility.hpp"
 #include "remote/url.hpp"
 #include "base/configwriter.hpp"
 #include "base/serializer.hpp"
@@ -580,11 +581,11 @@ Dictionary::Ptr ConsoleCommand::SendRequest()
 
 	http::request<http::string_body> request(http::verb::post, std::string(l_Url->Format(false)), 10);
 
-	request.set(http::field::user_agent, "Icinga/DebugConsole/" + Application::GetAppVersion());
-	request.set(http::field::host, l_Url->GetHost() + ":" + l_Url->GetPort());
+	HttpUtility::Set(request, http::field::user_agent, "Icinga/DebugConsole/" + Application::GetAppVersion());
+	HttpUtility::Set(request, http::field::host, l_Url->GetHost() + ":" + l_Url->GetPort());
 
-	request.set(http::field::accept, "application/json");
-	request.set(http::field::authorization, "Basic " + Base64::Encode(l_Url->GetUsername() + ":" + l_Url->GetPassword()));
+	HttpUtility::Set(request, http::field::accept, "application/json");
+	HttpUtility::Set(request, http::field::authorization, "Basic " + Base64::Encode(l_Url->GetUsername() + ":" + l_Url->GetPassword()));
 
 	try {
 		http::write(*l_TlsStream, request);
