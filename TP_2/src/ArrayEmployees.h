/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: adrian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"
//defino estructura
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;
int initemployees(Employee array[], int len);
int encontrarIndexVacio(Employee array[],int len);
int cargarSoloUno(Employee array[]);
int cargaVerificada(Employee array[],int len);
int findEmployeeById(Employee array[], int len, int ID);
int removeEmployee(Employee array[],int len,int id);
int modificarSoloUno(Employee array[]);
int modificacionVerificada(Employee array[],int len);
void imprimirSoloUno(Employee array);
int printEmployees (Employee array[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
