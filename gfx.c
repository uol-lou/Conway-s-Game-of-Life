/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Grafikausgabe-Modul
 */

// für vorgegebene Grafik Funktionen grafik_paint_point() und andere:

#include <unistd.h>
#include "gfx.h"
#include "config.h"
#include "graphic.h"
#include "engine.h"
#include "ui.h"

// Funktionen zur Grafikausgabe

void farb_demonstration(void){
    int dialog_showed = 0;
    grafik_create_paint_area(0,
                             lauf_Zeit_Daten1.spalten,
                             0,
                             lauf_Zeit_Daten1.zeilen,
                             lauf_Zeit_Daten1.spalten,
                             lauf_Zeit_Daten1.zeilen);
    while(lauf_Zeit_Daten1.schritt<lauf_Zeit_Daten1.schnitte_maximal)
    {
        grafik_lock_for_painting();
        for(int i=0;i<lauf_Zeit_Daten1.zeilen;i++)
        {
            for(int j=0;j<lauf_Zeit_Daten1.spalten;j++)
            {
                if (karte_aktuell[i][j])
                {
                    grafik_paint_point(j, i, 21);
                }
                else if(karte_aktuell[i][j]==0)
                    grafik_paint_point(j, i, 0);
            }
        }
        engine(lauf_Zeit_Daten1.zeilen,lauf_Zeit_Daten1.spalten,karte_aktuell);
        //usleep(1000000*lauf_Zeit_Daten1.pause_von_lauf);
        grafik_unlock_and_show();

        if(dialog_showed ==0) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                     "MRT 1 - V3 - Information",
                                     "MRT 1 - V3 - Farbdemonstration\n\n"
                                     "Nach dem Schließen dieses Dialogs,\n"
                                     "kann die Taste 'q' verwendet werden "
                                     "um das Programm zu beenden.\n"
                                     "kann die Taste 'Leertaste' verwendet werden"
                                     "um Animation zu pausieren oder weiterführen.\n"
                                     "kann die Taste '.' verwendet werden"
                                     "um den nächsten Animationsschritt anzuzeigen und dann zu pausieren.\n",
                                     NULL);
            dialog_showed = 1;

            while (grafik_user_input(10)>Fehler);
        }

        switch (grafik_user_input(1000*lauf_Zeit_Daten1.pause_von_lauf))
        {
            case Beenden:
                exit(0);
            case Pause:
                ui_pause();
                continue;
            case Schritt:
                ui_schnitt();
            default:
                continue;
        }
    }
}
