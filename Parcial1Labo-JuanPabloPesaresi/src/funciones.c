/*
 * funciones.c
 *
 *  Created on: 13 may. 2021
 *      Author: Juan
 */
#include "funciones.h"
#include "inputs.h"
#define EMPTY 0
#define OCUPADO 1

int idIncremental=20000;
int ObtenerId()
{
	return idIncremental += 1;
}
int Buscarid(eTrabajos lista[],int tam)
{
	int idIngresada;
	int index=-1;
	int i;

	idIngresada=GetInt("Ingrese el ID que desee:");

	for(i=0;i<tam;i++)
	{
		if(idIngresada == lista[i].idIncremental)
		{
			index = i;
			break;
		}
	}
return index;
}
int Entrada(eTrabajos trabajos[],int tam)
{
    int index;
    int i;

    index=-1;

    for(i=0;i<tam;i++)
    {
        if(trabajos[i].isEmpty!=EMPTY)
        {
            index=1;
            break;
        }
    }
    return index;
}
void InicializarTrabajo(eTrabajos parametro[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        parametro[i].isEmpty = EMPTY;
    }
}
int CargarTrabajo(eTrabajos lista[], int tam,eServicios servicios[],int tServicios)
{
    int index;
    index = BuscarLibre(lista, tam);
    if(index==-1)
    {
       printf("No hay mas espacio en la fabrica");

    }else
    {
    	lista[index]=PedirDatosTrabajador(servicios,tam);
    }

    return 0;
}
eTrabajos PedirDatosTrabajador(eServicios servicios[],int tam)
{
	eTrabajos miTrabajo;

	miTrabajo.idIncremental=ObtenerId();
    GetString("Ingrese la marca de la bici: ",miTrabajo.marcaBici);
    miTrabajo.rodadoBici=GetInt("Ingrese el rodado de la bici: ");
    MostrarServicios(servicios,tam);
    miTrabajo.idServicio=GetInt("Ingrese el servicio que quiera mediante el ID:");
    miTrabajo.fecha.dia=GetInt("Ingrese el dia: ");
    while(miTrabajo.fecha.dia>31 || miTrabajo.fecha.dia<1)
    {
    	miTrabajo.fecha.dia=GetInt("ERROR.Ingrese el dia: ");
    }
    miTrabajo.fecha.mes=GetInt("Ingrese mes: ");
    while(miTrabajo.fecha.mes>12 || miTrabajo.fecha.mes<1)
    {
    	miTrabajo.fecha.mes=GetInt("ERROR.Ingrese mes: ");
    }
    miTrabajo.fecha.anio=GetInt("Ingrese el año: ");

    printf("\nTrabajo registrado con exito!!\n\n");

    miTrabajo.isEmpty=OCUPADO;

    return miTrabajo;
}
int BuscarLibre(eTrabajos lista[], int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==EMPTY)
        {
            index = i;
            break;
        }
    }
    return index;
}
void HardcodearServicios(eServicios servicios[],int tam)
{
	int i;
	int id[]={20000,20001,20002};
	char descripcion[][25]={"Limpieza","Parche","Centrado","Cadena"};
	float precio[]={250,300,400,350};

	for(i=0;i<tam;i++)
		{
			servicios[i].idIncremental=id[i];
			strcpy(servicios[i].descripcion,descripcion[i]);
			servicios[i].precio=precio[i];

		}

}
void MostrarServicios(eServicios servicios[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		printf("ID:%d--%s--$%f\n", servicios[i].idIncremental,servicios[i].descripcion,servicios[i].precio);

	}

}
void ModificarTrabajo(eTrabajos lista[], int index,eServicios servicios[],int tam)
{
	int menu;

	printf("1.MODIFICAR MARCA\n");
	printf("2.MODIFICAR SERVICIO \n");

	menu=GetInt("Ingrese una opcion:");
	switch(menu)
	{
	case 1:
		GetString("Ingrese el nuevo nombre: ",lista[index].marcaBici);
		printf("Trabajo modificado con exito!\n");
	break;
	case 2:
		MostrarServicios(servicios,tam);
		lista[index].idServicio=GetInt("Ingrese el nuevo servicio: ");
	   printf("Trabajo modificado con exito!\n");
	break;
	}

}
void EditarTrabajo(eTrabajos lista[],int tam,eServicios servicios[])
{
	int index;
	index=Buscarid(lista,tam);

	if(index==-1)
	{
		printf("ERROR , no se encontro el id que usted ingreso\n");
	}
	else
	{
		ModificarTrabajo(lista,index,servicios,tam);
	}
}
void MostrarTrabajo(eTrabajos Trabajo)
{
     printf("ID -%d- Marca -%s- Rodado -%d- Servicio -%d- Dia-%d \n",
    		 Trabajo.idIncremental,
			 Trabajo.marcaBici,
			 Trabajo.rodadoBici,
			 Trabajo.idServicio,
			 Trabajo.fecha
                                   	   	   	   	   	   	   	   );
}
void ListadoDeTrabajo(eTrabajos lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
        	MostrarTrabajo(lista[i]);
        }

    }
}
int BajaTrabajo(eTrabajos lista[], int tam)
{
	int index;
	index=Buscarid(lista,tam);

	if(index==-1)
	{
		printf("No se encontro el ID ingresado!\n");
	}
	else
	{
			lista[index].isEmpty = EMPTY;
			printf("Se dio de baja al trabajo con exito\n");
	}

return 0;
}
void OrdenarTrabajosPorAnio(eFecha lista[],int tam)
{
	int i;
		 int j;

		 eFecha auxiliaranio;

		  for(i=0; i<tam-1; i++)
		   {
		       for(j=i+1; j<tam; j++)
		       {
		           if(lista[i].anio>lista[j].anio)
		           {
		        	   auxiliaranio = lista[i];
		                lista[i] = lista[j];
		                lista[j] = auxiliaranio;;
		           }
		       }
		   }
}
float SumarDePrecioServicios(eTrabajos trabajos[],int tTrabajos,eServicios servicios[],int tServicios)
{
	int i;
	int j;
	float suma;


	for(i=0;i<tTrabajos;i++)
	{
		for(j=0;j<tServicios;j++)
		{
			if(trabajos[i].idServicio==servicios[j].idIncremental)
			{
				suma+=servicios[j].precio;
			}

		}

	}

	return suma;
}
