#include <gtk/gtk.h>

#include <stdbool.h>

#include "agreementapp.h"
#include "agreementappwin.h"

#define STR(x) #x

struct _AgreementAppWindow
{
    GtkApplicationWindow parent;
};

struct _AgreementAppWindowClass
{
    GtkApplicationWindowClass parent_class;
};

G_DEFINE_TYPE(AgreementAppWindow, agreement_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void agreement_app_window_init(AgreementAppWindow *win)
{
    gtk_window_set_title(GTK_WINDOW(win), "Agreement");
    gtk_window_set_default_size(GTK_WINDOW(win), 800, 500);

    GtkWidget* grid;
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(win), grid);

    GtkWidget *view;
    view = gtk_text_view_new();
    gtk_widget_set_hexpand(view, true);
    gtk_widget_set_vexpand(view, true);
    gtk_grid_attach(GTK_GRID(grid), view, 0, 0, 1, 1);

    GtkTextBuffer *buffer;
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
    gtk_text_buffer_set_text(buffer, "Hello world", -1);

    GtkWidget *flow_box;
    flow_box = gtk_flow_box_new();
    gtk_flow_box_set_min_children_per_line(GTK_FLOW_BOX(flow_box), 2);
    gtk_widget_set_halign(flow_box, GTK_ALIGN_CENTER);
    gtk_grid_attach(GTK_GRID(grid), flow_box, 0, 1, 1, 1);

    GtkWidget *no_button;
    no_button = gtk_button_new_from_icon_name("window-close", GTK_ICON_SIZE_BUTTON);
    gtk_button_set_always_show_image(GTK_BUTTON(no_button), true);
    gtk_button_set_label(GTK_BUTTON(no_button), "I do not agree");
    gtk_container_add(GTK_CONTAINER(flow_box), no_button);

    GtkWidget *yes_button;
    yes_button = gtk_button_new_from_stock(GTK_STOCK_YES);
    gtk_container_add(GTK_CONTAINER(flow_box), yes_button);

    gtk_widget_show_all(GTK_WIDGET(win));
}

static void agreement_app_window_class_init(AgreementAppWindowClass *class)
{
}

AgreementAppWindow *agreement_app_window_new(AgreementApp *app)
{
  return g_object_new (AGREEMENT_APP_WINDOW_TYPE, "application", app, NULL);
}

void agreement_app_window_open (AgreementAppWindow *win, GFile *file)
{
    static bool called = false;
    if (called)
    {
        g_warning( STR(__FUNCTION__) " was already called");
        return;
    }

    called = true;
}


