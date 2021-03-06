// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Auto.h"
#include "Menu.h"


int inicializarTrabajo(eTrabajo vec[], int tam){
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

int buscarIndiceLibreTrabajo(eTrabajo trabajos[], int tam, int* pIndice){

    int control = 0;
    if( trabajos != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(trabajos[i].isEmpty) // busca en el array de estructuras algun indice libre
            {
                *pIndice = i;
                break;
            }
        }
        control = 1;
    }
    return control;
}


int buscarTrabajo(eTrabajo vec[], int tam, int id, int* pIndice){

    int control = 0;

    if( vec != NULL && pIndice != NULL && tam > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id)
            {
                *pIndice = i;
                control = 1;
                break;
            }
        }
    }
    return control;
}


//H. ALTA TRABAJO: Se dar? de alta cada ocurrencia de trabajo pidi?ndole al usuario que elija un auto y un Servicio
int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA,
				eServicio servicios[], int tamS, eMarca marcas[], int tamM,
				eColor colores[], int tamC, int* pProximoId ){

	int control = 0;
    int indice;
    char idAutoAux[8];
    int idServicioAux;
    eFecha fechaAux;

    eTrabajo nuevoTrabajo;

    if( trabajos != NULL && autos != NULL && servicios != NULL
    		&& tamT > 0 && tamA > 0 && tamS > 0 && pProximoId != NULL)
    {
        system("cls");
        printf("    *** Alta de nuevo trabajo ***\n\n");
        buscarIndiceLibreTrabajo(trabajos, tamT, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        	listarAutos(autos, tamA, marcas, tamM, colores, tamC);
            printf("Ingrese el ID del auto: \n");
            fflush(stdin);
            gets(idAutoAux);
            strupr(idAutoAux);
            while( !validarAuto(autos, tamA, idAutoAux) )
            {
                printf("Id invalido. Reingrese ID del auto: \n");
                gets(idAutoAux);
                strupr(idAutoAux);
            }
            strcpy(nuevoTrabajo.idAuto, idAutoAux);


            listarServicios(servicios, tamS);
            printf("Ingrese el ID del servicio: \n\n");
            fflush(stdin);
            scanf("%d",&idServicioAux);
            while ( !validarServicio(servicios, tamS, idServicioAux))
            {
                printf("Id invalido. Reingrese ID del servicio: \n");
                scanf("%d",&idServicioAux);
            }
            nuevoTrabajo.idServicio = idServicioAux;


            printf("Ingrese fecha de realizacion del trabajo dd/mm/aaaa: ");
            scanf("%d/%d/%d",
                  &fechaAux.dia,
                  &fechaAux.mes,
                  &fechaAux.anio);
            nuevoTrabajo.fechaServicio = fechaAux;

            // si todos los pasos anteriores estan ok
            nuevoTrabajo.isEmpty = 0;
            nuevoTrabajo.id = *pProximoId;
            trabajos[indice] = nuevoTrabajo;
            (*pProximoId)++;
            control = 1;

            printf("\nAlta de trabajo realizado correctamente \n\n");
            system("pause");
        }
    }
    return control;

}


void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS){
// recibe 1 solo vector por cada llamado

	char descripServ[25];
	float precioServ;

	cargarServDescrip(servicios, tamS, trabajo.idServicio, descripServ, &precioServ);


	printf("%2d        %-7s           %02d/%02d/%4d      %10s     $%.2f \n",
			trabajo.id,
			trabajo.idAuto,
			trabajo.fechaServicio.dia,
			trabajo.fechaServicio.mes,
			trabajo.fechaServicio.anio,
			descripServ,
			precioServ
		);
}

int listarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

	int control = 0;
	int flagEmpty = 1;

    if( trabajos != NULL && tamT > 0 && servicios != NULL && tamS > 0 )
    {
    	system("cls");
    	printf(" 		** Listado de trabajos registrados ** \n");
    	printf("-------------------------------------------------------------------\n");
    	printf(" id    Auto (patente)     Fecha Trabajo       Servicio     Precio \n");
    	printf("-------------------------------------------------------------------\n");
//    	printf("%2d          %8s       %02d/%02d/%4d              %10s       %.2f \n",

        for(int i=0; i < tamT; i++)
        {
            if( !trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], servicios, tamS);
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay trabajos registrados en el sistema\n");
        }
        printf("_____________________________________________________________________\n");
    	control = 1;
//    	system("pause");
    }
    return control;
}


int modificarTrabajo(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS,
					eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

	int control = 0;
    int indice;

    int idTrabajoAux;
    char idAutoAux[8];  // para buscar y validar
    int idServAux; 	   // para buscar y validar
    eFecha fechaAux;

//    eAuto autoAux;

    if( trabajos != NULL && servicios != NULL && autos != NULL && tamT > 0 && tamS > 0 && tamA > 0
    		&& marcas != NULL && tamM > 0 && colores != NULL && tamC > 0)
    {
        system("cls");
        printf("    *** Modificar trabajo *** \n\n");
        listarTrabajos(trabajos, tamT, servicios, tamS);
        printf("\n\n");

        printf("Ingrese id del trabajo \n");
        fflush(stdin);
        scanf("%d", &idTrabajoAux);

        if( buscarTrabajo(trabajos, tamT, idTrabajoAux, &indice) )
        {
            if(indice == -1)
            {
                printf("Trabajo no encontrado en el sistema \n");
            }
            else
            {
            	system("cls");
            	printf(" id    Auto (patente)     Fecha Trabajo       Servicio     Precio \n");
            	printf("----------------------------------------------------------------- \n");
                mostrarTrabajo(trabajos[indice], servicios, tamS);
            	printf("----------------------------------------------------------------- \n");

                switch ( menuModifTrabajo() ){

                case 1:
                	listarAutos(autos, tamA, marcas, tamM, colores, tamC);
                	printf("Fabricante del auto: (ingrese el codigo que corresponda)\n");
                    gets(idAutoAux);
                    strupr(idAutoAux);
                	while( !validarAuto(autos, tamA, idAutoAux) )
                	{
                		printf("Id invalido. Reingrese id auto: \n");
                        gets(idAutoAux);
                        strupr(idAutoAux);
                	}
                	strcpy(trabajos[indice].idAuto, idAutoAux);
                	printf("Trabajo modificado correctamente");
                	break;

                case 2:
                	listarServicios(servicios, tamS);
                	printf("Id Servicio: (ingrese el codigo que corresponda)\n");
                	scanf("%d", &idServAux);
                	while( !validarServicio(servicios, tamS, idServAux))
                	{
                		printf("Id invalido. Reingrese id servicio: \n");
                		scanf("%d", &idServAux);
                	}
                	trabajos[indice].idServicio = idServAux;
                	printf("Trabajo modificado correctamente");
                	break;


                case 3:
                    printf("Ingrese fecha de realizacion del trabajo dd/mm/aaaa: ");
                    scanf("%d/%d/%d",
                          &fechaAux.dia,
                          &fechaAux.mes,
                          &fechaAux.anio);;
                    trabajos[indice].fechaServicio = fechaAux;
                    printf("Trabajo modificado correctamente");
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


int ordenarTrabajosPorServicio(eTrabajo vec[], int tam){

    int control = 0;
    eTrabajo vecAux;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if( (vec[i].idServicio < vec[j].idServicio) )
                {
                	vecAux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = vecAux;
                }
            }
        }
        printf("\nOrdenamiento efectuado correctamente\n\n");
        control = 1;
    }
    return control;
}


int ordenarTrabajosPorFecha(eTrabajo vec[], int tam){

    int control = 0;
    eTrabajo vecAux;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if( vec[i].fechaServicio.anio > vec[j].fechaServicio.anio
                		|| vec[i].fechaServicio.mes > vec[j].fechaServicio.mes
						|| vec[i].fechaServicio.dia > vec[j].fechaServicio.dia
					)
                {
                	vecAux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = vecAux;
                }
            }
        }
        printf("\nOrdenamiento efectuado correctamente\n\n");
        control = 1;
    }
    return control;
}


int listarTrabajosPorIdAuto(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA,
		eServicio servicios[], int tamS, eMarca marcas[], int tamM,
		eColor colores[], int tamC){

	int control = 0;
	int flagEmpty = 1;
	char autoId[8];

    if( trabajos != NULL && tamT > 0 && servicios != NULL && tamS > 0
    		&& autos != NULL && tamA > 0 && marcas != NULL && tamM > 0)
    {
    	system("cls");
       	listarAutos(autos, tamA, marcas, tamM, colores, tamC);
        printf("Ingrese id de auto para buscar en registros de trabajos realizados)\n");
        fflush(stdin);
        gets(autoId);
        while( !validarAuto(autos, tamA, autoId) )
        {
            printf("Id invalido. Reintente nuevamente: \n");
            fflush(stdin);
            gets(autoId);
        }


    	system("cls");
    	printf(" 		** Listado de trabajos registrados ** \n");
    	printf("-------------------------------------------------------------------\n");
    	printf(" id    Auto (patente)     Fecha Trabajo       Servicio     Precio \n");
    	printf("-------------------------------------------------------------------\n");
//    	printf("%2d          %8s       %02d/%02d/%4d              %10s       %.2f \n",

        for(int i=0; i < tamT; i++)
        {
            if( !trabajos[i].isEmpty && ( strcmp(trabajos[i].idAuto, autoId) == 0))
            {
                mostrarTrabajo(trabajos[i], servicios, tamS);
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay trabajos registrados en el sistema\n");
        }
        printf("_____________________________________________________________________\n");
    	control = 1;
//    	system("pause");
    }
    return control;
}



int listarTrabajosPorFechaExacta(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

	int control = 0;
	int flagEmpty = 1;

	eFecha trabajoFecha;

    if( trabajos != NULL && tamT > 0 && servicios != NULL && tamS > 0 )
    {
    	system("cls");
        printf("Ingrese fecha para buscar trabajos dd/mm/aaaa: ");
        scanf("%d/%d/%d",
              &trabajoFecha.dia,
              &trabajoFecha.mes,
              &trabajoFecha.anio);

    	system("cls");
    	printf(" 		** Listado de trabajos registrados ** \n");
    	printf("-------------------------------------------------------------------\n");
    	printf(" id    Auto (patente)     Fecha Trabajo       Servicio     Precio \n");
    	printf("-------------------------------------------------------------------\n");

        for(int i=0; i < tamT; i++)
        {
            if( !trabajos[i].isEmpty
            		&& trabajos[i].fechaServicio.anio == trabajoFecha.anio
            		&& trabajos[i].fechaServicio.mes == trabajoFecha.mes
					&& trabajos[i].fechaServicio.dia == trabajoFecha.dia)
            {
                mostrarTrabajo(trabajos[i], servicios, tamS);
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay trabajos registrados en el sistema\n");
        }
        printf("_____________________________________________________________________\n");
    	control = 1;
//    	system("pause");

    }
    return control;
}
