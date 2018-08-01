#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int validarRangoEntero(int, int, int);

int main()
{
    int i, valor, numeros[TAM] = {0}, indice, auxInt;

    for(i=0; i < TAM; i++)
    {
        numeros[i] = 0;
    }


    for(i = 0; i < 10; i++)
    {
        printf("\nIngresar indice a cargar: ");
        scanf("%d", &auxInt);
        printf("\nIngrese numero: ");
        scanf("%d", &valor);

        while(!(validarRangoEntero(auxInt, 0, TAM-1)))
        {
            printf("Error, el indice debe estar comprendido entre 0 y %d . Reingrese: ", TAM-1);
            scanf("%d", &auxInt);
        }

        indice = auxInt;

        numeros[indice] += valor;
    }

    for(i = 0; i < TAM; i++)
    {
        printf("\nEl indice [%d] vale: %d", i, numeros[i]);
    }

        getch();
        return 0;
}

int validarRangoEntero(int num, int inf, int sup){

    int esValido = 0;
    int aux;
    if(inf > sup){
        aux = inf;
        inf = sup;
        sup = aux;
    }

    if( num >= inf && num <= sup){
        esValido = 1;
    }

    return esValido;
}
