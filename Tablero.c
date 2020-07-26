#include "Tablero.h"
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void inicializarTablero(Tablero *t){
	// 0 para los cuadros que no se pueden utilizar
	// 1 para los cuadros donde no hay piezas
	// 2 para las fichas del jugador 1
	// 3 para las damas del jugador 1
	// 4 para las fichas del jugador 2
	// 5 para las damas del jugador 2

	//fichas jugador 1
	int fila,col,init;
	for(fila = 0; fila < 3; fila++){
		init = fila%2;
		//fichas
		for(col = init; col < TAMANIO; col+=2){
			t->matriz[fila][col] = 2;
		}
		//casilleros nulos
		for(col = (init+1)%2; col < TAMANIO; col+=2){
			t->matriz[fila][col] = 0;
		}
	}

	//casilleros centrales
	for(fila = 3; fila < 7; fila++){
		init = fila%2;
		//casilleros vacios
		for(col = init; col < TAMANIO; col+=2){
			t->matriz[fila][col] = 1;
		}
		//casilleros nulos
		for(col = (init+1)%2; col < TAMANIO; col+=2){
			t->matriz[fila][col] = 0;
		}
	}

	//fichas jugador 2
	for(fila = 7; fila < TAMANIO; fila++){
		init = fila%2;
		//fichas
		for(col = init; col < TAMANIO; col+=2){
			t->matriz[fila][col] = 4;
		}
		//casilleros nulos
		for(col = (init+1)%2; col < TAMANIO; col+=2){
			t->matriz[fila][col] = 0;
		}
	}
	/*for (fila = 0;fila<10;fila++){
			for(col = init; col < TAMANIO; col++){
				t->matriz[fila][col] = 1;
			}
		}
		t->matriz[5][5] = 5;
		t->matriz[6][6] = 3;
		t->matriz[6][4] = 3;
		t->matriz[4][4] = 3;
		t->matriz[4][6] = 3;*/
}


int condicionFinal(Tablero *t, Tablero *tj){
	// A la funcion le faltaria la opcion de que empataron que seria cuando todas las fichas quedan bloqueadas,
	// en otras palabras ningun jugador puede mover ninguna ficha. Nose como hacerlo todavia
	int hayfichasJ1 = 0, hayfichasJ2 = 0, bloqueado = 0, fil = 0, col = 0, final = 0;
	//mientras no se haya terminado de recorrer el tablero y todavia no se hayan encontrado fichas de los dos jugadores
	while(!(hayfichasJ1 && hayfichasJ2) && fil<TAMANIO) {
		if(t->matriz[fil][col] == 2 || t->matriz[fil][col] == 3){
			hayfichasJ1 = 1;
		} else if (t->matriz[fil][col] == 4 || t->matriz[fil][col] == 5){
			hayfichasJ2 = 1;
		}
		if (hayfichasJ1 && hayfichasJ2) {
		  break;
		}
		col++;
		if (col == TAMANIO){
			col = 0;
			fil++;
		}
	}

  bloqueado = sonIguales(t, tj);

  if (!hayfichasJ1) {
    fprintf(stdout,"Jugador 1 ha quedado sin fichas, fin del juego");
    final = 2;
  } else if (!hayfichasJ2) {
    fprintf(stdout,"Jugador 2 ha quedado sin fichas, fin del juego");
    final = 1;
  } else if (bloqueado) {
    fprintf(stdout,"Tablero bloqueado, fin del juego");
    final = 3;
  }
	return final;
}


void mostrarTablero(Tablero *t){
	int fila,col;
	fprintf(stdout,"Estado actual del tablero: \n");
	for(col = 0; col < TAMANIO; col++){
		if (col == 0) {
			fprintf(stdout, "      ");
			fprintf(stdout, "[%d] ",col);
		} else {
			fprintf(stdout, "[%d] ",col);
		}

	}
	fprintf(stdout,"\n");
	for(col = 0; col < TAMANIO; col++){
		//fprintf(stdout,"[%d ] ",col);
		if (col == 0) {
			fprintf(stdout,"     -----");
		} else {
			fprintf(stdout,"----");
		}
	}
	fprintf(stdout,"\n");
	for(fila = TAMANIO - 1; fila >= 0; fila--){
		fprintf(stdout,"[%d]  ",fila);
		printf("|");
		for(col = 0; col < TAMANIO; col++){
			if(t->matriz[fila][col] == 4 || t->matriz[fila][col] == 5){
				printf(ANSI_COLOR_RED " %d " ANSI_COLOR_RESET "|" ,t->matriz[fila][col]);
			}else if(t->matriz[fila][col] == 2 || t->matriz[fila][col] == 3){
				printf(ANSI_COLOR_BLUE " %d " ANSI_COLOR_RESET "|",t->matriz[fila][col]);
			}else{
				printf(" %d |",t->matriz[fila][col]);
			}
		}
		fprintf(stdout,"\n");
		for(col = 0; col < TAMANIO; col++){
			if (col == 0) {
				fprintf(stdout,"     -----");
			} else {
				fprintf(stdout,"----");
			}
		}
		fprintf(stdout,"\n");
	}
	fprintf(stdout,"\n");
	fprintf(stdout,"\n");
}

void copiarTablero(Tablero *from, Tablero *to){
	int fil,col;
	for(fil = 9; fil >= 0; fil--){
		for(col = 0; col < TAMANIO; col++){
			to->matriz[fil][col] = from->matriz[fil][col];
		}
	}
}

void informarEstado(Tablero *t){
	int fil,col,fichasJ1,fichasJ2,damasJ1,damasJ2;
	fichasJ1 = 0;
	damasJ1 = 0;
	fichasJ2 = 0;
	damasJ2 = 0;
	for(fil = 9; fil >= 0; fil--){
		for(col = 0; col < TAMANIO; col++){
			if(t->matriz[fil][col] == 2){
				fichasJ1++;
			}else if(t->matriz[fil][col] == 3){
				damasJ1++;
			}else if(t->matriz[fil][col] == 4){
				fichasJ2++;
			}else if(t->matriz[fil][col] == 5){
				damasJ2++;
			}
		}
	}
	fprintf(stdout,"fichas Jugador 1: %d \n",fichasJ1);
	fprintf(stdout,"damas Jugador 1: %d \n",damasJ1);
	fprintf(stdout,"fichas Jugador 2: %d \n",fichasJ2);
	fprintf(stdout,"damas Jugador 2: %d \n",damasJ2);
	fprintf(stdout,"\n");
	fprintf(stdout,"\n");
}

//chequeo si los dos tableros son iguales
int sonIguales(Tablero *t, Tablero *tj) {
  int i, j, iguales = 1;
  for (i = 0; i < TAMANIO; i ++) {
    for (j = 0; j < TAMANIO; j++) {
      if (t->matriz[i][j] != tj->matriz[i][j]) {
        iguales = 0;
        break;
      }
    }
    if (iguales == 0) {
      break;
    }
  }
  return iguales;
}
