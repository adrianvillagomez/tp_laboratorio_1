/*
 * utn.c
 *
 *  Created on: 24 sep. 2021
 *      Author: adrian
 */

#include "utn.h"
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
