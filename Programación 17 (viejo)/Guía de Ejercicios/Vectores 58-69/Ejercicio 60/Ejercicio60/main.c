#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main()
{
    int vector[MAX] = {};

    for(int i = 0; i < MAX; i++)
    {
        printf("Ingrese entero indice [%d]: ", i);
        scanf("%d", &vector[i]);
    }

     printf("\nEl vector entero es: ");
     for(int i = 0; i < MAX; i++)
     {
         printf("\n%d, ", vector[i]);
     }

        printf("\nEl vector en forma decreciente es: ");
        for(int i = MAX; i > 0; i--)
        {
         printf("\n%d, ", vector[i-1]);
        }


        for(int i = 0; i < MAX-1; i++)
        {
            for(int j = i+1; j < MAX; j++)
            {
                if(vector[i] < vector[j])
                {
                    int aux = vector[i];
                    vector[i] = vector[j];
                    vector[j] = aux;
                }
            }
        }

        printf("\nEl vector ORDENADO en forma decreciente es: ");
        for(int i = 0; i < MAX; i++)
        {
            printf("%d, ", vector[i]);
        }

        getch();
        return 0;
}
