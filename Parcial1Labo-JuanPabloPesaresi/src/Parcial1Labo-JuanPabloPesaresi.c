/*
 ============================================================================
 Name        : Parcial1Labo-JuanPabloPesaresi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "inputs.h"
#define EMPTY 0
#define OCUPADO 1
#define T 3
#define S 3

int main(void)
{
	setbuf(stdout, NULL);
	eServicios servicios[S];
	eTrabajos listaDeTrabajos[T];
	int opcion;
	int TotalPrecio;
	int entrada;
	InicializarTrabajo(listaDeTrabajos,T);
	HardcodearServicios(servicios,S);


	printf("-------------Bienvenido!-------------\n");
	printf("Elija la opcion que desee:\n");

	do
	{
		printf("\n1. ALTA TRABAJO\n");
		printf("2.MODIFICAR TRABAJO\n");
		printf("3.BAJA TRABAJO\n");
		printf("4.LISTADO DE TRABAJO POR AÑO\n");
		printf("5.LISTADO DE SERVICIOS\n");
		printf("6.TOTAL PESOS DE LOS SERVICIOS\n");
		printf("7.CANCELAR");
		opcion=GetInt("\nIngrese una opcion:");

		switch(opcion)
		{
		case 1:
			CargarTrabajo(listaDeTrabajos,T, servicios,S);
			break;

		case 2:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				ListadoDeTrabajo(listaDeTrabajos, T);
				EditarTrabajo(listaDeTrabajos,T,servicios);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}
			break;
		case 3:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				ListadoDeTrabajo(listaDeTrabajos, T);
				BajaTrabajo(listaDeTrabajos,T);
			}else
			{
			printf("Error Ingrese primero la opcion 1");
			}
			break;
		case 4:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				OrdenarTrabajosPorAnio(listaDeTrabajos,T);
				ListadoDeTrabajo(listaDeTrabajos, T);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}

			break;
		case 5:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				MostrarServicios(servicios,S);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}

			break;
		case 6:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				TotalPrecio=SumarDePrecioServicios(listaDeTrabajos,T,servicios,S);
				printf("El precio total es $%d\n", TotalPrecio);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}

			break;
		}

	}while(opcion!=7);

}
