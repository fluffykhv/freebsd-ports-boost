--- lib/remote/httputility.hpp.orig	2020-12-15 11:30:19 UTC
+++ lib/remote/httputility.hpp
@@ -5,8 +5,12 @@
 
 #include "remote/url.hpp"
 #include "base/dictionary.hpp"
+#include "base/string.hpp"
 #include <boost/beast/http.hpp>
+#include <boost/lexical_cast.hpp>
 #include <string>
+#include <type_traits>
+#include <utility>
 
 namespace icinga
 {
@@ -26,6 +30,30 @@ class HttpUtility (public)
 	static void SendJsonBody(boost::beast::http::response<boost::beast::http::string_body>& response, const Dictionary::Ptr& params, const Value& val);
 	static void SendJsonError(boost::beast::http::response<boost::beast::http::string_body>& response, const Dictionary::Ptr& params, const int code,
 		const String& verbose = String(), const String& diagnosticInformation = String());
+
+	template<class Message, class Key, class Value, typename std::enable_if<std::is_arithmetic<Value>::value, int>::type = 0>
+	static void Set(Message& message, Key&& key, Value value)
+	{
+		Set(message, std::forward<Key>(key), boost::lexical_cast<std::string>(value));
+	}
+
+	template<class Message, class Key>
+	static void Set(Message& message, Key&& key, const String& value)
+	{
+		Set(message, std::forward<Key>(key), value.GetData());
+	}
+
+	template<class Message, class Key>
+	static void Set(Message& message, Key&& key, String&& value)
+	{
+		Set(message, std::forward<Key>(key), value.GetData());
+	}
+
+	template<class Message, class Key, class Value, typename std::enable_if<!std::is_arithmetic<Value>::value, int>::type = 0>
+	static void Set(Message& message, Key&& key, Value&& value)
+	{
+		message.set(std::forward<Key>(key), std::forward<Value>(value));
+	}
 };
 
 }
