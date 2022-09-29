/*
 * tableroMatriz.h
 *
 *  Created on: 30/08/2022
 *
 */

#ifndef TABLEROMATRIZ_H_
#define TABLEROMATRIZ_H_

//declaro los enum utilizados en este módulo
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

//declaro los struct utilizados en este módulo
struct Tablero {
	const int FILAS;
	const int COLUMNAS;
};
struct Celula {
	Estado estado;
	Tipo tipo;
};
struct CelulaAuxiliar {
	Estado estado;
};
struct InformacionTurno {
	int celulasMuertas;
	int celulasNacidas;
	int celulasVivas;
};

//declaro las funciónes que componen este módulo
void inicializar(Celula** ppmatriz, Tablero tablero);
void ingresarCelulas(Celula** ppmatriz, Tablero tablero);
void imprimirMatriz(Celula** ppmatriz, Tablero tablero);
void comprobar(Celula** ppmatriz, Tablero tablero, InformacionTurno* pdatosTurno);


#endif /* TABLEROMATRIZ_H_ */
