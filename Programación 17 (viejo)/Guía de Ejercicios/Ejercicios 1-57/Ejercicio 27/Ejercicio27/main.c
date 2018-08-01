#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_vendedor, i;
    float n_importe, n_gananciaVendedor;

    for(i = 0; i < 3; i++)
    {
            printf("\nINGRESAR DATOS\n");
            printf("\nIngrese numero de vendedor: ");
            scanf("%d", &n_vendedor);

            printf("\nIngrese importe: ");
            scanf("%f", &n_importe);

            n_gananciaVendedor = n_importe * 0.05;
            printf("\nLa ganancia del vendedor es: %.2f", n_gananciaVendedor);

            getch();
            system("cls");
    }

            return 0;
}
