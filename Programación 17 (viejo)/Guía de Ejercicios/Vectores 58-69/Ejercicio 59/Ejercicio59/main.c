#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main()
{
    int vector[MAX] = {}, maxNum, indice, maxIndice, flagMax = 0;

    for(int i = 0; i < MAX; i++)
    {
        printf("Ingrese indice: ");
        scanf("%d", &indice);

        printf("Ingrese entero indice [%d]: ", indice);
        scanf("%d", &vector[indice]);

        if(vector[indice] < 0)
        {
            printf("ERROR! Reingrese entero positivo: ");
            scanf("%d", &vector[indice]);
        }

        if(flagMax == 0 || vector[indice] > maxNum)
        {
            maxNum = vector[indice];
            maxIndice = indice;
            flagMax = 1;
        }

    }

    printf("El mayor numero es %d y esta en el indice %d", maxNum, maxIndice);

    printf("\nEl vector entero es: ");
    for(int i = 0; i < MAX; i++)
    {
        printf("\n%d, ", vector[i]);
    }

    getch();
    return 0;
}
