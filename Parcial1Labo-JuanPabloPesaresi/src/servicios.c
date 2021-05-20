/*
 * servicios.c
 *
 *  Created on: 20 may. 2021
 *      Author: Juan
 */

#include "servicios.h"

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
