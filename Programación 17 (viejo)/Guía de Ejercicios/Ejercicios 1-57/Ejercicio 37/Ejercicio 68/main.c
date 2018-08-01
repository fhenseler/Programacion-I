#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5

int main()
{
    int mesa[MAX_ARRAY], numMesa;
    float ventaAux, ventas[MAX_ARRAY] = {}, ventaTotal;
    char resp = 'S';

        for(int i = 1; i < MAX_ARRAY+1; i++)
        {
            mesa[i] = i;
        }

        printf("INGRESO DE DATOS\n");

        do
        {
            printf("\nIngrese numero de mesa: ");
            scanf("%d", &numMesa);

            if(numMesa < 1 || numMesa > 5)
            {
                printf("ERROR! Mesa inexistente. Reingrese: ");
                scanf("%d", &numMesa);
            }

            printf("\nIngrese valor: ");
            scanf("%f", &ventaAux);

            ventaTotal += ventaAux;
            ventas[i] += ventaAux;

            printf("\nIngresar otra mesa? (S/N)\n");
            resp = toupper(getche(resp));

        }while(resp == 'S');


        printf("\n\nVENTA TOTAL DEL DIA: %.2f\n", ventaTotal);

        printf("\nMESAS VACIAS: ");
        for(int i = 0; i < MAX_ARRAY+1; i++)
        {
            if(ventas[i] == 0)
            {
                printf("%d ", mesa[i]);
            }
        }

        printf("\n\nNRO DE MESA\tVENTA");
        for(int i = 0; i < MAX_ARRAY; i++)
        {
            if(ventas[i] != 0)
            {
               printf("\n%d\t\t%.2f", mesa[i], ventas[i]);
            }
        }

                return 0;
}
