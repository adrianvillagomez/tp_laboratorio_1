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
int utn_PedirNumero(float *pResultado,float*psegundo);
float sumaNumeros(float A,float B);
float restaNumeros(float A,float B);
float multiplicacionNumeros(float A,float B);
float dividirNumeros(float A,float B,float*C);
int factorialNumeros(float A,float*D);

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
	int factorialA;
	int factorialB;
	utn_PedirNumero(&A,&B);
	suma=sumaNumeros(A,B);
	resta=restaNumeros(A, B);
	multiplicacion=multiplicacionNumeros(A, B);
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
	division=dividirNumeros(A, B, &c);
		if(division==0)
		{
			printf("El resultado de A/B es: %.2f\n",c);

		}else
			{
				printf("error en la division ingrese un denominador distinto a 0\n");
			}
	printf("El resultado de A + B es: %.2f\n",suma);
	printf("El resultado de A - B es: %.2f\n",resta);
	printf("El resultado de A * B es: %.2f\n",multiplicacion);
	return EXIT_SUCCESS;
}

int utn_PedirNumero(float *pResultado,float*psegundo)
{
	int aux;
	aux=0;
	if(pResultado!=NULL&&psegundo!=NULL)
	{
	printf("Ingresar 1er operando\n");
	scanf("%f",pResultado);
	printf("ingresar 2do operando\n");
	scanf("%f",psegundo);
	aux=1;
	}
	return aux;
}
float sumaNumeros(float A,float B)
{
	int resultado;
	resultado=A+B;
	return resultado;
}
float restaNumeros(float A,float B)
{
	int resultado;
	resultado=A-B;
	return resultado;
}
float multiplicacionNumeros(float A,float B)
{
	int resultado;
	resultado=A*B;
	return resultado;
}
float dividirNumeros(float A,float B,float*C)
{
	int retorno;
	float resultado;
	if(C!=NULL&&B!=0)
	{
		resultado=A/B;
		*C=resultado;
		retorno=0;
	}else
	{
		retorno=-1;
	}
	return retorno;
}
int factorialNumeros(float A,float*D)
{
	int i;
	int retorno;
	float aux;
	aux=1;
	if(D!=NULL&&A!=0)
	{
		for(i=1;i<=A;i++)
		{
			aux*= i;
			*D=aux;
			retorno=0;
		}
	}else
		{
		retorno=-1;
		}
	return retorno;
}
