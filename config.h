#ifndef CONFIG_HH
#define CONFIG_HH

// Config Schnittstelle

typedef struct laufzeitdaten
{
    int spalten; //die Anzahl der Pixel der Animationsfläche in Richtung der X-Achse
    int zeilen; //die Anzahl der Pixel der Animationsfläche in Richtung der Y-Achse
    int schritt; //ein Zähler, welcher den derzeitigen Animationsschritt speichert (Schritt)
    int schnitte_maximal; // ein Zähler, welcher den derzeitigen Animationsschritt speichert
    float pause_von_lauf;
    int puffer[15][15];
//    int za; //na
//    int zam; //zam
//    float pa; //pa
//    int puffer[3][10]; //puffer

}LAUF_ZEIT_DATEN;


extern LAUF_ZEIT_DATEN lauf_Zeit_Daten1;
void config(void);
#endif //CONFIG_HH

