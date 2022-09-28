/*
 * tableroMatriz.h
 *
 *  Created on: 26/09/2022
 *      Author: algo2
 */

#ifndef TABLEROMATRIZ_H_
#define TABLEROMATRIZ_H_

void inicializar(Celula** matriz, Tablero tablero);
void ingresarCelulas(Celula** matriz, Tablero tablero);
void imprimirMatriz(Celula** matriz, Tablero tablero);

struct Tablero {
	int filas;
	int columnas;
}tablero = {20, 80};

enum Estado {
	muerta,
	viva
};

enum Tipo {
	interior,
	bordeSup,
	bordeInf,
	bordeDer,
	bordeIzq,
	esqSupIzq,
	esqSupDer,
	esqInfIzq,
	esqInfDer
};

struct Celula {
	Estado estado;
	Tipo tipo;
}matriz[20][80];

/*

struct CelulaAuxiliar {
	Estado estado;
}AUX[20][80];

*/

int otra, fila_celula, columna_celula;

#endif /* TABLEROMATRIZ_H_ */
