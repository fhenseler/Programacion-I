#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int vector[MAX] = {};

    for(int i = 0; i < MAX; i++)
    {
        printf("Ingrese entero indice [%d]: ", i);
        scanf("%d", &vector[i]);
    }

    printf("Los enteros ingresados son: ");
    for(int i = 0; i < MAX; i++)
    {
        printf("%d, ", vector[i]);
    }

    getch();
    return 0;
}
