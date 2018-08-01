#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5

float pAprobados(int);
void muestraAprobados(int[], int[]);

int main()
{
    int porcentaje, notaAux, legajo[MAX_ARRAY], aprobados[MAX_ARRAY] = {}, cantAprobados = 0;

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo[i]);

        printf("Ingrese nota: ");
        scanf("%d", &notaAux);

        if(notaAux >= 7)
        {
            aprobados[i] = notaAux;
            cantAprobados++;
        }
    }
        muestraAprobados(legajo, aprobados);
        porcentaje = pAprobados(cantAprobados);
        printf("\n%d es el porcentaje de aprobados", porcentaje);
        return 0;
}

float pAprobados(int cantAprobados)
{
    float porcentaje;
    porcentaje = ((float)cantAprobados / MAX_ARRAY) * 100;
    return porcentaje;
}

void muestraAprobados(int legajo[], int aprobados[])
{
    printf("\tLEGAJO\tNOTA");
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        if(aprobados[i] >= 7)
        {
            printf("\n\t%d\t%d", legajo[i], aprobados[i]);
        }
    }
}
