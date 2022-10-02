#include "config.h"
#include "app.h"
#include "window.h"

struct _App
{
  AdwApplication parent_instance;
};

G_DEFINE_TYPE (App, showhide_application, ADW_TYPE_APPLICATION)

App * app_new (const char *application_id, GApplicationFlags flags)
{
  g_return_val_if_fail (application_id != NULL, NULL);

  return g_object_new (SHOWHIDE_TYPE_APPLICATION, "application-id", application_id, "flags", flags, NULL);
}

static void showhide_application_activate (GApplication *app)
{
  GtkWindow *window;

  g_assert (SHOWHIDE_IS_APPLICATION (app));

  window = gtk_application_get_active_window (GTK_APPLICATION (app));

  if (window == NULL)
  {
    window = g_object_new (SHOWHIDE_TYPE_WINDOW, "application", app, NULL);
  }

  gtk_window_present (window);
}

static void showhide_application_class_init (AppClass *klass)
{
  GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

  app_class->activate = showhide_application_activate;
}

static void showhide_application_about_action (GSimpleAction *action, GVariant *parameter, gpointer user_data)
{
  static const char *developers[] = {"Martins", NULL};
  App *self = user_data;

  adw_show_about_window(
    gtk_application_get_active_window (GTK_APPLICATION (self)),
    "application-name", "showhide",
    "application-icon", "org.martins.ShowHide",
    "developer-name", "Martins",
    "version", "0.1.0",
    "developers", developers,
    "copyright", "© 2022 Martins",
    NULL
  );
}

static void showhide_application_quit_action (GSimpleAction *action, GVariant * parameter, gpointer user_data)
{
  App *self = user_data;

  g_assert (SHOWHIDE_IS_APPLICATION (self));

  g_application_quit (G_APPLICATION (self));
}

static const GActionEntry app_actions[] = {
  { "quit", showhide_application_quit_action },
  { "about", showhide_application_about_action },
};

static void showhide_application_init (App *self)
{
  g_action_map_add_action_entries (G_ACTION_MAP (self), app_actions, G_N_ELEMENTS (app_actions), self);
  gtk_application_set_accels_for_action (GTK_APPLICATION (self), "app.quit", (const char *[]) { "<primary>q", NULL });
}

