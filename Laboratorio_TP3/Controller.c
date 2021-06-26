#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int loaded = 0;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        loaded = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El archivo no existe.\n");
        system("pause");
    }

    return loaded;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int loaded = 0;

    FILE* pFile = fopen("data.bin", "rb");
    if(pFile != NULL)
    {
        loaded = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("El archivo no existe.\n");
        system("pause");
    }

    return loaded;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int added = 1;

    Employee* employee = employee_new();
    char id[10];
    char nombre[52];
    char horasTrabajadas[10];
    char sueldo[10];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID: ");
        scanf("%s", id);

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese Horas Trabajadas: ");
        scanf("%s", horasTrabajadas);

        printf("Ingrese Sueldo: ");
        scanf("%s", sueldo);


        employee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
        added = ll_add(pArrayListEmployee, employee);
    }
    else
    {
        printf("Error en lista de empleados.\n");
        system("pause");
    }
    return added;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int found = 0;
    int todoOK = 0;
    Employee* employee = employee_new();
    int id;
    char nombre[20];
    char horasTrabajadas[3];
    char sueldo[8];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            employee = ll_get(pArrayListEmployee, i);

            found = employee_getId(employee, &id);

            if(found)
            {
                switch(menuEdit())
                {
                case 1:
                    printf("Ingrese Nombre: ");
                    scanf("%s", nombre);
                    todoOK = employee_setNombre(employee, nombre);
                    break;
                case 2:
                    do
                    {
                        printf("Ingrese Horas Trabajadas: ");
                        scanf("%s", horasTrabajadas);
                        todoOK = employee_setHorasTrabajadas(employee, atoi(horasTrabajadas));
                    }
                    while(horasTrabajadas < 0);
                    break;
                case 3:

                    do
                    {
                        printf("Ingrese Sueldo: ");
                        scanf("%s", sueldo);
                        todoOK = employee_setSueldo(employee, atoi(sueldo));
                    }
                    while(sueldo < 0);
                    break;
                default:
                    break;
                }

                if(!todoOK)
                {
                    printf("No se ha modificado el campo correctamente.\n");
                }

                todoOK = ll_set(pArrayListEmployee, i, employee);
                break;
            }
        }
    }

    else
    {
        printf("No hay datos en la lista.\n");
    }

    return todoOK;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int id;
    int idAux;
    int len = ll_len(pArrayListEmployee);
    Employee* employee = employee_new();

    if(pArrayListEmployee != NULL && len > 0)
    {
        printf("Ingrese un ID: ");
        scanf("%d", &id);

        for(int i = 0; i < len; i++)
        {
            employee = (Employee*) ll_get(pArrayListEmployee, i); // guarda en el punter Employee el elemento del nodo ubicado en la posicion i;

            if(employee_getId(employee, &idAux))
            {
                if(idAux == id)
                {
                    todoOk = ll_remove(pArrayListEmployee, i);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int len = ll_len(pArrayListEmployee);
    Employee* employee;

    if(pArrayListEmployee != NULL && len > 0)
    {
        if(len != 0)
        {
            printf("     ID   NOMBRE   HORAS  SUELDO\n\n");
            for(int i = 1; i < len; i++)
            {
                employee = ll_get(pArrayListEmployee, i);
                employee_showEmployee(employee);

                todoOk = 1;
            }
        }
        else
        {
            printf("No hay empleados\n");
            system("pause");
        }
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && len > 0)
    {
        switch(menuSort())
        {
        case 1:
            ll_sort(pArrayListEmployee, employee_sortById,1);
            employee_showEmployees(pArrayListEmployee);
            break;
        case 2:
            ll_sort(pArrayListEmployee, employee_sortByName,1);
            employee_showEmployees(pArrayListEmployee);
            break;
        case 3:
            ll_sort(pArrayListEmployee, employee_sortByHsTrabajadas,1);
            employee_showEmployees(pArrayListEmployee);
            break;
        case 4:
            ll_sort(pArrayListEmployee, employee_sortBySueldo,1);
            employee_showEmployees(pArrayListEmployee);
            break;
        case 5:
            break;
        }
    }
    else
    {
        printf("No hay datos para ordenar\n");
        system("pause");
        error = 1;
    }
    system("pause");

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int saved = 0;
    int length;

    if(ll_len(pArrayListEmployee) == 0)
    {
        printf("No hay datos en la lista.\n");
        system("pause");
    }
    else
    {
        Employee* pEmployee = employee_new();

        FILE *pFile = fopen(path,"w");
        if(pFile==NULL)
        {
            printf("El archivo no existe.\n");
            system("pause");
        }
        else
        {
            length = ll_len(pArrayListEmployee);
            for(int i = 0; i < length; i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                fprintf(pFile, "%d, %s, %d, %d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);

            }
            saved = 1;
            fclose(pFile);
        }
    }

    return saved;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int saved = 0;

    FILE* pFile;
    pFile = fopen("data.bin", "wb");
    Employee* emp;

    if(ll_len(pArrayListEmployee)!= 0)
    {
        if(pArrayListEmployee != NULL)
        {
            for(int i = 0; i<ll_len(pArrayListEmployee); i++)
            {
                emp = (Employee*)ll_get(pArrayListEmployee, i);
                fwrite(emp, sizeof(Employee*), 1, pFile);
            }
            fclose(pFile);
            saved = 1;
        }
        else
        {
            printf("El archivo no existe.\n");
            system("pause");
        }
    }
    else
    {
        printf("No se encontraron datos\n");
        system("pause");
    }

    return saved;
}

int menuPrincipal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  ***MENU DE OPCIONES***                                                         \n");
        printf("  1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   \n");
        printf("  2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). \n");
        printf("  3. Alta de empleado                                                            \n");
        printf("  4. Modificar datos de empleado                                                 \n");
        printf("  5. Baja de empleado                                                            \n");
        printf("  6. Listar empleados                                                            \n");
        printf("  7. Ordenar empleados                                                           \n");
        printf("  8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     \n");
        printf("  9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   \n");
        printf(" 10. Salir                                                                       \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 10);

    return r;
}

int menuEdit()
{
    int opcion;

    do
    {
        system("cls");
        printf("Seleccione el campo a modificar\n");
        printf("1. Nombre\n");
        printf("2. Horas Trabajadas\n");
        printf("3. Sueldo\n");
        printf("4. Salir\n\n");
        printf("Opcion seleccionada: ");
        scanf("%d", &opcion);
    }
    while(opcion < 1 || opcion > 4);

    return opcion;
}

int menuSort()
{
    int opcion;

    do
    {
        system("cls");

        printf("Seleccione el ordenamiento\n");
        printf("1. Id\n");
        printf("2. Nombre\n");
        printf("3. Horas Trabajadas\n");
        printf("4. Sueldo\n");
        printf("5. Salir\n\n");
        printf("Opcion seleccionada: ");
        scanf("%d", &opcion);
    }
    while(opcion < 1 || opcion > 5);

    return opcion;
}

