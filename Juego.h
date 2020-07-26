#ifndef JUEGO_H_
#define JUEGO_H_

#include "Arbol.h"
#include "Tablero.h"

int bestFit(Nodo *raiz, Tablero *tNuevo);
int recorridoAnchoLargo(Nodo *raiz, Tablero *tNuevo, int estrategia);
void jugar(Tablero *tActual, Tablero *tNuevo, int estrategia, int jug2);
void insertarListaAlPpio(Nodo** head, Nodo* n);
void insertarListaAlFinal(Nodo** head, Nodo* n);
void insertarElementoOrdenado(Nodo** head, Nodo* n);
void liberarNodo(Nodo *n);
int tamanioLista(Nodo *nodo);

#endif /* JUEGO_H_ */
