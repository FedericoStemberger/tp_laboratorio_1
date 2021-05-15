#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menu.h"

#define TAM 10



int main()
{
    int idSeleccionado;
    int flagPermiso = 0;
    Employee Employees[TAM];/* =
    {
        {1, {"Federico"}, "Stemberger", 24000.0, 1, 0},
        {2, "Maria Eva", "Duarte", 58000.0, 2, 0},
        {3, "Bryan", "Ronzano", 50000.0, 3, 0},
        {4, "Leandro", "Ronzano", 40000.0, 1, 0},
        {5, "Ivan", "Stemberger", 72000.0, 4, 0}
    };*/
    initEmployees(Employees, TAM);
    char salir = 'n';
    do
    {
        switch(menu())
        {
        case 1:
            if(new_employee(Employees,TAM) == 0)
            {
                printf("El empleado ha sido ingresado con exito!\n");
                flagPermiso = 1;
            }
            else
            {
                printf("No se ha podido cargar el empleado\n");
            }
            break;

        case 2:
            if(flagPermiso == 1)
            {
                if(modifyEmployee(Employees, TAM) == -1)
                {
                    printf("No se pudo encontrar el empleado.\n");
                }
            }
            else
            {
                printf("Primero tiene que cargar un empleado.\n");
            }
            break;
        case 3:
            if(flagPermiso == 1)
            {
                idSeleccionado = buscarId(Employees, TAM);
                if(removeEmployee(Employees, TAM, idSeleccionado) == -1)
                {
                    printf("No se ha podido realizar la baja.\n");
                }
                else
                {
                    printf("La baja se ha realizado correctamente.\n");
                }
            }
            else
            {
                printf("Primero tiene que cargar un empleado.\n");
            }
            break;

        case 4:
            if(flagPermiso == 1)
            {
                switch(preguntarOrden())
                {
                case 1:
                    sortEmployees(Employees, TAM, 0);
                    printEmployees(Employees, TAM);
                    mostrarSalarios(Employees, TAM);
                    break;

                case 2:
                    sortEmployees(Employees, TAM, 1);
                    printEmployees(Employees, TAM);
                    mostrarSalarios(Employees, TAM);
                    break;
                }
            }
            else
            {
                printf("Primero tiene que cargar un empleado.\n");
            }
        }
        system("pause");
    }
    while(salir != 's');



    return 0;
}

