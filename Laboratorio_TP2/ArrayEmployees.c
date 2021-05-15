#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menu.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    int error = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].id = 0;
            strcpy(list[i].name, " ");
            strcpy(list[i].lastName, " ");
            list[i].salary = 0;
            list[i].sector = 0;
            list[i].isEmpty = 1;
        }
        error = 0;
    }

    return error;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 *
 * \param list[] Employee array
 * \param len int tamanio del array
 * \param id int id a guardar en el lugar libre
 * \param name[] char nombre a guardar en el lugar libre
 * \param lastName[] char apellido a guardar en el lugar libre
 * \param salary float salario a guardar en el lugar libre
 * \param sector int sector a guardar en el lugar libre
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int error = -1;

    for(int i = 0; i < len; i++)
    {
        if(list != NULL && len > 0 && list[i].isEmpty == 1)
        {
            list[i].id = id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;

            error = 0;
            break;
        }
    }
    return error;
}

/** \brief Pide los datos del nuevo empleado al usuario
 *
 * \param list[] Employee array
 * \param len int tamanio del array
 * \return int Devuelve -1 si el array es inexistente, si el tamanio no es mayor a 0 o si no hay espacio en el array. Devuelve 0 si no hay ningun error.
 *
 */
int new_employee(Employee list[],int len)
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int error = -1;

    for(int i = 0; i < len; i++)
    {
        if(list != NULL && len > 0 && list[i].isEmpty == 1)
        {
            system("cls");
            id = i + 1;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(name);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(lastName);

            printf("Ingrese salario: ");
            scanf("%f", &salary);

            printf("Ingrese sector: ");
            scanf("%d", &sector);
            break;
        }
    }

    if(addEmployee(list,len,id,name,lastName,salary,sector) == 0)
    {
        error = 0;
    }

    return error;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list[] Employee array
 * \param len int tamanio del array
 * \param id int id a buscar
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{
    int indice = -1;
    for(int i = 0; i < len; i++)
    {
        if(list != NULL && len > 0 && list[i].id == id)
        {
            indice = i;
        }
    }
    return indice;
}

/** \brief Modifica algun dato del empleado
 *
 * \param list[] Employee array
 * \param len int tamanio del array
 * \return int Devuelve -1 si el array es inexistente, si el tamanio no es mayor a 0 o si no hay espacio en el array. O devuelve el indice en el que esta guardado el empleado
 *
 */
int modifyEmployee(Employee list[], int len)
{
    int id;
    int indice;
    char confirma = 'n';
    system("cls");
    printf("   MENU DE OPCIONES    \n\n");
    printf("Ingrese el id a buscar: ");
    scanf("%d", &id);

    indice = findEmployeeById(list, len, id);
    printEmployee(list[indice]);
    printf("Confirma empleado?(s/n): ");
    fflush(stdin);
    scanf("%c", &confirma);
    if( confirma == 's')
    {

        do
        {
            switch(menuModificar())
            {
            case 1:
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(list[indice].name);
                break;

            case 2:
                printf("Ingrese apellido: ");
                fflush(stdin);
                gets(list[indice].lastName);
                break;

            case 3:
                printf("Ingrese salario: ");
                scanf("%f", &list[indice].salary);
                break;

            case 4:
                printf("Ingrese sector: ");
                scanf("%d", &list[indice].sector);
                break;
            }
            printf("Desea modificar otro dato de este empleado?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
        }
        while(confirma == 's');
    }
    return indice;
}

/** \brief print the content of employees array
 *
 * \param list[] Employee array
 * \param length int tamanio del array
 * \return void
 *
 */
void printEmployees(Employee list[], int length)
{
    printf("Id   Nombre      Apellido     Salario       Sector\n");
    for(int i = 0; i < length; i++)
    {
        printEmployee(list[i]);
    }

}

/** \brief Imprime los campos de un empleado
 *
 * \param employee Employee la variable a utilizar
 * \return void
 *
 */
void printEmployee(Employee employee)
{
    printf("%d   %10s   %10s   %.2f        %d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}

/** \brief Remueve un empleado
 *
 * \param list[] Employee array
 * \param len int tamanio del array
 * \param id int id a buscar
 * \return int Devuelve -1 si el array es inexistente, si el tamanio no es mayor a 0 o si no hay espacio en el array. O devuelve el indice en el que se encuentra el empleado
 *
 */
int removeEmployee(Employee list[], int len, int id)
{
    int indice;
    char confirma = 'n';
    system("cls");
    indice = findEmployeeById(list, len, id);
    printEmployee(list[indice]);
    printf("Confirma empleado?(s/n): ");
    fflush(stdin);
    scanf("%c", &confirma);
    if( confirma == 's')
    {
        list[indice].id = 0;
        strcpy(list[indice].name, " ");
        strcpy(list[indice].lastName, " ");
        list[indice].salary = 0;
        list[indice].sector = 0;
        list[indice].isEmpty = 1;
    }
    return indice;
}

/** \brief Busca un empleado por id
 *
 * \param list[] Employee array
 * \param len int tamanio del array
 * \return int devuelve el id del empleado
 *
 */
int buscarId(Employee list[], int len)
{
    int id;
    printf("   MENU DE OPCIONES    \n\n");
    printf("Ingrese el id a buscar: ");
    scanf("%d", &id);
    return id;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee* array
* \param len int tamanio del array
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee list[], int len, int order)
{
    int error = -1;

    if(list != NULL && len > 0)
    {
        if(order == 1)
        {
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(strcmp(list[i].lastName,list[j].lastName) < 0 || ((strcmp(list[i].lastName,list[j].lastName) == 0) && list[i].sector < list[j].sector))
                    {
                        burbujeo(list, i, j);
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(strcmp(list[i].lastName,list[j].lastName) > 0 || ((strcmp(list[i].lastName,list[j].lastName) == 0) && list[i].sector > list[j].sector))
                    {
                        burbujeo(list, i, j);
                    }
                }
            }
        }
    }
    return error;
}

/** \brief Muestra el total de los salarios, el salario promedio y la cantidad de empleados que supera el salario promedio
 *
 * \param list[] Employee
 * \param len int
 * \return void
 *
 */
void mostrarSalarios(Employee list[], int len)
{
    float totalSalarios = 0;
    int contEmpleados = 0;
    float promedioSalarios;
    int cantEmplSalarioMayorAlPromedio = 0;
    for(int i = 0; i < len; i++)
    {
        if(list != NULL && len > 0 && list[i].isEmpty == 0)
        {
            totalSalarios = totalSalarios + list[i].salary;
            contEmpleados++;
        }
    }
    promedioSalarios = (float)totalSalarios/contEmpleados;
    for(int i = 0; i < len; i++)
    {
        if(list != NULL && len > 0 && list[i].isEmpty == 0 && list[i].salary > promedioSalarios)
        {
            cantEmplSalarioMayorAlPromedio++;
        }
    }
    printf("\nTotal de los salarios: %.2f\n", totalSalarios);
    printf("Promedio de los salarios: %.2f\n", promedioSalarios);
    printf("Cantidad de empleados que superan el salario promedio: %d\n", cantEmplSalarioMayorAlPromedio);
}

/** \brief Realiza un burbujeo tomando los valores i y j de la funcion sortEmployees
 *
 * \param list[] Employee array
 * \param i int indice de i
 * \param j int indice de j
 * \return void
 *
 */
void burbujeo(Employee list[], int i, int j)
{
    char auxChar[51];
    int auxInt;
    float auxFloat;

    strcpy(auxChar,list[i].lastName);
    strcpy(list[i].lastName,list[j].lastName);
    strcpy(list[j].lastName,auxChar);

    strcpy(auxChar,list[i].name);
    strcpy(list[i].name,list[j].name);
    strcpy(list[j].name,auxChar);

    auxFloat = list[i].salary;
    list[i].salary = list[j].salary;
    list[j].salary = auxFloat;

    auxInt = list[i].sector;
    list[i].sector = list[j].sector;
    list[j].sector = auxInt;

    auxInt = list[i].id;
    list[i].id = list[j].id;
    list[j].id = auxInt;

    auxInt = list[i].isEmpty;
    list[i].isEmpty = list[j].isEmpty;
    list[j].isEmpty = auxInt;
}
