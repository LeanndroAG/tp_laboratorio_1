#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
int utn_getEntero(int* pEntero, char* mensaje, char* eMensaje, int min, int max, int reIntentos);
int utn_getFlotante(float* pFlotante, char* mensaje, char* eMensaje, float min, float max, int reIntentos);
int utn_getCaracter(char* pCaracter, char* mensaje, char* eMensaje, int min, int max, int reIntentos);
int utn_getLongInt(long int* pLongInt, char* mensaje, char* eMensaje, long int min, long int max, int reIntentos);

void clearScreen(void);

int esNumerico(char* str);
int esTelefono(char* str);
int esAlfaNumero(char* str);
int esSoloLetras(char* str);
int esNumericoFlotante(char* str);

void getString(char* input,char* mensaje);
int getStringLetras(char* input,char* mensaje);
int getStringNumeros(char* input,char* mensaje);
int getStringNumerosFlotantes(char* input,char* mensaje);

int getValidString(char* input,char* mensaje,char* eMensaje, char* eMensajeLargo,int maxLargo,int reIntentos);
int getValidInt(int* input,char* mensaje,char* eMensaje, int min,int max,int reIntentos);
int getValidSFloat(float* input, char* mensaje,char* eMensaje, float min,float max,int reIntentos);
#endif // UTN_H_INCLUDED
