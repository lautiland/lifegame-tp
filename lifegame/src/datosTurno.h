/*
 * datosTurno.h
 *
 *  Created on: 26/09/2022
 *      Author: algo2
 */

#ifndef DATOSTURNO_H_
#define DATOSTURNO_H_

enum SiguienteTurno {
	seguir,
	noSeguir
};

struct Informacion {
	float turno;
	float nacidasTotal;
	float muertasTotal;
	int vivasTotal;
	int nacidas;
	int muertas;
	SiguienteTurno sigTurno;

}datos;

float promedioNacidas;
float promedioMuertas;

int deseo;

SiguienteTurno sigTurno;

void mostrarDatos(Informacion* datos);
//void comprobar(Celula** matriz, Tablero tablero, Informacion* datos);
SiguienteTurno preguntar();

#endif /* DATOSTURNO_H_ */
