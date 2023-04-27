#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

//archivo data.csv ya editado y data.bin creado para probar funcionalidad dellas funciones.//
//editado jueves 8hs.

int main()
{
    int seguir = 's';
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char txtPath[50] = "data.csv";
    char binPath[50] = "data.bin";
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(ll_isEmpty(listaEmpleados))
            {
                if(controller_loadFromText(txtPath, listaEmpleados)==0)
                {
                	flag = 1;
                	printf("\nArchivo txt cargado correctamente.\n");
                	printf("---------------------------------------------------------------------\n");
                }
            }
            else
            {
            	printf("\nLa lista ya fue cargada en modo texto.\n\n");
            	printf("---------------------------------------------------------------------\n");
            }
            break;
        case 2:
        	if(flag == 1)
        	{
				if(controller_loadFromBinary(binPath, listaEmpleados)==0)
				{
                	printf("\nArchivo bin cargado correctamente.\n");
					printf("---------------------------------------------------------------------\n");
				}
			}
			else
			{
				printf("\nPrimero debes cargar la lista en modo txt.\n\n");
				printf("---------------------------------------------------------------------\n");
			}
        	break;
        case 3:
        	if(flag == 1)
        	{
				if(controller_addEmployee(listaEmpleados)==0)
				{
					printf("\nEmpleado agregado.\n\n");
					printf("---------------------------------------------------------------------\n");
				}
        	}
			else{
				printf("\nNo se cargaron empleados.\n\n");
				printf("---------------------------------------------------------------------\n");
			}
        	break;
        case 4:
        	if(flag == 1)
        	{
				if(controller_editEmployee(listaEmpleados)==0)
				{
					printf("\nEmpleado editado.\n\n");
					printf("---------------------------------------------------------------------\n");
				}
        	}
			else
			{
				printf("\nNo se cargaron empleados.\n\n");
				printf("---------------------------------------------------------------------\n");
			}
        	break;
        case 5:
        	if(flag == 1)
        	{
        		if(controller_removeEmployee(listaEmpleados)==0)
        		{
        			printf("\nEmpleado eliminado.\n\n");
        			printf("---------------------------------------------------------------------\n");
        		}
        	}
        	else{
                printf("\nNo se cargaron empleados.\n\n");
            	printf("---------------------------------------------------------------------\n");
        	}
        	break;
        case 6:
			if(flag == 1)
			{
				controller_ListEmployee(listaEmpleados);
			}
			else
			{
                printf("\nNo se cargaron empleados.\n\n");
            	printf("---------------------------------------------------------------------\n");
			}
            break;
        case 7:
        	if(flag == 1)
        	{
        		controller_sortEmployee(listaEmpleados);
        	 }
        	else
        	{
        		printf("\nNo se cargaron empleados.\n\n");
        		printf("---------------------------------------------------------------------\n");
        	}
        	break;
        case 8:
            if(flag == 1)
            {
                controller_saveAsText(txtPath,listaEmpleados);
            }
            else
            {
                printf("\nNo se cargaron empleados.\n\n");
            	printf("---------------------------------------------------------------------\n");
            }
            break;
        case 9:
        	if(flag == 1)
        	{
        		controller_saveAsBinary(binPath,listaEmpleados);
        	}
			else
			{
				printf("\nNo se cargaron empleados.\n\n");
				printf("---------------------------------------------------------------------\n");
			}
        	break;
        case 10:
        	return 0;
            break;
        default:
            printf("Opcion incorrecta, reintente.\n\n");
        	printf("---------------------------------------------------------------------\n");
            getchar();
        }
    }while(seguir == 's');
    return 0;
}
