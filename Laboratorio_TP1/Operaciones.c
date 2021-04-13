#include <stdlib.h>
#include <stdio.h>
#include "Operaciones.h"


/** \brief Realiza la suma entre dos numeros y devuelve el resultado
 *
 * \param a float primer numero a sumar
 * \param b float segundo numero a sumar
 * \return float el resultado de la suma de ambos operandos
 *
 */
float sumar(float a, float b)
{
    float resultado;

    resultado = a + b;

    return resultado;
}

/** \brief Realiza la resta entre dos numeros y devuelve el resultado
 *
 * \param a float primer numero a restar
 * \param b float segundo numero a restar
 * \return float el resultado de la resta de ambos operandos
 *
 */
float restar(float a, float b)
{
    float resultado;

    resultado = a - b;

    return resultado;
}

/** \brief Realiza la division entre dos numeros y devuelve el resultado
 *
 * \param a float dividendo
 * \param b float divisor
 * \return float el resultado de la division entre ambos operandos
 *
 */
float dividir(float a, float b)
{
    float resultado;

    resultado = (float)a/b;

    return resultado;
}


/** \brief Realiza la multiplicacion entre dos numeros y devuelve el resultado
 *
 * \param a float primer numero a restar
 * \param b float segundo numero a restar
 * \return float el resultado de la resta de ambos operandos
 *
 */
float multiplicar(float a, float b)
{
    float resultado;

    resultado = a * b;

    return resultado;
}

/** \brief Realiza el factorial de un numero
 *
 * \param a int numero a realizarse el factorial
 * \return int el resultado del factorial del operando ingresado
 *
 */
int FactA(int a)
{
    int resultado = 1;

    for(int i = a; i > 0; i--)
    {
        resultado = resultado * i;
    }

    return resultado;
}

/** \brief Realiza el factorial de un numero
 *
 * \param b int numero a realizarse el factorial
 * \return int el resultado del factorial del operando ingresado
 *
 */
int Factb(int b)
{
    int resultado = 1;

    for(int i = b; i > 0; i--)
    {
        resultado = resultado * i;
    }

    return resultado;
}

