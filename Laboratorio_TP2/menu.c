#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "validaciones.h"

/** \brief Muestra el menu de opciones
 *
 * \return int devuelve el numero ingresado
 *
 */
int menu()
{
    char aux[100];
    int opcion;
    system("cls");
    printf("   MENU DE OPCIONES    \n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n\n");
    printf("Elija opcion: ");
    fflush(stdin);
    gets(aux);
    while(menuValido(aux) == 0)
    {
        printf("Ingrese un numero valido\n");
        fflush(stdin);
        gets(aux);
    }
    opcion = convertirCadenaAInt(aux);
    system("cls");

    return opcion;
}

/** \brief muestra el submenu
 *
 * \return int devuelve el numero ingresado
 *
 */
int preguntarOrden()
{
    char aux[100];
    int opcion;
    system("cls");
    printf("   MENU DE OPCIONES    \n\n");
    printf("1. Ordenar lista de empleados de manera ascendente.\n");
    printf("2. Ordenar lista de empleados de manera descendente.\n\n");
    printf("Elija opcion: ");
    fflush(stdin);
    gets(aux);
    while(menuOrdenarValido(aux) == 0)
    {
        printf("Ingrese un numero valido\n");
        fflush(stdin);
        gets(aux);
    }
    opcion = convertirCadenaAInt(aux);
    system("cls");

    return opcion;
}

/** \brief muestra el menu modificar
 *
 * \return int devuelve el numero ingresado
 *
 */
int menuModificar()
{
    int opcion;
    char aux[100];
    system("cls");
    printf("   MENU DE OPCIONES    \n\n");
    printf("Que desea modificar?\n");
    printf("1. NOMBRE\n");
    printf("2. APELLIDO\n");
    printf("3. SALARIO\n");
    printf("4. SECTOR\n\n");
    printf("Elija opcion: ");
    fflush(stdin);
    gets(aux);
    while(menuValido(aux) == 0)
    {
        printf("Ingrese un numero valido\n");
        fflush(stdin);
        gets(aux);
    }
    opcion = convertirCadenaAInt(aux);
    system("cls");

    return opcion;
}
