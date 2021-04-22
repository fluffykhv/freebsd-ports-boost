--- lib/remote/eventshandler.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/remote/eventshandler.cpp
@@ -100,7 +100,7 @@ bool EventsHandler::HandleRequest(
 	server.StartStreaming();
 
 	response.result(http::status::ok);
-	response.set(http::field::content_type, "application/json");
+	HttpUtility::Set(response, http::field::content_type, "application/json");
 
 	IoBoundWorkSlot dontLockTheIoThread (yc);
 
