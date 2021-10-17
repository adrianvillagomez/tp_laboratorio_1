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
	int isEmpty;//1-libre   0-ocupado
}Employee;
/// \fn int initemployees(Employee[], int)
/// \brief Esta funcion pone la bandera isEmpty en 1(libre)
/// \param array puntero al array de empleados
/// \param len tamaño del array
/// \return -1 si ocurrio un error 0 si esta todo bien
int initemployees(Employee array[], int len);
/// \fn int encontrarIndexVacio(Employee[], int)
/// \brief Busca en el array el primer lugar en 1
/// \param array puntero al array
/// \param len tamaño de funcion
/// \return-1 si ocurre un error 0 si esta todo bien
int encontrarIndexVacio(Employee array[],int len);
/// \fn int findEmployeeById(Employee[], int, int)
/// \brief Busca un empleado recibiendo como parámetro de búsqueda su Id
/// \param array puntero al array
/// \param len tamaño del array
/// \param ID id ingresado para la busqueda
/// \return -1 si ocurrio un error y me devulve el Index si salio todo bien
int findEmployeeById(Employee array[], int len, int ID);
/// \fn int removeEmployee(Employee[], int, int id)
/// \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
/// \param array array puntero al array
/// \param len tamaño del array
/// \param id
/// \return -1 si ocurrio un error 0 si esta todo bien
int removeEmployee(Employee array[],int len,int id);
/// \fn int modificarSoloUno(Employee[])
/// \brief funcion utilizada para preguntar denuevo todos los campos
/// \param array array puntero al array
/// \return -1 si ocurrio un error 0 si esta todo bien
int modificarSoloUno(Employee array[]);
/// \fn int modificacionVerificada(Employee[], int)
/// \brief funcion ultilizada para modificiar los campos
/// \param array array puntero al array
/// \param len tamaño del array
/// \return-1 si ocurrio un error 0 si esta todo bien
int modificacionVerificada(Employee array[],int len);
 /// \fn void imprimirSoloUno(Employee)
 /// \brief imprime solo una vez todos los campos
 /// \param array  array puntero al array
void imprimirSoloUno(Employee array);
/// \fn int printEmployees(Employee[], int)
/// \brief imprime todos los empleados existentes
/// \param array array puntero al array
/// \param len tamaño del array
/// \return-1 si ocurrio un error 0 si esta todo bien
int printEmployees (Employee array[], int len);
/// \fn int chargeEmployee(Employee[], int)
/// \brief alta de empleados
/// \param array array puntero al array
/// \param len tamaño del array
/// \return-1 si ocurrio un error 0 si esta todo bien
int chargeEmployee (Employee array[],int len);
/// \fn int addEmployee(Employee[], int, int, char[], char[], float, int)
/// \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre.
/// \param array array puntero al array
/// \param len tamaño del array
/// \param id id recibido como valor
/// \param name	nombre recibido valor
/// \param lastName apellido recibido como valor
/// \param salary salario recibido como valor
/// \param sector sector recibido como valor
/// \return -1 si ocurrio un error 0 si esta todo bien
int addEmployee(Employee array[],int len,int id,char name[],char lastName[],float salary,int sector);
/// \fn int sortEmployees(Employee[], int, int)
/// \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
/// \param array array puntero al array
/// \param len tamaño del array
/// \param order 1 de manera ascendente 2 descendente
/// \return -1 si ocurrio un error 0 si esta todo bien
int sortEmployees(Employee array[],int len,int order);
/// \fn int salaryEmployees(Employee[], int, float*, int*, float*)
/// \brief funcion que calcula el promedio y total de los sueldos
/// \param array array puntero al array
/// \param len tamaño del array
/// \param promedio promedio como valor
/// \param contador contador como valor
/// \param acumulador acumulador como valor
/// \return -1 si esta todo bien 0 si ocurrio un error
int salaryEmployees (Employee array[],int len,float *promedio,int *contador,float *acumulador);


#endif /* ARRAYEMPLOYEES_H_ */
