--- lib/remote/configfileshandler.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/remote/configfileshandler.cpp
@@ -82,9 +82,9 @@ bool ConfigFilesHandler::HandleRequest(
 
 		String content((std::istreambuf_iterator<char>(fp)), std::istreambuf_iterator<char>());
 		response.result(http::status::ok);
-		response.set(http::field::content_type, "application/octet-stream");
+		HttpUtility::Set(response, http::field::content_type, "application/octet-stream");
 		response.body() = content;
-		response.set(http::field::content_length, response.body().size());
+		HttpUtility::Set(response, http::field::content_length, response.body().size());
 	} catch (const std::exception& ex) {
 		HttpUtility::SendJsonError(response, params, 500, "Could not read file.",
 			DiagnosticInformation(ex));
