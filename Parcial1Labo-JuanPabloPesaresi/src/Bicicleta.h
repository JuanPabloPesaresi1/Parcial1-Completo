/*
 * Bicicleta.h
 *
 *  Created on: 20 may. 2021
 *      Author: Juan
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_
#include "inputs.h"
#define EMPTY 0
#define OCUPADO 1

typedef struct
{
	int idIncremental;
	char marcaBici[25];
	int rodadoBici;
	char color[15];

}eBicicleta;

void HardcodearBicis(eBicicleta[],int);
void MostrarBicis(eBicicleta[],int);


#endif /* BICICLETA_H_ */
