/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Konfigurationsdatei-Modul
 */

#include "config.h"

// für fopen, getline, fscanf, fclose:
#include <stdio.h>

// für strncmp und memset:
#include <string.h>

// für malloc, calloc und atoi:
#include <stdlib.h>
	 
// Config und Dateiarbeit Funktionen
#include "engine.h"

LAUF_ZEIT_DATEN lauf_Zeit_Daten1;

void config(void)
{
    int i,j,k,l,ex,ey;
    //char pf[16][10];
    char pf[30][15];
    FILE *r= fopen("settings-1.txt","r");
    for(i=0;i<30;i++)
    {
        fscanf(r,"%s",pf[i]);
    }
    for(i=0;i<16;i++)
    {
    	if(pf[i][0]=='Z')
    	{
    		lauf_Zeit_Daten1.zeilen=atoi(pf[i+1]);
    		printf("zeile: %d\n",lauf_Zeit_Daten1.zeilen);
    	}
    	else if(pf[i][0]=='P')
    	{
    		lauf_Zeit_Daten1.pause_von_lauf=atof(pf[i+1]);
    		printf("pause: %f s\n",lauf_Zeit_Daten1.pause_von_lauf);
    	}
    	else if(pf[i][0]=='S')
    	{
    		if(pf[i][1]=='p')
    		{
    			lauf_Zeit_Daten1.spalten=atoi(pf[i+1]);
    			printf("spalte: %d \n",lauf_Zeit_Daten1.spalten);
    		}
    		else if(pf[i][7]==':')
    		{
    		    lauf_Zeit_Daten1.schritt=atoi(pf[i+1]);
    		    printf("schritt: %d \n",lauf_Zeit_Daten1.schritt);
    		}
    		else if(pf[i][7]=='e')
    		{
    		    lauf_Zeit_Daten1.schnitte_maximal=atoi(pf[i+1]);
    		    printf("schritte: %d \n",lauf_Zeit_Daten1.schnitte_maximal);
    		}
    	}
    	else if(pf[i][0]=='A')
    	{
    		for(k=0;k<15;k++)
    		{
    			for(l=0;l<15;l++)
    			{
    				if(pf[i+k+1][l]=='x')
    					{lauf_Zeit_Daten1.puffer[k][l]=1;ex=k+1;ey=l+1;}
    				else if(pf[i+k+1][l]=='.')
    					{lauf_Zeit_Daten1.puffer[k][l]=0;ex=k+1;ey=l+1;}
    				printf("%d ",lauf_Zeit_Daten1.puffer[k][l]);
    			}
    			printf("\n");
    		}
    	}
    }
    fclose(r);


    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            karte_aktuell[i+lauf_Zeit_Daten1.zeilen/2-ex/2][j+lauf_Zeit_Daten1.spalten/2-ey/2]=lauf_Zeit_Daten1.puffer[i][j];
        }
    }
}
