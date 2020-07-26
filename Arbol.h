#include "Tablero.h"
#include "MovsTablero.h"

#ifndef ARBOL_H_
#define ARBOL_H_

//nodo del arbol
typedef struct Nodo {
	Tablero t;
	int peso;
	Pos desde;
	Pos hasta;
	//puntero al nodo hermano
	struct Nodo *sig;
	struct Nodo *nodoHijo;
	int profundidad;
	struct Nodo *nodoRaiz;
	int jug2;
} Nodo;

void evaluarFichaJug2(Tablero *t, int profundidad, Pos desde, Nodo **nodoActual);
void evaluarFichaJug1(Tablero *t, int profundidad, Pos desde, Nodo **nodoActual);
void evaluarDama(Tablero *t, int profundidad, Pos desde, Nodo **nodoActual, int jug2);
void comerEnCascada(Pos *posFinal, Nodo *nuevoNodo, int reina);
Nodo* crearNivel(Tablero *t,int profundidad, int jug2);
Nodo* crearNodo(Nodo *sig, Pos desde, int peso, int profundidad, int jug2);
void mostrarArbol(Nodo *n, int profundidad, char trayectoria[], int valorNodo);

#endif /* ARBOL_H_ */
