/*
 * MovsTablero.h
 *
 *  Created on: 05/04/2014
 *      Author: Alejandro
 */

#ifndef MOVSTABLERO_H_
#define MOVSTABLERO_H_

#include "Tablero.h"

typedef struct posicion{
	int x;
	int y;
}Pos;

//PUEDE MOVER
int puedeMoverIzAb (Tablero *t, Pos p);
int puedeMoverDerAb (Tablero *t, Pos p);
int puedeMoverIzAr(Tablero *t, Pos p);
int puedeMoverDerAr(Tablero *t, Pos p);
//MOVER
int moverIzAb(Tablero *t,Pos p);
int moverDerAb(Tablero *t,Pos p);
int moverIzAr(Tablero *t, Pos p);
int moverDerAr(Tablero *t, Pos p);
//PUEDE COMER
int puedeComerIzAb(Tablero *t, Pos p);
int puedeComerDerAb(Tablero *t, Pos p);
int puedeComerIzAr(Tablero *t, Pos p);
int puedeComerDerAr(Tablero *t, Pos p);
//COMER
Pos comerIzAb(Tablero *t, Pos p);
Pos comerDerAb(Tablero *t, Pos p);
Pos comerIzAr(Tablero *t, Pos p);
Pos comerDerAr(Tablero *t, Pos p);

////////////
//REINAS
////////////

//PUEDE MOVER REINA
int puedeMovReinaDeAr (Tablero *t, Pos p);
int puedeMovReinaDeAb (Tablero *t, Pos p);
int puedeMovReinaIzAr (Tablero *t, Pos p);
int puedeMovReinaIzAb (Tablero *t, Pos p);
//MOVER REINA
void movReinaDeAr (Tablero *t, Pos p, int c);
void movReinaDeAb (Tablero *t, Pos p, int c);
void movReinaIzAr (Tablero *t, Pos p, int c);
void movReinaIzAb (Tablero *t, Pos p, int c);
//PUEDE COMER REINA
int puedeComerReinaDeAr (Tablero *t, Pos p, int reina);
int puedeComerReinaDeAb (Tablero *t, Pos p, int reina);
int puedeComerReinaIzAr (Tablero *t, Pos p, int reina);
int puedeComerReinaIzAb (Tablero *t, Pos p, int reina);
//COMER REINA
Pos comerReinaDeAr (Tablero *t, Pos p, int posOpuesto);
Pos comerReinaDeAb (Tablero *t, Pos p, int posOpuesto);
Pos comerReinaIzAr (Tablero *t, Pos p, int posOpuesto);
Pos comerReinaIzAb (Tablero *t, Pos p, int posOpuesto);

#endif /* MOVSTABLERO_H_ */
