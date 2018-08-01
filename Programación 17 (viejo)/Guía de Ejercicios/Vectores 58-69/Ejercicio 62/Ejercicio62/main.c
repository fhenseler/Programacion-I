#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int vA[MAX] = {5, 0, 4, 3, 2}, vB[MAX] = {4, 3, 2, 1, 0}, vC[MAX] = {};

    for(int i = 0; i < MAX; i++)
    {
        if(vA[i] < vB[i])
        {
            vC[i] = vA[i];
        }
        else
        {
            if(vB[i] < vA[i])
            {
                vC[i] = vB[i];
            }
        }
    }

        printf("El vector A es: ");

        for(int i = 0; i < MAX; i++)
        {
            printf("%d, ", vA[i]);
        }


        printf("El vector B es: ");

        for(int i = 0; i < MAX; i++)
        {
            printf("%d, ", vB[i]);
        }

        printf("El vector C es: ");

        for(int i = 0; i < MAX; i++)
        {
            printf("%d, ", vC[i]);
        }

        getch();
        return 0;
}
