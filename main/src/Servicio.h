#ifndef SERVICIO_H_
#define SERVICIO_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct{

	int id;
	char descripcion[25];
	float precio;

}eServicio;

#endif /* SERVICIO_H_ */

int buscarServicio(eServicio servicios[], int tam, int id, int* pIndice);

int validarServicio(eServicio servicio[], int tam, int id);

void mostrarServicio(eServicio servicio);

int listarServicios(eServicio servicio[], int tam);

int cargarServDescrip(eServicio vec[], int tam, int id, char descrip[], float* pPrecio);
