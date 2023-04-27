#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include <stdio_ext.h>
#include <string.h>

int menuPrincipal()
{
    int opcion;
    printf("========\n");
    printf(" MENU\n");
    printf("========\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (txt).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (txt).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (binario).\n");
    printf("10.Salir.\n");

    opcion = getValidInt("\nIngrese opcion: ", "Error de ingreso, reintente.\n");
	printf("---------------------------------------------------------------------\n");
    return opcion;
}

static int menuModificar(){

	int opcion;
	printf("\n MODIFICAR \n");
	printf("------------\n");
	printf("1  Nombre\n");
	printf("2. Horas trabajadas.\n");
	printf("3. Sueldo.\n");
    opcion = getValidInt("\nIngrese opcion: ", "Error de ingreso, reintente.\n");
	printf("---------------------------------------------------------------------\n");
	return opcion;
}

static int menuOrdenar(){

	int opcion;
	printf("\n ORDENAR \n");
	printf("------------\n");
	printf("1. Id\n");
	printf("2  Nombre\n");
	printf("3. Horas trabajadas.\n");
	printf("4. Sueldo.\n");
	opcion = getValidInt("\nIngrese opcion: ", "Error de ingreso, reintente.\n");
	printf("---------------------------------------------------------------------\n");
	return opcion;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *  \param path char*
 *  \param pArrayListEmployee LinkedList*
 *  \return int
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if((pArchivo = fopen(path, "r")) != NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        retorno = 0;
    }
    else
    {
        printf("\nArchivo: \"%s\" no encontrado.\n\n", path);
    	printf("---------------------------------------------------------------------\n");
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if((pArchivo = fopen(path, "rb")) != NULL) //abro uno nuevo para luego guardar los datos en modo bin en el punto 8.
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        retorno = 0;
    }
    else
    {
    	if((pArchivo = fopen(path, "wb")) != NULL)
    	{
		//  printf("\nArchivo: \"%s\" no encontrado.\n\n", path);
			printf("\nArchivo no encontrado. Se creo uno con el nombre \"%s\"\n\n", path);
			printf("---------------------------------------------------------------------\n");
    	}
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char id[50], nombre[50], horasTrabajadas[50], sueldo[50];
    printf("=================\n");
    printf("ALTA DE EMPLEADO\n");
    printf("=================\n");
    Employee* this = employee_new();
    if(pArrayListEmployee != NULL)
    {
		if(!utn_getValidStringNumeros(id,"Ingrese ID: ","Error.\n","OVERFLOW.\n",5,3))
		{
			if(employee_nextId(this,pArrayListEmployee,id) == 1)
			{
				printf("---------------------------------------------------------------------\n");
				printf("ID en uso.\n");
			}
			else{
				if(!utn_getValidStringLetras(nombre,"Nombre: ","Error.\n","OVERFLOW.\n",50,3))
				{
					if(!utn_getValidStringNumeros(horasTrabajadas,"Horas trabajadas: ","Error.\n","OVERFLOW.\n",10,3))
					{
						if(!utn_getValidStringNumeros(sueldo,"Sueldo: ","Error.\n","OVERFLOW.\n",10,3))
						{
							this = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
							ll_add(pArrayListEmployee,this);
							retorno = 0;
						}
					}
				}
			}
		}
		printf("---------------------------------------------------------------------\n");
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id,idAux,horasTrabajadasAux;
    float sueldoAux;
    char nombre[50];
    char respuesta;
    Employee* this;
    printf("================\n");
    printf("EDITAR EMPLEADO\n");
    printf("================\n");
    if(pArrayListEmployee != NULL)
    {
        if(utn_getEntero(&id,"Ingrese ID: ","Error.\n",0,9999,3) == 0)
        {
        	idAux = employee_findById(pArrayListEmployee, id);
            if(idAux != -1){
            	printf("---------------------------------------------------------------------\n");
				this = ll_get(pArrayListEmployee, idAux);
	        	employee_printData(this);
	        	printf("---------------------------------------------------------------------\n");
	        	do{
					switch(menuModificar())
					{
						case 1:
							utn_getValidStringLetras(nombre,"Nombre: ","Error.\n","OVERFLOW.\n",50,3);
							employee_setNombre(this,nombre);
							retorno = 0;
							break;
						case 2:
							utn_getEntero(&horasTrabajadasAux,"Horas trabajadas: ","Error.\n",1,999,3);
							employee_setHorasTrabajadas(this,horasTrabajadasAux);
							retorno = 0;
							break;
						case 3:
							utn_getFlotante(&sueldoAux,"Sueldo: ","Error.\n",1,50000,3);
							employee_setSueldo(this,sueldoAux);
							retorno = 0;
							break;
						default:
							printf("Opcion incorrecta, reintente.\n\n");
							printf("\n---------------------------------------------------------------------\n");
							getchar();
					}
					printf("Seguir? S/N: ");
					__fpurge(stdin);
					scanf("%c", &respuesta);
				}while(respuesta == 's');
			}
            else
            {
            	printf("\n---------------------------------------------------------------------\n");
				printf("\nID incorrecto.\n");
				retorno = -2;
            }
        }
    }
	printf("---------------------------------------------------------------------\n");
    getchar();
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int id,idAux;
	char respuesta;
	Employee* this;
	printf("================\n");
	printf("BAJA DE EMPLEADO\n");
	printf("================\n");
	if(pArrayListEmployee != NULL)
	{
		if(!utn_getEntero(&id,"Ingrese ID: ","Error.\n",0,9999,3))
		{
			idAux =	employee_findById(pArrayListEmployee, id);
			if(idAux != -1)
			{
				printf("---------------------------------------------------------------------\n");
				this = ll_get(pArrayListEmployee, idAux);
				employee_printData(this);
				printf("---------------------------------------------------------------------\n");
				do
				{
					printf("\nBorrar? S/N: ");
					__fpurge(stdin);
					scanf("%c", &respuesta);
				}while(respuesta != 's' && respuesta != 'n');
				if(respuesta == 's'){
					ll_remove(pArrayListEmployee, idAux);
					retorno = 0;
				}
				else{
					printf("\nOperacion cancelada.\n");
					retorno = -2;
				}
			}
			else
			{
				printf("\n---------------------------------------------------------------------\n");
				printf("ID incorrecto.\n");
				retorno = -3;
			}
		}
	}
	printf("\n---------------------------------------------------------------------\n");
	getchar();
	return retorno;
}

/** \brief Listar empleados
 *  \param pArrayListEmployee LinkedList*
 *  \return int retorno 0 ok
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* this;
    printf("===================\n");
    printf("LISTA DE EMPLEADOS\n");
    printf("===================\n");
    if(pArrayListEmployee != NULL)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%50 == 0)
            {
                printf("\nPRESIONE ENTER PARA IMPRIMIR DE A 50 EMPLEADOS\n");
                getchar();
                this = (Employee*)ll_get(pArrayListEmployee,i);
                employee_printData(this);
                retorno = 0;
            }
           else
           {
                this = ll_get(pArrayListEmployee,i);
                employee_printData(this);
            }
        }
    }
	printf("\n---------------------------------------------------------------------\n");
    getchar();
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char respuesta;
    int orden;
    if(pArrayListEmployee != NULL)
    {
    	do
    	{
			switch(menuOrdenar())
			{
				case 1:
					utn_getEntero(&orden,"Ascendente[1] - Descendente[0]: ","Error.\n",0,1,3);
					printf("Se esta cargando...\n");
					ll_sort(pArrayListEmployee,employee_sortById,orden);
					controller_ListEmployee(pArrayListEmployee);
					retorno = 0;
					break;
				case 2:
					utn_getEntero(&orden,"Ascendente[1] - Descendente[0]: ","Error.\n",0,1,3);
					printf("Se esta cargando...\n");
					ll_sort(pArrayListEmployee,employee_sortByName,orden);
					controller_ListEmployee(pArrayListEmployee);
					retorno = 0;
					break;
				case 3:
					utn_getEntero(&orden,"Ascendente[1] - Descendente[0]: ","Error.\n",0,1,3);
					printf("Se esta cargando...\n");
					ll_sort(pArrayListEmployee,employee_sortByHoursWorked,orden);
					controller_ListEmployee(pArrayListEmployee);
					retorno = 0;
					break;
				case 4:
					utn_getEntero(&orden,"Ascendente[1] - Descendente[0]: ","Error.\n",0,1,3);
					printf("Se esta cargando...\n");
					ll_sort(pArrayListEmployee,employee_sortBySalary,orden);
					controller_ListEmployee(pArrayListEmployee);
					retorno = 0;
					break;
				default:
					printf("Opcion incorrecta, reintente.\n\n");
					getchar();
					break;
			}
		printf("Seguir? S/N: ");
		__fpurge(stdin);
		scanf("%c", &respuesta);
    	}while(respuesta == 's');
    	printf("\n---------------------------------------------------------------------\n");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *  \param path char*
 *  \param pArrayListEmployee LinkedList*
 *  \return int
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* this;
    int retorno = -1;
    int i;
    char nombre[51];
    int id;
    int horasTrabajadas;
    float sueldo;
    pArchivo = fopen(path, "w");
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArchivo);
        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(this,&id);
            employee_getNombre(this, nombre);
            employee_getHorasTrabajadas(this, &horasTrabajadas);
            employee_getSueldo(this, &sueldo);
            fprintf(pArchivo, "%d,%s,%d,%.2f\n", id, nombre, horasTrabajadas, sueldo);
        }
        printf("\nArchivo guardado.\n\n");
        retorno = 0;
    }
	printf("---------------------------------------------------------------------\n");
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    int lecturas;
    int i;
    pArchivo = fopen(path, "wb");
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArchivo);
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            Employee* this = (Employee*)ll_get(pArrayListEmployee,i);
            lecturas = fwrite(this, sizeof(Employee), 1, pArchivo);
          // retorno = 0;
            if(lecturas != 1)
            {
                printf("\nError.\n");
            }
            else{
                printf("\nArchivo guardado.\n\n");
                retorno = 0;
            }
        }
       // printf("\nArchivo guardado.\n\n");
    }
	printf("---------------------------------------------------------------------\n");
    fclose(pArchivo);
    return retorno;
}
