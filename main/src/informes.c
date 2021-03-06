#include <stdio.h>
#include <stdlib.h>

#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Auto.h"
#include "Menu.h"


int informeIngresosPorServicio(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

	int control = 0;

	int idBuscado;
    int contTrabajos = 0;
    float precio = 0;
    float importeTotal = 0;
    char descrip[25];

    listarServicios(servicios, tamS);
	printf("Id Servicio: (ingrese el codigo que corresponda)\n");
	scanf("%d", &idBuscado);
	while( !validarServicio(servicios, tamS, idBuscado))
	{
		printf("Id invalido. Reingrese id servicio: \n");
		scanf("%d", &idBuscado);
	}

    cargarServDescrip(servicios, tamS, idBuscado, descrip, &precio);

    if( trabajos != NULL && tamT > 0 && servicios != NULL && tamS > 0)
    {
    	for(int i=0; i < tamT; i++)
    	{
    		if( !trabajos[i].isEmpty && trabajos[i].idServicio == idBuscado)
    		{
    			contTrabajos++;

    			for(int j=0; j < tamS; j++){

    				if(servicios[j].precio == idBuscado){
    					precio = servicios[j].precio;
    				}
    			}
    		}
    	}

        if(contTrabajos > 0)
        {
        	importeTotal = contTrabajos * precio;
        }

        system("cls");
        printf("   *** Informe de saldos por %s ***\n\n", descrip);
        printf("Trabajos registrados: %d  || Ingresos $ %.2f\n\n", contTrabajos, importeTotal);
        printf("______________________________________________\n");
        control = 1;
    }
    return control;
}

