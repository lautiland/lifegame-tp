/*
 * principal.cpp
 *
 *  Fecha de creación: 30/08/2022
 *      Autor: Lautaro Jovanovics
 */

//-------------------------------------------------------------//
//--------------------inclusión de librerias-------------------//
//-------------------------------------------------------------//

#include <iostream>
#include "tableroMatriz.h"
#include "datosTurno.h"

using namespace std;

//-------------------------------------------------------------//
//----------------------función principal----------------------//
//-------------------------------------------------------------//

int main(){

	//Celula* pmatriz = &matriz;

	Celula* pmatriz[tablero.columnas];
	for (int i = 0; i < tablero.columnas; i++){
		pmatriz[i]=&matriz[i][0];
	}
	Celula** ppmatriz = pmatriz;

	Informacion* pdatos = &datos;

	cout<<"Bienvenido al Juego de la Vida de Conway"<<endl;

	//inicializa el tablero con células muerta y declara su tipo
	inicializar(ppmatriz, tablero);


	//ingresa las células vivas iniciales del juego
	ingresarCelulas(ppmatriz, tablero);


	//imprime el tablero inicial
	cout<<endl<<"Tablero inicial:"<<endl<<endl;

	imprimirMatriz(ppmatriz, tablero);

	//nos pregunta que queremos hacer
	datos.sigTurno = preguntar();

	//empieza el turno
	datos.turno = 0.00;
	datos.nacidasTotal = 0.00;
	datos.muertasTotal = 0.00;
	while (datos.sigTurno == true){

		datos.turno += 1;
		datos.vivasTotal = 0;

		//comprueba las condiciones y hace los cambios
//		comprobar(ppmatriz, tablero, pdatos);

		//imprime la matriz
		cout.precision(0);
		cout<<"Turno "<<fixed<<datos.turno<<" :"<<endl<<endl;
		imprimirMatriz(ppmatriz, tablero);

		//nos muestra los datos del turno
		mostrarDatos(pdatos);

		//nos pregunta que queremos hacer
		datos.sigTurno = preguntar();
	}
	return 0;
}