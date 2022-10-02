#include "config.h"
#include "window.h"

struct _MainWindow
{
    AdwApplicationWindow  parent_instance;
    GtkHeaderBar         * header_bar;
    GtkLabel             * label;
};

G_DEFINE_FINAL_TYPE (MainWindow, showhide_window, ADW_TYPE_APPLICATION_WINDOW)

static void showhide_window_class_init (MainWindowClass * class)
{
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (class);

    gtk_widget_class_set_template_from_resource (widget_class, "/org/martins/ShowHide/window.ui");
    gtk_widget_class_bind_template_child (widget_class, MainWindow, header_bar);
    gtk_widget_class_bind_template_child (widget_class, MainWindow, label);
}

static void showhide_window_init (MainWindow * self)
{
    gtk_widget_init_template (GTK_WIDGET (self));
}
