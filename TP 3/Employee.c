#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee));
    if(this == NULL)
    {
        printf("No hay lugar para crear nuevo empleado.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* id, char* nombre, char* horasTrabajadas, char* sueldo){
    int idAux,horasTrabajadasAux;
    float sueldoAux;
    Employee* this = employee_new();
    idAux = atoi(id);
    horasTrabajadasAux = atoi(horasTrabajadas);
    sueldoAux = atof(sueldo);
    if(this != NULL)
    {
        employee_setId(this,idAux);
        employee_setNombre(this, nombre);
        employee_setHorasTrabajadas(this, horasTrabajadasAux);
        employee_setSueldo(this,sueldoAux);
    }
    return this;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
	/*return strcpy(nombre, this->nombre);*/
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_nextId(Employee* this,LinkedList* pArrayListEmployee,char* id){
    int retorno = -1;
    int auxId = atoi(id);
    int i = 0;
    if(this != NULL && pArrayListEmployee != NULL)
    {
        while(i < ll_len(pArrayListEmployee))
        {
            this = ll_get(pArrayListEmployee,i);
            i++;
            if(auxId == this->id)
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

void employee_printData(Employee* this)
{
    int id;
    char nombre[51];
    int horasTrabajadas;
    float sueldo;
    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    employee_getSueldo(this,&sueldo);
    printf("Id: %5d | Nombre: %10s | Horas trabajadas: %5d | Sueldo: %.2f\n", id, nombre, horasTrabajadas, sueldo);
}

int employee_findById(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	Employee* this;
	int i;
	for(i = 0; i < ll_len(pArrayListEmployee); i++)
	{
        this = (Employee*)ll_get(pArrayListEmployee,i);
        if(this->id == id)
        {
			retorno = i;
			break;
        }
	}
	return retorno;
}


int employee_sortById(void* employeeA, void* employeeB)
{
    int retorno = 0;
    int auxIdA;
    int auxIdB;
    Employee* auxEmployeeA = (Employee*) employeeA;
    Employee* auxEmployeeB = (Employee*) employeeB;

    employee_getId(auxEmployeeA,&auxIdA);
    employee_getId(auxEmployeeB,&auxIdB);
    if (auxEmployeeA != NULL && auxEmployeeB != NULL)
    {
        if(auxIdA > auxIdB)
        {
            retorno = 1;
        }
        else if(auxIdA < auxIdB)
        {
            retorno = -1;
        }
    }
    return retorno;

}

int employee_sortByName(void* employeeA, void* employeeB)
{
    int retorno = 0;
    char auxNameA[128];
    char auxNameB[128];
    Employee* auxEmployeeA = (Employee*) employeeA;
    Employee* auxEmployeeB = (Employee*) employeeB;

    employee_getNombre(auxEmployeeA,auxNameA);
    employee_getNombre(auxEmployeeB,auxNameB);
    if (auxEmployeeA != NULL && auxEmployeeB != NULL)
    {
        if(strcmp(auxNameA,auxNameB)>0)
        {
            retorno = 1;
        }
        else if(strcmp(auxNameA,auxNameB)<0)
        {

            retorno = -1;
        }
    }
    return retorno;

}

int employee_sortByHoursWorked(void* employeeA, void* employeeB)
{
    int retorno = 0;
    int auxHourA;
    int auxHourB;
    Employee* auxEmployeeA = (Employee*) employeeA;
    Employee* auxEmployeeB = (Employee*) employeeB;

    employee_getHorasTrabajadas(auxEmployeeA,&auxHourA);
    employee_getHorasTrabajadas(auxEmployeeB,&auxHourB);
    if (auxEmployeeA != NULL && auxEmployeeB != NULL)
    {
        if(auxHourA > auxHourB)
        {

            retorno = 1;
        }
        else if(auxHourA < auxHourB)
        {

            retorno = -1;
        }

    }
    return retorno;

}

int employee_sortBySalary(void* employeeA, void* employeeB)
{
    int retorno = 0;
    float auxSueldoA;
    float auxSueldoB;
    Employee* auxEmployeeA = (Employee*) employeeA;
    Employee* auxEmployeeB = (Employee*) employeeB;

    employee_getSueldo(auxEmployeeA,&auxSueldoA);
    employee_getSueldo(auxEmployeeB,&auxSueldoB);
    if (auxEmployeeA != NULL && auxEmployeeB != NULL)
    {
        if(auxSueldoA > auxSueldoB)
        {
            retorno = 1;
        }
        else if(auxSueldoA < auxSueldoB)
        {
            retorno = -1;
        }
    }
    return retorno;

}
