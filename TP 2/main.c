#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include "controller.h"
#define CANTIDAD 1000

int main()
{
    Employee pEmployee[CANTIDAD];
    int menu;
    char mensajeMenu[]="\n MENU\
                        \n --------------------\
                        \n1-Alta de empleado.\
                        \n2-Baja de empleado.\
                        \n3-Modificar empleado.\
                        \n4-Informar.\
                        \n --------------------\
                        \n5-Salir.\n\
                        \nOpcion: ";
    char mensajeErrorMenu[]="Opcion invalida.\n";
    initEmployees(pEmployee,CANTIDAD);
    do{
        clearScreen();
        menu = 0;
        if(getValidInt(&menu,mensajeMenu,mensajeErrorMenu,1,5,5) == 0 ){
            switch(menu){
                case 1:
                        controller_addEmployee(pEmployee,CANTIDAD);
                       break;
                case 2:
                        controller_removeEmployee(pEmployee, CANTIDAD);
                        break;
                case 3:
                        controller_updateEmployee(pEmployee,CANTIDAD);
                        break;
                case 4:
                        controller_printEmployee(pEmployee, CANTIDAD);
                        break;
            }
        }
        else{
            break;
        }
    }while(menu != 5);
    return 0;
}
