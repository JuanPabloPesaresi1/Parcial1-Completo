/*
 * trabajos.h
 *
 *  Created on: 20 may. 2021
 *      Author: Juan
 */

#ifndef TRABAJOS_H_
#define TRABAJOS_H_
#include "inputs.h"
#include "Fecha.h"
#include "Bicicleta.h"
#define EMPTY 0
#define OCUPADO 1

typedef struct
{
	int idIncremental;
	//char marcaBici[50];
	//int rodadoBici;
	int idServicio;
	int idBicicleta;
	eFecha fecha;
	int isEmpty;

}eTrabajos;

int BuscarLibre(eTrabajos[],int );
int Buscarid(eTrabajos[],int);
int Entrada(eTrabajos[],int);
void InicializarTrabajo(eTrabajos[], int);
void MostrarTrabajo(eTrabajos Trabajo);
int BajaTrabajo(eTrabajos[], int);

#endif /* TRABAJOS_H_ */
