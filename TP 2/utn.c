#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

/** \brief solicita un entero.
 */
static int getInt(int* pBuffer){
    return scanf("%d", pBuffer);
}

/** \brief solicita un flotante.
 */
static float getFloat(float* pBuffer){
    return scanf("%f", pBuffer);
}
/** \brief solicita un caracter.
 */
static char getChar(char* pBuffer){
    return scanf("%c", pBuffer);
}

/** \brief solicita un entero largo.
 */
static int getLongInt(long int* pBuffer){
return scanf("%ld", pBuffer);
}

/** \brief solcita un entero largo.
 * \param  pLongInt parametro donde se cargara el long int.
 * \param  mensaje  mensaje a ser mostrado.
 * \param  eMensaje mensaje de error.
 * \param  min numero minimo permitido.
 * \param  max numero maximo permitido.
 * \param  reIntentos cantidad de reintentos.
 * \return -1 si esta mal, 0 si esta bien.
 */
int utn_getLongInt(long int* pLongInt, char* mensaje, char* eMensaje, long int min, long int max, int reIntentos){
    int retorno=-1;
    long int bufferLongInt;
    if(pLongInt != NULL && mensaje != NULL && eMensaje != NULL && min <= max && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            if( (getLongInt(&bufferLongInt) == 1) && (bufferLongInt >= min && bufferLongInt <= max) ){
                  *pLongInt = bufferLongInt;
                  retorno=0;
                  break;
            }
            else{
                fflush(stdin);
                printf("%s", eMensaje);
            }
        }while(reIntentos>0);
    }
    return retorno;
}

/** \brief solcita un entero.
 * \param  pEntero parametro donde se cargara el int.
 * \param  mensaje  mensaje a ser mostrado.
 * \param  eMensaje mensaje de error.
 * \param  min numero minimo permitido.
 * \param  max numero maximo permitido.
 * \param  reIntentos cantidad de reintentos.
 * \return -1 si esta mal, 0 si esta bien.
 */
int utn_getEntero(int* pEntero, char* mensaje, char* eMensaje, int min, int max, int reIntentos){
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && mensaje != NULL && eMensaje != NULL && min <= max && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            if( (getInt(&bufferInt) == 1) && (bufferInt >= min && bufferInt <= max) ){
                  *pEntero = bufferInt;
                  retorno=0;
                  break;
            }
            else{
                printf("%s", eMensaje);
                fflush(stdin);
            }
        }while(reIntentos>=0);
    }
    return retorno;
}

/** \brief solcita un flotante.
 * \param  pFlotante parametro donde se cargara el float.
 * \param  mensaje  mensaje a ser mostrado.
 * \param  eMensaje mensaje de error.
 * \param  min numero minimo permitido.
 * \param  max numero maximo permitido.
 * \param  reIntentos cantidad de reintentos.
 * \return -1 si esta mal, 0 si esta bien.
 */
int utn_getFlotante(float* pFlotante, char* mensaje, char* eMensaje, float min, float max, int reIntentos){
    int retorno=-1;
    float bufferFloat;
    if(pFlotante != NULL && mensaje != NULL && eMensaje != NULL && min <= max && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            if( (getFloat(&bufferFloat)==1) && (bufferFloat >= min && bufferFloat <= max) ){
                    *pFlotante=bufferFloat;
                    retorno=0;
                    break;
            }
            else{
                fflush(stdin);
                printf("%s", eMensaje);
            }
        }while(reIntentos>0);
    }
    return retorno;
}

/** \brief solcita un caracter.
 * \param  pCaracter parametro donde se cargara el char.
 * \param  mensaje  mensaje a ser mostrado.
 * \param  eMensaje mensaje de error.
 * \param  min rango minimo permitido.
 * \param  max rango maximo permitido.
 * \param  reIntentos cantidad de reintentos.
 * \return -1 si esta mal, 0 si esta bien.
 */
int utn_getCaracter(char* pCaracter, char* mensaje, char* eMensaje, int min, int max, int reIntentos){
    int retorno=-1;
    char bufferChar;
    if(pCaracter != NULL && mensaje != NULL && eMensaje != NULL && min <= max && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            if( (getChar(&bufferChar)==1)&&(bufferChar >= min && bufferChar <= max) ){
                    *pCaracter=bufferChar;
                    retorno=0;
                    break;
            }
            else{
                fflush(stdin);
                printf("%s", eMensaje);
            }
        }while(reIntentos>0);
    }
    return retorno;
}

/** \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumericoFlotante(char* str){
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0'){
       if (i == 0 && str[i] == '-'){
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0){
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/** \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char* str){
    int i=0;
    while(str[i] != '\0'){
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int esSoloLetras(char* str){
    int i=0;
    while(str[i] != '\0'){
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */
int esAlfaNumero(char* str){
     int i=0;
     while(str[i] != '\0'){
         if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
             return 0;
         i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 */
int esTelefono(char* str){
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0'){
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1)
        return 1;

    return 0;
}

/** \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char* input,char* mensaje){
    printf(mensaje);
    scanf("%s", input);
}

/** \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
 int getStringNumeros(char* input,char* mensaje){
     char aux[256];
     getString(aux,mensaje);
     if(esNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }

/** \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
 int getStringLetras(char* input,char* mensaje){
    char aux[256];
    getString(aux,mensaje);
    if(esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }

/** \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char* input,char* mensaje)
{
    char aux[256];
    getString(aux,mensaje);
    if(esNumericoFlotante(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief Solicita un String
 * \param input Array donde se cargará el texto ingresado
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param eMensaje Es el mensaje a ser mostrado en caso de error de tipo
 * \param eMensajeLargo Es el mensaje a ser mostrado en caso de error de longitud
 * \param maxLargo int Longitud maxima del texto ingresado
 * \param reintetos indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 */
int getValidString(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<reIntentos;i++)
    {
        if (!getStringLetras(buffer,mensaje))
        {
            printf ("%s",eMensaje);
            continue;
        }
        if(strlen(buffer) >= maxLargo)
        {
            printf ("%s",eMensajeLargo);
            fflush(stdin);
            continue;
        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

/** \brief Solicita un string
 * \param input Array donde se cargará el texto numerico
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param eMensaje Es el mensaje a ser mostrado en caso de error de tipo
 * \param eMensajeLargo Es el mensaje a ser mostrado en caso de error de longitud
 * \param maxLargo int Longitud maxima del texto ingresado
 * \param reintetos indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 */
int getValidInt(int* input,char* mensaje,char* eMensaje, int min,int max,int reIntentos)
{
    int i;
    int auxInt;
    int retorno=-1;
    char auxStr[256];

    for(i=0;i<reIntentos;i++)
    {
        if (!getStringNumeros(auxStr,mensaje))
        {
            printf ("%s",eMensaje);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < min || auxInt > max)
        {
            printf ("%s",eMensaje);
            continue;
        }
        *input = auxInt;
        retorno=0;
        break;
    }
    return retorno;
}

/** \brief Solicita un string
 * \param input Array donde se cargará el texto numerico flotante
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param eMensaje Es el mensaje a ser mostrado en caso de error de tipo
 * \param eMensajeLargo Es el mensaje a ser mostrado en caso de error de longitud
 * \param maxLargo int Longitud maxima del texto ingresado
 * \param reintetos indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 */
int getValidSFloat(float* input, char* mensaje,char* eMensaje, float min,float max,int reIntentos)
{
    int i;
    int retorno=-1;
    float auxFloat;
    char auxStr[256];

    for(i=0;i<reIntentos;i++)
    {
        if (!getStringNumerosFlotantes(auxStr,mensaje))
        {
            printf ("%s",eMensaje);
            continue;
        }
        auxFloat = atof(auxStr);
        if(auxFloat < min || auxFloat > max)
        {
            printf ("%s",eMensaje);
            continue;
        }
        *input = auxFloat;
        retorno=0;
        break;
    }
    return retorno;
}

void clearScreen(void)
{
    system("clear");
}
