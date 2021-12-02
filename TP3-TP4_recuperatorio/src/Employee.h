#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include"LinkedList.h"//agregado 01.15am
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Prueba;
/** \brief Crea un espacio de memoria para una struct Employee*
 *
 * \return Employee*
 *
 */
Employee* employee_new(void);//esto devuelve un puntero empleado

/** \brief Crea un nuevo employee con parametros
 *
 * param char* idStr
 * param char* nombreStr
 * param char* horasTrabajadasStr
 * param char* sueldoSrt
 *
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);// un puntero a empleado con sus campos creados
/** \brief Elimina el espacio de memoria del Employee
 *
 * param Employee* this
 *
 */
void employee_delete(Employee* this);
/** \brief Setea el ID
 *
 * \param Employee* this
 * \param int id
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Pide el ID
 *
 * \param Employee* this
 * \param int* id
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief Setea el nombre
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Pide el nombre
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Setea las horas trabajadas
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Pide las horas trabajadas
 *
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Setea el sueldo
 *
 * \param Employee* this
 * \param int sueldo
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Pide el sueldo
 *
 * \param Employee* this
 * \param int* sueldo
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);
/** \brief buscar empleado por ID
 *
 * \param LinkedList* this
 * \param int id
 * \return int
 *
 */
int employee_buscarPorId(LinkedList* pArrayListEmployee,int id);
int sort_salario(void* salarioUno,void* salarioDos);
int sort_id(void* idUno,void* idDos);
int sort_nombre(void* nombreUno,void* nombreDos);
int sort_horasDeTrabajo(void* horasUno, void* horasDos);
//alta empleado
//modificar empleado
//buscar por id


#endif // employee_H_INCLUDED
