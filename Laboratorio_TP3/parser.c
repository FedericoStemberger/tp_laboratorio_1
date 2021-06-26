#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int parsed = 0;
    int cant = 0;
    char idStr[6];
    char nombreStr[20];
    char horasTrabajadasStr[10];
    char sueldoStr[10];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            if(cant != 4)
            {
                printf("El archivo no se ha leido correctamente.\n");
                system("pause");
            }
            else
            {
                Employee* employee = employee_new();
                employee = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
                ll_add(pArrayListEmployee, employee);
            }
        }
    fclose(pFile);
    parsed = 1;
    }
    else
    {
        printf("No se han encontrado datos en el archivo.\n");
        system("pause");
    }

    return parsed;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int parsed = 0;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

                Employee* emp = employee_new();
                parsed = fread(emp, sizeof(Employee),1,pFile);
                if(parsed != 1)
                {
                    printf("El archivo no se ha leido correctamente.\n");
                    system("pause");
                }
                else
                {
                    ll_add(pArrayListEmployee, emp);
                }
        }
    fclose(pFile);
    parsed = 1;
    }
    else
    {
        printf("No se han encontrado datos en el archivo.\n");
        system("pause");
    }

    return parsed;
}
