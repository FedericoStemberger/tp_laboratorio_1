#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Operaciones.h"
#include "Menu.h"

int main()
{
    int opcion;
    float operando1 = 0;
    float operando2 = 0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int factorialA;
    int factorialB;
    char salir = 'n';
    int entero1;
    int entero2;
    char aux;
    int opcionInvalida;


    do
    {
        menu(operando1, operando2);

        do
        {
            fflush(stdin);
            scanf("%c", &aux);

            if(aux < '1' || aux > '5')
            {
                opcionInvalida = 1;
                printf("Ingrese una opcion valida, por favor.\n");

            }
            else
            {
                opcionInvalida = 0;
                opcion = atoi(&aux);
            }
        }
        while(opcionInvalida == 1);



        switch(opcion)
        {
        case 1:
            printf("Operando 1: ");
            scanf("%f", &operando1);
            entero1 = operando1;
            break;
        case 2:

            printf("Operando 2: ");
            scanf("%f", &operando2);
            entero2 = operando2;
            break;
        case 3:
            suma = sumar(operando1, operando2);
            resta = restar(operando1, operando2);
            division = dividir(operando1, operando2);
            multiplicacion = multiplicar(operando1, operando2);
            factorialA = FactA(operando1);
            factorialB = Factb(operando2);
            break;
        case 4:
            printf("El resultado de A+B es: %.2f\n", suma);
            printf("El resultado de A-B es: %.2f\n", resta);

            if(operando2 == 0)
            {
                printf("No es posible dividir por cero\n");
            }
            else
            {
                printf("El resultado de A/B es: %.2f\n", division);
            }

            printf("El resultado de A*B es: %.2f\n", multiplicacion);

            if(operando1 > entero1 || operando1 < 0)
            {
                printf("No se puede hacer el factorial de este numero\n");
            }
            else
            {
                printf("El factorial de A es: %d\n", factorialA);
            }

            if(operando2 > entero2 || operando2 < 0)
            {
                printf("No se puede hacer el factorial de este numero\n\n");
            }
            else
            {
                printf("El factorial de B es: %d\n\n", factorialB);
            }

            system("pause");
            break;
        case 5:
            printf("Desea salir? (s/n): ");
            fflush(stdin);
            scanf("%c", &salir);
            salir = tolower(salir);
            break;

        }

    }
    while(salir != 's');

    return 0;
}
