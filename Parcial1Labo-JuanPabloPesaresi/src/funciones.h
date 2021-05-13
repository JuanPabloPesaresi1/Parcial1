/*
 * funciones.h
 *
 *  Created on: 13 may. 2021
 *      Author: Juan
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define EMPTY 0
#define OCUPADO 1
#include "Fecha.h"
#include "inputs.h"

typedef struct
{
	int idIncremental;
	char descripcion[25];
	float precio;

}eServicios;

typedef struct
{
	int idIncremental;
	char marcaBici[50];
	int rodadoBici;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajos;

int ObtenerId();
int CargarTrabajo(eTrabajos[],int,eServicios[],int);
eTrabajos PedirDatosTrabajador(eServicios[],int);
int BuscarLibre(eTrabajos[],int );
int Buscarid(eTrabajos[],int);
int Entrada(eTrabajos[],int);
void InicializarTrabajo(eTrabajos[], int);
void HardcodearServicios(eServicios[],int);
void MostrarServicios(eServicios [],int);
void ModificarTrabajo(eTrabajos [],int,eServicios[],int);
void EditarTrabajo(eTrabajos[],int,eServicios[]);
void MostrarTrabajo(eTrabajos Trabajo);
void ListadoDeTrabajo(eTrabajos[],int);
int BajaTrabajo(eTrabajos[], int);
void OrdenarTrabajosPorAnio(eFecha[],int);
float SumarDePrecioServicios(eTrabajos[],int,eServicios [],int);
//void OrdenarTrabajosPorAño(eTrabajos[],int);
#endif /* FUNCIONES_H_ */
