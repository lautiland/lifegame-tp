/*
 * tableroMatriz.cpp
 *
 *  Created on: 30/08/2022
 *
 */

#include "tableroMatriz.h"

#include <iostream>

using namespace std;

void inicializar(Celula** ppmatriz, Tablero tablero){

	//recorre la matriz
	for (int i = 0; i < tablero.FILAS; i++){
		for (int j = 0; j < tablero.COLUMNAS; j++){

			//declara como muerta la célula
			ppmatriz[i][j].estado = muerta;

			//define el tipo de célula
			if (i == 0){
				if (j == 0){
					ppmatriz[i][j].tipo = esqSupIzq;
				}else if (j == (tablero.COLUMNAS - 1)){
					ppmatriz[i][j].tipo = esqSupDer;
				}else{
					ppmatriz[i][j].tipo = bordeInf;
				}
			}else if (j == 0){
				if (i == (tablero.FILAS -1)){
					ppmatriz[i][j].tipo = esqInfIzq;
				}else{
					ppmatriz[i][j].tipo = bordeIzq;
				}
			}else if (i == (tablero.FILAS - 1)){
				if (j == (tablero.COLUMNAS - 1)){
					ppmatriz[i][j].tipo = esqInfDer;
				}else{
					ppmatriz[i][j].tipo = bordeInf;
				}
			}else if (j == (tablero.COLUMNAS - 1)){
				ppmatriz[i][j].tipo = bordeDer;

			}else{
				ppmatriz[i][j].tipo = interior;
			}
		}
	}
}

void ingresarCelulas(Celula** ppmatriz, Tablero tablero){

	//defino las variables a utilizar
	int otra, filaCelula, columnaCelula;

	do{

		//pide un numero de fila y columna, y comprueba su existencia
		do{
			cout<<endl<<"Ingrese el numero de fila de la célula viva: ";
			cin>>filaCelula;
			if (filaCelula <= 0 || filaCelula > tablero.FILAS){
				cout<<endl<<"La fila ingresada no es válida"<<endl;
			}
		}while(filaCelula <= 0 || filaCelula > tablero.FILAS);
		do{
			cout<<endl<<"Ingrese el numero de columna de la célula viva: ";
			cin>>columnaCelula;
			if (columnaCelula <= 0 || columnaCelula > tablero.COLUMNAS){
				cout<<endl<<"La columna ingresada no es válida"<<endl;
			}
		}while(columnaCelula <= 0 || columnaCelula > tablero.COLUMNAS);

		//prueba que la célula ingresada no esté viva
		if (ppmatriz[filaCelula -1][columnaCelula -1].estado == viva){
			cout<<endl<<"Esa célula viva ya ha sido ingresada"<<endl;
		}else if (ppmatriz[filaCelula -1][columnaCelula -1].estado == muerta){

			//añade la célula a la matriz
			ppmatriz[filaCelula -1][columnaCelula -1].estado = viva;
		}
		do{
			//nos pregunta si deseamos seguir ingresando células
			cout<<endl<<"¿Desea ingresar otra célula viva?"<<endl<<"1. Si   2. No"<<endl<<endl;
			cin>>otra;
			if ((otra != 1) && (otra !=2)){
				cout<<endl<<"Se ingresó un valor incorrecto"<<endl;
			}
		}while((otra != 1) && (otra !=2));
	}while (otra == 1);
}

void imprimirMatriz(Celula** ppmatriz, Tablero tablero){

	//recorro la matriz
	for (int i = 0; i < tablero.FILAS; i++){
		cout<<"     ";
		for (int j = 0; j < tablero.COLUMNAS; j++){

			//imprime las células muertas con '0'
			if (ppmatriz[i][j].estado == muerta){
				cout<<"0 ";

			//imprime las células vivas con 'X'
			}else if (ppmatriz[i][j].estado == viva){
				cout<<"X ";
			}
		}
		cout<<endl;
	}
}

void comprobar(Celula** ppmatriz, Tablero tablero, InformacionTurno* pdatosTurno){

	//reseteo variable
	pdatosTurno->celulasVivas = 0;
	pdatosTurno->celulasNacidas = 0;
	pdatosTurno->celulasMuertas = 0;

	//creo una matriz auxiliar para ir haciendo las modificaciónes ahi
	CelulaAuxiliar matrizAuxiliar[tablero.FILAS][tablero.COLUMNAS];

	//copia el tablero al tablero auxiliar
	for (int i = 0; i < tablero.FILAS; i ++){
		for (int j = 0; j < tablero.COLUMNAS; j++){
			matrizAuxiliar[i][j].estado = ppmatriz[i][j].estado;
		}
	}

	//hace los cálculos de cuantas vivas hay al rededor de cada célula
	for (int i = 0; i < tablero.FILAS; i ++){
		for (int j = 0; j < tablero.COLUMNAS; j++){
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

				//da vida a la célula por reproducción
				matrizAuxiliar[i][j].estado = viva;
				pdatosTurno->celulasNacidas += 1;
			}
			if ((ppmatriz[i][j].estado == viva) && ((vivas < 2)||(vivas > 3))){

				//mata a la célula por sobrepoblación o soledad
				matrizAuxiliar[i][j].estado = muerta;
				pdatosTurno->celulasMuertas += 1;
			}
		}
	}

	//copia el tablero auxiliar al tablero
	for (int i = 0; i < tablero.FILAS; i ++){
		for (int j = 0; j < tablero.COLUMNAS; j++){
			ppmatriz[i][j].estado = matrizAuxiliar[i][j].estado;

			//cuenta las células vivas a medida que va copiando
			if (ppmatriz[i][j].estado == viva){
				pdatosTurno->celulasVivas += 1;
			}
		}
	}
}

