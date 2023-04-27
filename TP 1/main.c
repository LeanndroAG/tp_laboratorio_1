#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion,resultado=0,operandoUno=0,operandoDos=0,flag=0,resultadoFactorialUno=0,resultadoFactorialDos=0;
    float resultadoDivision=0;
    do{
        system("cls");
        printf("----------------------------------\n");
        printf("\t  CALCULADORA \n\n");
        printf("1. Ingresar 1er operando:(A=%d).\n", operandoUno);
        printf("2. Ingresar 2do operando:(B=%d).\n", operandoDos);
        printf("3. Calcular todas las operaciones.\n");
        printf("   -Suma\n   -Resta\n   -Division\n   -Multiplicacion\n   -Factorial A\n   -Factorial B\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n");
        printf("----------------------------------\n");
        getInt("\nOpcion: ","ERROR. Elija una opcion valida.\n",30000,5,1, &opcion);
        switch(opcion){
            case 1:
                    system("cls");
                    if(getInt("Ingrese el 1er numero entero: ","ERROR. numeros validos: -32767 a 32767\n",4,32767,-32767, &resultado)==0){
                    operandoUno=resultado;
                    }
                    break;
            case 2:
                    system("cls");
                    if(getInt("Ingrese el 2do numero entero: ","ERROR. numeros validos: -32767 a 32767\n",4,32767,-32767, &resultado)==0){
                    operandoDos=resultado;
                    }
                    break;
            case 3:
                    flag++;
                    suma(operandoUno,operandoDos, &resultado);
                    resta(operandoUno,operandoDos, &resultado);
                    division(operandoUno,operandoDos, &resultadoDivision);
                    multiplicacion(operandoUno,operandoDos, &resultado);
                    factorial(operandoUno,&resultadoFactorialUno);
                    factorial(operandoDos,&resultadoFactorialDos);
                    system("pause");
                    break;
            case 4:
                    if(flag==0){
                        printf("\nPrimero debe realizar los calculos. \n\n");
                    }
                    else{
                        if(suma(operandoUno,operandoDos,&resultado)==-2){
                            printf("A) ERROR OVERFLOW.\n");
                        }
                        else{
                            printf("A) El resultado de A+B es: %d\n", resultado);
                        }
                        if(resta(operandoUno,operandoDos,&resultado)==-2){
                            printf("B) ERROR OVERFLOW.\n");
                        }
                        else{
                            printf("B) El resultado de A-B es: %d\n", resultado);
                        }
                        if(division(operandoUno,operandoDos,&resultadoDivision)==-2){
                            printf("C) ERROR. No se puede dividir por 0\n");
                        }
                        else if(division(operandoUno,operandoDos,&resultadoDivision)==-3){
                            printf("C) ERROR OVERFLOW.\n");
                        }
                        else{
                            printf("C) El resultado de A/B es: %.2f \n", resultadoDivision);
                        }
                        if(multiplicacion(operandoUno,operandoDos, &resultado)==-2){
                            printf("D) ERROR OVERFLOW.\n");
                        }
                        else{
                            printf("D) El resultado de A*B es: %d\n", resultado);
                        }
                        if(factorial(operandoUno,&resultadoFactorialUno)==-2){
                            printf("E) ERROR OVERFLOW.\n");
                        }
                        else if(factorial(operandoUno,&resultadoFactorialUno)==-3){
                            printf("E) No existe factorial de numeros negativos.\n");
                        }
                        else if(factorial(operandoUno,&resultadoFactorialUno)==-4){
                            printf("E) El factorial A es: 1\n");
                        }
                        else{
                            printf("E) El factorial A es: %d\n",resultadoFactorialUno);
                        }
                        if(factorial(operandoDos,&resultadoFactorialDos)==-2){
                            printf("F) ERROR OVERFLOW.\n");
                        }
                        else if(factorial(operandoDos,&resultadoFactorialDos)==-3){
                            printf("F) No existe factorial de numeros negativos.\n");
                        }
                        else if(factorial(operandoDos,&resultadoFactorialDos)==-4){
                            printf("E) El factorial B es: 1\n");
                        }
                        else{
                            printf("F) El factorial B es: %d\n",resultadoFactorialDos);
                        }
                        flag--;
                    }
                    system("pause");
                    break;
            case 5:
                    opcion=5;
        }
    }while(opcion!=5);
    return 0;
}
