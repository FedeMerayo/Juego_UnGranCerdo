#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cctype>
#include <stdlib.h>
#include "rlutil.h"

using namespace std;



/// FUNCIONES DE JUEGO Y DADOS

void Funcion2DJ1(int &AcumgeneralJ1,int &AcumrondaJ1,int &LanzamientosJ1, int
                &Maxlanzamientos,int &ContoinkJ1,int &Turno,bool &Barro,bool &Porky,int&PorkyJugador, int &Ronda);

void Funcion2DJ2(int &AcumgeneralJ2,int &AcumrondaJ2,int &LanzamientosJ2,int
                  &MaxlanzamientosJ2, int &ContoinkJ2,int &Turno,bool &Barro,bool &Porky,int&PorkyJugador,int &Ronda);

void Funcion3DJ1 (int &AcumgeneralJ1,int &AcumrondaJ1, int &AcumgeneralJ2,
                  int &LanzamientosJ1, int &MaxlanzamientosJ1,int &ContoinkJ1,int &Turno, int &Ronda);

void Funcion3DJ2 (int &AcumgeneralJ2,int &AcumrondaJ2, int &AcumgeneralJ1,
                  int &LanzamientosJ2, int &MaxlanzamientosJ2,int &ContoinkJ2,int &Turno, int &Ronda);


/// FUNCIONES INTEGRADORAS

int Menuprincipal (int OMP);

void Ingresonombres (string &Jugador1, string &Jugador2);

void Turnos (string &Jugador1,string &Jugador2);

void Calculopuntajes (int VectorPDVJ1[5],int VectorPDVJ2[5],int &AcumgeneralJ1, int&AcumgeneralJ2,
                      int &Contoink1,int &Contoink2,int &MaxlanzamientosJ1, int &MaxlanzamientosJ2,int &PorkyJugador );


/// FUNCIONES VISUALES
void Intro();
void Lanzamiento ();
void Creditos ();
void Dados (int Dado);


#endif // FUNCIONES_H_INCLUDED
