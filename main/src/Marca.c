// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Marca.h"


void mostrarMarca(eMarca marca){
	// recibe 1 solo vector por cada llamado
	printf("|%d            %10s| \n", marca.id, marca.descripcion);
}


int listarMarcas(eMarca vec[], int tam){

	int control = 0;
    if( vec != NULL && tam > 0 )
    {
    	system("cls");
    	printf(" ** Listado de marcas disponibles ** \n");
    	printf("--------------------------------------\n");
    	printf("   Codigo       Descripcion     \n");
    	printf("--------------------------------------\n");

    	for(int i = 0; i < tam; i++){
    		mostrarMarca(vec[i]);
    	}

        printf("______________________________________\n\n");

    	control = 1;
//    	system("pause");
    }
    return control;
}


int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice){

    int control = 0;
    if( marcas != NULL && pIndice != NULL && tam > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(marcas[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        control = 1;
    }
    return control;
}


int validarMarca(eMarca vec[], int tam, int id){
	int validacion = 0;
	int indice;

	if (buscarMarca(vec, tam, id, &indice) ){
		if(indice != -1){
			validacion = 1;
		}
	}
	return validacion;
}


int cargarMarcaDescripcion(eMarca vec[], int tam, int id, char descrip[]){

    int control = 0;
    if(vec != NULL && tam > 0 && descrip != NULL){

         for(int i= 0; i < tam; i++){

            if( vec[i].id == id){
                strcpy( descrip, vec[i].descripcion);
                control = 1;
                break;
            }
         }
    }
    return control;
}
