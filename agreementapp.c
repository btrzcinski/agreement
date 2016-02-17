#include <gtk/gtk.h>

#include "agreementapp.h"
#include "agreementappwin.h"

struct _AgreementApp
{
    GtkApplication parent;
};

struct _AgreementAppClass
{
    GtkApplicationClass parent_class;
};

G_DEFINE_TYPE(AgreementApp, agreement_app, GTK_TYPE_APPLICATION);

static void agreement_app_init(AgreementApp *app)
{
}

static void agreement_app_activate(GApplication *app)
{
    AgreementAppWindow *win;

    win = agreement_app_window_new(AGREEMENT_APP(app));
    gtk_window_present(GTK_WINDOW(win));
}

static void agreement_app_open(GApplication *app, GFile **files,
        gint n_files, const gchar *hint)
{
    GList *windows;
    AgreementAppWindow *win;
    int i;

    windows = gtk_application_get_windows(GTK_APPLICATION(app));
    if (windows)
    {
        win = AGREEMENT_APP_WINDOW(windows->data);
    }
    else
    {
        win = agreement_app_window_new(AGREEMENT_APP(app));
    }

    for (i = 0; i < n_files; i++)
    {
        agreement_app_window_open(win, files[i]);
    }

    gtk_window_present(GTK_WINDOW(win));
}

static void agreement_app_class_init(AgreementAppClass *class)
{
    G_APPLICATION_CLASS(class)->activate = agreement_app_activate;
    G_APPLICATION_CLASS(class)->open = agreement_app_open;
}

AgreementApp *agreement_app_new()
{
    return g_object_new(AGREEMENT_APP_TYPE,
            "application-id", "me.seabat.agreementapp",
            "flags", G_APPLICATION_HANDLES_OPEN,
            NULL);
}

