#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Tablero.h"
#include "Juego.h" //archivo del jugador 2
#include "jugador1.h" //archivo del jugador 1
#include <time.h>

int main(){
	printf("INICIO DE JUEGO");
	printf("\n");
	printf("\n");

	clock_t comienzo, final;
	double tiempo;
	comienzo = 0;
	final = 0;
	Tablero tActual,tJugado;
	//coloca las fichas en las posiciones iniciales
	inicializarTablero(&tActual);
	//incializo los dos tableros iguales para poder comparar si esta bloqueado el tablero
	inicializarTablero(&tJugado);
	mostrarTablero(&tActual);

	//inicializa el turno para el primer jugador
	int turno = 0;

	do {
		if (turno != 0) {
		  copiarTablero(&tJugado, &tActual);
		}

		/*if(turno == 47)
			printf("turno 47");*/

		//jugador 1
		if(turno % 2 == 1){

			printf("Jugada nº: %d, Jugador 1 \n",turno);
			comienzo = clock();
			//jugar(&tActual,&tJugado,1,0);
			jugar1(&tActual,&tJugado);//func jugador 1
			final = clock();
			tiempo = (double)(final - comienzo);

			printf("El jugador 1 tardo %f segundos\n",tiempo);
			mostrarTablero(&tJugado);
			informarEstado(&tJugado);
		//jugador 2
		} else {
			printf("Jugada nº: %d, Jugador 2 \n",turno);
			comienzo = clock();
			jugar(&tActual,&tJugado,3,1);
			final = clock();
			tiempo = (double)(final - comienzo);

			printf("El jugador 2 tardo %f segundos\n",tiempo);
			mostrarTablero(&tJugado);
			informarEstado(&tJugado);
		}
		turno++;
		printf("\n presione una tecla para el siguiente turno... \n");
		getchar();

	} while(!condicionFinal(&tActual, &tJugado));

	return 0;
}
