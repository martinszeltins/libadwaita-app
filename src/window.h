#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SHOWHIDE_TYPE_WINDOW (showhide_window_get_type())

G_DECLARE_FINAL_TYPE (ShowhideWindow, showhide_window, SHOWHIDE, WINDOW, AdwApplicationWindow)

G_END_DECLS
