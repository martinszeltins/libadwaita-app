#include "config.h"
#include "app.h"
#include "window.h"

struct _App
{
  AdwApplication parent_instance;
};

G_DEFINE_TYPE (App, app, ADW_TYPE_APPLICATION)

App * app_new (const char * id, GApplicationFlags flags)
{
  g_return_val_if_fail (id != NULL, NULL);

  return g_object_new (SHOWHIDE_TYPE_APPLICATION, "application-id", id, "flags", flags, NULL);
}

static void app_activate (GApplication * app)
{
  GtkWindow * window;

  window = gtk_application_get_active_window (GTK_APPLICATION (app));

  if (window == NULL) {
    window = g_object_new (SHOWHIDE_TYPE_WINDOW, "application", app, NULL);
  }

  gtk_window_present (window);
}

static void app_class_init (AppClass * class)
{
  GApplicationClass * app_class = G_APPLICATION_CLASS (class);

  app_class->activate = app_activate;
}

static void app_about_action (GSimpleAction *action, GVariant *parameter, gpointer user_data)
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

static void app_quit_action (GSimpleAction *action, GVariant * parameter, gpointer user_data)
{
  App *self = user_data;

  g_assert (SHOWHIDE_IS_APPLICATION (self));

  g_application_quit (G_APPLICATION (self));
}

static const GActionEntry app_actions[] = {
  { "quit", app_quit_action },
  { "about", app_about_action },
};

static void app_init (App *self)
{
  g_action_map_add_action_entries (G_ACTION_MAP (self), app_actions, G_N_ELEMENTS (app_actions), self);
  gtk_application_set_accels_for_action (GTK_APPLICATION (self), "app.quit", (const char *[]) { "<primary>q", NULL });
}

