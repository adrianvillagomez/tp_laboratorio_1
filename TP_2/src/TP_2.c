/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define	ELEMENTS 5

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int idBaja;
	int order;
	float promedio;
	float acumulador=0;
	int contador=0;
	Employee empleados[ELEMENTS];
	initemployees(empleados, ELEMENTS);
	do{
		utn_getInt(&opcion, "ingrese una opcion 0 para salir 1 para ALTA--2PARA MODIFICAR--3PARA BAJA--4PARA MOSTRAR EMPLEADOS**5informes\n", "error\n", 0, 5, 3);
		switch(opcion)
		{
		case 0 :
			opcion=0;
			break;
		case 1 :
			chargeEmployee(empleados, ELEMENTS);
			break;
		case 2:
			modificacionVerificada(empleados, ELEMENTS);
			break;
		case 3:
			utn_getInt(&idBaja, "Ingrese el ID que quiere dar de baja", "Dato invalido", 0, 50, 2);
			if(removeEmployee(empleados, ELEMENTS, idBaja)==1)
			{
				printf("Baja correcta\n");
			}else
			{
				printf("Error");
			}
			break;
		case 4:
			printEmployees(empleados, ELEMENTS);
			break;
		case 5:
			utn_getInt(&order, "Ingrese 1 para ordenar Alfabeticamente de A a Z o 2 de Z a A: ","Dato invalido", 1, 2, 2);
			sortEmployees(empleados, ELEMENTS, order);
			printEmployees(empleados, ELEMENTS);
			printf("\nInforme de Sueldos\n");
			salaryEmployees(empleados, ELEMENTS, &promedio, &contador, &acumulador);
			printf("El total de los sueldos es: %.2f \n",acumulador);
			printf("El promedio de los sueldos es: %.2f \n",promedio);
			printf("La cantidad de trabajadores que superan el salario promedio es: %d \n",contador);
			break;
		}
	}while (opcion!=0);
	printf("fin del programa");


	//min:1,27 video 10/07
	//1:32 modificar
	return EXIT_SUCCESS;
}
