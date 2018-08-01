#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"

ArrayList* al_new()
{
    ArrayList* pArray;
    pArray = malloc(sizeof(ArrayList));
    pArray->r_size = INIT_SIZE;
    pArray->size = 0;
    pArray->pElements = malloc(sizeof(void*) * pArray->r_size); //pArray->r_size = INIT_SIZE = 10

    return pArray;
}

int al_add(ArrayList* pArray, void* element)
{
    int retorno = -1;

    if(pArray->size < pArray->r_size)
    {
       *(pArray->pElements + pArray->size) = element;
       pArray->size++;
       retorno = 0;
    }
       return retorno;
}

void al_debugShow(ArrayList* pArray)
{
    int retorno = -1;
    int i;

    for(i = 0; i < pArray->size; i++)
    {
        printf("\n%p numero %d de %d", (*(pArray->pElements + i), i, pArray->size)
    }
        return retorno;
}
