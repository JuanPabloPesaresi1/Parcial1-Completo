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
#include "trabajos.h"
#include "servicios.h"
#include "Bicicleta.h"


int ObtenerId();
int CargarTrabajo(eTrabajos[],int,eServicios[],int,eBicicleta[],int);
eTrabajos PedirDatosTrabajador(eServicios[],int,eBicicleta[],int);
void ModificarTrabajo(eTrabajos [],int,eServicios[],int,eBicicleta[]);
void EditarTrabajo(eTrabajos[],int,eServicios[],eBicicleta[]);
void ListadoDeTrabajo(eTrabajos[],int,eServicios[],int,eBicicleta[],int);
float SumarDePrecioServicios(eTrabajos[],int,eServicios [],int);
void MostrarServiciosNombre(eTrabajos[],int,eServicios[],int);
void OrdenarTrabajosPorAnio(eTrabajos[],int,eBicicleta [],int);
void OrdenarPorMarca(eTrabajos [],int,eBicicleta [],int);
void MostrarTodo(eTrabajos [],int,eServicios[],int,eBicicleta[],int);
void MostrarTrabajosMarca(eTrabajos[],int,eBicicleta[],int);
void TrabajosMarca(eTrabajos[],int,eBicicleta[],int);
void ServiciosMasPedidos(eTrabajos[],int,eServicios[]);
int ContadorDeRojos(eTrabajos[],int,eBicicleta[],int);
#endif /* FUNCIONES_H_ */
