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
int initemployees(Employee array[], int len)//1-libre   0-ocupado
{
    int i;
    int banderaTodoBien=-1;

    banderaTodoBien = 0;

    if(array != NULL && len>0)
    {
        banderaTodoBien = 1;
        for (i=0; i<len ;i++)
        {
        	array[i].isEmpty = 1;
        	 banderaTodoBien = 0;
        }
    }
    return banderaTodoBien;
}
int chargeEmployee (Employee array[],int len)
{
	int rtn=-1;
	char auxName[52];
	char auxLastName[52];
	float auxSalary;
	int auxSector;
	int auxId;
	if(array!=NULL && len>0)
	{
		if(utn_getText(auxName, 52, "Ingrese Nombre del empleado: ", "Dato invalido.\n	",2)==0)
		{
			if(utn_getText(auxLastName, 52, "Ingrese Apellido del empleado: ", "Dato invalido.\n",2)==0)
			{
				if(utn_getFloat(&auxSalary, "Ingrese Salario del empleado: ", "Dato invalido", 0,10000, 2)==0)
				{
					if(utn_getInt(&auxSector, "Ingrese Sector", "Dato invalido", 0, 50, 2)==0)
					{
						auxId=getNewId();

						addEmployee(array, len, auxId, auxName, auxLastName, auxSalary, auxSector);
						rtn=0;

					}
				}

			}
		}

	}
	return rtn;
}
int addEmployee(Employee array[],int len,int id,char name[],char lastName[],float salary,int sector)
{
	int rtn=-1;
	int lugarLibre;
	if(array!=NULL && len>0)
	{
		lugarLibre=encontrarIndexVacio(array, len);
		if(lugarLibre==-1)
		{
			printf("Error todos los lugares ocupados: %d \n",lugarLibre);
		}else
		{
			array[lugarLibre].id=id;
			strncpy(array[lugarLibre].name,name,sizeof(array->name));
			strncpy(array[lugarLibre].lastName,lastName,sizeof(array->lastName));
			array[lugarLibre].salary=salary;
			array[lugarLibre].sector=sector;
			array[lugarLibre].isEmpty=0;
			rtn=0;
		}

	}

	return rtn;
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
	printf("%3d     %10s      %10s       %.2f            %d\n",array.id, array.name, array.lastName, array.salary, array.sector);
}
int printEmployees (Employee array[], int len)
{
	printf("\n-----------------Lista de Empleados---------------------------\n");
	printf("  id       Nombre         Apellido       Salario      Sector\n");
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
	char auxName[52];
	char auxLastName[52];
	float auxSalary;
	int auxSector;
	if(array!=NULL)
	{
		if(utn_getText(auxName, 52, "Ingrese nombre del empleado", "Dato invalido", 2)==0)
				{
					if(utn_getText(auxLastName, 52, "Ingrese apellido del empleado", "Dato invalido", 2)==0)
					{
						if(utn_getFloat(&auxSalary, "Ingrese salario", "Dato invalido", 0, 1000, 2)==0)
						{
							if(utn_getInt(&auxSector, "Ingrese Sector", "Dato invalido", 0, 50, 2)==0)
							{

								array->id=getNewId(); // generar el ID
								strncpy(array->name,auxName,sizeof(array->name));
								strncpy(array->lastName,auxLastName,sizeof(array->lastName));
								array->salary=auxSalary;
								array->sector=auxSector;
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
			if(utn_getInt(&idIngresado, "Ingrese el ID a modificar", "Error ingrese ID valido", 0, 99, 5)==0)// pido el id al usuario
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
int sortEmployees(Employee array[],int len,int order)
{
	int retorno = -1;
		Employee bufferList;
		int i;
		int j;

		if (array!= NULL && len >= 0)
		{
			switch (order)
			{
			case 1:
				for (i = 0; i < len; i++) {
					for (j = i + 1; j < len; j++) {
						if (strcmp(array[i].lastName, array[j].lastName) > 0) {
							bufferList = array[i];
							array[i] = array[j];
							array[j] = bufferList;
							retorno = 0;
						} else {
							if (strcmp(array[i].lastName, array[j].lastName) == 0
									&& array[i].sector > array[j].sector) // > de menor a mayor
											{
								bufferList = array[i];
								array[i] = array[j];
								array[j] = bufferList;
							}
						}
					}
				}
				break;
			case 2:
				for (i = 0; i < len; i++) {
					for (j = i + 1; j < len; j++) {
						if (strcmp(array[i].lastName, array[j].lastName) < 0) {
							bufferList = array[i];
							array[i] = array[j];
							array[j] = bufferList;
							retorno = 0;
						} else {
							if (strcmp(array[i].lastName, array[j].lastName) == 0
									&& array[i].sector < array[j].sector) // > de menor a mayor
											{
								bufferList = array[i];
								array[i] = array[j];
								array[j] = bufferList;
							}
						}
					}
				}
				break;
			}
		}
		return retorno;
}
int salaryEmployees (Employee array[],int len,float *promedio,int *contador,float *acumulador)
{

	int i;
	int retorno=-1;
	float bufferAcumulador=0;
	int bufferContador=0;
	int bufferContadorMayor=0;
	float bufferPromedio;
	if (array != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (array[i].isEmpty == 0)
			{
				bufferAcumulador = bufferAcumulador + array[i].salary;
				bufferContador++;
				retorno=0;
			}
		}
	}

	*acumulador=bufferAcumulador;
	bufferPromedio=bufferAcumulador/bufferContador;
	*promedio=bufferPromedio;

	for (i = 0; i < len; i++)
			{
				if (array[i].isEmpty == 0 && array[i].salary>bufferPromedio)
				{

					bufferContadorMayor++;

				}

			*contador=bufferContadorMayor;

			}
return retorno;


}

