#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int i, numeros[TAM], numeros2[TAM];

    for(i = 0; i < 5; i++)
    {
        printf("Ingrese numero indice [%d]: ", i);
        scanf("%d", &numeros[i]);
        numeros2[i] = numeros[i] * 2;
    }

    for(i = 0; i < 5; i++)
    {
        printf("\n1er Array indice [%d]: %d", i, numeros[i]);
    }

    printf("\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("\n2do Array indice [%d]: %d", i, numeros2[i]);
    }

        getch();
        return 0;
}
