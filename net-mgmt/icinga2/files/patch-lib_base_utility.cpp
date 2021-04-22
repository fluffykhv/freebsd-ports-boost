--- lib/base/utility.cpp.orig	2020-12-15 11:30:19 UTC
+++ lib/base/utility.cpp
@@ -725,7 +725,11 @@ void Utility::CopyFile(const String& source, const String& target)
 {
 	namespace fs = boost::filesystem;
 
+#if BOOST_VERSION >= 107400
+	fs::copy_file(fs::path(source.Begin(), source.End()), fs::path(target.Begin(), target.End()), fs::copy_options::overwrite_existing);
+#else /* BOOST_VERSION */
 	fs::copy_file(fs::path(source.Begin(), source.End()), fs::path(target.Begin(), target.End()), fs::copy_option::overwrite_if_exists);
+#endif /* BOOST_VERSION */
 }
 
 /*
