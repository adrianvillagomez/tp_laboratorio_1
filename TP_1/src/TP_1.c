/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main(void) {
	setbuf(stdout,NULL);
	float A;
	float B;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	float c;
	float D;
	float E;
	int a;
	int b;
	int d;
	int factorialA;
	int factorialB;
	utn_PedirNumero(&A,&B);
	suma=sumaNumeros(A,B);
	resta=restaNumeros(A, B);
	multiplicacion=multiplicacionNumeros(A, B);
	printf("El resultado de A + B es: %.2f\n",suma);
	printf("El resultado de A - B es: %.2f\n",resta);
	printf("El resultado de A * B es: %.2f\n",multiplicacion);
	division=dividirNumeros(A, B, &c);
	if(division==0)
		{
			printf("El resultado de A/B es: %.2f\n",c);

		}else
			{
				printf("error en la division ingrese un denominador distinto a 0\n");
			}
	factorialA=factorialNumeros(A,&D);
		if(factorialA==0)
		{
			printf("El factorial de A es : %.2f\n",D);
		}else
			{
				printf("error ingrese un numero distinto de 0\n");
			}
	factorialB=factorialNumeros(B,&E);
		if(factorialB==0)
			{
				printf("El factorial de B es : %.2f\n",E);
			}else
				{
					printf("error ingrese un numero distinto de 0\n");
				}


	return EXIT_SUCCESS;
}
