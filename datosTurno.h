/*
 * datosTurno.h
 *
 *  Created on: 30/08/2022
 *
 */

#ifndef DATOSTURNO_H_
#define DATOSTURNO_H_

//declaro el enum utilizado en este módulo
enum SiguienteTurno {
	seguir,
	noSeguir
};

//declaro el struct utilizado en este módulo
struct Informacion {
	int vivasTotal;
	int nacidas;
	int muertas;
	float turno;
	float nacidasTotal;
	float muertasTotal;
	SiguienteTurno sigTurno;

};

//declaro las funciones utilizadas en este módulo
void mostrarDatos(Informacion* pdatos);
void preguntar(Informacion* pdatos);

#endif /* DATOSTURNO_H_ */
