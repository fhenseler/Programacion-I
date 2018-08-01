#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main()
{
    int num[MAX] = {}, numPos[MAX] = {}, numNeg[MAX] = {};

    for(int i = 0; i < MAX; i++)
    {
        printf("\nIngrese numero distinto de 0: ");
        scanf("%d", &num[i]);

        if(num[i] == 0)
        {
            printf("\nERROR! El numero ingresado debe ser distinto de 0. Reingrese: ");
            scanf("%d", &num[i]);
        }

        else
        {
            if(num[i] > 0)
            {
                numPos[i] = num[i];
            }
            if(num[i] < 0)
            {
                numNeg[i] = num[i];
            }

        }

    }

    printf("\nEl vector ingresado es: ");
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", num[i]);
    }

    printf("\nNumeros positivos ordenados en forma decreciente: ");
    for(int i = 0; i < MAX - 1; i++)
    {
        for(int j = i + 1; j < MAX; j++)
        {
            if(numPos[i] > numPos[j])
            {
                int aux = numPos[i];
                numPos[i] = numPos[j];
                numPos[j] = aux;
            }
        }
    }

    for(int i = MAX - 1; i > 0; i--)
    {
        if(numPos[i] != 0)
        {
            printf("%d ", numPos[i]);
        }
    }

    printf("\nNumeros negativos ordenados en forma creciente: ");
    for(int i = 0; i < MAX - 1; i++)
    {
        for(int j = i + 1; j < MAX; j++)
        {
            if(numNeg[i] > numNeg[j])
            {
                int aux = numNeg[i];
                numNeg[i] = numNeg[j];
                numNeg[j] = aux;
            }
        }
    }

    for(int i = 0; i < MAX; i++)
    {
        if(numNeg[i] != 0)
        {
            printf("%d ", numNeg[i]);
        }
    }

                getch();
                return 0;
}
