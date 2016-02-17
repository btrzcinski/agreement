#include <gtk/gtk.h>

#include "agreementapp.h"

int main(int argc, char *argv[])
{
    return g_application_run(G_APPLICATION(agreement_app_new()), argc, argv);
}
