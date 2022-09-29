/*
 * datosTurno.cpp
 *
 *  Created on: 30/08/2022
 *
 */

//incluyo su header y libreria
#include "datosTurno.h"
#include <iostream>
using namespace std;

void mostrarDatos(Informacion* pdatos){

	//defino las variables a utilizar
	float promedioNacidas, promedioMuertas;


	//hace los cálculos de totales y promedios
	pdatos->nacidasTotal += pdatos->nacidas;
	pdatos->muertasTotal += pdatos->muertas;
	promedioNacidas = pdatos->nacidasTotal / pdatos->turno;
	promedioMuertas = pdatos->muertasTotal / pdatos->turno;

	//imprime los datos del turno
	cout<<endl<<"La cantidad de células vivas es de "<<pdatos->vivasTotal<<endl;
	cout<<"La cantidad de células nacidas en el ultimo turno es de "<<pdatos->nacidas<<endl;
	cout<<"La cantidad de células muertas en el ultimo turno es de "<<pdatos->muertas<<endl;
	cout.precision(2);
	cout<<"El promedio de nacimientos en el juego es de "<<fixed<<promedioNacidas<<endl;
	cout<<"El promedio de muertes en el juego es de "<<fixed<<promedioMuertas<<endl;

	//comprueba si el juego se congeló
	if (pdatos->nacidas == 0 && pdatos->muertas == 0){
		cout<<"El juego se congeló en el ultimo turno"<<endl;
	}

	//reseteo los valores nacidas y muertas para el siguiente turno
	pdatos->nacidas = 0;
	pdatos->muertas = 0;
}

void preguntar(Informacion* pdatos){

	//defino las variables a utilizar
	int deseo;

	//nos pregunta que deseamos realizar a continuación
	cout<<endl<<"¿Que desea hacer?"<<endl<<"1. Ejecutar un turno   2. Reiniciar el juego   3. Terminar"<<endl<<endl;
	cin>>deseo;
	cout<<endl<<endl;

	//analiza el resultado
	switch(deseo){
		case 1:
			pdatos->sigTurno = seguir;
			break;
		case 2:
			pdatos->sigTurno = noSeguir;
			//main();
			break;
		case 3:
			pdatos->sigTurno = noSeguir;
			break;
	}
}

