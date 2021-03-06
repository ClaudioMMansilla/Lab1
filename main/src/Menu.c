#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Auto.h"
#include "Menu.h"


char menuPrincipal(){

    char opcion;

    system("cls");
    printf("     *** Lavadero: MENU DE OPCIONES ***\n\n");
    printf("A. ALTA AUTO\n");
    printf("B. MODIFICAR AUTO:\n");
    printf("C. BAJA AUTO:\n");
    printf("D. LISTAR AUTOS:\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO:\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("X. MENU DE INFORMES\n");
    printf("Y. OPCIONES DE ORDENAMIENTO DE DATOS\n");
    printf("\n");
    printf("Z. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;

}


int menuModifAuto(){

    int opcion;

    printf("\n     *** Campo a modificar *** \n");
    printf("1. Marca\n");
    printf("2. Color\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menuModifTrabajo(){

    int opcion;

    printf("\n     *** Campo a modificar *** \n");
    printf("1. Patente auto\n");
    printf("2. Servicio\n");
    printf("3. Fecha\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menuInformes(){

    int opcion;

    system("cls");
    printf("\n     *** Informes Varios *** \n");
    printf("1. Ingresos por tipo de servicio\n"); // informeIngresosPorServicio()
    printf("2. Listar autos por color\n"); // listarAutosIdColor()
    printf("3. Listar autos por marca\n"); // int listarAutosIdMarca()
    printf("4. Listar trabajos por auto\n");// listarTrabajosPorIdAuto()
    printf("5. Buscar trabajos por fecha\n");// listarTrabajosPorFechaExacta()
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menuOrdenamiento(){

    int opcion;

    system("cls");
    printf("\n     *** Menu de ordenamiento de datos *** \n");
    printf("1. Ordenar trabajos por tipo de servicio\n"); // ordenarTrabajosPorServicio(listaTrabajos, TAM_TRAB);
    printf("2. Ordenar trabajos por fecha\n"); // ordenarTrabajosPorFecha(listaTrabajos, TAM_TRAB);

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

