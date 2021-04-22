--- lib/remote/httpserverconnection.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/remote/httpserverconnection.cpp
@@ -184,12 +184,12 @@ bool EnsureValidHeaders(
 				{ "status", String("Bad Request: ") + errorMsg }
 			}));
 		} else {
-			response.set(http::field::content_type, "text/html");
+			HttpUtility::Set(response, http::field::content_type, "text/html");
 			response.body() = String("<h1>Bad Request</h1><p><pre>") + errorMsg + "</pre></p>";
-			response.set(http::field::content_length, response.body().size());
+			HttpUtility::Set(response, http::field::content_length, response.body().size());
 		}
 
-		response.set(http::field::connection, "close");
+		HttpUtility::Set(response, http::field::connection, "close");
 
 		boost::system::error_code ec;
 
@@ -247,20 +247,20 @@ bool HandleAccessControl(
 				auto& origin (request[http::field::origin]);
 
 				if (allowedOrigins.find(origin.to_string()) != allowedOrigins.end()) {
-					response.set(http::field::access_control_allow_origin, origin);
+					HttpUtility::Set(response, http::field::access_control_allow_origin, origin);
 				}
 
 				allowOriginHeader.Done();
 
-				response.set(http::field::access_control_allow_credentials, "true");
+				HttpUtility::Set(response, http::field::access_control_allow_credentials, "true");
 
 				if (request.method() == http::verb::options && !request[http::field::access_control_request_method].empty()) {
 					response.result(http::status::ok);
-					response.set(http::field::access_control_allow_methods, "GET, POST, PUT, DELETE");
-					response.set(http::field::access_control_allow_headers, "Authorization, X-HTTP-Method-Override");
+					HttpUtility::Set(response, http::field::access_control_allow_methods, "GET, POST, PUT, DELETE");
+					HttpUtility::Set(response, http::field::access_control_allow_headers, "Authorization, X-HTTP-Method-Override");
 					response.body() = "Preflight OK";
-					response.set(http::field::content_length, response.body().size());
-					response.set(http::field::connection, "close");
+					HttpUtility::Set(response, http::field::content_length, response.body().size());
+					HttpUtility::Set(response, http::field::connection, "close");
 
 					boost::system::error_code ec;
 
@@ -288,10 +288,10 @@ bool EnsureAcceptHeader(
 
 	if (request.method() != http::verb::get && request[http::field::accept] != "application/json") {
 		response.result(http::status::bad_request);
-		response.set(http::field::content_type, "text/html");
+		HttpUtility::Set(response, http::field::content_type, "text/html");
 		response.body() = "<h1>Accept header is missing or not set to 'application/json'.</h1>";
-		response.set(http::field::content_length, response.body().size());
-		response.set(http::field::connection, "close");
+		HttpUtility::Set(response, http::field::content_length, response.body().size());
+		HttpUtility::Set(response, http::field::connection, "close");
 
 		boost::system::error_code ec;
 
@@ -320,8 +320,8 @@ bool EnsureAuthenticatedUser(
 			<< "Unauthorized request: " << request.method_string() << ' ' << request.target();
 
 		response.result(http::status::unauthorized);
-		response.set(http::field::www_authenticate, "Basic realm=\"Icinga 2\"");
-		response.set(http::field::connection, "close");
+		HttpUtility::Set(response, http::field::www_authenticate, "Basic realm=\"Icinga 2\"");
+		HttpUtility::Set(response, http::field::connection, "close");
 
 		if (request[http::field::accept] == "application/json") {
 			HttpUtility::SendJsonBody(response, nullptr, new Dictionary({
@@ -329,9 +329,9 @@ bool EnsureAuthenticatedUser(
 				{ "status", "Unauthorized. Please check your user credentials." }
 			}));
 		} else {
-			response.set(http::field::content_type, "text/html");
+			HttpUtility::Set(response, http::field::content_type, "text/html");
 			response.body() = "<h1>Unauthorized. Please check your user credentials.</h1>";
-			response.set(http::field::content_length, response.body().size());
+			HttpUtility::Set(response, http::field::content_length, response.body().size());
 		}
 
 		boost::system::error_code ec;
@@ -421,12 +421,12 @@ bool EnsureValidBody(
 				{ "status", String("Bad Request: ") + ec.message() }
 			}));
 		} else {
-			response.set(http::field::content_type, "text/html");
+			HttpUtility::Set(response, http::field::content_type, "text/html");
 			response.body() = String("<h1>Bad Request</h1><p><pre>") + ec.message() + "</pre></p>";
-			response.set(http::field::content_length, response.body().size());
+			HttpUtility::Set(response, http::field::content_length, response.body().size());
 		}
 
-		response.set(http::field::connection, "close");
+		HttpUtility::Set(response, http::field::connection, "close");
 
 		http::async_write(stream, response, yc[ec]);
 		stream.async_flush(yc[ec]);
@@ -511,7 +511,7 @@ void HttpServerConnection::ProcessMessages(boost::asio
 			parser.header_limit(1024 * 1024);
 			parser.body_limit(-1);
 
-			response.set(http::field::server, l_ServerHeader);
+			HttpUtility::Set(response, http::field::server, l_ServerHeader);
 
 			if (!EnsureValidHeaders(*m_Stream, buf, parser, response, m_ShuttingDown, yc)) {
 				break;
