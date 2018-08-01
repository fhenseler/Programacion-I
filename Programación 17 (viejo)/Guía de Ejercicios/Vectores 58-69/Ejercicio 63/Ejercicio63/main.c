#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int edad[MAX] = {}, edadMayor[MAX] = {}, edadTotal = 0, legajosEdadMayor[MAX] = {0, 1, 2, 3, 4};
    float salario, edadPromedio;

    for(int i = 0; i < MAX; i++)
    {
        printf("\nIngrese edad legajo [%d]: ", i);
        scanf("%d", &edad[i]);

        printf("\nIngrese salario legajo [%d]: ", i);
        scanf("%f", &salario);

        edadTotal += edad[i];
    }

        edadPromedio = edadTotal / MAX;

    for(int i = 0; i < MAX; i++)
    {
        if(edad[i] > edadPromedio)
        {
            edadMayor[i] = edad[i];
        }
    }

    printf("\nLos legajos de los empleados cuya edad supera el promedio son: ");
    for(int i = 0; i < MAX; i++)
    {
        if(edadMayor[i] != 0)
        {
            printf("%d ", legajosEdadMayor[i]);
        }
    }
            getch();
            return 0;
}
