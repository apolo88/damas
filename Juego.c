#include "Juego.h"
#include "MovsTablero.h"
#include <stdlib.h>
#include <stdio.h>

#define PROFUNDIDAD 2

int bestFit(Nodo *raiz, Tablero *tNuevo){
	int nodosProcesados = 0;
	Nodo *listaAbierta = NULL, *listaCerrada = NULL, *iterador = raiz->nodoHijo;
	Tablero *tPadre = &raiz->t;

	insertarListaAlPpio(&listaCerrada,raiz);
	nodosProcesados++;

	/*printf("abierta:\n");
	//printf("peso elegido: %d \n",listaAbierta->peso);
	mostrarLista(iterador);*/

	//agrega todos los elementos a la lista y les setea la raiz
	while(iterador){
		iterador->nodoRaiz = iterador;
		Nodo *temp = iterador;
		iterador = iterador->sig;
		temp->sig = NULL;
		insertarElementoOrdenado(&listaAbierta,temp);
		nodosProcesados++;
	}

	while(listaAbierta && PROFUNDIDAD > listaAbierta->profundidad && condicionFinal(tPadre, &listaAbierta->t) != 2){
		int tamLista;
		Nodo *nivel = NULL;
		//toma la cabeza y expande ese nodo
		if(listaAbierta->jug2){
			nivel = crearNivel(&listaAbierta->t,listaAbierta->profundidad + 1,0);
		}else{
			nivel = crearNivel(&listaAbierta->t,listaAbierta->profundidad + 1,1);
		}

		tamLista = tamanioLista(nivel);
		iterador = nivel;
		while(iterador){
			//CALCULO DE HEURISTICA
			if(iterador->jug2){
				iterador->peso = listaAbierta->peso + iterador->peso;// + tamLista;
			}else{
				iterador->peso = listaAbierta->peso - iterador->peso;// -  + tamLista;
			}
			iterador->nodoRaiz = listaAbierta->nodoRaiz;
			iterador = iterador->sig;
			nodosProcesados++;
		}

		//elimina la cabeza
		Nodo *head = listaAbierta;
		if(head){
			listaAbierta = listaAbierta->sig;
			head->sig = NULL;
			insertarElementoOrdenado(&listaCerrada,head);
			tPadre = &head->t;
		}

		//TOMA TODOS LOS ELEMENTOS DEL NODO
		//inserta los elementos ordenados
		/*if(nivel){
			iterador = nivel;
			while(iterador){
				Nodo *temp = iterador;
				iterador = iterador->sig;
				temp->sig = NULL;
				insertarElementoOrdenado(&listaAbierta,temp);
			}
		}*/

		//SOLO INSERTA EL NODO DE MAYOR PESO
		if(nivel){
			iterador = nivel;
			Nodo *maxPointer = iterador;
			while(iterador){
				if(iterador->peso > maxPointer->peso){
					maxPointer = iterador;
				}
				iterador = iterador->sig;
			}
			maxPointer->sig = NULL;
			insertarElementoOrdenado(&listaAbierta,maxPointer);
		}
	}

	Nodo *nodoElegido;
	//toma la cabeza y elige la raiz de ese nodo
	if(listaAbierta){
		nodoElegido = listaAbierta->nodoRaiz;
		copiarTablero(&nodoElegido->t,tNuevo);
		//printf("abierta:\n");
		printf("peso elegido: %d \n",listaAbierta->peso);
		mostrarLista(listaAbierta);
	}else{
		nodoElegido = listaCerrada->nodoRaiz;
		copiarTablero(&nodoElegido->t,tNuevo);
		//printf("cerrada:\n");
		printf("peso elegido: %d \n",listaCerrada->peso);
		mostrarLista(listaCerrada);
	}

	printf("el Jugador movio desde: %d,%d hasta %d,%d \n",nodoElegido->desde.x,nodoElegido->desde.y,nodoElegido->hasta.x,nodoElegido->hasta.y);

	//liberarNodo(listaAbierta);
	//liberarNodo(listaCerrada);

	return nodosProcesados;
}

int recorridoAnchoLargo(Nodo *raiz, Tablero *tNuevo, int estrategia){
	int nodosProcesados = 0;
	Nodo *listaAbierta = NULL, *listaCerrada = NULL, *iterador = raiz->nodoHijo;
	Tablero *tPadre = &raiz->t;

	insertarListaAlPpio(&listaCerrada,raiz);
	nodosProcesados++;

	//agrega todos los elementos a la lista y les setea la raiz
	while(iterador){
		iterador->nodoRaiz = iterador;
		iterador = iterador->sig;
		nodosProcesados++;
	}

	if(estrategia == 1){
		insertarListaAlPpio(&listaAbierta,raiz->nodoHijo);
	}else{
		insertarListaAlFinal(&listaAbierta,raiz->nodoHijo);
	}

	while(listaAbierta && condicionFinal(tPadre, &listaAbierta->t) != 2){
		Nodo *iterador, *nivel = NULL;
		//toma la cabeza y expande ese nodo
		if(PROFUNDIDAD > listaAbierta->profundidad){
			if(listaAbierta->jug2){
				nivel = crearNivel(&listaAbierta->t,listaAbierta->profundidad + 1,0);
			}else{
				nivel = crearNivel(&listaAbierta->t,listaAbierta->profundidad + 1,1);
			}

			iterador = nivel;
			while(iterador){
				iterador->nodoRaiz = listaAbierta->nodoRaiz;
				iterador = iterador->sig;
				nodosProcesados++;
			}
		}

		//elimina la cabeza
		Nodo *head = listaAbierta;
		if(head){
			listaAbierta = listaAbierta->sig;
			head->sig = NULL;
			insertarListaAlPpio(&listaCerrada,head);
			tPadre = &head->t;
		}

		//inserta los elementos ordenados
		if(nivel){
			if(estrategia == 1){
				insertarListaAlPpio(&listaAbierta,nivel);
			}else{
				insertarListaAlFinal(&listaAbierta,nivel);
			}
		}
	}

	Nodo *nodoElegido;
	//toma la cabeza y elige la raiz de ese nodo
	if(listaAbierta){
		nodoElegido = listaAbierta->nodoRaiz;
		copiarTablero(&nodoElegido->t,tNuevo);
		printf("peso elegido: %d \n",listaAbierta->peso);
	}else{
		nodoElegido = listaCerrada->nodoRaiz;
		copiarTablero(&nodoElegido->t,tNuevo);
		printf("peso elegido: %d \n",listaCerrada->peso);
	}

	printf("el Jugador movio desde: %d,%d hasta %d,%d \n",nodoElegido->desde.x,nodoElegido->desde.y,nodoElegido->hasta.x,nodoElegido->hasta.y);

	//liberarNodo(listaAbierta);
	//liberarNodo(listaCerrada);

	return nodosProcesados;
}

void jugar(Tablero *tActual, Tablero *tNuevo, int estrategia, int jug2){
	int nodosProcesados = 0;
	//crea la raiz del arbol con el tablero actual
	Nodo *raiz = (struct Nodo *) malloc (sizeof(struct Nodo));
	raiz->t = *tActual;
	raiz->nodoHijo = crearNivel(tActual,1,jug2);
	raiz->nodoRaiz = raiz;
	raiz->sig = NULL;

	//si tiene posibilidad de movimiento
	if(raiz->nodoHijo){
		if(estrategia != 3){
			nodosProcesados = recorridoAnchoLargo(raiz,tNuevo,estrategia);
		}else{
			nodosProcesados = bestFit(raiz,tNuevo);
		}
		printf("nodos procesados: %d, \n",nodosProcesados);
	}
}

void insertarListaAlPpio(Nodo** head, Nodo* n){
	if(n){
		if(*head == NULL){
			*head = n;
			return ;
		}

		//search through to find correct spot and insert the node
		Nodo *temp = n;
		while(temp->sig != NULL) {
			temp = temp->sig;
		}
		temp->sig = *head;
		*head = n;
	}
}

void insertarListaAlFinal(Nodo** head, Nodo* n){
	if(n){
		if(*head == NULL){
			*head = n;
			return ;
		}

		//search through to find correct spot and insert the node
		Nodo *temp = *head;
		while(temp->sig != NULL) {
			temp = temp->sig;
		}
		temp->sig = n;
	}
}

void insertarElementoOrdenado(Nodo** head, Nodo* n){

	if(*head == NULL){
		*head = n;
		return ;
	}

    //see if new node should be placed before head
    if(n->peso > (*head)->peso){
        n->sig = *head;
        *head = n;
        return ;
    }

    //search through to find correct spot and insert the node
    Nodo *temp = *head;
    while(temp->sig != NULL && temp->sig->peso > n->peso) {
    	temp = temp->sig;
    }
    n->sig = temp->sig;
    temp->sig = n;
}

void liberarNodo(Nodo *n){
	if(n){
		liberarNodo(n->sig);
		free(n);
	}
	return ;
}

int tamanioLista(Nodo *nodo){
	int tamanio = 0;
	Nodo *temp = nodo;
	while(temp){
		temp = temp->sig;
		tamanio++;
	}
	return tamanio;
}

void mostrarLista(Nodo *n){
	Nodo *nActual = n;
	while(nActual){
		printf("peso nodo: %d - prof: %d - desde//", nActual->peso,nActual->profundidad);
		nActual = nActual->sig;
	}
}
