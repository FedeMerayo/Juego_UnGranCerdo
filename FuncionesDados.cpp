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


void Funcion2DJ1(int &AcumgeneralJ1,int &AcumrondaJ1,int &LanzamientosJ1, int &MaxlanzamientosJ1,

                 int &ContoinkJ1,int &Turno,bool &Barro, bool&Porky, int&PorkyJugador, int &Ronda)
{

    srand(time(NULL)); /// INICIALIZACION MOTOR DE RANDOM
    int Dado1=rand()%6+1;
    int Dado2=rand()%6+1;
    Dados(Dado1);
    Dados(Dado2);

    if(Porky==0){

        if(Dado1==Dado2-1||Dado1==Dado2+1){

            cout << "HICISTE UN PORKY!!!"<< endl;
            Porky=1;
            PorkyJugador=1;
                  getch();
    rlutil::cls();

        }



    }


    if(Dado1!=Dado2&&Dado1!=1&&Dado2!=1)
    {
        /// 2 DADOS DIFERENTES Y NINGUN AS SUMA TRUFAS Y OFRECE VOLVER A TIRAR

        AcumrondaJ1+=Dado1+Dado2;

        char Continuar=0;
        while (Continuar!='N'&&Continuar!='S')
        {
            cout << " Sumas " << AcumrondaJ1 << endl;
            cout << " Deseas continuar tirando?(S/N)" ;
            cin >> Continuar;
            Continuar=toupper(Continuar);
            if (Continuar=='N')

                Turno=2;
        }
        rlutil::cls();



    }

    if (Dado1==Dado2&&Dado1!=1)
        /// 2 DADOS IGUALES Y NINGUN AS,UN "OINK", DUPLICA PUNTAJE Y VUELVE A TIRAR AUTOMATICAMENTE
    {

        AcumrondaJ1+=Dado1*4;
        ContoinkJ1++;
        cout << " Hiciste un OINK!!! Tus puntos duplican! --> Volves a tirar. " << endl << endl << endl;
        getch();
        rlutil::cls();
    }

    if (Dado1!=Dado2&&(Dado1==1||Dado2==1))
        /// 1 AS ENTRE CUALQUIERA DE LOS DADOS RESETEA EL PUNTAJE DE LA RONDA A 0 Y CAMBIA EL TURNO
    {

        AcumrondaJ1=0;
        cout << " Salio un AS! Perdes el turno y las trufas acumuladas durante esta ronda! :( " << endl;
        Turno=2;
        getch();
        rlutil::cls();
    }
    if (Dado1==1&&Dado1==Dado2)
        /// 2 ASES "HUNDE EN EL BARRO" PIERDE TURNO, TRUFAS RONDA Y TODAS LAS TRUFAS ACUMULADAS
    {

        AcumrondaJ1=0;
        AcumgeneralJ1=0;
        cout << " Te hundiste en el barro! Perdes todas tus trufas! :(  " << endl;
        Turno=2;
        Barro=1;
        getch();
        rlutil::cls();
    }

    if(Ronda==1)
    {

        MaxlanzamientosJ1=LanzamientosJ1;

    }
    else
    {

        if (LanzamientosJ1>MaxlanzamientosJ1)
        {

            MaxlanzamientosJ1=LanzamientosJ1;
        }
    }

}

void Funcion2DJ2(int &AcumgeneralJ2,int &AcumrondaJ2,int &LanzamientosJ2, int &MaxlanzamientosJ2,

                 int &ContoinkJ2,int &Turno,bool &Barro,bool &Porky,int&PorkyJugador, int &Ronda){




    srand(time(NULL)); /// INICIALIZACION MOTOR DE RANDOM
    int Dado1=rand()%6+1;
    int Dado2=rand()%6+1;
    Dados(Dado1);
    Dados(Dado2);

    if(Porky==0){

        if(Dado1==Dado2-1||Dado1==Dado2+1){

            cout << "HICISTE UN PORKY!!!" << endl;
            Porky=1;
            PorkyJugador=2;

            getch();
    rlutil::cls();

        }



    }



    if(Dado1!=Dado2&&Dado1!=1&&Dado2!=1)
    {
        /// 2 DADOS DIFERENTES Y NINGUN AS SUMA TRUFAS Y OFRECE VOLVER A TIRAR

        AcumrondaJ2+=Dado1+Dado2;

        char Continuar=0;
        while (Continuar!='N'&&Continuar!='S')
        {
            cout << " Sumas " << AcumrondaJ2 << endl;
            cout << " Deseas continuar tirando?(S/N)" ;
            cin >> Continuar;
            Continuar=toupper(Continuar);
            if (Continuar=='N')

                Turno=1;
        }
        rlutil::cls();



    }

    if (Dado1==Dado2&&Dado1!=1)
        /// 2 DADOS IGUALES Y NINGUN AS,UN "OINK", DUPLICA PUNTAJE Y VUELVE A TIRAR AUTOMATICAMENTE
    {

        AcumrondaJ2+=Dado1*4;
        ContoinkJ2++;
        cout << " Hiciste un OINK!!! Tus puntos duplican! --> Volves a tirar. " << endl << endl << endl;
        getch();
        rlutil::cls();
    }

    if (Dado1!=Dado2&&(Dado1==1||Dado2==1))
        /// 1 AS ENTRE CUALQUIERA DE LOS DADOS RESETEA EL PUNTAJE DE LA RONDA A 0 Y CAMBIA EL TURNO
    {

        AcumrondaJ2=0;
        cout << " Salio un AS! Perdes el turno y las trufas acumuladas durante esta ronda! :( " << endl;
        Turno=1;
        getch();
        rlutil::cls();
    }
    if (Dado1==1&&Dado1==Dado2)
        /// 2 ASES "HUNDE EN EL BARRO" PIERDE TURNO, TRUFAS RONDA Y TODAS LAS TRUFAS ACUMULADAS
    {

        AcumrondaJ2=0;
        AcumgeneralJ2=0;
        cout << " Te hundiste en el barro! Perdes todas tus trufas! :(  " << endl;
        Turno=1;
        Barro=1;
        getch();
        rlutil::cls();
    }
    if(Ronda==1)
    {

        MaxlanzamientosJ2=LanzamientosJ2;

    }
    else
    {

        if (LanzamientosJ2>MaxlanzamientosJ2)
        {

            MaxlanzamientosJ2=LanzamientosJ2;
        }
    }

}

void Funcion3DJ1 (int &AcumgeneralJ1,int &AcumrondaJ1,int &AcumgeneralJ2,int &LanzamientosJ1,

                  int &MaxlanzamientosJ1,int &ContoinkJ1,int &Turno, int &Ronda)
{

    int Dado1=rand()%6+1;
    int Dado2=rand()%6+1;
    int Dado3=rand()%6+1;
    Dados(Dado1);
    Dados(Dado2);
    Dados(Dado3);

    if (Dado1==1 && Dado2==1 && Dado3==1) /// SUPERBARRO
    {

        AcumrondaJ1=0;
        AcumgeneralJ2+=AcumgeneralJ1;
        AcumgeneralJ1=0;
        cout << "DOBLE BARRO TUS TRUFAS VAN AL JUGADOR 1  " << endl;
        Turno=2;
        getch();
        rlutil::cls();

    }

    else
    {
        if (Dado1 == Dado2 && Dado2 == Dado3) ///OINK
        {

            AcumrondaJ1+=Dado1*6;
            ContoinkJ1++;
            cout << " Hiciste un OINK!!! Tus puntos duplican! --> Volves a tirar" << endl << endl << endl;
            getch();
            rlutil::cls();
        }
        else
        {
            if (Dado1 !=1 && Dado2 !=1 && Dado3 !=1) /// SUMAS ! Volver a tirar?
            {
                AcumrondaJ1+=Dado1+Dado2+Dado3;
                char Continuar=0;
                while (Continuar!='N'&&Continuar!='S')
                {
                    cout << " Sumas " << AcumrondaJ1 << endl;
                    cout << " Deseas continuar tirando?(S/N)" ;
                    cin >> Continuar;
                    Continuar=toupper(Continuar);
                    if (Continuar=='N')

                        Turno=2;
                }
                rlutil::cls();

            }
            else
            {
                if ((Dado1 == 1 && Dado2 ==1) || (Dado1 ==1 && Dado3 ==1) || (Dado2 ==1 && Dado3 ==1) ) /// BARRO
                {
                    AcumrondaJ1=0;
                    AcumgeneralJ1=0;
                    cout << " Te hundiste en el barro! Perdes todas tus trufas! :(  " << endl;
                    Turno=2;

                    getch();
                    rlutil::cls();

                }
                else /// Pierde trufas y turno
                {

                    AcumrondaJ1=0;
                    cout << " Salio un AS! Perdes el turno y las trufas acumuladas durante esta ronda! :( " << endl;
                    Turno=2;
                    getch();
                    rlutil::cls();
                }
            }
        }
    }


    if(Ronda==1)
    {

        MaxlanzamientosJ1=LanzamientosJ1;

    }
    else
    {

        if (LanzamientosJ1>MaxlanzamientosJ1)
        {

            MaxlanzamientosJ1=LanzamientosJ1;
        }
    }

}

void Funcion3DJ2 (int &AcumgeneralJ2,int &AcumrondaJ2,int &AcumgeneralJ1,int &LanzamientosJ2,

                  int &MaxlanzamientosJ2,int &ContoinkJ2,int &Turno, int &Ronda)
{

    int Dado1=rand()%6+1;
    int Dado2=rand()%6+1;
    int Dado3=rand()%6+1;
    Dados(Dado1);
    Dados(Dado2);
    Dados(Dado3);

    if (Dado1==1 && Dado2==1 && Dado3==1) /// DOBLEBARRO
    {


        AcumrondaJ2=0;
        AcumgeneralJ1+=AcumgeneralJ2;
        AcumgeneralJ2=0;
        cout << "DOBLE BARRO TUS TRUFAS VAN AL JUGADOR 1  " << endl;
        Turno=1;
        getch();
        rlutil::cls();

    }

    else
    {
        if (Dado1 == Dado2 && Dado2 == Dado3) ///OINK
        {

            AcumrondaJ2+=Dado1*6;
            ContoinkJ2++;
            cout << " Hiciste un OINK!!! Tus puntos duplican! --> Volves a tirar." << endl << endl << endl;
            getch();
            rlutil::cls();
        }
        else
        {
            if (Dado1 !=1 && Dado2 !=1 && Dado3 !=1) /// SUMAS ! Volver a tirar?
            {
                AcumrondaJ2+=Dado1+Dado2+Dado3;
                char Continuar=0;
                while (Continuar!='N'&&Continuar!='S')
                {
                    cout << " Sumas " << AcumrondaJ2 << endl;
                    cout << " Deseas continuar tirando?(S/N)" ;
                    cin >> Continuar;
                    Continuar=toupper(Continuar);
                    if (Continuar=='N')

                        Turno=1;
                }
                rlutil::cls();

            }
            else
            {
                if ((Dado1 == 1 && Dado2 ==1) || (Dado1 ==1 && Dado3 ==1) || (Dado2 ==1 && Dado3 ==1) ) /// BARRO
                {
                    AcumrondaJ2=0;
                    AcumgeneralJ2=0;
                    cout << " Te hundiste en el barro! Perdes todas tus trufas! :(  " << endl;
                    Turno=1;

                    getch();
                    rlutil::cls();


                }
                else /// Pierde trufas y turno
                {

                    AcumrondaJ2=0;
                    cout << " Salio un AS! Perdes el turno y las trufas acumuladas durante esta ronda! :( " << endl;
                    Turno=1;
                    getch();
                    rlutil::cls();
                }
            }
        }
    }

    if(Ronda==1)
    {

        MaxlanzamientosJ2=LanzamientosJ2;

    }
    else
    {

        if (LanzamientosJ2>MaxlanzamientosJ2)
        {

            MaxlanzamientosJ2=LanzamientosJ2;
        }
    }



}
