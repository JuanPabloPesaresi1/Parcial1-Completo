/*
 * Bicicleta.c
 *
 *  Created on: 20 may. 2021
 *      Author: Juan
 */


#include "Bicicleta.h"

void HardcodearBicis(eBicicleta bicicletas[],int tam)
{
	int i;
	int id[]={25,26,27,28,29};
	char marcaBici[][25]={"BMX","MountainBike","Playera","Ruta","Deportiva"};
	int rodadoBici[]={20,29,27,28,30};
	char color[][15]={"Negro","Blanco","Rojo","Azul","Gris"};

	for(i=0;i<tam;i++)
		{
			bicicletas[i].idIncremental=id[i];
			strcpy(bicicletas[i].marcaBici,marcaBici[i]);
			bicicletas[i].rodadoBici=rodadoBici[i];
			strcpy(bicicletas[i].color,color[i]);

		}

}
void MostrarBicis(eBicicleta bicicleta[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		printf("ID:%d--%s--%d--%s\n", bicicleta[i].idIncremental,bicicleta[i].marcaBici,bicicleta[i].rodadoBici,bicicleta[i].color);

	}

}

