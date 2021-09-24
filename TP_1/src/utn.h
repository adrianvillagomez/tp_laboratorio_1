/*
 * utn.h
 *
 *  Created on: 24 sep. 2021
 *      Author: adrian
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>

/// \fn int utn_PedirNumero(float*, float*)
/// \brief Pide dos numeros al usuario
/// \param pResultado Operando A
/// \param psegundo Operando B
/// \return 1[si salio todo bien]
int utn_PedirNumero(float *pResultado,float*psegundo);
/// \fn float sumaNumeros(float, float)
/// \brief Suma dos numeros flotantes
/// \param A El primer operando
/// \param B El segundo operando
/// \return El resultado de la suma
float sumaNumeros(float A,float B);
/// \fn float restaNumeros(float, float)
/// \brief Resta dos numeros flotantes
/// \param A El primer operando
/// \param B El segundo operando
/// \return El resultado del a resta
float restaNumeros(float A,float B);
/// \fn float multiplicacionNumeros(float, float)
/// \brief Multiplica dos numero flotantes
/// \param A El primer operando
/// \param B El segundo operando
/// \return El resultado de la multiplicacion
float multiplicacionNumeros(float A,float B);
/// \fn float dividirNumeros(float, float, float*)
/// \brief Divide dos numero flotantes
/// \param A El primer operando
/// \param B El segundo operando
/// \param C El resultado de la division,vuelve por punto
/// \return 0[si salio todo bien]-1[si hubo un error]
float dividirNumeros(float A,float B,float*C);
/// \fn int factorialNumeros(float, float*)
/// \brief Calcula el factorial de un numero
/// \param A El operando a factorizar
/// \param D El resultado de la factorizacion,vuelve por puntero
/// \return 0[si salio todo bien]-1[si hubo un error]
int factorialNumeros(float A,float*D);



#endif /* UTN_H_ */
