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

int main()
{
/// DECLARACION DE VARIABLES
    string Jugador1, Jugador2, NombreTop1,NombreTop2;
    int   OMP=0;///OPCION MENU PRINCIPAL
    int Top1=0,Top2=0; /// TOP 1 Y 2 DE ESTADISTICAS

    Intro(); /// FUNCION CON UNA INTRO


    while (OMP!=4) /// FUNCION MENU PRINCIPAL - PASAJE DE PARAMETROS POR VALOR /// MIENTRAS LA OPCION NO SEA 4 EL JUEGO NO SE CIERRA
    {

        OMP=Menuprincipal(OMP);

        switch (OMP)
        {
        case 1:/// JUGAR
            rlutil::cls();
            Ingresonombres(Jugador1,Jugador2);     /// FUNCION INGRESO DE LOS NOMBRES

            rlutil::cls();

            break;
        case 2: /// ESTADISTICAS
            rlutil::cls();
            cout << endl << endl <<endl << endl;
            cout << "       --------------------------------------------------------------------------------------------" << endl;
            cout << "                  EL CERDO MAS ANGURRIENTO ES: " << NombreTop1 << " CON " <<Top1 << " PUNTOS DE VICTORIA" << endl;
            cout << "                               LO SIGUE: " << NombreTop2 << " CON " <<Top2 << " PUNTOS DE VICTORIA"<< endl;
            cout << "       --------------------------------------------------------------------------------------------" << endl;
            getch();
            rlutil::cls();
            break;
        case 3: /// FUNCION CREDITOS

            Creditos ();
            break;
        case 4: /// SALIR
            rlutil::cls();
            cout << endl;
            cout << "VUELVE POR MAS CERDO CODICIOSO!" << endl;
            cout << endl;
            cout << endl;
            return 0;
        }


/// JUEGO
        if (OMP==1)
        {

            Turnos (Jugador1,Jugador2);///FUNCION DETERMINA QUIEN ARRANCA


            /// VARIABLES DEL JUEGO
            int AcumrondaJ1=0,AcumrondaJ2=0, AcumgeneralJ1=0,AcumgeneralJ2=0,ContoinkJ1=0,ContoinkJ2=0;
            int Ronda=1,Turno=1;
            bool Barro=0, Porky=0;
            int LanzamientosJ2,LanzamientosJ1,MaxlanzamientosJ1,MaxlanzamientosJ2,PorkyJugador=0;

            while(Ronda!=6)
            {
                AcumrondaJ1=0; /// RESETEO
                AcumrondaJ2=0;/// RESETEO
                LanzamientosJ1=0;/// RESETEO



                while(Turno==1)  /// TURNO JUGADOR 1
                {

                    cout << "                                    ....UN...GRAN...CERDO!!!       " << endl;
                    cout <<" ----------------------------------------------------------------------------------------------------------------"<< endl;
                    cout <<" RONDA #" << Ronda << endl;
                    cout << " " << Jugador1 << ": " << AcumgeneralJ1 << " TRUFAS ACUMULADAS          " << Jugador2 << ": " << AcumgeneralJ2 << " TRUFAS ACUMULADAS          "<<endl;
                    cout << " TURNO DE: " << Jugador1 << endl;
                    cout << " LANZAMIENTOS EN ESTA RONDA: "<< LanzamientosJ1 << endl;
                    cout << " TRUFAS ACUMULADAS EN ESTA RONDA: " << AcumrondaJ1 << endl << endl<< endl << endl<< endl << endl;
                    cout << " Presiona una tecla cualquiera para lanzar los dados!" ;


                    getch();
                    Lanzamiento(); /// LANZAMIENTO DE DADOS // FUNCION VISUAL
                    LanzamientosJ1++;
                    cout << "                                    ....UN...GRAN...CERDO!!!       " << endl;
                    cout <<" ----------------------------------------------------------------------------------------------------------------"<< endl;
                    cout <<" RONDA #" << Ronda << endl;
                    cout << " "<< Jugador1 << ": " << AcumgeneralJ1 << " TRUFAS ACUMULADAS          " << Jugador2 << ": " << AcumgeneralJ2 << " TRUFAS ACUMULADAS          "<<endl;
                    cout << " TURNO DE: " << Jugador1 << endl;
                    cout << " LANZAMIENTOS EN ESTA RONDA: "<< LanzamientosJ1 << endl;
                    cout << " TRUFAS ACUMULADAS EN ESTA RONDA: " << AcumrondaJ1 << endl << endl;


                    if (Barro==0)
                    {
                        Funcion2DJ1(AcumgeneralJ1,AcumrondaJ1, LanzamientosJ1,

                                    MaxlanzamientosJ1, ContoinkJ1, Turno, Barro,Porky,PorkyJugador, Ronda); /// FUNCION 2 DADOS
                    }
                    else
                    {

                        Funcion3DJ1(AcumgeneralJ1,AcumrondaJ1,AcumgeneralJ2,

                                    LanzamientosJ1, MaxlanzamientosJ1, ContoinkJ1, Turno, Ronda); /// FUNCION 3 DADOS
                    }

                }

                AcumgeneralJ1+=AcumrondaJ1;
                if(AcumgeneralJ1>50&&AcumgeneralJ2>50)
                {

                    Barro=1; /// ACTIVADOR DE 3 DADOS POR PUNTAJE
                }

                ///TERMINA TURNO JUGADOR 1

                /// TURNO JUGADOR 2
                LanzamientosJ2=0; /// RESETEO

                while(Turno==2)
                {


                    cout << "                                    ....UN...GRAN...CERDO!!!       " << endl;
                    cout <<" ----------------------------------------------------------------------------------------------------------------"<< endl;
                    cout <<" RONDA #" << Ronda << endl;
                    cout <<" " <<Jugador1 << ": " << AcumgeneralJ1 << " TRUFAS ACUMULADAS          " << Jugador2 << ": " << AcumgeneralJ2 << " TRUFAS ACUMULADAS          "<<endl;
                    cout << " TURNO DE: " << Jugador2 << endl;
                    cout << " LANZAMIENTOS EN ESTA RONDA: "<< LanzamientosJ2 << endl;
                    cout << " TRUFAS ACUMULADAS EN ESTA RONDA: " << AcumrondaJ2 << endl << endl<< endl << endl<< endl << endl;
                    cout << " Presiona una tecla cualquiera para lanzar los dados!" ;

                    getch();
                    Lanzamiento();/// LANZAMIENTO DE DADOS // FUNCION VISUAL
                    LanzamientosJ2++;


                    cout << "                                    ....UN...GRAN...CERDO!!!       " << endl;
                    cout <<" ----------------------------------------------------------------------------------------------------------------"<< endl;
                    cout <<" RONDA #" << Ronda << endl;
                    cout << " " <<Jugador1 << ": " << AcumgeneralJ1 << " TRUFAS ACUMULADAS          " << Jugador2 << ": " << AcumgeneralJ2 << " TRUFAS ACUMULADAS          "<<endl;
                    cout << " TURNO DE: " << Jugador2 << endl;
                    cout << " LANZAMIENTOS EN ESTA RONDA: "<< LanzamientosJ2 << endl;
                    cout << " TRUFAS ACUMULADAS EN ESTA RONDA: " << AcumrondaJ2 << endl << endl;


                    /// 2 O 3 DADOS
                    if (Barro==0)
                    {

                        Funcion2DJ2(AcumgeneralJ2,AcumrondaJ2, LanzamientosJ2,

                                    MaxlanzamientosJ2, ContoinkJ2, Turno, Barro,Porky,PorkyJugador, Ronda); /// FUNCION 2 DADOS

                    }
                    else
                    {

                        Funcion3DJ2(AcumgeneralJ2,AcumrondaJ2,AcumgeneralJ1,

                                    LanzamientosJ2, MaxlanzamientosJ2, ContoinkJ1, Turno, Ronda);/// FUNCION 3 DADOS
                    }
                }
                AcumgeneralJ2+=AcumrondaJ2;

                /// ACTIVADOR DE 3 DADOS POR PUNTAJE
                if(AcumgeneralJ1>50&&AcumgeneralJ2>50)
                {

                    Barro=1;
                }
                ///TERMINA TURNO JUGADOR 2
                Ronda++;
            }

            /// TERMINO LA PARTIDA


            /// FUNCION DE CALCULO DE PUNTAJES

            int VectorPDVJ1[6] {},VectorPDV     J2[6] {};

            Calculopuntajes(VectorPDVJ1, AcumgeneralJ1,AcumgeneralJ2,
                            ContoinkJ1,ContoinkJ2, MaxlanzamientosJ1,MaxlanzamientosJ2,PorkyJugador); /// FUNCION DE CALCULO DE PUNTAJES

            cout << "                                    ....UN...GRAN...CERDO!!!       " << endl;
            cout <<"----------------------------------------------------------------------------------------------------------------"<< endl<< endl;
            cout <<"HITO                              "<< Jugador1 << "                             " << Jugador2 << endl;
            cout <<"----------------------------------------------------------------------------------------------------------------"<< endl;
            cout <<"Mas trufas en total               "<<VectorPDVJ1[0]<<"PDV"<< "("<<AcumgeneralJ1<<" trufas)                 "<<VectorPDVJ2[0]<<"PDV"<< "("<<AcumgeneralJ2<<" trufas)"<< endl;
            cout <<"Cada 50 trufas                    "<<VectorPDVJ1[1]<<"PDV"<< "("<<VectorPDVJ1[1]*50 <<" trufas)                 "<<VectorPDVJ2[1]<<"PDV"<< "("<<VectorPDVJ2[1]*50 <<" trufas)"<<endl;
            cout <<"Oinks                             "<<VectorPDVJ1[2]<<"PDV"<< "("<<ContoinkJ1<< " Oinks)                  "<<VectorPDVJ2[2]<<"PDV"<< "("<<ContoinkJ2<< " Oinks)"<<endl;
            cout <<"Cerdo codicioso                   "<<VectorPDVJ1[3]<<"PDV"<< "("<<MaxlanzamientosJ1<< " lanzamientos)           "<<VectorPDVJ2[3]<<"PDV"<< "("<<MaxlanzamientosJ2<< " lanzamientos) "<<endl;
            cout <<"Porky                               "<<VectorPDVJ1[4]<<"PDV                                          "<< VectorPDVJ2[4]<<               "PDV" <<endl;
            cout <<"----------------------------------------------------------------------------------------------------------------"<< endl;
            cout <<"TOTAL                             "<<VectorPDVJ1[5]<<"PDV                            "<< VectorPDVJ2[5] << "PDV "<< endl;
            cout<< endl;





            /// DECLARAR UN GANADOR O EMPATE
            if (VectorPDVJ1[5]>VectorPDVJ2[5])
            {
                cout <<"GANADOR: "<< Jugador1 << " con ";
                cout << VectorPDVJ1[4] << " Puntos de Victoria. ";

            }
            else
            {
                if (VectorPDVJ1[5]<VectorPDVJ2[5])
                {
                    cout <<"GANADOR: "<< Jugador2 ;
                    cout << " con " << VectorPDVJ2[5] << " Puntos de Victoria. ";


                }
                else
                {

                    cout << "EMPATE! CON " << VectorPDVJ1[5] << " Puntos de Victoria. ";
                }


            }
            /// REGISTRO DE TOP 1 Y TOP 2 DE ESTADISTICAS
            if(VectorPDVJ1[5]>=Top1)
            {
                Top2=Top1;
                NombreTop2=NombreTop1;
                Top1=VectorPDVJ1[5];
                NombreTop1=Jugador1;

            }
            else
            {
                if(Top2<VectorPDVJ1[5])
                {
                    Top2=VectorPDVJ1[5];
                    NombreTop2=Jugador1;
                }
            }
            if(VectorPDVJ2[5]>=Top1)
            {
                Top2=Top1;
                NombreTop2=NombreTop1;
                Top1=VectorPDVJ2[5];
                NombreTop1=Jugador2;

            }
            else
            {
                if(VectorPDVJ2[5]>=Top2)
                {
                    Top2=VectorPDVJ2[5];
                    NombreTop2=Jugador2;
                }

            }
            OMP=0;
            cout<< endl << endl;
            cout<< "Presiona cualquier tecla para volver al menu principal" << endl;
            getch();
            rlutil::cls();



        }
    }
    return 0;
}







