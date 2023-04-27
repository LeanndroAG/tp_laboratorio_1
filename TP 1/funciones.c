#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXIMO 32767
#define MINIMO -32767
/** \brief Suma dos enteros.
 *
 * \param int operandoUno Se carga el 1er numero ingresado.
 * \param int operandoDos Se carga el 2do numero ingresado.
 * \param int*resultado Se carga el resultado.
 * \return int retorno Devuelvo 0 si esta ok, -2 si hay desborde de limites.
 *
 */
int suma(int operandoUno,int operandoDos,int *resultado){
    int resultadoAuxiliar;
    int retorno=-1;
    resultadoAuxiliar=operandoUno+operandoDos;
        if(resultadoAuxiliar>MAXIMO || resultadoAuxiliar<MINIMO){
            retorno=-2;
            }
        else{
            *resultado=operandoUno+operandoDos;
            retorno=0;
            }
    return retorno;
}
/** \brief Resta dos enteros.
 *
 * \param int operandoUno Se carga el 1er numero ingresado.
 * \param int operandoDos Se carga el 2do numero ingresado.
 * \param int*resultado Se carga el resultado.
 * \return int retorno Devuelvo 0 si esta ok, -2 si hay desborde de limites.
 *
 */
int resta(int operandoUno,int operandoDos,int *resultado){
    int resultadoAuxiliar;
    int retorno=-1;
    resultadoAuxiliar=operandoUno-operandoDos;
        if(resultadoAuxiliar>MAXIMO || resultadoAuxiliar<MINIMO){
            retorno=-2;
            }
        else{
            *resultado=operandoUno-operandoDos;
            retorno=0;
            }
    return retorno;
}
/** \brief Divide dos enteros.
 *
 * \param int operandoUno Se carga el 1er numero ingresado.
 * \param int operandoDos Se carga el 2do numero ingresado.
 * \param float*resultado Se carga el resultado.
 * \return int retorno Devuelvo 0 si esta ok, -2 si el 2do operando es 0 y -3 si hay desborde de limites.
 *
 */
int division(int operandoUno,int operandoDos,float *resultado){
    float resultadoAuxiliar;
    int retorno=-1;
    resultadoAuxiliar=(float)operandoUno/operandoDos;
        if(operandoDos==0){
            retorno=-2;
            }
        else if(resultadoAuxiliar>MAXIMO || resultadoAuxiliar<MINIMO){
            retorno=-3;
            }
        else{
            *resultado=resultadoAuxiliar;
            retorno=0;
            }
    return retorno;
}
/** \brief Multiplica dos enteros.
 *
 * \param int operandoUno Se carga el 1er numero ingresado.
 * \param int operandoDos Se carga el 2do numero ingresado.
 * \param int*resultado Se carga el resultado.
 * \return int retorno Devuelvo 0 si esta ok, -2 si hay desborde de limites.
 *
 */
int multiplicacion(int operandoUno,int operandoDos,int *resultado){
    int resultadoAuxiliar;
    int retorno=-1;
    resultadoAuxiliar=operandoUno*operandoDos;
        if(resultadoAuxiliar>MAXIMO || resultadoAuxiliar<MINIMO){
            retorno=-2;
            }
        else{
            resultadoAuxiliar=operandoUno*operandoDos;
            *resultado=resultadoAuxiliar;
            retorno=0;
            }
    return retorno;
}
/** \brief Factorial de un numero.
 *
 * \param int operando Se carga el numero ingresado.
 * \param int*resultado Se carga el resultado del factorial.
 * \return int retorno 0 si esta ok, -2 si es mayor a 8, -3 si es menor a 0, y -4 si es igual a 0.
 *
 */
int factorial(int operando, int*resultado){
    int i;
    int retorno=-1;
    int factorialAuxiliar=1;
    if(operando>8){
        retorno=-2;
    }
    else if(operando<0){
        retorno=-3;
    }
    else if(operando==0){
        retorno=-4;
    }
    else{
        for(i=1;i<=operando;i++){
            *resultado=factorialAuxiliar*=i;
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Pide un entero.
 *
 * \param char*mensaje Mensaje a ser mostrado.
 * \param char*mensajeError Mensaje de error por desborde de limites.
 * \param int intentos Intentos que tendra el usuario.
 * \param int maximoRango Limite maximo.
 * \param int minimoRango Limite minimo.
 * \param int*resultado Donde se cargara el resultado.
 * \return retorno -0 si esta todo ok, -1 si hay error.
 *
 */
int getInt( char *mensaje,char *mensajeError,int intentos,int maximoRango,int minimoRango,int *resultado){
    int auxiliarNumero;
    int retorno=-3;
    int i=1;
    do{
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%d",&auxiliarNumero);
            if(auxiliarNumero>=minimoRango && auxiliarNumero<=maximoRango)
                {
                *resultado=auxiliarNumero;
                retorno=0;
                break;
                }
            else{
                retorno=-1;
                printf("%s",mensajeError);
                }
        i++;
    }while(i<intentos);
    return retorno;
}
