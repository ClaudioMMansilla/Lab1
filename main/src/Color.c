// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Color.h"

void mostrarColor(eColor color){
// recibe 1 solo vector por cada llamado
	printf("|%d            %10s| \n", color.id, color.nombreColor);
}

int listarColores(eColor vec[], int tam){

	int control = 0;
    if( vec != NULL && tam > 0 )
    {
    	system("cls");
    	printf(" ** Listado de colores disponibles ** \n");
    	printf("--------------------------------------\n");
    	printf("   Codigo       Descripcion     \n");
    	printf("--------------------------------------\n");

    	for(int i = 0; i < tam; i++){
    		mostrarColor(vec[i]);
    	}
        printf("______________________________________\n\n");

    	control = 1;
//    	system("pause");
    }
    return control;
}




int buscarColor(eColor colores[], int tam, int id, int* pIndice){

    int control = 0;
    if( colores != NULL && pIndice != NULL && tam > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(colores[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        control = 1;
    }
    return control;
}


int validarColor(eColor vec[], int tam, int id){
	int validacion = 0;
	int indice;

	if (buscarColor(vec, tam, id, &indice) ){
		if(indice != -1){
			validacion = 1;
		}
	}
	return validacion;
}


int cargarNombreColor(eColor vec[], int tam, int id, char descrip[]){

    int control = 0;
    if(vec != NULL && tam > 0 && descrip != NULL){

         for(int i= 0; i < tam; i++){

            if( vec[i].id == id){
                strcpy( descrip, vec[i].nombreColor);
                control = 1;
                break;
            }
         }
    }
    return control;
}
