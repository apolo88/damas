#include "MovsTablero.h"
#include <stdio.h>

/////////////
//FICHAS
/////////////

//PUEDE MOVER
int puedeMoverIzAb (Tablero *t, Pos p){
    return p.x-1 >= 0 && 0 <= p.y-1 && t->matriz[p.x-1][p.y-1] == 1;
}

int puedeMoverDerAb (Tablero *t, Pos p){
    return p.x-1 >= 0 && p.y+1 < 10 && t->matriz[p.x-1][p.y+1] == 1;
}

int puedeMoverIzAr(Tablero *t, Pos p){
    return p.x+1 < 10 && 0 <= p.y-1 && p.y-1 < 10 && t->matriz[p.x+1][p.y-1] == 1;
}

int puedeMoverDerAr(Tablero *t, Pos p){
    return p.x+1 < 10 && 0 <= p.y+1 && p.y+1 < 10 && t->matriz[p.x+1][p.y+1] == 1;
}

//MOVER
int moverIzAb(Tablero *t,Pos p){
	t->matriz[p.x][p.y] = 1;
	if(p.x-1 > 0){
		t->matriz[p.x-1][p.y-1] = 4;
		return 0;
	}else{
		t->matriz[p.x-1][p.y-1] = 5;
		return 1;
	}
}

int moverDerAb(Tablero *t,Pos p){
	t->matriz[p.x][p.y] = 1;
	if(p.x-1 > 0){
		t->matriz[p.x-1][p.y+1] = 4;
		return 0;
	}else{
		t->matriz[p.x-1][p.y+1] = 5;
		return 1;
	}
}

int moverIzAr(Tablero *t, Pos p) {
	t->matriz[p.x][p.y] = 1;
	if (p.x + 1 < 9){
		t->matriz[p.x + 1][p.y - 1] = 2;
		return 0;
	}else{
		t->matriz[p.x + 1][p.y - 1] = 3;
		return 1;
	}
}

int moverDerAr(Tablero *t, Pos p) {
	t->matriz[p.x][p.y] = 1;
	if (p.x + 1 < 9){
		t->matriz[p.x + 1][p.y + 1] = 2;
		return 0;
	}else{
		t->matriz[p.x + 1][p.y + 1] = 3;
		return 1;
	}
}

//PUEDE COMER
int puedeComerIzAb(Tablero *t, Pos p){
	return p.x-2 >= 0 && 0 <= p.y-2 && (t->matriz[p.x-1][p.y-1] == 2 || t->matriz[p.x-1][p.y-1] == 3) && t->matriz[p.x-2][p.y-2] == 1;
}

int puedeComerDerAb(Tablero *t, Pos p){
	return p.x-2 >= 0 && 0 <= p.y+2 && (t->matriz[p.x-1][p.y+1] == 2 || t->matriz[p.x-1][p.y+1] == 3) && t->matriz[p.x-2][p.y+2] == 1;
}

int puedeComerIzAr(Tablero *t, Pos p){
    return p.x+2 < 10 && 0 <= p.y-2 && (t->matriz[p.x+1][p.y-1] == 4 || t->matriz[p.x+1][p.y-1] == 5) && t->matriz[p.x+2][p.y-2] == 1;
}

int puedeComerDerAr(Tablero *t, Pos p){
    return p.x+2 < 10 && 0 <= p.y+2 && (t->matriz[p.x+1][p.y+1] == 4 || t->matriz[p.x+1][p.y+1] == 5) && t->matriz[p.x+2][p.y+2] == 1;
}

//COMER
Pos comerIzAb(Tablero *t, Pos p){
	Pos posFinal;
	posFinal.x = p.x - 2;
	posFinal.y = p.y - 2;
	t->matriz[p.x][p.y] = 1; //posicion que abandona la ficha
	t->matriz[p.x - 1][p.y - 1] = 1; //ficha que acaba de comer
	if (p.x - 2 > 0)
		t->matriz[posFinal.x][posFinal.y] = 4; //ficha
	else
		t->matriz[posFinal.x][posFinal.y] = 5; //reina

	return posFinal;
}

Pos comerDerAb(Tablero *t, Pos p){
	Pos posFinal;
	posFinal.x = p.x - 2;
	posFinal.y = p.y + 2;
	t->matriz[p.x][p.y] = 1; //posicion que abandona la ficha
	t->matriz[p.x - 1][p.y + 1] = 1; //ficha que acaba de comer
	if (p.x - 2 > 0)
		t->matriz[posFinal.x][posFinal.y] = 4; //ficha
	else
		t->matriz[posFinal.x][posFinal.y] = 5; //reina

	return posFinal;
}

Pos comerIzAr(Tablero *t, Pos p){
	Pos posFinal;
	posFinal.x = p.x + 2;
	posFinal.y = p.y - 2;
	t->matriz[p.x][p.y] = 1; //posicion que abandona la ficha
	t->matriz[p.x + 1][p.y - 1] = 1; //ficha que acaba de comer
	if (p.x + 2 < 9)
		t->matriz[posFinal.x][posFinal.y] = 2; //ficha
	else
		t->matriz[posFinal.x][posFinal.y] = 3; //reina

	return posFinal;
}

Pos comerDerAr(Tablero *t, Pos p){
	Pos posFinal;
	posFinal.x = p.x + 2;
	posFinal.y = p.y + 2;
	t->matriz[p.x][p.y] = 1; //posicion que abandona la ficha
	t->matriz[p.x + 1][p.y + 1] = 1; //ficha que acaba de comer
	if (p.x + 2 < 9)
		t->matriz[posFinal.x][posFinal.y] = 2; //ficha
	else
		t->matriz[posFinal.x][posFinal.y] = 3; //reina

	return posFinal;
}

////////////
//REINAS
////////////

//PUEDE MOVER REINA
//devuelve la cant de posiciones en que se puede mover
int puedeMovReinaDeAr (Tablero *t, Pos p){
	int c = 0;
	p.x++;
	p.y++;
	while (p.x<10 && p.y<10 && t->matriz[p.x][p.y]==1){
		c++;
		p.x++;
		p.y++;
	}

	return c;
}

int puedeMovReinaDeAb (Tablero *t, Pos p){
	int c = 0;
	p.x--;
	p.y++;
	while (p.x>=0 && p.y<10 && t->matriz[p.x][p.y]==1){
		c++;
		p.x--;
		p.y++;
	}

	return c;
}

int puedeMovReinaIzAr (Tablero *t, Pos p){
	int c = 0;
	p.x++;
	p.y--;
	while (p.x<10 && p.y>=0 && t->matriz[p.x][p.y]==1){
		c++;
		p.x++;
		p.y--;
	}

	return c;
}

int puedeMovReinaIzAb (Tablero *t, Pos p){
	int c = 0;
	p.x--;
	p.y--;
	while (p.x>=0 && p.y>=0 && t->matriz[p.x][p.y]==1){
		c++;
		p.x--;
		p.y--;
	}

	return c;
}

//MOVER REINA
void movReinaDeAr (Tablero *t, Pos p, int c){
	t->matriz[p.x+c][p.y+c] = t->matriz[p.x][p.y];
	t->matriz[p.x][p.y] = 1;
}

void movReinaDeAb (Tablero *t, Pos p, int c){
	t->matriz[p.x-c][p.y+c] = t->matriz[p.x][p.y];
	t->matriz[p.x][p.y] = 1;
}

void movReinaIzAr (Tablero *t, Pos p, int c){
	t->matriz[p.x+c][p.y-c] = t->matriz[p.x][p.y];
	t->matriz[p.x][p.y] = 1;
}

void movReinaIzAb (Tablero *t, Pos p, int c){
	t->matriz[p.x-c][p.y-c] = t->matriz[p.x][p.y];
	t->matriz[p.x][p.y] = 1;
}

//PUEDE COMER REINA
int puedeComerReinaDeAr (Tablero *t, Pos p, int reina){
	int distOponente = 1;
	int fichaJugador = reina == 5 ? 4 : 2;

	//comprueba que no haya llegado al final del tablero y que no se cumpla la condicion
	//de que encontro una ficha en el casillero siguiente
	while (p.x+distOponente+1 < 9 && p.y+distOponente+1 < 9) {
		if (t->matriz[p.x + distOponente][p.y + distOponente] == 1) {
			distOponente++;
		} else if(t->matriz[p.x + distOponente][p.y + distOponente] != fichaJugador && t->matriz[p.x + distOponente][p.y + distOponente] != reina && t->matriz[p.x+distOponente+1][p.y+distOponente+1] == 1){
			return distOponente;
		}else{
			break;
		}
	}

	return 0;
}


int puedeComerReinaDeAb (Tablero *t, Pos p, int reina){
	int distOponente = 1;
	int fichaJugador = reina == 5 ? 4 : 2;

	//comprueba que no haya llegado al final del tablero y que no se cumpla la condicion
	//de que encontro una ficha en el casillero siguiente
	while (p.x-distOponente-1 >= 0 && p.y+distOponente+1 < 9) {
		if (t->matriz[p.x - distOponente][p.y + distOponente] == 1) {
			distOponente++;
		} else if(t->matriz[p.x - distOponente][p.y + distOponente] != fichaJugador && t->matriz[p.x - distOponente][p.y + distOponente] != reina && t->matriz[p.x-distOponente-1][p.y+distOponente+1] == 1){
			return distOponente;
		}else{
			break;
		}
	}

	return 0;
}

int puedeComerReinaIzAr (Tablero *t, Pos p, int reina){
	int distOponente = 1;
	int fichaJugador = reina == 5 ? 4 : 2;

	//comprueba que no haya llegado al final del tablero y que no se cumpla la condicion
	//de que encontro una ficha en el casillero siguiente
	while (p.x+distOponente+1 < 9 && p.y-distOponente-1 >= 0) {
		if (t->matriz[p.x + distOponente][p.y - distOponente] == 1) {
			distOponente++;
		} else if(t->matriz[p.x + distOponente][p.y - distOponente] != fichaJugador && t->matriz[p.x + distOponente][p.y - distOponente] != reina && t->matriz[p.x+distOponente+1][p.y-distOponente-1] == 1){
			return distOponente;
		}else{
			break;
		}
	}

	return 0;
}

int puedeComerReinaIzAb (Tablero *t, Pos p, int reina){
	int distOponente = 1;
	int fichaJugador = reina == 5 ? 4 : 2;

	//comprueba que no haya llegado al final del tablero y que no se cumpla la condicion
	//de que encontro una ficha en el casillero siguiente
	while (p.x-distOponente-1 >= 0 && p.y-distOponente-1 >= 0) {
		if (t->matriz[p.x - distOponente][p.y - distOponente] == 1) {
			distOponente++;
		} else if(t->matriz[p.x - distOponente][p.y - distOponente] != fichaJugador && t->matriz[p.x - distOponente][p.y - distOponente] != reina && t->matriz[p.x-distOponente-1][p.y-distOponente-1] == 1){
			return distOponente;
		}else{
			break;
		}
	}

	return 0;
}

//COMER REINA
Pos comerReinaDeAr (Tablero *t, Pos p, int posOpuesto){

	int posFutura = posOpuesto;
	posFutura++;
	Pos posFinal;
	posFinal.x = p.x + posFutura;
	posFinal.y = p.y + posFutura;

	//situa la reina en la nueva posicion
	t->matriz[posFinal.x][posFinal.y] = t->matriz[p.x][p.y];
	//elimina la ficha del contrario
	t->matriz[p.x + posOpuesto][p.y + posOpuesto] = 1;
	//elimina la reina de su ubicacion anterior
	t->matriz[p.x][p.y] = 1;

	return posFinal;
}

Pos comerReinaDeAb (Tablero *t, Pos p, int posOpuesto){

	int posFutura = posOpuesto;
	posFutura++;
	Pos posFinal;
	posFinal.x = p.x - posFutura;
	posFinal.y = p.y + posFutura;

	t->matriz[posFinal.x][posFinal.y] = t->matriz[p.x][p.y];
	t->matriz[p.x - posOpuesto][p.y + posOpuesto] = 1;
	t->matriz[p.x][p.y] = 1;

	return posFinal;
}

Pos comerReinaIzAr (Tablero *t, Pos p, int posOpuesto){

	int posFutura = posOpuesto;
	posFutura++;
	Pos posFinal;
	posFinal.x = p.x + posFutura;
	posFinal.y = p.y - posFutura;

	t->matriz[posFinal.x][posFinal.y] = t->matriz[p.x][p.y];
	t->matriz[p.x + posOpuesto][p.y - posOpuesto] = 1;
	t->matriz[p.x][p.y] = 1;

	return posFinal;
}

Pos comerReinaIzAb (Tablero *t, Pos p, int posOpuesto){

	int posFutura = posOpuesto;
	posFutura++;
	Pos posFinal;
	posFinal.x = p.x - posFutura;
	posFinal.y = p.y - posFutura;

	t->matriz[posFinal.x][posFinal.y] = t->matriz[p.x][p.y];
	t->matriz[p.x - posOpuesto][p.y - posOpuesto] = 1;
	t->matriz[p.x][p.y] = 1;

	return posFinal;
}
