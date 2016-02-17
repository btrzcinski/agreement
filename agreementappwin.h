#ifndef __AGREEMENTAPPWIN_H
#define __AGREEMENTAPPWIN_H

#include <gtk/gtk.h>
#include "agreementapp.h"

#define AGREEMENT_APP_WINDOW_TYPE (agreement_app_window_get_type())
#define AGREEMENT_APP_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), AGREEMENT_APP_WINDOW_TYPE, AgreementAppWindow))

typedef struct _AgreementAppWindow AgreementAppWindow;
typedef struct _AgreementAppWindowClass AgreementAppWindowClass;

GType agreement_app_window_get_type();
AgreementAppWindow *agreement_app_window_new(AgreementApp *app);
void agreement_app_window_open(AgreementAppWindow *win, GFile *file);

#endif /* __AGREEMENTAPPWIN_H */
