#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5

int main()
{
    int i, arrayNumeros[MAX_ARRAY];

    for(i = 0; i < MAX_ARRAY; i++)
    {
        printf("\nIngrese elemento para el indice %d del array: ", i);
        scanf("%d", &arrayNumeros[i]);
    }

        printf("\n\n************************************************************\n\n");

    for(i = 0; i < MAX_ARRAY; i++)
    {
        printf("\nIndice %d del array cargado con: %d\n", i, arrayNumeros[i]);
    }

        printf("\n\n************************************************************\n\n");

    for(i = MAX_ARRAY; i > 0; i--)
    {
        printf("\nElemento del array %d cargado con: %d\n", i - 1, arrayNumeros[i - 1]);
    }

        getch();
        return 0;
}
