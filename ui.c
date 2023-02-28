/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Nutzerinteraktions-Modul
 */

#include "ui.h"

// für vorgegebene UI Funktionen: grafik_user_input()
# include "graphic.h"

// für die Funktion `exit`
#include <stdlib.h>
#include "config.h"
#include "engine.h"

// Funktionen um Nutzerinteraktionen zu behandeln

//void ui(void){
//    switch (grafik_user_input(100))
//    {
//        case Beenden:
//            //(exit(0);
//            return;
//        case Pause:
//            while(grafik_user_input(100)!=Pause);
//            continue;
//        case Schritt:
//            while(1)
//            {
//                if(grafik_user_input(0)==Schritt)
//                {
//                    grafik_lock_for_painting();
//                    for(int i=0;i<lauf_Zeit_Daten1.zeilen;i++)
//                    {
//                        for(int j=0;j<lauf_Zeit_Daten1.spalten;j++)
//                        {
//                            if (karte_aktuell[i][j])
//                                grafik_paint_point(j, i, 21);
//                            else if(karte_aktuell[i][j]==0)
//                                grafik_paint_point(j, i, 0);
//                        }
//                    }
//                    grafik_unlock_and_show();
//                    engine(lauf_Zeit_Daten1.zeilen,lauf_Zeit_Daten1.spalten,karte_aktuell);
//                }
//                else if(grafik_user_input(0)==Beenden)
//                {
//                    return;
//                }
//            }
//        default:
//            continue;
//    }
//}

void ui_pause(void){
    while(1)
    {
    	int a;
    	a=grafik_user_input(1000*lauf_Zeit_Daten1.pause_von_lauf);
    	if(a==Schritt)
    	{
    		grafik_lock_for_painting();
    		for(int i=0;i<lauf_Zeit_Daten1.zeilen;i++)
    		{
    			for(int j=0;j<lauf_Zeit_Daten1.spalten;j++)
    			{
    				if (karte_aktuell[i][j])
    					grafik_paint_point(j, i, 21);
    				else if(karte_aktuell[i][j]==0)
    					grafik_paint_point(j, i, 0);
    			}
    		}
    		grafik_unlock_and_show();
    		engine(lauf_Zeit_Daten1.zeilen,lauf_Zeit_Daten1.spalten,karte_aktuell);

    	}
    	else if(a==Beenden)
    		exit(0);
    	else if(a==Pause)
    		break;
    }
}

void ui_schnitt(void){
    while(1)
    {
    	int a;
    	a=grafik_user_input(1000*lauf_Zeit_Daten1.pause_von_lauf);
        if(a==Schritt)
        {
            grafik_lock_for_painting();
            for(int i=0;i<lauf_Zeit_Daten1.zeilen;i++)
            {
                for(int j=0;j<lauf_Zeit_Daten1.spalten;j++)
                {
                    if (karte_aktuell[i][j])
                        grafik_paint_point(j, i, 21);
                    else if(karte_aktuell[i][j]==0)
                        grafik_paint_point(j, i, 0);
                }
            }
            grafik_unlock_and_show();
            engine(lauf_Zeit_Daten1.zeilen,lauf_Zeit_Daten1.spalten,karte_aktuell);
        }
        else if(a==Beenden)
            exit(0);
        else if(a==Pause)
            break;
    }
}
