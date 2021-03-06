// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>

#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Auto.h"
#include "Menu.h"
#include "informes.h"

#define TAM_AUT 15
#define TAM_TRAB 10
#define TAM_MAR 5
#define TAM_COL 5
#define TAM_SERV 4

int main(void) {
	setbuf(stdout, NULL);

	eMarca marcas[TAM_MAR]={
			{1000, "Renault"},
			{1001, "Ford"},
			{1002, "Fiat"},
			{1003, "Chevrolet"},
			{1004, "Peugeot"}
	};

	eColor colores[TAM_COL]={
			{5000, "Negro"},
			{5001, "Blanco"},
			{5002, "Rojo"},
			{5003, "Verde"},
			{5004, "Azul"}
	};

	eServicio servicios[TAM_SERV]={
			{20000, "Lavado", 450},
			{20001, "Pulido", 500},
			{20002, "Encerado", 600},
			{20003, "Completo", 900}
	};
	// ---- fin datos hardcodeados ----

	eAuto listaAutos[TAM_AUT];
	inicializarAutos(listaAutos, TAM_AUT);

	eTrabajo listaTrabajos[TAM_TRAB];
	inicializarTrabajo(listaTrabajos, TAM_TRAB);

	char opcion;
	int idInicialTrab = 1;

	eAuto hardAutos[10]= {
			{"AA420AR", 1000, 5000, 'm', 0},
			{"LQR085", 1001, 5001, 'a', 0},
			{"MYP499", 1002, 5002, 'm', 0},
			{"KSX685", 1003, 5003, 'a', 0},
			{"AE388AR", 1000, 5004, 'a', 0},
			{"SZZ808", 1001, 5002, 'm', 0},
			{"GHL150", 1002, 5001, 'a', 0},
			{"AEA410", 1003, 5004, 'm', 0},
			{"JPE773", 1004, 5003, 'm', 0},
			{"QNA956", 1001, 5002, 'a', 0}
	};
	for(int i=0; i<10; i++){
		listaAutos[i] = hardAutos[i];
	}

	eTrabajo hardTrabajos[4]= {
			{1, "QNA956", 20000, {01,01,2023}, 0},
			{2, "JPE773", 20001, {02,02,2021}, 0},
			{3, "AEA410", 20002, {03,03,2024}, 0},
			{4, "JPE773", 20003, {04,04,2022}, 0}
	};
	for(int i=0; i<4; i++){
		listaTrabajos[i] = hardTrabajos[i];
	}
	// fin hardcodeo para testear codigo


	do
	{
		switch(menuPrincipal()){

		case 'A':
			altaAuto(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
			break;

		case 'B':
			modificarAuto(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
			break;

		case 'C':
			bajaAuto(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
			break;

		case 'D':
			listarAutos(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
			system("pause");
			break;

		case 'E':
			listarMarcas(marcas, TAM_MAR);
			system("pause");
			break;

		case 'F':
			listarColores(colores, TAM_COL);
			system("pause");
			break;

		case 'G':
			listarServicios(servicios, TAM_SERV);
			system("pause");
			break;

		case 'H':
			altaTrabajo(listaTrabajos, TAM_TRAB, listaAutos, TAM_AUT, servicios, TAM_SERV, marcas, TAM_MAR, colores, TAM_COL, &idInicialTrab);
			break;

		case 'I':
			listarTrabajos(listaTrabajos, TAM_TRAB, servicios, TAM_SERV);
			system("pause");
			break;

		case 'J': // para Testing

			//			modificarTrabajo(listaTrabajos, TAM_TRAB, servicios, TAM_SERV, listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);

			system("pause");
			break;

		case 'X':  //sub switch informes
			switch(menuInformes()){

			case 1:
				informeIngresosPorServicio(listaTrabajos, TAM_TRAB, servicios, TAM_SERV);
				system("pause");
				break;

			case 2:
				listarAutosIdColor(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
				system("pause");
				break;

			case 3:
				listarAutosIdMarca(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
				system("pause");
				break;

			case 4:
				listarTrabajosPorIdAuto(listaTrabajos, TAM_TRAB, listaAutos, TAM_AUT, servicios, TAM_SERV, marcas, TAM_MAR, colores, TAM_COL);
				system("pause");
				break;

			case 5:
				listarTrabajosPorFechaExacta(listaTrabajos, TAM_TRAB, servicios, TAM_SERV);
				system("pause");
				break;

			}
			break;

			case 'Y':  //sub switch ordenamiento
				switch(menuOrdenamiento()){

				case 1:
					ordenarTrabajosPorServicio(listaTrabajos, TAM_TRAB);
					system("pause");
					break;

				case 2:
					ordenarTrabajosPorFecha(listaTrabajos, TAM_TRAB);
					system("pause");
					break;

				}
				break;

				case 'Z':
					opcion = 's';
					break;
		}

	} while (opcion != 's');


	return EXIT_SUCCESS;
}
