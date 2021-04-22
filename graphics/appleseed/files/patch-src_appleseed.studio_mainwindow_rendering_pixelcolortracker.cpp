--- src/appleseed.studio/mainwindow/rendering/pixelcolortracker.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed.studio/mainwindow/rendering/pixelcolortracker.cpp
@@ -133,10 +133,10 @@ void PixelColorTracker::set_rgba_labels(const QPoint& 
             static_cast<size_t>(pixel.y),
             linear_rgba);
 
-        m_r_label->setText(QString().sprintf("%4.3f", linear_rgba.r));
-        m_g_label->setText(QString().sprintf("%4.3f", linear_rgba.g));
-        m_b_label->setText(QString().sprintf("%4.3f", linear_rgba.b));
-        m_a_label->setText(QString().sprintf("%4.3f", linear_rgba.a));
+        m_r_label->setText(QString::number(linear_rgba.r, 'f', 3));
+        m_g_label->setText(QString::number(linear_rgba.g, 'f', 3));
+        m_b_label->setText(QString::number(linear_rgba.b, 'f', 3));
+        m_a_label->setText(QString::number(linear_rgba.a, 'f', 3));
     }
     else
     {
