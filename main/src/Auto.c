// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include <string.h>

#include "Marca.h"
#include "Color.h"
#include "Auto.h"
#include "Menu.h"


int ordenarAutosMarcaCaja(eAuto vec[], int tam){
    int control = 0;
    eAuto vecAux;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if( (vec[i].idMarca == vec[j].idMarca && vec[i].caja > vec[j].caja)
                	||
					(vec[i].idMarca > vec[j].idMarca))
                {
                	vecAux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = vecAux;
                }
            }
        }

        control = 1;
    }
    return control;
}


int inicializarAutos(eAuto vec[], int tam){
    int control = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
        	vec[i].isEmpty = 1;
        }
        control = 1;
    }
    return control;
}


void mostrarAuto(eAuto a, eMarca marcas[], int tamM, eColor colores[], int tamC){
// recibe 1 solo vector por cada llamado

	char descrip[tamM];
	char color[tamC];

	cargarMarcaDescripcion(marcas, tamM, a.idMarca, descrip);
	cargarNombreColor(colores, tamC, a.idColor, color);


	printf("%-7s            %c       %9s       %6s \n",
			a.id,
			a.caja,
			descrip,
			color
		);
}

int listarAutos(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

	int control = 0;
	int flagEmpty = 1;

    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
    	system("cls");
    	printf(" ** Listado de vehiculos registrados ** \n");
    	printf("--------------------------------------------------\n");
    	printf("id (patente)   Tipo Caja       Marca        Color \n");
    	printf("--------------------------------------------------\n");

        for(int i=0; i < tamA; i++)
        {
            if( !autos[i].isEmpty)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay vehiculos registrados en el sistema\n");
        }

        printf("__________________________________________________\n\n");
    	control = 1;
//    	system("pause");
    }
    return control;
}


int buscarIndiceLibreAuto(eAuto autos[], int tam, int* pIndice){

    int control = 0;
    if( autos != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(autos[i].isEmpty) // busca en el array de estructuras algun indice libre
            {
                *pIndice = i;
                break;
            }
        }
        control = 1;
    }
    return control;
}



int buscarAuto(eAuto vec[], int tam, char id[], int* pIndice){

    int control = 0;

    if( vec != NULL && pIndice != NULL && tam > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty && strcmp(vec[i].id, id) == 0)
            {
                *pIndice = i;
                control = 1;
                break;
            }
        }
    }
    return control;
}


int validarAuto(eAuto vec[], int tam, char id[]){
	int validacion = 0;
	int indice;

	if (buscarAuto(vec, tam, id, &indice) ){
		if(indice != -1){
			validacion = 1;
		}
	}
	return validacion;
}


int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){
    int control = 0;
    int indice;
    int idMarcaAux;  // sector para buscar y validar
    int idColorAux; // sector para buscar y validar

    eAuto nuevoAuto;

    if( autos != NULL && marcas != NULL && colores != NULL && tamA > 0 && tamM > 0 && tamC > 0)
    {
        system("cls");
        printf("    *** Alta de nuevo auto ***\n\n");
        buscarIndiceLibreAuto(autos, tamA, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese el dominio/patente (SIN ESPACIOS) \n");
            fflush(stdin);
            gets(nuevoAuto.id);
            strupr(nuevoAuto.id);

            printf("Ingrese tipo de transmision: M (manual) - A (automatica)\n");
            fflush(stdin);
            scanf("%c", &nuevoAuto.caja);
            nuevoAuto.caja = tolower(nuevoAuto.caja);

            listarMarcas(marcas, tamM);
            printf("Fabricante del auto: (ingrese el codigo que corresponda)\n");
            fflush(stdin);
            scanf("%d", &idMarcaAux);
            while( !validarMarca(marcas,tamM, idMarcaAux) )
            {
                printf("Id invalido. Reingrese id marca: \n");
                scanf("%d", &idMarcaAux);
            }
            nuevoAuto.idMarca = idMarcaAux;


           	listarColores(colores, tamC);
            printf("Color del auto: (ingrese el codigo que corresponda)\n");
            scanf("%d", &idColorAux);
            while( !validarColor(colores,tamC, idColorAux) )
            {
                printf("Id invalido. Reingrese id color: \n");
                scanf("%d", &idColorAux);
            }
            nuevoAuto.idColor = idColorAux;

            // si todos los pasos anteriores estan ok
            nuevoAuto.isEmpty = 0;

            autos[indice] = nuevoAuto;
            //(*pProximoId)++;
            control = 1;

            printf("\nAlta de vehiculo realizada correctamente \n\n");
            system("pause");
        }
    }
    return control;
}


int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){
    int control = 0;
    int indice;

    char idAux[8];    // para buscar y validar
    int idMarcaAux;  // para buscar y validar
    int idColorAux; // para buscar y validar

//    eAuto autoAux;

    if( autos != NULL && marcas != NULL && colores != NULL && tamA > 0 && tamM > 0 && tamC > 0)
    {
        system("cls");
        printf("    *** Modificar auto *** \n\n");
        listarAutos(autos, tamA, marcas, tamM, colores, tamC);
        printf("\n\n");

        printf("Ingrese el dominio/patente (SIN ESPACIOS) \n");
        fflush(stdin);
        gets(idAux);
        strupr(idAux);

        if( buscarAuto(autos, tamA, idAux, &indice) )
        {
            if(indice == -1)
            {
                printf("Dominio/Patente no encontrado en el sistema \n");
            }
            else
            {
            	system("cls");
            	printf("\nid (patente)   Tipo Caja       Marca        Color \n");
            	printf("-------------------------------------------------- \n");
                mostrarAuto(autos[indice], marcas, tamM, colores, tamC);
            	printf("-------------------------------------------------- \n");

                switch( menuModifAuto() ){

                case 1:
                	listarMarcas(marcas, tamM);
                	printf("Fabricante del auto: (ingrese el codigo que corresponda)\n");
                	fflush(stdin);
                	scanf("%d", &idMarcaAux);
                	while( !validarMarca(marcas,tamM, idMarcaAux) )
                	{
                		printf("Id invalido. Reingrese id marca: \n");
                		scanf("%d", &idMarcaAux);
                	}
                	autos[indice].idMarca = idMarcaAux;
                	printf("Marca modificada correctamente");
                	break;

                case 2:
                	listarColores(colores, tamC);
                	printf("Color del auto: (ingrese el codigo que corresponda)\n");
                	scanf("%d", &idColorAux);
                	while( !validarColor(colores,tamC, idColorAux) )
                	{
                		printf("Id invalido. Reingrese id color: \n");
                		scanf("%d", &idColorAux);
                	}

                	autos[indice].idColor = idColorAux;
                	printf("Color modificado correctamente");
                	break;

                default:
                	printf("La opcion ingresada es incorrecta, reintente nuevamente\n");
                	break;
                }
            }
         control = 1;
        }
        else
        {
        	printf("Se ha producido un error, reintente nuevamente \n");
        }

        system("pause");
    }
    return control;
}


int bajaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int control = 0;
    int indice;
    char idAux[8];    // para buscar y validar
    char salir;

    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        listarAutos(autos, tamA, marcas, tamM, colores, tamC);
        printf("Ingrese el dominio/patente (SIN ESPACIOS) \n");
        fflush(stdin);
        gets(idAux);
        strupr(idAux);

        if( buscarAuto(autos, tamA, idAux, &indice) )
        {
            if(indice == -1)
            {
            	printf("Dominio/Patente no encontrado en el sistema \n");
            }
            else
            {
            	system("cls");
            	printf("\nid (patente)   Tipo Caja       Marca        Color \n");
            	printf("-------------------------------------------------- \n");
                mostrarAuto(autos[indice], marcas, tamM, colores, tamC);
            	printf("-------------------------------------------------- \n");
                printf("Confirma baja?: (s / n)\n");
                fflush(stdin);
                scanf("%c", &salir);

                if(salir == 's' || salir == 'S')
                {
                    autos[indice].isEmpty = 1;
                    printf("Baja realizada correctamente\n");
                }
                else
                {
                    printf("Baja no realizada, cancelada por el usuario\n");
                }
            }
            control = 1;
        }
        else
        {
        	printf("Se ha producido un error, reintente nuevamente \n");
        }

        system("pause");
    }
    return control;
}



int buscarAutoColor(eAuto autos[], int tamA, eColor color[], int tamC, int id, int* pIndice){

    int control = 0;

    if( autos != NULL && tamA > 0 && autos != NULL && tamA > 0 && pIndice != NULL ){

        *pIndice = -1;

        for(int i=0; i < tamA; i++)
        {
            if(!autos[i].isEmpty && autos[i].idColor == id){
                *pIndice = i;
                control = 1;
                break;
            }
        }
    }
    return control;
}


int listarAutosIdColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

	int control = 0;
	int flagEmpty = 1;
	int autoColor;

    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
    	system("cls");
       	listarColores(colores, tamC);
        printf("Color del auto: (ingrese el codigo que corresponda)\n");
        scanf("%d", &autoColor);
        while( !validarColor(colores,tamC, autoColor) )
        {
            printf("Id invalido. Reingrese id color: \n");
            scanf("%d", &autoColor);
        }


    	system("cls");
    	printf(" ** Listado de vehiculos registrados ** \n");
    	printf("--------------------------------------------------\n");
    	printf("id (patente)   Tipo Caja       Marca        Color \n");
    	printf("--------------------------------------------------\n");

        for(int i=0; i < tamA; i++)
        {
            if( !autos[i].isEmpty && autos[i].idColor == autoColor)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay vehiculos registrados en el sistema\n");
        }

        printf("__________________________________________________\n\n");
    	control = 1;
//    	system("pause");
    }
    return control;
}


int listarAutosIdMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

	int control = 0;
	int flagEmpty = 1;
	int autoMarca;

    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
    	system("cls");
       	listarMarcas(marcas, tamM);
        printf("Fabricante: (ingrese el codigo que corresponda)\n");
        scanf("%d", &autoMarca);
        while( !validarMarca(marcas, tamM, autoMarca) )
        {
            printf("Id invalido. Reintente nuevamente: \n");
            scanf("%d", &autoMarca);
        }


    	system("cls");
    	printf(" ** Listado de vehiculos registrados ** \n");
    	printf("--------------------------------------------------\n");
    	printf("id (patente)   Tipo Caja       Marca        Color \n");
    	printf("--------------------------------------------------\n");

        for(int i=0; i < tamA; i++)
        {
            if( !autos[i].isEmpty && autos[i].idMarca == autoMarca)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay vehiculos registrados en el sistema\n");
        }

        printf("__________________________________________________\n\n");
    	control = 1;
//    	system("pause");
    }
    return control;
}
