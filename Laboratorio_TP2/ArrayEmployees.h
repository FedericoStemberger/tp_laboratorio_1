#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;


int initEmployees(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int new_employee(Employee list[],int len);
int findEmployeeById(Employee list[], int len,int id);
int modifyEmployee(Employee list[], int len);
void printEmployees(Employee list[], int length);
void printEmployee(Employee employee);
int removeEmployee(Employee list[], int len, int id);
int buscarId(Employee list[], int len);
int sortEmployees(Employee list[], int len, int order);
void mostrarSalarios(Employee list[], int len);
void burbujeo(Employee list[], int i, int j);

#endif // ARRAYEMPLOYEES_H_INCLUDED
