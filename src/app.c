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
    return g_object_new (TYPE_APP, "application-id", id, "flags", flags, NULL);
}

static void app_activate (GApplication * app)
{
    GtkWindow * window;

    window = gtk_application_get_active_window (GTK_APPLICATION (app));

    if (window == NULL) {
        window = g_object_new (TYPE_WINDOW, "application", app, NULL);
    }

    gtk_window_present (window);
}

static void app_class_init (AppClass * class)
{
    GApplicationClass * app_class = G_APPLICATION_CLASS (class);

    app_class->activate = app_activate;
}

static void app_about_action (GSimpleAction * action, GVariant * parameter, gpointer user_data)
{
    static const char * developers[] = { "Martins", NULL };
    App * app = user_data;

    adw_show_about_window(
        gtk_application_get_active_window (GTK_APPLICATION (app)),
        "application-name", "showhide",
        "application-icon", "org.martins.ShowHide",
        "developer-name", "Martins",
        "version", "0.1.0",
        "developers", developers,
        "copyright", "© 2022 Martins",
        NULL
    );
}

static void app_quit_action (GSimpleAction * action, GVariant * parameter, gpointer user_data)
{
    App * app = user_data;

    g_application_quit (G_APPLICATION (app));
}

static const GActionEntry app_actions[] = {
    { "quit", app_quit_action },
    { "about", app_about_action },
};

static void app_init (App * app)
{
    g_action_map_add_action_entries (G_ACTION_MAP (app), app_actions, G_N_ELEMENTS (app_actions), app);
    gtk_application_set_accels_for_action (GTK_APPLICATION (app), "app.quit", (const char *[]) { "<primary>q", NULL });
}

