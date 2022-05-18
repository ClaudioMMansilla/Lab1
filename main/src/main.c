// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Auto.h"

#define TAM_AUT 10
#define TAM_LAV 10
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

	eTrabajo listaTrab[TAM_LAV];

	char opcion;
	int idInicialTrab = 0;

	eAuto hardAutos[5]= {
			{"AA420AR", 1000, 5000, 'm', 0},
			{"LQR085", 1001, 5001, 'a', 0},
			{"MYP499", 1002, 5002, 'm', 0},
			{"KSX685", 1003, 5003, 'a', 0},
			{"CFK666", 1004, 5004, 'a', 0}
	};
	for(int i=0; i<5; i++){
		listaAutos[i] = hardAutos[i];
	}

	do
	{
		switch(menuPrincipal()){

		case 'A':
			altaAuto(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
			system("pause");
			break;

		case 'B':
			modificarAuto(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
			system("pause");
			break;

		case 'C':
			bajaAuto(listaAutos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL);
			system("pause");
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

		case 'Z':
			opcion = 's';
			break;


		}

	} while (opcion != 's');


	return EXIT_SUCCESS;
}