#include "config.h"
#include <glib/gi18n.h>
#include "app.h"

int main (int argc, char *argv[])
{
  g_autoptr(App) app = NULL;

  app = app_new ("org.martins.ShowHide", G_APPLICATION_FLAGS_NONE);

  return g_application_run (G_APPLICATION (app), argc, argv);
}
