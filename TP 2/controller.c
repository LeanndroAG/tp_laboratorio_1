#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"

int flag = 0;

int controller_addEmployee(Employee* pEmployee, int length){
    int retorno = -2;
    int index;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    clearScreen();
    printf("================\n");
    printf("ALTA DE CLIENTE\n");
    printf("================\n\n");

    if(findEmptyPlace(pEmployee,length) >= 0){
        if(pEmployee != NULL && length > 0){
            retorno = -2;
            index = findEmptyPlace(pEmployee,length);
            if(index >= 0){
                retorno=-3;
                if(!getValidString(name,"\nNombre: ","Error.\n", "OVERFLOW.\n", 51, 3))
                    if(!getValidString(lastName, "Apellido: ", "Error.\n", "OVERFLOW.\n", 51, 3))
                       if(!getValidSFloat(&salary,"Salario: ", "Error. Salario minimo 10mil - maximo 80Mil.\n", 10000, 80000, 3))
                          if(!getValidInt(&sector, "Sector: ", "Error. Sectores del 1 al 100.\n", 1, 100, 3)){
                                retorno = addEmployee(pEmployee,length,name,lastName,salary,sector);
                                printf("---------------");
                                printf("\nAlta completa.\n");
                                flag++;
                                getchar();
                            }

                   }
            }

        }
    else{
        printf("\nNo hay lugar.\n");
        getchar();
    }
    getchar();
    return retorno;
}

int controller_removeEmployee(Employee* pEmployee, int length){

    int retorno = -3;
    int idAux;

    clearScreen();
    printf("================\n");
    printf("BAJA DE CLIENTE\n");
    printf("================\n\n");
    if(flag == 0){
        printf("\nNo hay empleados cargados.\n");
        getchar();
        retorno = -2;
    }
    else{
        printEmployees(pEmployee,length);
        if(getValidInt(&idAux,"\nID: ","Error. Rango validos: 0 a 1000. \n",0,999,3) == 0){
            if(removeEmployee(pEmployee,length,idAux) == 0){
                printf("--------------------");
                printf("\nEmpleado eliminado.\n");
                flag--;
                getchar();
                retorno = 0;
            }
            else{
                printf("-----------------\n");
                printf("\nID inexistente.\n");
                getchar();
                retorno = -1;
            }
        }
    }
    getchar();
    return retorno;
}

int controller_updateEmployee(Employee* pEmployee, int length){

    int idAux;
    int retorno = -3;

    clearScreen();
    printf("=====================\n");
    printf("MODIFICAR DE CLIENTE\n");
    printf("=====================\n\n");
    if(flag == 0){
        printf("\nNo hay empleados cargados.\n");
        getchar();
        retorno = -2;
    }
    else{
        printEmployees(pEmployee,length);
        if(getValidInt(&idAux,"\nID: ","Error. Rango validos: 0 a 1000. \n",0,999,3) == 0){
            if(updateEmployee(pEmployee,length,idAux) == 0){
                printf("---------------------");
                printf("\nEmpleado modificado.\n");
                getchar();
                retorno = 0;
            }
            else{
                printf("-----------------\n");
                printf("\nID inexistente.\n");
                getchar();
                retorno = -1;
            }
        }
    }
    getchar();
    return retorno;
}

int controller_printEmployee(Employee* pEmployee, int length){

    int salaryAux;
    float avarageAux;
    int retorno = -2;
    int order;

    clearScreen();
    printf("=================\n");
    printf("INFORMAR CLIENTE\n");
    printf("=================\n\n");
    if(flag == 0){
        printf("\nNo hay empleados cargados.\n");
        getchar();
        retorno = -1;
    }
    else{
        getValidInt(&order,"0 - Orden ascendente\n1 - Orden descendente\n\n","Error.\n",0,1,2);
        sortEmployees(pEmployee,length,order);
        printEmployees(pEmployee,length);
        avarageAux=avarageEmployees(pEmployee,length);
        salaryAux=salaryExceededEmployee(pEmployee,length,avarageAux);
        printf("\n- Salario promedio: %.2f\n", avarageAux);
        printf("\n- Empleados que superan el promedio: %d\n", salaryAux);
        getchar();
        retorno = 0;
    }
    getchar();
    return retorno;
}

