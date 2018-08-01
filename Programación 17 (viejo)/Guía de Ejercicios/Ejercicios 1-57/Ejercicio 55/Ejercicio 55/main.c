#include <stdio.h>
#include <stdlib.h>

int main()
{
    int legajo, legajoMejorPromedio, flagMax = 0, cantAprobados = 0, cantDiciembre = 0, cantMarzo = 0;
    float promedio, maxPromedio;
    char resp = 's';

    printf("***INGRESO DE DATOS***\n");

    do
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        printf("Ingrese promedio: ");
        scanf("%f", &promedio);

        if(flagMax == 0 || promedio > maxPromedio)
        {
            maxPromedio = promedio;
            legajoMejorPromedio = legajo;
            flagMax = 1;
        }

        if(promedio >= 7)
        {
            cantAprobados++;
        }
        else
        {
            if(promedio < 7 && promedio >= 4)
            {
                cantDiciembre++;
            }
            if(promedio >= 1 && promedio < 4)
            {
                cantMarzo++;
            }
        }

        printf("\nIngresar otro alumnno? (s/n)\n");
        resp = tolower(getch(resp));

    }while(resp == 's');

        printf("\n\n%d alumno(s) aprobaron la materia\n", cantAprobados);
        printf("\n%d alumno(s) rinden en Diciembre\n", cantDiciembre);
        printf("\n%d alumno(s) rinden en Marzo\n", cantMarzo);
        printf("\n%d es el legajo del alumno con mejor promedio (%.2f))", legajoMejorPromedio, maxPromedio);
        getch();
        return 0;

}
