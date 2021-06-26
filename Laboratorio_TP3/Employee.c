#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{
    Employee* employee;
    employee = (Employee*)malloc(sizeof(Employee));
    employee->id = 0;
    strcpy(employee->nombre, "");
    employee->horasTrabajadas = 0;
    employee->sueldo = 0;

    return employee;
};

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* employee;
    employee = (Employee*)malloc(sizeof(Employee));
    employee_setId(employee,atoi(idStr));
    employee_setNombre(employee,nombreStr);
    employee_setHorasTrabajadas(employee,atoi(horasTrabajadasStr));
    employee_setSueldo(employee,atoi(sueldoStr));

    return employee;
};

void employee_delete()
{

};


void  employee_showEmployee(Employee* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %10s   %3d   %5d \n\n ", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}

void  employee_showEmployees(LinkedList* this)
{
    Employee* emp;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this); i++)
        {
            emp = (Employee*)ll_get(this, i+1);
            employee_showEmployee(emp);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        system("pause");
    }

}

int employee_sortByName(void* empleadoA, void* empleadoB)
{
    int sorted;
    sorted = strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre);
    return sorted;
}


int employee_sortById(void* empleadoA, void* empleadoB)
{
    int sorted;
    if(((Employee*)empleadoA)->id > ((Employee*)empleadoB)->id)
    {
        sorted = 1;
    }
    if(((Employee*)empleadoA)->id < ((Employee*)empleadoB)->id)
    {
        sorted = -1;
    }
    else
    {
        sorted = 0;
    }
    return sorted;

}

int employee_sortByHsTrabajadas(void* empleadoA, void* empleadoB)
{
    int sorted;
    if(((Employee*)empleadoA)->horasTrabajadas > ((Employee*)empleadoB)->horasTrabajadas)
    {
        sorted = 1;
    }
    else if(((Employee*)empleadoA)->horasTrabajadas < ((Employee*)empleadoB)->horasTrabajadas)
    {
        sorted = -1;
    }
    else
    {
        sorted = 0;
    }
    return sorted;
}

int employee_sortBySueldo(void* empleadoA, void* empleadoB)
{
    int sorted;
    if(((Employee*)empleadoA)->sueldo > ((Employee*)empleadoB)->sueldo)
    {
        sorted = 1;
    }
    else if(((Employee*)empleadoA)->sueldo < ((Employee*)empleadoB)->sueldo)
    {
        sorted = -1;
    }
    else
    {
        sorted = 0;
    }
    return sorted;
}

int employee_setId(Employee* this,int id)
{
    int set = 0;
    if( id > 0 && this != NULL)
    {
        this->id = id;
        set = 1;
    }
    return set;
}

int employee_getId(Employee* this,int* id)
{
    int gotten = 0;

    if( this != NULL )
    {
        *id = this->id;
        gotten = 1;
    }

    return gotten;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int set = 0;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        set = 1;
    }
    return set;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int gotten;
    gotten = 0;

    if(this != NULL)
    {
        strcpy(nombre,(*this).nombre);
        gotten=1;
    }

    return gotten;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int set = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        set = 1;
    }
    return set;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int gotten;
    gotten = 0;

    if(this != NULL)
    {
        *horasTrabajadas = (*this).horasTrabajadas;
        gotten=1;
    }

    return gotten;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int set = 0;
    if(this != NULL)
    {
        this->sueldo= sueldo;
        set = 1;
    }
    return set;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int gotten;
    gotten = 0;

    if(this != NULL)
    {
        *sueldo = (*this).sueldo;
        gotten=1;
    }

    return gotten;
}


