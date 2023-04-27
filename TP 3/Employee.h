#ifndef Employee_H_INCLUDED
#define Employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

/** \brief Obtiene espacio en memoria para un nuevo puntero a estructura
 *
 * \return Employee* el puntero a la estructura
 *
 */
Employee* employee_new();

/** \brief Asigna parametros a una estructura
 *
 * \param idStr char* Id en formato string
 * \param nombreStr char* nombre
 * \param horasTrabajadasStr char* horas trabajadas en formato string
 * \param sueldoStr char* sueldo en formato string
 * \return Employee* el puntero a la estructura
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Verifica el id y lo asigna a la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param id int el id a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Verifica el id y lo obtiene de la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param id int el id a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Verifica nombre y lo asigna a la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param nombre char el nombre a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Verifica el nombre y lo obtiene de la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param nombre char el nombre a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Verifica las horas trabajadas y lo asigna a la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param horasTrabajadas int las horas a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Verifica las horas trabajadas y lo obtiene de la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param horasTrabajadas int las horas a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Verifica el sueldo y lo asigna a la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param sueldo float el sueldo a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_setSueldo(Employee* this,float sueldo);

/** \brief Verifica el sueldo y lo obtiene de la estructura
 *
 * \param this Employee* puntero a la estructura
 * \param sueldo float el sueldo a asignar
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_getSueldo(Employee* this,float* sueldo);

/** \brief Carga el nuevo id
 *
 * \param this Employee* puntero a la estructura
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id char* id por parametro
 * \return int 1 si hubo error -1 si salio bien
 *
 */
int employee_nextId(Employee* this,LinkedList* pArrayListEmployee,char* id);

/** \brief Imprime los datos de una estructura
 *
 * \param this Employee* la estructura a imprimir
 * \return void
 *
 */
void employee_printData(Employee* this);

/** \brief Controla si el id ingresado se encuentra en la lista
 *
 * \param pArrayListEmployee LinkedList* lista de empelados
 * \param idStr char* id en formato string
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int employee_findById(LinkedList* pArrayListEmployee, int id);

/** \brief Ordena por id
 *
 * \param empleadoA void* puntero void a la estructura
 * \param empleadoB void* puntero void a la estructura
 * \return tipo de ordenamiento a realizar
 *
 */
int employee_sortById(void* employeeA, void* employeeB);

/** \brief Ordena por nombre
 *
 * \param empleadoA void* puntero void a la estructura
 * \param empleadoB void* puntero void a la estructura
 * \return tipo de ordenamiento a realizar
 *
 */
int employee_sortByName(void* employeeA, void* employeeB);

/** \brief Ordena por horas trabajadas
 *
 * \param empleadoA void* puntero void a la estructura
 * \param empleadoB void* puntero void a la estructura
 * \return tipo de ordenamiento a realizar
 *
 */
int employee_sortByHoursWorked(void* employeeA, void* employeeB);

/** \brief Ordena por salario
 *
 * \param empleadoA void* puntero void a la estructura
 * \param empleadoB void* puntero void a la estructura
 * \return tipo de ordenamiento a realizar
 *
 */
int employee_sortBySalary(void* empleadoA, void* empleadoB);


#endif // Employee_H_INCLUDED
