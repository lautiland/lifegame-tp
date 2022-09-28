/*
 * tableroMatriz.cpp
 *
 *  Created on: 27/09/2022
 *      Author: algo2
 */

#include "tableroMatriz.h"
#include <iostream>

using namespace std;

void inicializar(Celula** ppmatriz, Tablero tablero){

	for (int i = 0; i < tablero.filas; i++){
		for (int j = 0; j < tablero.columnas; j++){
			ppmatriz[i][j].estado = muerta;
			if (i == 0){
				if (j == 0){
					ppmatriz[i][j].tipo = esqSupIzq;
				}else if (j == (tablero.columnas - 1)){
					ppmatriz[i][j].tipo = esqSupDer;
				}else{
					ppmatriz[i][j].tipo = bordeInf;
				}
			}else if (j == 0){
				if (i == (tablero.filas -1)){
					ppmatriz[i][j].tipo = esqInfIzq;
				}else{
					ppmatriz[i][j].tipo = bordeIzq;
				}
			}else if (i == (tablero.filas - 1)){
				if (j == (tablero.columnas - 1)){
					ppmatriz[i][j].tipo = esqInfDer;
				}else{
					ppmatriz[i][j].tipo = bordeInf;
				}
			}else if (j == (tablero.columnas - 1)){
				ppmatriz[i][j].tipo = bordeDer;

			}else{
				ppmatriz[i][j].tipo = interior;
			}
		}
	}
}

void ingresarCelulas(Celula** ppmatriz, Tablero tablero){

	otra = 1;
	while (otra == 1){

		//pide un numero de fila y columna, y comprueba su existencia
		do{
			cout<<endl<<"Ingrese el numero de fila de la célula viva: ";
			cin>>fila_celula;
			if (fila_celula <= 0 || fila_celula > tablero.filas){
				cout<<endl<<"La fila ingresada no es válida"<<endl;
			}
		}while(fila_celula <= 0 || fila_celula > tablero.filas);
		do{
			cout<<endl<<"Ingrese el numero de columna de la célula viva: ";
			cin>>columna_celula;
			if (columna_celula <= 0 || columna_celula > tablero.columnas){
				cout<<endl<<"La columna ingresada no es válida"<<endl;
			}
		}while(columna_celula <= 0 || columna_celula > tablero.columnas);

		//prueba que la célula ingresada no haya sido ingresada
		if (ppmatriz[fila_celula -1][columna_celula -1].estado == viva){
			cout<<endl<<"Esa célula viva ya ha sido ingresada"<<endl;
		}else if (ppmatriz[fila_celula -1][columna_celula -1].estado == muerta){

			// añade la célula a la matriz
			ppmatriz[fila_celula -1][columna_celula -1].estado = viva;
		}
		do{
			//nos pregunta si deseamos seguir ingresando células
			cout<<endl<<"¿Desea ingresar otra célula viva?"<<endl<<"1. Si   2. No"<<endl<<endl;
			cin>>otra;
			if ((otra != 1) && (otra !=2)){
				cout<<endl<<"Se ingresó un valor incorrecto"<<endl;
			}
		}while((otra != 1) && (otra !=2));
	}
}

void imprimirMatriz(Celula** ppmatriz, Tablero tablero){

	//recorro la matriz imprimiendo las células
	for (int i = 0; i < tablero.filas; i++){
		cout<<"     ";
		for (int j = 0; j < tablero.columnas; j++){
			if (ppmatriz[i][j].estado == viva){
				cout<<"0 ";
			}else if (ppmatriz[i][j].estado == viva){
				cout<<"X ";
			}
		}
		cout<<endl;
	}
}
