#include "ArrayEmployees.h"
#include "utn.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_addEmployee(Employee* pEmployee, int length);
int controller_removeEmployee(Employee* pEmployee, int length);
int controller_updateEmployee(Employee* pEmployee, int length);
int controller_printEmployee(Employee* pEmployee, int length);

#endif // CONTROLLER_H_INCLUDED
