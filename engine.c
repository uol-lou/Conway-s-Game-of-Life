/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Berechnungs-Modul
 */

#include "engine.h"
#include "config.h"
// Engine Quellcode


int karte_aktuell[500][500];

void engine(int mSpalten,int mZeilen,int p[500][500])
{
    //p[][]:karte_vorher
    int umgebung[mZeilen][mSpalten];
    int a, b, i, j;
    int karte_vorher[mZeilen + 2][mSpalten + 2];
    for (a = 0; a < mZeilen + 2; a++)
    {
        karte_vorher[a][0] = 0;
        karte_vorher[a][mSpalten + 1] = 0;
    }

    for (b = 0; b < mSpalten + 2; b++)
    {
        karte_vorher[0][b] = 0;
        karte_vorher[mZeilen + 1][b] = 0;
    }
    for (a = 1; a < mZeilen + 1; a++)
    {
        for (b = 1; b < mSpalten + 1; b++)
        {
            karte_vorher[a][b]=p[a-1][b-1];
        }
    }
    for (a = 1; a < mZeilen + 1; a++)
    {
        for (b = 1; b < mSpalten + 1; b++)
        {
            umgebung[a - 1][b - 1] = 0;
            for (i = -1; i < 2; i++)
            {
                for (j = -1; j < 2; j++)
                {
                    if (karte_vorher[a + i][b + j] == 1)
                        umgebung[a - 1][b - 1] = umgebung[a - 1][b - 1] + 1;
                }
            }
            if (karte_vorher[a][b] == 1)
                umgebung[a - 1][b - 1] = umgebung[a - 1][b - 1] - 1;
            if (karte_vorher[a][b] == 0 && umgebung[a - 1][b - 1] == 3)
                karte_aktuell[a - 1][b - 1] = 1;
            else if (karte_vorher[a][b] == 1 && umgebung[a - 1][b - 1] < 2)
                karte_aktuell[a - 1][b - 1] = 0;
            else if (karte_vorher[a][b] == 1 && umgebung[a - 1][b - 1] > 3)
                karte_aktuell[a - 1][b - 1] = 0;
            else
                karte_aktuell[a - 1][b - 1] = karte_vorher[a][b];
        }
    }
    lauf_Zeit_Daten1.schritt++;
}
