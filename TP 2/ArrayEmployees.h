#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


int findEmptyPlace(Employee* pEmployee, int length);
int initEmployees(Employee* pEmployee, int length);
int addEmployee(Employee* pEmployee,int length,char* name,char* lastName,float salary,int sector);
int findEmployeeById(Employee* pEmployee,int length,int id);
int removeEmployee(Employee* pEmployee,int length,int id);
int sortEmployees(Employee* pEmployee,int length,int order);
int printEmployees(Employee* pEmployee,int length);
int updateEmployee(Employee* pEmployee, int length,int id);

float avarageEmployees(Employee* pEmployee,int lenght);
int salaryExceededEmployee(Employee* pEmployee,int length,int salaryAvarage);


#endif // ARRAYEMPLOYEES_H_INCLUDED

