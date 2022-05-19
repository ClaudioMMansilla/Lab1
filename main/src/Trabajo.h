#include <stdio.h>
#include <stdlib.h>
#include "Auto.h"
#include "Servicio.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{

	int id;//auto incr
	char idAuto[8];
	int idServicio;
	eFecha fechaServicio;
	int isEmpty;

}eTrabajo;

#endif /* TRABAJO_H_ */

int inicializarTrabajo(eTrabajo vec[], int tam);

int buscarIndiceLibreTrabajo(eTrabajo trabajos[], int tam, int* pIndice);

int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA,
				eServicio servicios[], int tamS, eMarca marcas[], int tamM,
				eColor colores[], int tamC, int* pProximoId );


void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS);

int listarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);

int buscarTrabajo(eTrabajo vec[], int tam, int id, int* pIndice);

int modificarTrabajo(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS,
					eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int ordenarTrabajosPorServicio(eTrabajo vec[], int tam);

int ordenarTrabajosPorFecha(eTrabajo vec[], int tam);

int listarTrabajosPorIdAuto(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA,
		eServicio servicios[], int tamS, eMarca marcas[], int tamM,
		eColor colores[], int tamC);

int listarTrabajosPorFechaExacta(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);


