#pragma once

#include <adwaita.h>

G_BEGIN_DECLS

#define SHOWHIDE_TYPE_APPLICATION (showhide_application_get_type())

G_DECLARE_FINAL_TYPE (ShowhideApplication, showhide_application, SHOWHIDE, APPLICATION, AdwApplication)

ShowhideApplication *showhide_application_new (const char * application_id, GApplicationFlags flags);

G_END_DECLS
