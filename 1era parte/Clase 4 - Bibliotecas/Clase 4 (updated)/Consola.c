#include <stdio.h>
#include "Consola.h"

/** \brief
 *
 * \param mensaje char
 * \param resultado int*
 * \param lowLim int
 * \param hiLim int
 * \return int (0) - ok  (-1) - error
 *
 */
int getFloat(char msg[], char errorMsg[], float* numero, int lowLim, int hiLim, int cantIntentos)
{
    int retorno = -1;
    float auxFloat;

    printf("%s", msg);
    scanf("%f", &auxFloat);

    while(auxFloat < lowLim || auxFloat > hiLim)
    {
        printf("ERROR! El numero debe estar entre %d y %d. \nReingrese (quedan %d intento(s)): ", lowLim, hiLim, cantIntentos);

        scanf("%f", &auxFloat);

        cantIntentos--;

        if(cantIntentos == 0 && (auxFloat < lowLim || auxFloat > hiLim))
        {
           printf("%s", errorMsg);
           break;
        }
    }

        if(auxFloat >= lowLim && auxFloat <= hiLim)
        {
            *numero = auxFloat;
            retorno = 0;
        }

            return retorno;
}
