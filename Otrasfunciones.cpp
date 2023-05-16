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


/// FUNCIONES INTEGRADORAS

int Menuprincipal (int OMP){


     cout << endl;
    cout << endl;
    cout << "                           **************************"<< endl;
    cout << "                           *             ___        * " << endl;
    cout << "                           *      UN   <(^ ^)>)     *   " << endl;
    cout << "                           *    GRAN    ( @ )  )~   *   " << endl;
    cout << "                           *   CERDO     ! ! !!     *   " << endl;
    cout << "                           *                        *   " << endl;
    cout << "                           **************************" << endl << endl<< endl;
    cout << "                              +------------------+ "  << endl;
    cout << "                              | 1 - JUGAR!       |  " << endl;
    cout << "                              | 2 - ESTADISTICAS | " << endl;
    cout << "                              | 3 - CERDITOS     |" << endl ;
    cout << "                              | 4 - SALIR        |" << endl ;
    cout << "                              +------------------+ " << endl;
    cout << endl << endl;
    cout << "                                   -->";
    cin >> OMP; ///OPCION MENU PRINCIPAL
    cin.ignore();

    return OMP;


}

void Ingresonombres (string &Jugador1, string &Jugador2){

 cout << endl << endl;
        cout << endl << endl;
        cout << "                     -------------------------------------------------------------" << endl;
        cout << "                       - Ingrese nombre del Jugador #1: ";
        getline(cin,Jugador1);
        for(int i=0; i<Jugador1.length();i++){
            Jugador1[i]=toupper(Jugador1[i]);
        }
        cout << "                     -------------------------------------------------------------" << endl;
        cout << "                       - Ingrese nombre del Jugador #2: ";
        getline(cin,Jugador2);
        for(int i=0; i<Jugador2.length();i++){
            Jugador2[i]=toupper(Jugador2[i]);
        }
        cout << endl << endl;


}

void Turnos (string &Jugador1,string &Jugador2){
rlutil::locate(15,5);
        cout << "***PARA DETERMINAR QUIEN EMPIEZA LANZARAN 2 DADOS CADA UNO.EL DE MAYOR PUNTAJE IRA PRIMERO***";
          rlutil::locate(30,6);  cout << "***CASO CONTRARIO, SERA EL QUE SAQUE EL DADO MAS ALTO***"<< endl;

  rlutil::locate(1,10);
  bool Iguales=1;
   while(Iguales==1){
        cout << Jugador1 << " PRESIONA PARA LANZAR!!";
           getch();
           Lanzamiento ();
 srand(time(NULL)); /// INICIALIZACION MOTOR DE RANDOM
                 cout << Jugador1 <<":"<< endl;
                    int Dado1J1=rand()%6+1;
                    int Dado2J1=rand()%6+1;
                    Dados(Dado1J1);
                    Dados(Dado2J1);



                cout << Jugador2 <<" PRESIONA PARA LANZAR!!";
                getch();
           Lanzamiento ();

        cout << Jugador1 <<":"<< endl;
                Dados(Dado1J1);
                    Dados(Dado2J1);

                                      cout << Jugador2 << ":" << endl;
        int Dado1J2=rand()%6+1;
                    int Dado2J2=rand()%6+1;
                    Dados(Dado1J2);
                    Dados(Dado2J2);
 getch();
       rlutil::cls();
        Iguales=0;
        if (Dado1J1+Dado2J1<Dado1J2+Dado2J2){

            string Auxiliar;
            Auxiliar=Jugador1;
            Jugador1=Jugador2;
            Jugador2=Auxiliar;

        }
        else{
             if (Dado1J1+Dado2J1==Dado1J2+Dado2J2){

                if((Dado1J2>Dado1J1&&Dado1J2>Dado2J1)||(Dado2J2>Dado1J1&&Dado2J2>Dado2J1)){
                          string Auxiliar;
            Auxiliar=Jugador1;
            Jugador1=Jugador2;
            Jugador2=Auxiliar;

                }
                else{

                    cout << "VUELVAN A LANZAR!!";
                    Iguales=1;
                    rlutil::cls();
                }

             }

        }
   }
}

void Calculopuntajes

(int VectorPDVJ1[5],int VectorPDVJ2[5],int &AcumgeneralJ1, int&AcumgeneralJ2,

int &ContoinkJ1,int &ContoinkJ2, int &MaxlanzamientosJ1, int &MaxlanzamientosJ2, int &PorkyJugador ){



        /// CALCULO JUGADOR 1
        /// PDVS POR MAYOR CANTIDAD DE TRUFAS
        if(AcumgeneralJ1>=AcumgeneralJ2){
        VectorPDVJ1[0]=5;}
        else{
        VectorPDVJ1[0]=0;
        }
        /// PDVS CADA 50 TRUFAS
        VectorPDVJ1[1]=AcumgeneralJ1/50;
        /// PDVS POR OINKS
        VectorPDVJ1[2]=ContoinkJ1*2;
        /// PDVS POR MAXLANZAMIENTOS
        if(MaxlanzamientosJ1>MaxlanzamientosJ2||MaxlanzamientosJ1==MaxlanzamientosJ2){
        VectorPDVJ1[3]=3;
        }
        else {

            VectorPDVJ1[3]=0;
        }
        /// PORKY
        if (PorkyJugador==1){

            VectorPDVJ1[4]=1;
        }


        /// CALCULO JUGADOR 2
        /// PDVS POR MAYOR CANTIDAD DE TRUFAS
        if(AcumgeneralJ1<=AcumgeneralJ2){
        VectorPDVJ2[0]=5;}
        else{
        VectorPDVJ2[0]=0;
        }
        /// PDVS CADA 50 TRUFAS
        VectorPDVJ2[1]=AcumgeneralJ2/50;
         /// PDVS POR OINKS
        VectorPDVJ2[2]=ContoinkJ2*2;
        /// PDVS POR MAXLANZAMIENTOS
        if(MaxlanzamientosJ2>MaxlanzamientosJ1||MaxlanzamientosJ1==MaxlanzamientosJ2){
        VectorPDVJ2[3]=3;
        }
        else {

            VectorPDVJ2[3]=0;
        }
    /// PORKY
        if (PorkyJugador==2){

            VectorPDVJ2[4]=1;
        }


         /// FOR SUMADOR DE JUGADOR 1
        int AcumuladorPDVS=0;
        for(int i=0;i<5;i++){

             AcumuladorPDVS+=VectorPDVJ1[i];
        }
        VectorPDVJ1[5]=AcumuladorPDVS;


        ///FOR SUMADOR JUGADOR 2
        AcumuladorPDVS=0;
            for(int i=0;i<5;i++){

             AcumuladorPDVS+=VectorPDVJ2[i];
        }
        VectorPDVJ2[5]=AcumuladorPDVS;

        if (PorkyJugador==1){

            if(VectorPDVJ2[5]>=1&&VectorPDVJ2[5]<=9){

                VectorPDVJ2[4]=-1;
            }
            else{
                if(VectorPDVJ2[5]>9&&VectorPDVJ2[5]<=15){

                VectorPDVJ2[4]=-2;
                }
                else{

                  if(VectorPDVJ2[5]>15){

                     VectorPDVJ2[4]=-3;

                  }

                }
                }
                 VectorPDVJ2[5]=VectorPDVJ2[5]+VectorPDVJ2[4];
            }



        if (PorkyJugador==2){

            if(VectorPDVJ1[5]>=1&&VectorPDVJ1[5]<=9){

                VectorPDVJ1[4]=-1;
            }
            else{
                if(VectorPDVJ1[5]>9&&VectorPDVJ1[5]<=15){

                VectorPDVJ2[4]=-2;
                }
                else{

                  if(VectorPDVJ1[5]>15){

                     VectorPDVJ1[4]=-3;

                  }

                }
                }
                   VectorPDVJ1[5]=VectorPDVJ1[5]+VectorPDVJ1[4];
            }

        }




/// FUNCIONES VISUALES

void Intro(){
   for(int i=0;i<2000000000;i++){

    if (i==333333333){
            rlutil::locate(30,10);
    cout << "   UN";
}

if (i==777777777){
          rlutil::locate(30,11);
cout << " GRAN";
}

if (i==1222222222){
        rlutil::locate(30,12);
cout << "CERDO";
}
if(i==1666666666){
   rlutil::cls();
rlutil::locate(35,11);
cout << "OINK!!";
}
if(i==1777777777){

cout << "OINK!!";

}
}
 rlutil::cls();
}


void Creditos(){
    rlutil::cls();
    cout << "Desarrollado por: "<< endl;
    cout << " - Federico Manuel  Merayo Legajo 26319 "<< endl;
    cout << " - Fernando Gabriel Merayo Legajo 26004 "<< endl;
    cout << "Presione cualquier tecla para volver al menu principal" << endl;
      getch();
        rlutil::cls();

}
void Dados(int Dado){
    switch(Dado)
    {

    case 1:
        cout << "    ___________ " << endl;
        cout << "   |           |" << endl;
        cout << "   |           |" << endl;
        cout << "   |     X     |" << endl;
        cout << "   |           |" << endl;
        cout << "   |___________|" << endl;
        cout << endl;
        break;
    case 2:
        cout << "    ___________ " << endl;
        cout << "   |           |" << endl;
        cout << "   |  X        |" << endl;
        cout << "   |           |" << endl;
        cout << "   |        X  |" << endl;
        cout << "   |___________|" << endl;
        cout << endl;
        break;
    case 3:
        cout << "    ___________ " << endl;
        cout << "   |           |" << endl;
        cout << "   |  X        |" << endl;
        cout << "   |     X     |" << endl;
        cout << "   |        X  |" << endl;
        cout << "   |___________|" << endl;
        cout << endl;
        break;
    case 4:
        cout << "    ___________ " << endl;
        cout << "   |           |" << endl;
        cout << "   |  X     X  |" << endl;
        cout << "   |           |" << endl;
        cout << "   |  X     X  |" << endl;
        cout << "   |___________|" << endl;
        cout << endl;
        break;
    case 5:
        cout << "    ___________ " << endl;
        cout << "   |           |" << endl;
        cout << "   |  X     X  |" << endl;
        cout << "   |     X     |" << endl;
        cout << "   |  X     X  |" << endl;
        cout << "   |___________|" << endl;
        cout << endl;
        break;
    case 6:
        cout << "    ___________ " << endl;
        cout << "   |           |" << endl;
        cout << "   |  X     X  |" << endl;
        cout << "   |  X     X  |" << endl;
        cout << "   |  X     X  |" << endl;
        cout << "   |___________|" << endl;
        cout << endl;;
        break;
    }
}
void Lanzamiento (){
for (int i=0;i<100000000;i++){

  if (i==1){
           rlutil::cls();
     rlutil::locate(30,5);
     cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

  }

     if (i==16666666){

        rlutil::cls();
             rlutil::locate(30,5);
                  cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

     }

       if (i==33333333){
        rlutil::cls();
     rlutil::locate(30,5);
          cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |                           |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

              }

  if (i==50000000){

        rlutil::cls();
     rlutil::locate(30,5);
          cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

  }

     if (i==66666666){

        rlutil::cls();
             rlutil::locate(30,5);
                  cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

     }

       if (i==83333333){
        rlutil::cls();
             rlutil::locate(30,5);
                  cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |                           |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

       }

}
for (int i=0;i<100000000;i++){

  if (i==1){
     rlutil::locate(30,5);
     cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

  }

     if (i==16666666){

        rlutil::cls();
             rlutil::locate(30,5);
                  cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

     }

       if (i==33333333){
        rlutil::cls();
     rlutil::locate(30,5);
          cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |                           |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

              }

  if (i==50000000){

        rlutil::cls();
     rlutil::locate(30,5);
          cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |     xxxxx                 |   |                           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                           |   |           xxxxx           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                 xxxxx     |   |                           |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

  }

     if (i==66666666){

        rlutil::cls();
             rlutil::locate(30,5);
                  cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx                  |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |          xxxxx            |   |           xxxxx           |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                   xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;

     }

       if (i==83333333){
        rlutil::cls();
             rlutil::locate(30,5);
                  cout<< endl;
        cout << "                   ___________________________     ___________________________ " << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |                           |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |                           |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |   xxxxx            xxxxx  |" << endl;
        cout << "                  |    xxxxx          xxxxx   |   |                           |" << endl;
        cout << "                  |___________________________|   |___________________________|" << endl;
 rlutil::cls();
       }

}
}


