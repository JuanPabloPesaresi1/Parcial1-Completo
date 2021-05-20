/*
 * trabajos.c
 *
 *  Created on: 20 may. 2021
 *      Author: Juan
 */
#include "trabajos.h"


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
void MostrarTrabajo(eTrabajos Trabajo)
{
     printf("ID -%d- Dia-%d- Mes -%d- Anio -%d- ",
    		 Trabajo.idIncremental,

			 Trabajo.fecha.dia,
			 Trabajo.fecha.mes,
			 Trabajo.fecha.anio
                                   	   	   	   	   	   	   	   );
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
