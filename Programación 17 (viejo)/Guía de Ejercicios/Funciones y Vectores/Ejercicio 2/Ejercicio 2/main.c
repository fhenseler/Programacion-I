#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5

int notasEnRango(int[], int, int);

int main()
{
    int nota[MAX_ARRAY], min, max, cantEnRango;

    printf("Ingrese nota minima: ");
    scanf("%d", &min);

    printf("Ingrese nota maxima: ");
    scanf("%d", &max);

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("Ingrese nota alumno [%d]: ", i);
        scanf("%d", &nota[i]);

        cantEnRango = notasEnRango(nota, min, max);
    }
        printf("Cantidad de notas entre la minima y la maxima: %d", cantEnRango);
        return 0;
}

int notasEnRango(int nota[], int min, int max)
{
    int cantEnRango = 0;
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        if(nota[i] >= min && nota[i] <= max)
        {
            cantEnRango++;
        }
    }
            return cantEnRango;
}


