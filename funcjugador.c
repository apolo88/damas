#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcjugador.h"

void initArray(Array *a, int initialSize) {
  a->array = NULL;
  a->used = 0;
  a->size = initialSize;
}

Array* crearArray(int size) {
  Array *a = (Array *) malloc(sizeof(Array));
  initArray(a, size);
  return a;
}

Nodo2* crearNodo2() {
  Nodo2 *nodo = (Nodo2 *) malloc(sizeof(Nodo2));
  initArray(&(nodo->hijos), 0);
  //inicializo riesgo en 0;
  nodo->riesgo = 0;
  return nodo;
}

Tablero* crearTableroVacio() {
  int i, j;
  Tablero *t = (Tablero *) malloc(sizeof(Tablero));
  for(i=0; i< TAMANIO; i++){
    for(j=0; j < TAMANIO; j++){
      t->matriz[i][j] = 0;
    }
  }
  return t;
}

void copiarTableroArbol(Tablero *from, Nodo2 *to){
	int fil,col;
	for(fil = 0; fil < TAMANIO; fil++){
		for(col = 0; col < TAMANIO; col++){
			to->tablero[fil][col] = from->matriz[fil][col];
		}
	}
}

void copiarArbolTablero(Nodo2 *from, Tablero *to){
	int fil, col;
	for(fil = 0; fil < TAMANIO; fil++){
		for(col = 0; col < TAMANIO; col++){
			to->matriz[fil][col] = from->tablero[fil][col];
		}
	}
}

void copiarArbolArbol(Nodo2 *from, Nodo2 *to){
	int fil,col;
	for(fil = 0; fil < TAMANIO; fil++){
		for(col = 0; col < TAMANIO; col++){
			to->tablero[fil][col] = from->tablero[fil][col];
		}
	}
}
void insertArray(Array *a, Nodo2 *element) {
  if (a->size == 0) {
    a->size = 1;
    a->array = (Nodo2 *)malloc(sizeof(Nodo2));
  } else if (a->used == a->size) {
    a->size += 1;
    a->array = (Nodo2 *)realloc(a->array, a->size * sizeof(Nodo2));
  }
  a->array[a->used] = *element;
  a->used += 1;
}

void eliminarNodo2(Nodo2 *nodo);

void freeArray(Array *a) {
  int i;
  for (i = 0; i < a->used; i++) {
    eliminarNodo2(&(a->array[i]));
  }
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void eliminarNodo2(Nodo2 *nodo) {
  freeArray(&(nodo->hijos));
}

void freeFirstLevel(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void concatArray(Array *a, Array *b) {
  int i;
  if (b->used == 0) {
    freeArray(b);
    free(b);
    return;
  }
  for (i = 0; i < b->used; i++) {
    insertArray(a, &(b->array[i]));
  }
  freeFirstLevel(b);
  free(b);
}

void inicializarArbol(Nodo2 *arbol, Tablero *tablero) {
  //copio el tablero al nodo;
  copiarTableroArbol(tablero, arbol);
}

//mostrar el tablero de un nodo
void mostrarTableroNodo2(Nodo2 *t){
	int fila,col;
  printf("Estado actual del tablero: \n");
  for(col = 0; col < TAMANIO; col++){
    if (col == 0) {
      printf("-----");
    } else {
      printf("----");
    }
  }
  printf("\n");
	for(fila = 0; fila < TAMANIO; fila++){
		for(col = 0; col < TAMANIO; col++){
      if (col == 0) {
        printf("| %d |",t->tablero[fila][col]);
      } else {
        printf(" %d |",t->tablero[fila][col]);
      }
		}
		printf("\n");
		for(col = 0; col < TAMANIO; col++){
      if (col == 0) {
        printf("-----");
      } else {
        printf("----");
      }
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
