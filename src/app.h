#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define TYPE_APP (app_get_type())

G_DECLARE_FINAL_TYPE (App, app, SHOWHIDE, APPLICATION, AdwApplication)

App *app_new (const char * application_id, GApplicationFlags flags);

G_END_DECLS
