/*
 * servicios.h
 *
 *  Created on: 20 may. 2021
 *      Author: Juan
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_
#include "inputs.h"
#define EMPTY 0
#define OCUPADO 1


typedef struct
{
	int idIncremental;
	char descripcion[25];
	float precio;

}eServicios;

void HardcodearServicios(eServicios[],int);
void MostrarServicios(eServicios [],int);


#endif /* SERVICIOS_H_ */
