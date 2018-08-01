#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int sexo, flagMax = 0, acumEdad = 0, s_edadMax, edad, legajo, cant1978 = 0, edadMax, l_edadMax;
    float edadPromedio;

    for(int i = 0; i < MAX; i++)
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad);

        acumEdad += edad;

        printf("Ingrese sexo (1-F / 2-M): ");
        scanf("%d", &sexo);

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        if(flagMax == 0 || edad > edadMax)
        {
            edadMax = edad;
            l_edadMax = legajo;
            s_edadMax = sexo;
            flagMax = 1;
        }

        if(edad == 39 && sexo == 1)
        {
            cant1978++;
        }

    }

        edadPromedio = (float)acumEdad / MAX;

        printf("\nLa edad promedio es: %.2f", edadPromedio);
        printf("\nLa persona de mayor edad (%d) tiene legajo %d y sexo %d", edadMax, l_edadMax, s_edadMax);
        printf("\n%d mujeres nacieron en 1978", cant1978);
        getch();
        return 0;
}
