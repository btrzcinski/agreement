#ifndef __AGREEMENTAPP_H
#define __AGREEMENTAPP_H

#include <gtk/gtk.h>

#define AGREEMENT_APP_TYPE (agreement_app_get_type())
#define AGREEMENT_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), AGREEMENT_APP_TYPE, AgreementApp))

typedef struct _AgreementApp AgreementApp;
typedef struct _AgreementAppClass AgreementAppClass;

GType agreement_app_get_type();
AgreementApp *agreement_app_new();

#endif /* __AGREEMENTAPP_H */
