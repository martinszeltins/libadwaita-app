#include "config.h"
#include <glib/gi18n.h>
#include "showhide-application.h"

int main (int argc, char *argv[])
{
  g_autoptr(ShowhideApplication) app = NULL;
  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  app = showhide_application_new ("org.martins.ShowHide", G_APPLICATION_FLAGS_NONE);

  return g_application_run (G_APPLICATION (app), argc, argv);
}
