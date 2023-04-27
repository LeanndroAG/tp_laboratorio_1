#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getInt( char*mensaje,char*mensajeError,int intentos,int maximo,int minimo,int*resultado);
int suma(int operandoUno,int operandoDos,int*resultado);
int resta(int operandoUno,int operandoDos,int*resultado);
int multiplicacion(int operandoUno,int operandoDos,int*resultado);
int division(int operandoUno,int operandoDos,float*resultado);
int factorial(int operando, int*resultado);

#endif // FUNCIONES_H_INCLUDED
