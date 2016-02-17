#include <gtk/gtk.h>

#include "agreementapp.h"
#include "agreementappwin.h"

struct _AgreementAppWindow
{
    GtkApplicationWindow parent;
};

struct _AgreementAppWindowClass
{
    GtkApplicationWindowClass parent_class;
};

G_DEFINE_TYPE(AgreementAppWindow, agreement_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void agreement_app_window_init(AgreementAppWindow *app)
{
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
}


