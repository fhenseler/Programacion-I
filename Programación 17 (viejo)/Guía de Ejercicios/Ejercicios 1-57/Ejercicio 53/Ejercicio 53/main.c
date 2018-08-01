#include <stdio.h>
#include <stdlib.h>
#define CANT_EMP 5

int main()
{
    int legajo, cod_sexo, cantHombres = 0, legajo_mujer[CANT_EMP] = {0};

    for(int i = 0; i < CANT_EMP; i++)
    {
        printf("\nIngrese legajo: ");
        scanf("%d", &legajo);

        printf("\nIngrese sexo (1 - F / 2 - M)");
        scanf("%d", &cod_sexo);

        if(cod_sexo == 1)
        {
            legajo_mujer[i] = legajo;
        }

        if(cod_sexo == 2)
        {
            cantHombres++;
        }

    }

    printf("\nLos numeros de legajo de las mujeres son: ");
    for(int i = 0; i < CANT_EMP; i++)
    {
        if(legajo_mujer[i] != 0)
        printf("\n%d, ", legajo_mujer[i]);
    }

        printf("\nLa cantidad de hombres es: %d", cantHombres);

        getch();
        return 0;
}
