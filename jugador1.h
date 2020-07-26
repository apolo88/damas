#include "Tablero.h"
#include <stdlib.h>
#include <stdbool.h>
#include "funcjugador.h"

#ifndef JUGADOR1_H_
#define JUGADOR1_H_

int filaAvance(int j);
int filaObjetivo(int j);
int peon(int j);
int dama(int j);
int dOponente(int j);
int pOponente(int j);
int jOponente(int j);
bool casilleroVacio(Nodo2 *n, int i, int j);
void convertirADama(Nodo2 * nodo, int i, int j);
bool estoyEnBorde(int i, int j);
bool dimensionesValidas (int num);
int fichaEnCasillero(Nodo2 *n, int i, int j);
bool fichaOponente(Nodo2 *n, int i, int j, int jug);
bool fichaAliada(Nodo2 *n, int i, int j, int jug);
int asignarRiesgoSiPuedoComer(Nodo2 * n, int i,int j, int jug);
bool damaMePuedeComer(Nodo2 *n, int i, int j, int jug);
int evaluarRiesgo(Nodo2 *t, int i, int j, int jug);
int evaluarRiesgoInicial(Nodo2 *t, int i, int j, int jug);
Array * recursionComiendoDama(Nodo2 *t, int jugador, int dir, int i, int j);
Array * agregarMovimientosDama(Nodo2 *n, int i, int j, int jug);
Array* recursionComiendo(Nodo2 *t, int jugador, int i, int j);
Array* arbolMovimientos(Tablero *t, int jugador, int i, int j);
int mejorCamino(Nodo2 *n, int nivel);
Nodo2* mejorMovimiento(Array *a);
Array* generarMovimientos(Nodo2 *n, int jugador, int nivel);
Tablero* elegirMovimiento(Tablero *t, int jugador);
void jugar1(Tablero *t, Tablero *tj);
void jugar2(Tablero *t, Tablero *tj);

#endif /* JUGADOR1_H_ */
