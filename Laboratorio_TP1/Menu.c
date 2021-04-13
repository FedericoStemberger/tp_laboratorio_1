#include <stdlib.h>
#include <stdio.h>
#include "Menu.h"

/** \brief muestra el menu
 *
 * \param op1 float primer operando a validarse
 * \param op2 float segundo operando a validarse
 * \return void
 *
 */
void menu(float op1, float op2)
{
    system("cls");
        if(op1 == '\0')
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1. Ingresar 1er operando (A=%.2f)\n", op1);
        }
        if(op2 == '\0')
        {
            printf("2. Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2. Ingresar 2do operando (B=%.2f)\n", op2);
        }

        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");

        printf("Ingrese opcion: ");
}
