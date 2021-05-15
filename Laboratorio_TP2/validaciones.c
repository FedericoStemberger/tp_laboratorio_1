#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validaciones.h"

/** \brief Valida si una cadena son solo numeros
 *
 * \param cadena[] char cadena a validar
 * \return int
 *
 */
int menuValido(char cadena[])
{
    int numeroValido = 1;
    int tam = strlen(cadena);



    for(int i = 0; i < tam - 1; i++)
    {
        if(cadena[i] < '1' || cadena[i] > '4')
        {
            numeroValido = 0;
        }
    }

    return numeroValido;
}

int menuOrdenarValido(char cadena[])
{
    int numeroValido = 1;
    int tam = strlen(cadena);



    for(int i = 0; i < tam - 1; i++)
    {
        if(cadena[i] < '1' || cadena[i] > '2')
        {
            numeroValido = 0;
        }
    }

    return numeroValido;
}

/** \brief convierte un string a int
 *
 * \param cadena[] char variable a convertir a int
 * \return int
 *
 */
int convertirCadenaAInt(char cadena[])
{
    int numero;

    numero = atoi(cadena);

    return numero;
}
