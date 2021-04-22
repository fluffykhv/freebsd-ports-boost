--- host/lib/usrp/usrp2/usrp2_iface.hpp.orig	2021-04-22 08:57:07 UTC
+++ host/lib/usrp/usrp2/usrp2_iface.hpp
@@ -13,6 +13,8 @@
 #include <uhd/types/serial.hpp>
 #include <uhd/types/wb_iface.hpp>
 #include <uhd/usrp/mboard_eeprom.hpp>
+#include <boost/math/special_functions/round.hpp>
+#include <boost/math/special_functions/sign.hpp>
 #include <boost/utility.hpp>
 #include <functional>
 #include <memory>
