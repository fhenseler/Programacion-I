#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


/** \brief División
 *
 * \param resultado Resultado de la división
 * \param a Dividendo
 * \param b Divisor
 * \return (0) ok - (-1) error
 *
 */
int operacionesMatematicas(float* resultDiv, float* resultMult, float* resultSuma, float* resultResta, int a, int b)
{
    int retorno = -1;

    *resultMult = a * b;
    *resultSuma = a + b;
    *resultResta = a - b;

    if(b != 0)
    {
        *resultDiv = (float)a / b;
        retorno = 0;
    }

    return retorno;
}
