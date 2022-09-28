/*
 * datosTurno.cpp
 *
 *  Created on: 27/09/2022
 *      Author: algo2
 */

#include "datosTurno.h"
#include <iostream>

using namespace std;

void mostrarDatos(Informacion* pdatos){

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
}

SiguienteTurno preguntar(){

	//nos pregunta que deseamos realizar a continuación
	cout<<endl<<"¿Que desea hacer?"<<endl<<"1. Ejecutar un turno   2. Reiniciar el juego   3. Terminar"<<endl<<endl;
	cin>>deseo;
	cout<<endl<<endl;
	switch(deseo){
		case 1:
			sigTurno = seguir;
			break;
		case 2:
			sigTurno = noSeguir;
			//main();
			break;
		case 3:
			sigTurno = noSeguir;
			break;
	}
	return sigTurno;
}

/*

void comprobar(Celula** ppmatriz, Tablero tablero, Informacion* datos){

	datos->nacidas = 0;
	datos->muertas = 0;

	//copia el tablero al tablero auxiliar
	for (int i = 0; i < tablero.filas; i ++){
		for (int j = 0; j < tablero.columnas; j++){
			AUX[i][j].estado = ppmatriz[i][j].estado;
		}
	}

	//hace los cálculos de cuantas vivas hay al rededor de cada célula
	for (int i = 0; i < tablero.filas; i ++){
		for (int j = 0; j < tablero.columnas; j++){
			int vivas = 0;
			switch(ppmatriz[i][j].tipo){
				case interior:
					if (ppmatriz[i-1][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j+1].estado == viva){
						vivas += 1;
					}
					break;
				case bordeSup:
					if (ppmatriz[i][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j+1].estado == viva){
						vivas += 1;
					}
					break;
				case bordeInf:
					if (ppmatriz[i][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i][j+1].estado == viva){
						vivas += 1;
					}
					break;
				case bordeDer:
					if (ppmatriz[i-1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j].estado == viva){
						vivas += 1;
					}
					break;
				case bordeIzq:
					if (ppmatriz[i-1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j].estado == viva){
						vivas += 1;
					}
					break;
				case esqSupIzq:
					if (ppmatriz[i][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j+1].estado == viva){
						vivas += 1;
					}
					break;
				case esqSupDer:
					if (ppmatriz[i][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i+1][j].estado == viva){
						vivas += 1;
					}
					break;
				case esqInfIzq:
					if (ppmatriz[i-1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j+1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i][j+1].estado == viva){
						vivas += 1;
					}
					break;
				case esqInfDer:
					if (ppmatriz[i][j-1].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j].estado == viva){
						vivas += 1;
					}
					if (ppmatriz[i-1][j-1].estado == viva){
						vivas += 1;
					}
					break;
			}

			//comprueba las reglas con la célula

			if ((ppmatriz[i][j].estado == muerta) && (vivas == 3)){

				//hace vivir a la célula por reproducción
				AUX[i][j].estado = viva;
				datos->nacidas += 1;
			}
			if ((ppmatriz[i][j].estado == viva) && ((vivas < 2)||(vivas > 3))){

				//mata a la célula por sobrepoblación o soledad
				AUX[i][j].estado = muerta;
				datos->muertas += 1;
			}
		}
	}

	//copia el tablero auxiliar al tablero
	for (int i = 0; i < tablero.filas; i ++){
		for (int j = 0; j < tablero.columnas; j++){
			ppmatriz[i][j].estado = AUX[i][j].estado;

			//cuenta las células vivas a medida que va copiando
			if (ppmatriz[i][j].estado == viva){
				datos->vivasTotal +=1;
			}
		}
	}
}

*/