#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define TYPE_WINDOW (window_get_type())

G_DECLARE_FINAL_TYPE (MainWindow, window, SHOWHIDE, WINDOW, AdwApplicationWindow)

G_END_DECLS
