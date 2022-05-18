#ifndef MARCA_H_
#define MARCA_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct{

	int id;
	char descripcion[20];

}eMarca;

#endif /* MARCA_H_ */


void mostrarMarca(eMarca marca);

int listarMarcas(eMarca vec[], int tam);

int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice);

int validarMarca(eMarca vec[], int tam, int id);

int cargarMarcaDescripcion(eMarca vec[], int tam, int id, char descrip[]);
