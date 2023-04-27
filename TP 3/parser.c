#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *  \param path char*
 *  \param pArrayListEmployee LinkedList*
 *  \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int lecturas;
    char auxId[50], auxNombre[50], auxHorasTrabajadas[50], auxSueldo[50]; //buffer
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas,auxSueldo);
    while(!feof(pFile))
    {
        Employee* this;
        lecturas = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas,auxSueldo);
        if(this != NULL && lecturas == 4)
        {
            this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas,auxSueldo);
            ll_add(pArrayListEmployee, this);
        }
        else if(lecturas != 4)
        {
            if(!feof(pFile)){
                printf("\nError al leer el ultimo dato.\n");
                break;
            }
        }
    }
    fclose(pFile);
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *  \param path char*
 *  \param pArrayListEmployee LinkedList*
 *  \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int lecturas;
    while(!feof(pFile))
    {
        Employee* this = employee_new();
        lecturas = fread(this, sizeof(Employee), 1, pFile);
        if(lecturas == 1 && this != NULL)
        {
            ll_add(pArrayListEmployee, this);
        }
        else if(lecturas != 1)
        {
            if(!feof(pFile))
            {
                printf("\nError.\n");
                break;
            }
        }
    }
    fclose(pFile);
    return 1;
}
