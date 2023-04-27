#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define OCUPADO 0
#define LIBRE 1

static int nextId();

/** \brief Genera un id secuencial.
 * \return static int lastId.
 */
static int nextId(){
    static int lastId = -1;
    lastId++;
    return lastId;
}

/** \brief Encuentra un lugar vacio.
 * \param Employee* pEmployee array donde encontrara, o no, un lugar.
 * \param int length longitud del array.
 * \return int retorno (-1) si no hay encontro lugar. (0) si encontro.
 */
int findEmptyPlace(Employee* pEmployee, int length){
    int retorno = -1;
    int i;
    if( pEmployee != NULL && length > 0 )
    {
        retorno = -2;
        for(i=0; i < length ; i++)
        {
            if(pEmployee[i].isEmpty == LIBRE)
            {
            retorno = i;
            break;
            }
        }
    }
    return retorno;
}

/** \brief inicializa el array.
 * \param  Employee* pEmployee array a ser inicializado.
 * \param  int length longitud del array.
 * \return int retorno (-1) si no pudo. (0) si pudo.
 */
int initEmployees(Employee* pEmployee,int length){
    int retorno = -1;
    int i;
    if(pEmployee != NULL && length > 0)
    {
        retorno = 0;
        for(i=0; i < length; i++)
        {
            pEmployee[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

/** \brief Agrega un empleado.
 * \param  Employee* pEmployee array donde se agregaran empleados.
 * \param  int length longitud del array.
 * \param  int id identificador unico de cada empleado que se generara automaticamente.
 * \return int retorno (-1)(-2)(-3) si hay un error [longitud invalida, puntero null o no hay espacio. (0) si pudo ser agregado.
 */
int addEmployee(Employee* pEmployee, int length, char* name, char* lastName, float salary, int sector){
    int retorno = -1;
    int index;
    int id;
    if(pEmployee != NULL && length > 0)
    {
        retorno = -2;
        index = findEmptyPlace(pEmployee,length);
        if(index >= 0)
        {
            id=nextId();
            retorno = 0;
            strcpy(pEmployee[index].name,name);
            strcpy(pEmployee[index].lastName,lastName);
            pEmployee[index].salary=salary;
            pEmployee[index].sector=sector;
            pEmployee[index].id=id;
            pEmployee[index].isEmpty=OCUPADO;
        }
     }
    return retorno;
}


/** \brief Encuentra empleado por id.
 * \param Employee* pEmployee array a ser buscado.
 * \param int length longitud del array.
 * \param int id identificador del empleado.
 * \return int retorno (-1)(-2) si hay error [puntero null, longitud invalida o no encontro nada]. (i) si encontro.
 */
int findEmployeeById(Employee* pEmployee,int length,int id){
    int retorno = -1;
    int i;
    if(pEmployee != NULL && length > 0)
    {
        retorno = -2;
        for(i=0 ; i < length ; i++)
        {
            if(pEmployee[i].isEmpty == OCUPADO && pEmployee[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Elimina un empleado.
 * \param  Employee* pEmployee array del cual se eliminara un empleado.
 * \param  int length longitud del array.
 * \param  int id identificador del empleado.
 * \return int retorno (-1) si no encontro nada. (0) si pudo liberar el lugar.
 */
int removeEmployee(Employee* pEmployee,int length,int id){
    int retorno = -1;
    int index;
    index = findEmployeeById(pEmployee, length, id);
    if( index >= 0)
    {
        retorno = 0;
        pEmployee[index].isEmpty = LIBRE;
    }
    return retorno;
}

/** \brief Ordena el array de empleados.
 * \param  Employee* pEmployee array a ser ordenado.
 * \param  int length longitud del array.
 * \param  int order criterio para ordernar.
 * \return int retorno (-1) si hay error. (0) si pudo ordenar.
 */
int sortEmployees(Employee* pEmployee,int length,int order){
    int retorno = - 1;
    int flagSwap;
    int i;
    Employee auxiliar;
        if(pEmployee != NULL && length > 0)
        {
            retorno = 0;
            do{
                flagSwap = 0;
                for(i=0;i < length - 1; i++){
                    if(pEmployee[i].isEmpty == OCUPADO && pEmployee[i+1].isEmpty == OCUPADO )
                    {
                       if((strcasecmp(pEmployee[i].lastName,pEmployee[i+1].lastName) > 0 && !order) || (strcasecmp(pEmployee[i].name,pEmployee[i+1].name) < 0 && order))
                        {
                            auxiliar = pEmployee[i];
                            pEmployee[i] = pEmployee[i+1];
                            pEmployee[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                        else if((strcasecmp(pEmployee[i].lastName,pEmployee[i+1].lastName) == 0 && !order) && (pEmployee[i].sector > pEmployee[i+1].sector))
                        {
                            auxiliar = pEmployee[i];
                            pEmployee[i] = pEmployee[i+1];
                            pEmployee[i+1] = auxiliar;
                            flagSwap = 2;
                        }
                    }
                }
            }while(flagSwap);
        }
    return retorno;
}

/** \brief Muestra el array de empleados.
 * \param  Employee* pEmployee array a ser mostrado.
 * \param  int length longitud del array.
 * \return int retorno (-1) si hay error. (0) si se pudo mostrar.
 */
int printEmployees(Employee* pEmployee,int length){
    int retorno = -1;
    int i;
    if(pEmployee != NULL && length > 0)
    {
        retorno = 0;
        printf("|SECTOR  | APELLIDO                 | NOMBRE                   | SALARIO | ID\n");
        for(i=0; i < length; i++){
            if(!pEmployee[i].isEmpty)
            {
                printf("| %3d    | %-25s| %-25s| %.1f |%2d\n",pEmployee[i].sector, pEmployee[i].lastName, pEmployee[i].name, pEmployee[i].salary, pEmployee[i].id);
            }
        }
    }
    return retorno;
}

/** \brief Modifica nombre, apellido, salario y sector de un empleado.
 * \param Employee* pEmployee array a ser modificado.
 * \param int length longitud del array.
 * \param int id identificador del empleado a ser modificado.
 * \return int retorno (-1)(-2) si hay error [puntero null, longitud invalida o no encontro nada]. (0) si pudo modificar.
 */
int updateEmployee(Employee* pEmployee, int length,int id){
    int retorno = -1;
    int index;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    index=findEmployeeById(pEmployee,length,id);
    if(index >= 0)
    {
        retorno = -2;
        if(index >=0)
        {
            if(!getValidString(name,"Nombre: ","Error.\n", "OVERFLOW.\n", 51, 3))
              {
                if(!getValidString(lastName, "Apellido: ", "Error.\n", "OVERFLOW.\n", 51, 3))
                {
                   if(!utn_getFlotante(&salary,"Salario: ", "Error. Salario minimo 10mil - maximo 80Mil.\n", 10000, 80000, 3))
                    {
                      if(!getValidInt(&sector, "Sector: ", "Error. Sectores del 1 al 100.\n", 1, 100, 3))
                        {
                        retorno = 0;
                        strcpy(pEmployee[index].name,name);
                        strcpy(pEmployee[index].lastName,lastName);
                        pEmployee[index].salary=salary;
                        pEmployee[index].sector=sector;
                        }
                   }
                }
            }
        }
    }
    return retorno;
}

/** \brief Promedio de salarios.
 * \param  Employee* pEmployee array del cual sacaremos el promedio.
 * \param int length longitud del array.
 * \return (totalSalary / (float)contEmployee) devolvera el resultado del promedio.
 */
float avarageEmployees(Employee* pEmployee,int lenght){
    int i;
    float totalSalary = 0;
    int contEmployee = 0;

    for(i=0;i < lenght; i++)
    {
        if(pEmployee[i].isEmpty == OCUPADO)
        {
            totalSalary = totalSalary + pEmployee[i].salary;
            contEmployee++;
        }
    }
    return (totalSalary / (float)contEmployee);
}

/** \brief Total de empleados que superan el promedio.
 * \param Employee* pEmployee array a ser comparado.
 * \param int length longitud del array.
 * \return int salaryAvarage personas que superan el salario promedio.
 */
int salaryExceededEmployee(Employee* pEmployee,int length,int salaryAvarage){
    int i;
    int salaryExceeded=0;

    for(i=0;i <length; i++)
    {
        if(pEmployee[i].salary > salaryAvarage && pEmployee[i].isEmpty == OCUPADO)
        {
            salaryExceeded++;
        }
    }
 return salaryExceeded;
}
