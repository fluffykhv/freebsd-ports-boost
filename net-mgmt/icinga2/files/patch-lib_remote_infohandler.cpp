--- lib/remote/infohandler.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/remote/infohandler.cpp
@@ -29,7 +29,7 @@ bool InfoHandler::HandleRequest(
 
 	if (url->GetPath().empty()) {
 		response.result(http::status::found);
-		response.set(http::field::location, "/v1");
+		HttpUtility::Set(response, http::field::location, "/v1");
 		return true;
 	}
 
@@ -74,7 +74,7 @@ bool InfoHandler::HandleRequest(
 
 		HttpUtility::SendJsonBody(response, params, result);
 	} else {
-		response.set(http::field::content_type, "text/html");
+		HttpUtility::Set(response, http::field::content_type, "text/html");
 
 		String body = "<html><head><title>Icinga 2</title></head><h1>Hello from Icinga 2 (Version: " + Application::GetAppVersion() + ")!</h1>";
 		body += "<p>You are authenticated as <b>" + user->GetName() + "</b>. ";
@@ -92,7 +92,7 @@ bool InfoHandler::HandleRequest(
 
 		body += R"(<p>More information about API requests is available in the <a href="https://icinga.com/docs/icinga2/latest/" target="_blank">documentation</a>.</p></html>)";
 		response.body() = body;
-		response.set(http::field::content_length, response.body().size());
+		HttpUtility::Set(response, http::field::content_length, response.body().size());
 	}
 
 	return true;
