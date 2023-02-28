/* BOF MAIN_C
 Praktikumsversuch: Einführung in die Sprache C
 Haupt-Programm
 */

#include "graphic.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"
#include "engine.h"
#include "gfx.h"
#include "ui.h"

// Forwarddeklaration der später definierten Hilfsfunktionen:
void goodbye_msg(void);
static void init_exit(void);



// -- Hilfsfunktionen ---
static void init_exit(void)
{
        if(atexit(goodbye_msg)){
                fprintf(stderr, "Fehler bei Registrierung der Exitfunktion\n");
                exit(-1);
        }
}

void goodbye_msg(void)
{
        printf("MRT1, V3, Programm beendet.\n");
}

/* EOF MAIN_C */
int main(int argc, char *argv[]) {

    init_exit();
    config();
    grafik_init_window();
    farb_demonstration();
    grafik_close_window();
    return 0;
}