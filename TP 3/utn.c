#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

static char static_getChar(char* pBuffer){
    return scanf("%c", pBuffer);
}
static int static_getInt(int* pBuffer){   //GUARDO
    return scanf("%d", pBuffer);
}
static float static_getFloat(float* pBuffer){ // GUARDO
	return scanf("%f",pBuffer);
}
float utn_getFlotante(float* pFlotante, char* mensaje, char* eMensaje, float min, float max, int reIntentos){
	int retorno=-1;   // GUARDO
	    float bufferFloat;
	    if(pFlotante != NULL && mensaje != NULL && eMensaje != NULL && reIntentos >=0){
	        do{
	            reIntentos--;
	            printf("%s", mensaje);
	           // __fpurge(stdin);
	            if( (static_getFloat(&bufferFloat) == 1) && (bufferFloat >= min && bufferFloat <= max) ){
	                  *pFlotante = bufferFloat;
	                  retorno=0;
	                  break;
	            }
	            else{
	                __fpurge(stdin);
	                printf("%s", eMensaje);
	            }
	        }while(reIntentos>=0);
	    }
	    return retorno;
}

int utn_getEntero(int* pEntero, char* mensaje, char* eMensaje, int min, int max, int reIntentos){
    int retorno=-1;
    int bufferInt;        // GUARDO
    if(pEntero != NULL && mensaje != NULL && eMensaje != NULL && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            __fpurge(stdin);
            if( (static_getInt(&bufferInt) == 1) && (bufferInt >= min && bufferInt <= max) ){
                  *pEntero = bufferInt;
                  retorno=0;
                  break;
            }
            else{
                printf("%s", eMensaje);
            }
        }while(reIntentos>=0);
    }
    return retorno;
}

int utn_getCaracter(char* pCaracter, char* mensaje, char* eMensaje, int min, int max, int reIntentos){
    int retorno=-1;
    char bufferChar;
    if(pCaracter != NULL && mensaje != NULL && eMensaje != NULL && min <= max && reIntentos >=0){
        do{
            reIntentos--;
            printf("%s", mensaje);
            if( (static_getChar(&bufferChar)==1)&&(bufferChar >= min && bufferChar <= max) ){
                    *pCaracter=bufferChar;
                    retorno=0;
                    break;
            }
            else{
                __fpurge(stdin);
                printf("%s", eMensaje);
            }
        }while(reIntentos>0);
    }
    return retorno;
}

float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    __fpurge(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

char getValidChar(char requestMessage[], char errorMessage[], char comparacionA, char comparacionB)
{
    char auxiliar;
    printf("%s",requestMessage);
    __fpurge(stdin);
    scanf("%c",&auxiliar);
    while(auxiliar!='s' && auxiliar!='n'){
        printf("%s",errorMessage);
        printf("%s",requestMessage);
        __fpurge(stdin);
        scanf("%c",&auxiliar);

    }
    return auxiliar;
}

char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
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

int esNumerico(char str[]) // GUARDO
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico( char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != '.') && (str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones == 1)
        return 1;

    return 0;
}

void getString(char mensaje[],char input[]) //GUARDO
{
    printf("%s",mensaje);
    __fpurge(stdin);
    scanf("%[^\n]s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[]) // GUARDO
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidIntRango(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }
}

int getValidIntOpcion(char requestMessage[],char errorMessage[], int comparacionA, int comparacionB)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt != comparacionA && auxInt != comparacionB)
        {
            printf ("El numero ingresado debe ser %d o %d.\n\n", comparacionA, comparacionB);
            continue;
        }
        return auxInt;
    }
}

int getValidInt(char requestMessage[],char errorMessage[]) // GUARDO
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        return auxInt;
    }
}

void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

float getValidFloat(char requestMessage[],char errorMessage[])
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        break;
    }
    auxFloat = atof(auxStr);
    return auxFloat;
}

void getValidStringEntrada(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        getString(requestMessage, input);
        if (!esAlfaNumerico(input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

int utn_esNumerico(char* str){
    int i=0;
    int retorno=0;
    if(str != NULL){
        while(str[i] != '\0'){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            i++;
            if(str[i]=='\0'){
                retorno = 1;
            }
        }
    }
    return retorno;
}

void utn_getString(char* input,char* mensaje){
    int cantidad;
    char buffer[256];
    printf("%s",mensaje);   // GUARDO
    __fpurge(stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);
    cantidad = strlen(buffer);
    buffer[cantidad-1] = '\0';
    strcpy(input,buffer);
}


int utn_getStringNumeros(char* input,char* mensaje){
     char aux[256];
     utn_getString(aux,mensaje);
     if(utn_esNumerico(aux)){  // GUARDO
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }

int utn_getValidStringNumeros(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos){
    int i;
    int retorno=-1;          // GUARDO
    char buffer[1024];

    for(i=0;i<reIntentos;i++)
    {
        if (!utn_getStringNumeros(buffer,mensaje))
        {
            printf ("%s",eMensaje);
            continue;
        }
        if(strlen(buffer) >= maxLargo)
        {
            printf ("%s",eMensajeLargo);
            __fpurge(stdin);
            continue;
        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

int utn_esSoloLetras(char* str){
    int i = 0;
    int retorno = 0;   // GUARDO
    if(str != NULL){
        while(str[i] != '\0'){
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                break;
            }
            i++;
            if(str[i]=='\0'){
                retorno = 1;
            }
        }
    }
    return retorno;
}

int utn_getStringLetras(char* input,char* mensaje){
    char aux[256];
    utn_getString(aux,mensaje);
    if(utn_esSoloLetras(aux)){  // GUARDO
        strcpy(input,aux);
        return 1;
    }
    return 0;
 }

int utn_getValidStringLetras(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos){
    int i;
    int retorno=-1;           // GUARDO
    char buffer[1024];

    if(input != NULL && mensaje != NULL && eMensaje != NULL && eMensajeLargo != NULL && reIntentos >=0){
        for(i=0;i<reIntentos;i++)
        {
            if (!utn_getStringLetras(buffer,mensaje))
            {
                printf ("%s",eMensaje);
                continue;
            }
            if(strlen(buffer) >= maxLargo)
            {
                printf ("%s",eMensajeLargo);
                __fpurge(stdin);
                continue;
            }
            retorno=0;
            strcpy(input,buffer);
            break;
        }
    }
    return retorno;
}

