/*
 * ArrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: adrian
 */
#include "ArrayEmployees.h"
#include <stdio.h>
#include "UTN.h"
static int getNewId(void);
static int getNewId(void)
{
	static int contador=0;
	return contador++;
}
int initemployees(Employee array[], int len)
{
    int i;
    int banderaTodoBien;

    banderaTodoBien = 0;

    if(array != NULL && len>0)
    {
        banderaTodoBien = 1;
        for (i=0; i<len ;i++)
        {
        	array[i].isEmpty = 1;
        }
    }
    return banderaTodoBien;
}
int cargarSoloUno(Employee array[])
{
	int rtn=-1;
	int typeAux;
	float pricePerDayAux;
	char nameAux[128];
	char addressAux[128];
	if(array!=NULL)
	{
		if(utn_getInt(&typeAux, "ingrese 0 para LCD o 1 para LED\n", "error\n", 0, 1, 5)==0)
				{
					if(utn_getFloat(&pricePerDayAux, "ingrese precio por dia\n", "error\n", 0, 10000, 5)==0)
					{
						if(utn_getText(nameAux, 128, "ingrese el nombre\n", "error\n", 5)==0)
						{
							if(utn_getText(addressAux, 128, "ingrese la direccion\n", "error\n", 5)==0)
							{
								//array->type=typeAux;
								//array->price=pricePerDayAux;
								array->id=getNewId(); // generar el ID
								//strncpy(array->name,nameAux,sizeof(array->name));
								//strncpy(array->address,addressAux,sizeof(array->address));
								array->isEmpty=0;
								rtn=0;
							}
						}
					}
				}

	}
	return rtn;
}
int cargaVerificada(Employee array[],int len)//busca lugar libre y carga los display
{
	int retorno=-1;
	int lugarLibre;
	if(array!=NULL)
	{
		lugarLibre=encontrarIndexVacio(array, len);//busca lugar libre
		if(lugarLibre==-1)
			{
				printf("error todos los lugares ocupados: %d \n",lugarLibre);
			 }else
			 {
				 cargarSoloUno(&array[lugarLibre]);
			 }

	}
	return retorno;
}

int encontrarIndexVacio(Employee array[],int len)//busca el primer lugar libre
{
	int retorno=-1;
	int i;
	if(array!=NULL&& len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
void imprimirSoloUno(Employee array)
{
			//printf("El tipo de pantalla es: 0 LCD,1 LED:%d\n",pdysplay.type);
			//printf("El precio por dia es: %.2f\n",pdysplay.price);
			//printf("El id es: %d \n",array.id);
			//printf("El nombre es : %s\n",array.name);
			//printf("La direccion es : %s\n",array.address);
			//printf("Este espacio en memoria esta en uso: %d\n",pdysplay.flagEmpty);
}
int printEmployees (Employee array[], int len)
{
	int rtn=-1;
	int i;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==0)
			{
				imprimirSoloUno(array[i]);
				rtn=1;
			}

		}
	}
	return rtn;
}
int findEmployeeById(Employee array[], int len, int ID) {
	int retorno = -1;//error
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && len > 0 && ID>=0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].id == ID && array[i].isEmpty == 0) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int removeEmployee(Employee array[],int len,int id)
{
	int rtn;
	int foundDysplayPosition;
	foundDysplayPosition=findEmployeeById(array, len, id);
	if(array!=NULL && foundDysplayPosition==-1)
	{
		printf("error del delete \n");
	}else
	{
		array[foundDysplayPosition].isEmpty=1;
		rtn=1;
	}

	return rtn;

}
int modificarSoloUno(Employee array[])
{
	int rtn=-1;
	int typeAux;
	float pricePerDayAux;
	char nameAux[128];
	char addressAux[128];
	if(array!=NULL)
	{
		if(utn_getInt(&typeAux, "ingrese 0 para LCD o 1 para LED\n", "error\n", 0, 1, 5)==0)
				{
					if(utn_getFloat(&pricePerDayAux, "ingrese precio por dia\n", "error\n", 0, 10000, 5)==0)
					{
						if(utn_getText(nameAux, 128, "ingrese el nombre\n", "error\n", 5)==0)
						{
							if(utn_getText(addressAux, 128, "ingrese la direccion\n", "error\n", 5)==0)
							{
								//array->type=typeAux;
								//array->price=pricePerDayAux;
								//pDisplay->id=getNewId(); // generar el ID
								//strncpy(array->name,nameAux,sizeof(pdysplay->name));
								//strncpy(array->address,addressAux,sizeof(array->address));
								array->isEmpty=0;
								rtn=0;
							}
						}
					}
				}

	}
	return rtn;
}
int modificacionVerificada(Employee array[],int len)
{
	int rtn=-1;//error
	int indexAmodificar;
	int idIngresado;
	if(array!=NULL && len >0)
	{
		printEmployees(array, len);//imprimir lista
			if(utn_getInt(&idIngresado, "ingrese el id a modificar", "error ingrese id valido", 0, 99, 5)==0)// pido el id al usuario
				 {
					 indexAmodificar=findEmployeeById(array,len,idIngresado);// Busco si ese ID esta en uso
					 if(indexAmodificar==-1)
					 {
						 printf("error no exite el ID\n");// el ID no existe porque esta libre y no se puede modificar
					 }else
					 {
						 // modificar// encuentra el ID que ingreso el usuario y esta en uso asi que lo puedo modificar
						 modificarSoloUno(&array[indexAmodificar]);
						 //disp_loadDisplay(pdysplay);//OJO ESTO NO VA PORQUE CAMBIA EL ID
						 rtn=0;
					 }
				 }
	}
		return rtn;
}



