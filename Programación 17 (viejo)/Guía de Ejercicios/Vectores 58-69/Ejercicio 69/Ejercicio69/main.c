#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int codigoAux, cantAux, codigo[MAX], codigoMin, cant[MAX];
    float precio[MAX], precioAux, precioMin;

    for(int i = 0; i < MAX; i++)
    {
        printf("\n");

        printf("Ingrese codigo: ");
        scanf("%d", &codigo[i]);

        printf("Ingrese precio: ");
        scanf("%f", &precioAux);

        precio[i] = precioAux;

        printf("Ingrese stock: ");
        scanf("%d", &cant[i]);

        printf("\n");

        if(i == 0 || precio[i] < precioMin)
        {
            precioMin = precio[i];
            codigoMin = codigo[i];
        }
    }

    for(int i = 0; i < MAX-1; i++)
    {
        for(int j = i+1; j < MAX; j++)
        {
            if(codigo[i] > codigo[j])
            {
                codigoAux = codigo[i];
                codigo[i] = codigo[j];
                codigo[j] = codigoAux;

                precioAux = precio[i];
                precio[i] = precio[j];
                precio[j] = precioAux;

                cantAux = cant[i];
                cant[i] = cant[j];
                cant[j] = cantAux;
            }
        }
    }

                printf("CODIGO\tPRECIO\tSTOCK");
                printf("\n\n");
                for(int i = 0; i < MAX; i++)
                {
                    printf("\n%d\t%.2f\t%d\n", codigo[i], precio[i], cant[i]);
                }
                printf("\n\nEl codigo del medicamento de precio mas bajo es: %d\n", codigoMin);

                getch();
                return 0;
}

