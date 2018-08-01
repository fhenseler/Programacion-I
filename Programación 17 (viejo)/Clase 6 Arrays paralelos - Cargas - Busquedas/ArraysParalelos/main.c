#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int legajo[MAX], edad[MAX];
    float salario[MAX], salarioAux;

    for(int i = 0; i < MAX; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo[i]);

        printf("Ingrese edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese salario: ");
        scanf("%f", &salarioAux);

        salario[i] = salarioAux;
    }

    printf("\n\nLegajo\t Edad\t Salario\t\n\n");
    for(int i = 0; i < MAX; i++)
    {
        printf("\n%d\t %d\t %.2f\t\n", legajo[i], edad[i], salario[i]);
    }

        getch();
        return 0;
}
