/*
 * principal.cpp
 *
 *  Fecha de creación: 30/08/2022
 *
 */

//inclusión de librerias
#include <iostream>
#include "tableroMatriz.h"
#include "datosTurno.h"
using namespace std;

//función principal
int main(){

	//inicializo las variables a utilizar
	Tablero tablero = {20, 80};
	Celula matriz[tablero.FILAS][tablero.COLUMNAS];
	InformacionTurno datosTurno;
	Informacion datos;

	//creo punteros para poder modificar las variables en las funciones
	Celula* pmatriz[tablero.COLUMNAS];
	for (int i = 0; i < tablero.COLUMNAS; i++){
		pmatriz[i]=&matriz[i][0];
	}
	Celula** ppmatriz = pmatriz;
	InformacionTurno* pdatosTurno = &datosTurno;
	Informacion* pdatos = &datos;

	//bienvenida al juego
	cout<<"Bienvenido al Juego de la Vida de Conway"<<endl;

	//inicializa el tablero con células muertas y declara su tipo
	inicializar(ppmatriz, tablero);

	//ingresa las células vivas iniciales del juego por consola
	ingresarCelulas(ppmatriz, tablero);


	//imprime el tablero inicial
	cout<<endl<<"Tablero inicial:"<<endl<<endl;
	imprimirMatriz(ppmatriz, tablero);

	//nos pregunta que hacer a continuación
	preguntar(pdatos);

	//empieza el turno
	datos.turno = 0.0;
	datos.nacidasTotal = 0.0;
	datos.muertasTotal = 0.0;
	while (datos.sigTurno == seguir){

		//resetea las variables necesarias
		datos.turno += 1;
		datos.vivasTotal = 0;

		//comprueba las condiciones y hace los cambios
		comprobar(ppmatriz, tablero, pdatosTurno);

		//unión de datos entre los módulos
		datos.muertas = datosTurno.celulasMuertas;
		datos.nacidas = datosTurno.celulasNacidas;
		datos.vivasTotal = datosTurno.celulasVivas;

		//imprime la matriz del turno
		cout.precision(0);
		cout<<"Turno "<<fixed<<datos.turno<<" :"<<endl<<endl;
		imprimirMatriz(ppmatriz, tablero);

		//nos muestra los datos del turno
		mostrarDatos(pdatos);

		//nos pregunta que hacer a continuación
		preguntar(pdatos);
	}
	return 0;
}



