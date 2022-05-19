// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "Servicio.h"
#include "string.h"


int buscarServicio(eServicio servicios[], int tam, int id, int* pIndice){

    int control = 0;
    if( servicios != NULL && pIndice != NULL && tam > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        control = 1;
    }
    return control;
}


int validarServicio(eServicio servicio[], int tam, int id){
	int validacion = 0;
	int indice;

	if (buscarServicio(servicio, tam, id, &indice) ){
		if(indice != -1){
			validacion = 1;
		}
	}
	return validacion;
}



void mostrarServicio(eServicio servicio){
// recibe 1 solo vector por cada llamado
	printf("|%-5d           %10s      $%.2f|\n",
			servicio.id,
			servicio.descripcion,
			servicio.precio);
}


int listarServicios(eServicio servicio[], int tam){

	int control = 0;
    if( servicio != NULL && tam > 0 )
    {
    	system("cls");
    	printf(" ** Listado de servicios disponibles ** \n");
    	printf("------------------------------------------\n");
    	printf("   Codigo       Descripcion       Precio \n");
    	printf("------------------------------------------\n");

    	for(int i = 0; i < tam; i++){
    		mostrarServicio(servicio[i]);
    	}
        printf("__________________________________________\n\n");

    	control = 1;
//    	system("pause");
    }
    return control;
}


int cargarServDescrip(eServicio vec[], int tam, int id, char descrip[], float* pPrecio){

	int control = 0;
	if( vec != NULL && tam > 0 && descrip != NULL && pPrecio != NULL){

		for(int i= 0; i < tam; i++){
			if( vec[i].id == id){
				strcpy( descrip, vec[i].descripcion);
				*pPrecio = vec[i].precio;
				control = 1;
				break;
			}
		}
	}
    return control;
}
