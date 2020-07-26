#ifndef FUNCJUGADOR_H_
#define FUNCJUGADOR_H_

#include "Tablero.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array {
  struct Nodo2 *array;
  int used;
  int size;
} Array;

typedef struct Nodo2 {
  int tablero[TAMANIO][TAMANIO];
  int riesgo;
  Array hijos;
} Nodo2;

void initArray(Array *a, int initialSize);
void copiarTableroArbol(Tablero *from, Nodo2 *to);
void copiarArbolTablero(Nodo2 *from, Tablero *to);
void copiarArbolArbol(Nodo2 *from, Nodo2 *to);
void insertArray(Array *a, Nodo2 *element);
void eliminarNodo2(Nodo2 *nodo);
void freeArray(Array *a);
void eliminarNodo2(Nodo2 *nodo);
void concatArray(Array *a, Array *b);
void inicializarArbol(Nodo2 *arbol, Tablero *tablero);
void mostrarTableroNodo2(Nodo2 *t);
Nodo2* crearNodo2();
Array* crearArray(int size);
Tablero* crearTableroVacio();

#endif /* FUNCJUGADOR_H_ */
