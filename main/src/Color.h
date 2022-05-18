#ifndef COLOR_H_
#define COLOR_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct{

	int id;
	char nombreColor[20];

}eColor;
#endif /* COLOR_H_ */


void mostrarColor(eColor color);

int listarColores(eColor vec[], int tam);

int buscarColor(eColor colores[], int tam, int id, int* pIndice);

int validarColor(eColor vec[], int tam, int id);

int cargarNombreColor(eColor vec[], int tam, int id, char descrip[]);
