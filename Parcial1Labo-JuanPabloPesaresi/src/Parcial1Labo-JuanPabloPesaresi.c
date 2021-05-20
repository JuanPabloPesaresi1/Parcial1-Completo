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
#define T 5
#define S 4
#define B 5

int main(void)
{
	setbuf(stdout, NULL);
	eServicios servicios[S];
	eTrabajos listaDeTrabajos[T];
	eBicicleta bicicleta[B];
	int opcion;
	int TotalPrecio;
	int entrada;
	int contadorRojo=0;
	InicializarTrabajo(listaDeTrabajos,T);
	HardcodearServicios(servicios,S);
	HardcodearBicis(bicicleta,B);

	printf("-------------Bienvenido!-------------\n");
	printf("Elija la opcion que desee:\n");

	do
	{
		printf("\n1.ALTA TRABAJO\n");
		printf("2.MODIFICAR TRABAJO\n");
		printf("3.BAJA TRABAJO\n");
		printf("4.LISTADO DE TRABAJO POR AÑO O POR MARCA\n");
		printf("5.LISTADO DE SERVICIOS\n");
		printf("6.TOTAL PESOS DE LOS SERVICIOS\n");
		printf("7.LISTADO SERVICIOS ORDENADOS POR MARCA\n");
		printf("8.SERVICIO MAS USADO\n");
		printf("9.NO FUNCIONA");
		printf("10.CANTIDAD DE BICIS DE COLOR ROJO");
		printf("11.CANCELAR");
		opcion=GetInt("\nIngrese una opcion:");

		switch(opcion)
		{
		case 1:
			CargarTrabajo(listaDeTrabajos,T, servicios,S,bicicleta,B);
			break;

		case 2:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				ListadoDeTrabajo(listaDeTrabajos, T,servicios,S,bicicleta,B);
				EditarTrabajo(listaDeTrabajos,T,servicios,bicicleta);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}
			break;
		case 3:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				ListadoDeTrabajo(listaDeTrabajos, T,servicios,S,bicicleta,B);
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
				OrdenarTrabajosPorAnio(listaDeTrabajos,T,bicicleta,B);
				ListadoDeTrabajo(listaDeTrabajos, T,servicios,S,bicicleta,B);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}

			break;
		case 5:
		     MostrarServicios(servicios,S);
			break;
		case 6:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				TotalPrecio=SumarDePrecioServicios(listaDeTrabajos,T,servicios,S);
				printf("\nEl precio total es $%d\n", TotalPrecio);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}

			break;
		case 7:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				TrabajosMarca(listaDeTrabajos,T,bicicleta,B);
				ListadoDeTrabajo(listaDeTrabajos, T,servicios,S,bicicleta,B);

			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}

			break;
		case 8:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				ServiciosMasPedidos(listaDeTrabajos,T,servicios);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}
			break;
		case 10:
			entrada=Entrada(listaDeTrabajos,T);
			if(entrada==1)
			{
				contadorRojo=ContadorDeRojos(listaDeTrabajos,T,bicicleta,B);
				printf("la cantidad de Bicis Rojos son:%d",contadorRojo);
			}else
			{
				printf("Error Ingrese primero la opcion 1");
			}
			break;


		}

	}while(opcion!=11);

}
