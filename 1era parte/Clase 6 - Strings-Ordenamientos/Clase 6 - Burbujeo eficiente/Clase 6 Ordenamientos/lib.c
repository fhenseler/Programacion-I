#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#define LEN 5

void ordenar(int arrayInt[], int len)
{
    int flagCambioAlgo, i;
    int aux;

    do
    {
        flagCambioAlgo = 0;
        for(i = 0; i < LEN-1; i++)
        {
            if(arrayInt[i] > arrayInt[i+1])
            {
                flagCambioAlgo = 1;

                aux = arrayInt[i];
                arrayInt[i] = arrayInt[i+1];
                arrayInt[i+1] = aux;
            }
        }
    }while(flagCambioAlgo == 1);
}

void imprimir(int arrayInt[], int len)
{
    int i;
    for(i = 0; i < LEN; i++)
    {
        printf("%d ", arrayInt[i]);
    }
}
