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


int CargarTrabajo(eTrabajos lista[], int tam,eServicios servicios[],int tServicios,eBicicleta bicicletas[],int tamanioBici)
{
    int index;
    index = BuscarLibre(lista, tam);
    if(index==-1)
    {
       printf("No hay mas espacio en la fabrica");

    }else
    {
    	lista[index]=PedirDatosTrabajador(servicios,tam,bicicletas,tamanioBici);
    }

    return 0;
}
eTrabajos PedirDatosTrabajador(eServicios servicios[],int tam,eBicicleta bicicletas[],int tamanioBici)
{
	eTrabajos miTrabajo; // bueno me tira error


	miTrabajo.idIncremental=ObtenerId();
	MostrarBicis(bicicletas,tamanioBici);
	miTrabajo.idBicicleta=GetInt("ingrese la ID de la bici que quiere:");
    MostrarServicios(servicios,tam);
    miTrabajo.idServicio=GetInt("Ingrese el servicio que quiera mediante el ID:");
    while(miTrabajo.idServicio<19999 || miTrabajo.idServicio>20002)
    {
    	miTrabajo.idServicio=GetInt("Error Ingrese un ID valido:");
    }
    miTrabajo.fecha.dia=GetInt("Ingrese el dia: ");
    while(miTrabajo.fecha.dia>31 || miTrabajo.fecha.dia<1)
    {
    	miTrabajo.fecha.dia=GetInt("ERROR.Ingrese un dia valido: ");
    }
    miTrabajo.fecha.mes=GetInt("Ingrese mes: ");
    while(miTrabajo.fecha.mes>12 || miTrabajo.fecha.mes<1)
    {
    	miTrabajo.fecha.mes=GetInt("ERROR.Ingrese un mes valido: ");
    }
    miTrabajo.fecha.anio=GetInt("Ingrese el año: ");

    printf("\nTrabajo registrado con exito!!\n\n");

    miTrabajo.isEmpty=OCUPADO;

    return miTrabajo;
}
void ModificarTrabajo(eTrabajos lista[], int index,eServicios servicios[],int tam,eBicicleta bicicleta[])
{
	int menu;

	printf("1.MODIFICAR MARCA\n");
	printf("2.MODIFICAR SERVICIO \n");

	menu=GetInt("Ingrese una opcion:");
	switch(menu)
	{
	case 1:
		GetString("Ingrese la nueva marca: ",bicicleta[index].marcaBici);
		printf("Trabajo modificado con exito!\n");
	break;
	case 2:
		MostrarServicios(servicios,tam);
		lista[index].idServicio=GetInt("Ingrese el nuevo servicio: ");
	   printf("Trabajo modificado con exito!\n");
	break;
	}

}
void EditarTrabajo(eTrabajos lista[],int tam,eServicios servicios[],eBicicleta bicicleta[])
{
	int index;
	index=Buscarid(lista,tam);

	if(index==-1)
	{
		printf("ERROR , no se encontro el id que usted ingreso\n");
	}
	else
	{
		ModificarTrabajo(lista,index,servicios,tam,bicicleta);
	}
}

void ListadoDeTrabajo(eTrabajos trabajo[], int tTrabajos, eServicios servicios[],int tServicios,eBicicleta trabajosMarca[],int tMarcas)
{
    int i;

    for(i=0; i<tTrabajos; i++)
    {
        if(trabajo[i].isEmpty == OCUPADO)
        {
        	MostrarTrabajo(trabajo[i]);
        	MostrarServiciosNombre(trabajo,tServicios,servicios,i);
        	MostrarTrabajosMarca(trabajo,tMarcas,trabajosMarca,i);

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
void MostrarServiciosNombre(eTrabajos trabajos[],int tServicios,eServicios servicios[],int index)
{
	int j;

	for(j=0;j<tServicios;j++)
	{
		if(trabajos[index].idServicio==servicios[j].idIncremental)
		{
		printf("Servicio --%s--",
		servicios[j].descripcion);
		}
    }
}

void MostrarTodo(eTrabajos trabajo[], int tTrabajos,eServicios servicios[], int tServicios,eBicicleta trabajosMarca[],int tMarcas)
{
	int i;

	for(i=0;i<tTrabajos;i++)
	{
		if(trabajo[i].isEmpty==OCUPADO)
		{
			MostrarTrabajo(trabajo[i]);
			MostrarServiciosNombre(trabajo,tServicios,servicios,i);
			MostrarTrabajosMarca(trabajo,tMarcas,trabajosMarca,i);
		}

	}

}
void MostrarTrabajosMarca(eTrabajos trabajos[],int tMarcas,eBicicleta trabajosMarca[],int index)
{
	int j;

	for(j=0;j<tMarcas;j++)
	{
		if(trabajos[index].idBicicleta==trabajosMarca[j].idIncremental)
		{
		printf(" Marca --%s-- Rodado --%d-- Color --%s--\n",
				trabajosMarca[j].marcaBici,trabajosMarca[j].rodadoBici,trabajosMarca[j].color);
		}
    }
}
void OrdenarTrabajosPorAnio(eTrabajos lista[],int tam,eBicicleta bicicletas[],int tBicicletas)
{
	int i;
    int j;

	 eTrabajos auxiliaranio;

	 for(i=0; i<tam-1; i++)
	 {
	   for(j=i+1; j<tam; j++)
	   {
		  if(lista[i].fecha.anio>lista[j].fecha.anio)
		  {
		     auxiliaranio = lista[i];
		     lista[i] = lista[j];
		     lista[j] = auxiliaranio;;
		   }else
		   {
			   if(lista[i].fecha.anio==lista[j].fecha.anio)
			   	 {
			   		 OrdenarPorMarca(lista,tBicicletas,bicicletas,i);
			   	 }
		   }
	   }
	 }

}
void OrdenarPorMarca(eTrabajos trabajos[],int tBicicletas,eBicicleta bicicletas[],int index)
{
	int j;
	int k;

	eTrabajos auxiliarmarca;

	for(j=0;j<tBicicletas;j++)
	{
		for(k=j+1;k<tBicicletas;k++)
		{
			if(trabajos[index].idBicicleta==bicicletas[j].idIncremental)
			{
				if(strcmp(bicicletas[j].marcaBici,bicicletas[k].marcaBici)>0)
				{
										auxiliarmarca = trabajos[j];
										trabajos[j] = trabajos[k];
										trabajos[k] = auxiliarmarca;;
				}
			}
		}
	}

}
void TrabajosMarca(eTrabajos trabajo[],int tTrabajos,eBicicleta bicicletas[],int tBicicleta)
{
	int i;

	for(i=0;i<tTrabajos;i++)
	{
		OrdenarPorMarca(trabajo,tBicicleta,bicicletas,i);
	}
}
void ServiciosMasPedidos(eTrabajos trabajos[], int tam,eServicios servicios[])
{
	int i;
	char nombreServicioMasUsado[25];
	int contadorLimpieza = 0;
	int contadorParche = 0;
	int contadorCentrado = 0;
	int contadorCadena = 0;
	int ServicioMasUsado = 0;

	for(i=0;i<tam;i++)
	{
		if(trabajos[i].idServicio == servicios[0].idIncremental)
		{
			contadorLimpieza++;
		}
		else
		{
			if(trabajos[i].idServicio == servicios[1].idIncremental)
			{
				contadorParche++;
			}
			else
			{
				if(trabajos[i].idServicio == servicios[2].idIncremental)
				{
					contadorCentrado++;
				}
				else
				{
					if(trabajos[i].idServicio == servicios[3].idIncremental)
					{
						contadorCadena++;
					}
				}
			}
		}
	}

	if(contadorParche > contadorLimpieza && contadorParche > contadorCentrado && contadorParche >contadorCadena)
	{
		ServicioMasUsado=contadorParche;
		strcpy(nombreServicioMasUsado, "Parche");
	}
	if(contadorLimpieza > contadorParche && contadorLimpieza > contadorCentrado && contadorLimpieza >contadorCadena)
		{
		ServicioMasUsado=contadorLimpieza;
			strcpy(nombreServicioMasUsado, "limpieza");
		}
	if(contadorCentrado > contadorParche && contadorCentrado > contadorLimpieza && contadorCentrado >contadorCadena)
		{
		ServicioMasUsado=contadorCentrado;
			strcpy(nombreServicioMasUsado, "centrado");
		}
	if(contadorCadena > contadorParche && contadorCadena > contadorCentrado && contadorCadena >contadorLimpieza)
		{
		ServicioMasUsado=contadorCadena;
			strcpy(nombreServicioMasUsado, "Cadena");
		}
	printf("El servicio mas usado es:%s, y se uso %d veces",nombreServicioMasUsado,ServicioMasUsado);

}
int ContadorDeRojos(eTrabajos trabajo[],int tTrabajos,eBicicleta bicicleta[],int tBicicletas)
{
	int contador=0;
	int i;
	int j;

	for(i=0;i<tTrabajos;i++)
	{
		for(j=0;j<tBicicletas;j++)
		{
			if(trabajo[i].idBicicleta==bicicleta[2].idIncremental)
			{
				contador++;
			}
		}
	}



	return contador;
}
