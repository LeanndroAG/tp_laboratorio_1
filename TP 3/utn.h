#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/**\brief Solicita un n�mero al usuario y devuelve el resultado
 *
 */
int utn_getEntero(int* pEntero, char* mensaje, char* eMensaje, int min, int max, int reIntentos);

/**\brief Solicita un caracter al usuario y devuelve el resultado
 *
 */
int utn_getCaracter(char* pCaracter, char* mensaje, char* eMensaje, int min, int max, int reIntentos);

/**\brief Solicita un float al usuario y devuelve el resultado
 *
 */
float utn_getFlotante(float* pFlotante, char* mensaje, char* eMensaje, float min, float max, int reIntentos);

/**\brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt();

/**\brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat();

/**\brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar();

/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar);

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumerico(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char *str);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char *str);

/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida con un rango
 * \param requestMessage char[] Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage char[] Es el mensaje a ser mostrado en caso de error
 * \param lowLimit int Limite inferior para la comparacion
 * \param hiLimit int Limite maximo para la comparacion
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidIntRango(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]);

/** \brief Cambia las primeras letras a mayusculas
 *
 * \param input[] Cadena a modificar
 * \return void
 *
 */
void corregirMayusculas(char input[]);

/** \brief Obtiene y valida una cadena de caracteres
 *
 * \param requestMessage[] Mensaje a mostrar
 * \param errorMessage[] Mensaje de error
 * \param input[] variable de retorno por referencia
 * \param tamanio cantidd de caracteres permitidos
 * \return void
 *
 */
void getValidStringRango(char requestMessage[],char errorMessage[], char input[], int tamanio);

/** \brief Obtiene un string
 *
 * \param mensaje[] Mensaje a mostrar
 * \param input[] variable de retorno por referencia
 * \param tamanio cantidd de caracteres permitidos
 * \return int (1) si es solo letras - (0) si no lo es
 *
 */
int getStringLetrasRango(char mensaje[],char input[], int tamanio);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[]);

/** \brief retorna un caracter validado con 2 comparaciones
 *
 * \param requestMessage[] char mensaje solicitando ingreso de datos
 * \param errorMessage[] char mensaje de error
 * \param comparacionA char primera comparacion
 * \param comparacionB char primera comparacion
 * \return char caracter valido
 *
 */
char getValidChar(char requestMessage[], char errorMessage[], char comparacionA, char comparacionB);

/** \brief Solicita un numero, lo valida y lo retorna
 *
 * \param requestMessage[] Mensaje solicitando numero
 * \param errorMessage[] Mnsaje error
 * \return float El numero validado
 *
 */
float getValidFloat(char requestMessage[],char errorMessage[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida con un comparando con 2 numeros
 * \param requestMessage char[] Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage char[] Es el mensaje a ser mostrado en caso de error
 * \param comparacionA int Primera comparacion
 * \param comparacionA int Segunda comparacion
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidIntOpcion(char requestMessage[],char errorMessage[], int comparacionA, int comparacionB);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);

/** \brief Valida el ingreso de caracteres para un archivo
 *
 * \param requestMessage[] char Mensaje solicitando datos
 * \param errorMessage[] char Mensaje error
 * \param input[] char Almacenamiento de texto
 * \return void
 *
 */
void getValidStringEntrada(char requestMessage[],char errorMessage[], char input[]);
int utn_esNumerico(char* str);
int utn_getStringNumeros(char* input,char* mensaje);
int utn_getValidStringNumeros(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos);
int utn_esSoloLetras(char* str);
void utn_getString(char* input,char* mensaje);
int utn_getStringLetras(char* input,char* mensaje);
int utn_getValidStringLetras(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos);


#endif // UTN_H_INCLUDED
