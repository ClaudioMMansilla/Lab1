#include <stdio.h>
#include <stdlib.h>
#include "Color.h"
#include "Marca.h"

#ifndef AUTO_H_
#define AUTO_H_

typedef struct{
	char id[8];
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}eAuto;

#endif /* AUTO_H_ */


int ordenarAutosMarcaCaja(eAuto vec[], int tam);

int inicializarAutos(eAuto vec[], int tam);

void mostrarAuto(eAuto a, eMarca marcas[], int tamM, eColor colores[], int tamC);

int listarAutos(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int buscarIndiceLibreAuto(eAuto autos[], int tam, int* pIndice);

int buscarAuto(eAuto vec[], int tam, char id[], int* pIndice);

int validarAuto(eAuto vec[], int tam, char id[]);

int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int bajaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int buscarAutoColor(eAuto autos[], int tamA, eColor color[], int tamC, int id, int* pIndice);

int listarAutosIdColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int listarAutosIdMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
