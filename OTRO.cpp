#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cctype>
#include <stdlib.h>
#include "Funciones.h"
#include "rlutil.h"

using namespace std;

int main (){

    int OMP=1;

    if (OMP==1) /// SI OPCION 1  COMIENZA EL JUEGO
    {
        int Ronda=0;
          while(Ronda!=6)
        {
        cout << "                                    ....UN...GRAN...CERDO!!!       " << endl;
        cout <<"----------------------------------------------------------------------------------------------------------------"<< endl;

         for (Ronda=1; Ronda<6; Ronda++){


        cout <<"RONDA #" << Ronda << endl;
     rlutil::cls();
        int Turno=0;
       if(Turno=0){


         rlutil::locate(20,10);
          cout <<  "*****ES TU TURNO DE JUGAR! PRESIONA UNA TECLA PARA TIRAR LOS DADOS*****" << endl << endl;
    getch();
       }}}}

       return 0;}
