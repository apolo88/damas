#include "Arbol.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PAD_BYTES 8

#define PESOMOVFICHA 2
#define PESOCOMFICHA 4
#define PESOCOMFICHACASC 6
#define PESOMOVREINA 1
#define PESOCOMREINA 8
#define PESOCOMREINACASC 12


void evaluarFichaJug2(Tablero *t, int profundidad, Pos desde, Nodo **nodoActual){
	Pos hasta;
	Nodo *nuevoNodo;
	int movAReina;

	//verifico que la ficha pueda avanzar hacia adelante y hacer algun movimiento
	if(puedeMoverIzAb(t, desde)){
		hasta.x = desde.x-1;
		hasta.y = desde.y-1;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVFICHA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		movAReina = moverIzAb(&nuevoNodo->t,desde);
		if(movAReina)
			nuevoNodo->peso += PESOCOMFICHA;
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}
	if(puedeMoverDerAb(t, desde)){
		hasta.x = desde.x-1;
		hasta.y = desde.y+1;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVFICHA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		movAReina = moverDerAb(&nuevoNodo->t,desde);
		if(movAReina)
			nuevoNodo->peso += PESOCOMFICHA;
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}
	if(puedeComerIzAb(t, desde)){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMFICHA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerIzAb(&nuevoNodo->t,desde);

		//verifica si puede seguir comiendo
		while(puedeComerIzAb(&nuevoNodo->t,posFinal) || puedeComerDerAb(&nuevoNodo->t,posFinal)){
			if(puedeComerIzAb(&nuevoNodo->t,posFinal))
				posFinal = comerIzAb(&nuevoNodo->t,posFinal);
			else
				posFinal = comerDerAb(&nuevoNodo->t,posFinal);
			nuevoNodo->peso += PESOCOMFICHACASC;
		}
		nuevoNodo->hasta = posFinal;
		if(posFinal.x == 0)
			nuevoNodo->peso += PESOCOMFICHA;
		*nodoActual = nuevoNodo;
	}
	if(puedeComerDerAb(t, desde)){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMFICHA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerDerAb(&nuevoNodo->t,desde);

		//verifica si puede seguir comiendo
		while(puedeComerIzAb(&nuevoNodo->t,posFinal) || puedeComerDerAb(&nuevoNodo->t,posFinal)){
			if(puedeComerIzAb(&nuevoNodo->t,posFinal))
				posFinal = comerIzAb(&nuevoNodo->t,posFinal);
			else
				posFinal = comerDerAb(&nuevoNodo->t,posFinal);
			nuevoNodo->peso += PESOCOMFICHACASC;
		}
		nuevoNodo->hasta = posFinal;
		if(posFinal.x == 0)
			nuevoNodo->peso += PESOCOMFICHA;
		*nodoActual = nuevoNodo;
	}
}

void evaluarFichaJug1(Tablero *t, int profundidad, Pos desde, Nodo **nodoActual){
	Pos hasta;
	Nodo *nuevoNodo;
	int movAReina;

	//verifico que la ficha pueda avanzar hacia adelante y hacer algun movimiento
	if(puedeMoverIzAr(t, desde)){
		hasta.x = desde.x+1;
		hasta.y = desde.y-1;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVFICHA, profundidad, 0);
		copiarTablero(t,&nuevoNodo->t);
		movAReina = moverIzAr(&nuevoNodo->t,desde);
		if(movAReina)
			nuevoNodo->peso += PESOCOMFICHA;
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}
	if(puedeMoverDerAr(t, desde)){
		hasta.x = desde.x+1;
		hasta.y = desde.y+1;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVFICHA, profundidad, 0);
		copiarTablero(t,&nuevoNodo->t);
		movAReina = moverDerAr(&nuevoNodo->t,desde);
		if(movAReina)
			nuevoNodo->peso += PESOCOMFICHA;
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}
	if(puedeComerIzAr(t, desde)){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMFICHA, profundidad, 0);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerIzAr(&nuevoNodo->t,desde);

		//verifica si puede seguir comiendo
		while(puedeComerIzAr(&nuevoNodo->t,posFinal) || puedeComerDerAr(&nuevoNodo->t,posFinal)){
			if(puedeComerIzAr(&nuevoNodo->t,posFinal))
				posFinal = comerIzAr(&nuevoNodo->t,posFinal);
			else
				posFinal = comerDerAr(&nuevoNodo->t,posFinal);
			nuevoNodo->peso += PESOCOMFICHACASC;
		}
		nuevoNodo->hasta = posFinal;
		if(posFinal.x == 9)
			nuevoNodo->peso += PESOCOMFICHA;
		*nodoActual = nuevoNodo;
	}
	if(puedeComerDerAr(t, desde)){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMFICHA, profundidad, 0);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerDerAr(&nuevoNodo->t,desde);

		//verifica si puede seguir comiendo
		while(puedeComerIzAr(&nuevoNodo->t,posFinal) || puedeComerDerAr(&nuevoNodo->t,posFinal)){
			if(puedeComerIzAr(&nuevoNodo->t,posFinal))
				posFinal = comerIzAr(&nuevoNodo->t,posFinal);
			else
				posFinal = comerDerAr(&nuevoNodo->t,posFinal);
			nuevoNodo->peso += PESOCOMFICHACASC;
		}
		nuevoNodo->hasta = posFinal;
		if(posFinal.x == 9)
			nuevoNodo->peso += PESOCOMFICHA;
		*nodoActual = nuevoNodo;
	}
}

void evaluarDama(Tablero *t, int profundidad, Pos desde, Nodo **nodoActual, int jug2){
	Pos hasta;
	Nodo *nuevoNodo;
	int movPosible,i;
	int reina = jug2 ? 5 : 3;
	movPosible = puedeMovReinaDeAr (t, desde);
	for(i = 1; i <= movPosible; i++){
		hasta.x = desde.x+i;
		hasta.y = desde.y+i;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVREINA, profundidad, jug2);
		copiarTablero(t,&nuevoNodo->t);
		movReinaDeAr (&nuevoNodo->t, desde, i);
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}

	movPosible = puedeMovReinaDeAb (t, desde);
	for(i = 1; i <= movPosible; i++){
		hasta.x = desde.x-i;
		hasta.y = desde.y+i;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVREINA, profundidad, jug2);
		copiarTablero(t,&nuevoNodo->t);
		movReinaDeAb (&nuevoNodo->t, desde, i);
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}

	movPosible = puedeMovReinaIzAr (t, desde);
	for(i = 1; i <= movPosible; i++){
		hasta.x = desde.x+i;
		hasta.y = desde.y-i;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVREINA, profundidad, jug2);
		copiarTablero(t,&nuevoNodo->t);
		movReinaIzAr (&nuevoNodo->t, desde, i);
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}

	movPosible = puedeMovReinaIzAb (t, desde);
	for(i = 1; i <= movPosible; i++){
		hasta.x = desde.x-i;
		hasta.y = desde.y-i;
		nuevoNodo = crearNodo(*nodoActual, desde, PESOMOVREINA, profundidad, jug2);
		copiarTablero(t,&nuevoNodo->t);
		movReinaIzAb (&nuevoNodo->t, desde, i);
		nuevoNodo->hasta = hasta;
		*nodoActual = nuevoNodo;
	}

	//funciones comer
	movPosible = puedeComerReinaDeAr (t, desde, reina);
	if(movPosible > 0){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMREINA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerReinaDeAr (&nuevoNodo->t, desde, movPosible);
		comerEnCascada(&posFinal, nuevoNodo, reina);
		nuevoNodo->hasta = posFinal;
		*nodoActual = nuevoNodo;
	}

	movPosible = puedeComerReinaDeAb (t, desde, reina);
	if(movPosible > 0){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMREINA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerReinaDeAb (&nuevoNodo->t, desde, movPosible);
		comerEnCascada(&posFinal, nuevoNodo, reina);
		nuevoNodo->hasta = posFinal;
		*nodoActual = nuevoNodo;
	}

	movPosible = puedeComerReinaIzAr (t, desde, reina);
	if(movPosible > 0){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMREINA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerReinaIzAr (&nuevoNodo->t, desde, movPosible);
		comerEnCascada(&posFinal, nuevoNodo, reina);
		nuevoNodo->hasta = posFinal;
		*nodoActual = nuevoNodo;
	}

	movPosible = puedeComerReinaIzAb (t, desde, reina);
	if(movPosible > 0){
		nuevoNodo = crearNodo(*nodoActual, desde, PESOCOMREINA, profundidad, 1);
		copiarTablero(t,&nuevoNodo->t);
		Pos posFinal = comerReinaIzAb (&nuevoNodo->t, desde, movPosible);
		comerEnCascada(&posFinal, nuevoNodo, reina);
		nuevoNodo->hasta = posFinal;
		*nodoActual = nuevoNodo;
	}
}

void comerEnCascada(Pos *posFinal, Nodo *nuevoNodo, int reina){
	int movPosible;
	//verifica si puede seguir comiendo
	while(puedeComerReinaDeAr (&nuevoNodo->t, *posFinal, reina) > 0 || puedeComerReinaDeAb (&nuevoNodo->t, *posFinal, reina) > 0 || puedeComerReinaIzAr (&nuevoNodo->t, *posFinal, reina) > 0 || puedeComerReinaIzAb (&nuevoNodo->t, *posFinal, reina) > 0){

		if(puedeComerReinaDeAr (&nuevoNodo->t, *posFinal, reina) > 0){
			movPosible = puedeComerReinaDeAr (&nuevoNodo->t, *posFinal, reina);
			*posFinal = comerReinaDeAr (&nuevoNodo->t, *posFinal, movPosible);
		}else if(puedeComerReinaDeAb (&nuevoNodo->t, *posFinal, reina) > 0){
			movPosible = puedeComerReinaDeAb (&nuevoNodo->t, *posFinal, reina);
			*posFinal = comerReinaDeAb (&nuevoNodo->t, *posFinal, movPosible);
		}else if(puedeComerReinaIzAr (&nuevoNodo->t, *posFinal, reina) > 0){
			movPosible = puedeComerReinaIzAr (&nuevoNodo->t, *posFinal, reina);
			*posFinal = comerReinaIzAr (&nuevoNodo->t, *posFinal, movPosible);
		}else if(puedeComerReinaIzAb (&nuevoNodo->t, *posFinal, reina) > 0){
			movPosible = puedeComerReinaIzAb (&nuevoNodo->t, *posFinal, reina);
			*posFinal = comerReinaIzAb (&nuevoNodo->t, *posFinal, movPosible);
		}
		nuevoNodo->peso += PESOCOMREINACASC;
	}
}

Nodo* crearNivel(Tablero *t,int profundidad, int jug2){
	Pos desde;
	Nodo *nodoActual;
	nodoActual = NULL;

	int fil,col, movAReina;
	//loopeo cada fila
	for(fil = 0; fil < 10 ; fil++){
		//cada columna
		for(col = 0; col < 10; col++){
			desde.x = fil;
			desde.y = col;
			if(jug2){
				if(t->matriz[fil][col] == 4){
					evaluarFichaJug2(t, profundidad, desde, &nodoActual);
				}else if(t->matriz[fil][col] == 5){
					evaluarDama(t, profundidad, desde, &nodoActual, 1);
				}
			}else{
				if(t->matriz[fil][col] == 2){
					evaluarFichaJug1(t, profundidad, desde, &nodoActual);
				}else if(t->matriz[fil][col] == 3){
					evaluarDama(t, profundidad, desde, &nodoActual, 0);
				}
			}
		}
	}

	return nodoActual;
}

Nodo* crearNodo(Nodo *sig, Pos desde, int peso, int profundidad, int jug2){
	Nodo* nuevoNodo = (struct Nodo *) malloc (sizeof(struct Nodo) + PAD_BYTES);
	nuevoNodo->sig = sig;
	nuevoNodo->nodoHijo = NULL;
	nuevoNodo->nodoRaiz = NULL;
	nuevoNodo->peso = peso;
	nuevoNodo->desde = desde;
	nuevoNodo->profundidad = profundidad;
	nuevoNodo->jug2 = jug2;
	return nuevoNodo;
}

void mostrarArbol(Nodo *n, int profundidad, char trayectoria[], int valorNodo){
	printf("numero de nodo: %d, ", valorNodo);
	printf("trayectoria: %s, ", trayectoria);
	printf("profundidad: %d, ", profundidad);
	printf("peso nodo: %d, ", n->peso);
	printf("\n");

	char out[20] = "";
	char buffer[4];
	strcat (out,trayectoria);
	strcat (out,"-");
	sprintf(buffer, "%d", valorNodo);
	strcat (out,buffer);

	profundidad++;
	int nuevoValorNodo = 0;
	Nodo *nActual = n->nodoHijo;
	while(nActual != NULL){
		nuevoValorNodo++;
		mostrarArbol(nActual, profundidad, out, nuevoValorNodo);
		nActual = nActual->sig;
	}
}
