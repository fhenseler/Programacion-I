#include <stdio.h>
#include <stdlib.h>
#define MAX 2
#define PLUS 0.33

int main()
{
    int i, bonus, n_mozo[MAX], n_clientes[MAX], flagMax = 0, clientesMax;
    float n_fac[MAX];

    do
    {
        i++;

        printf("\nIngrese numero mozo (0 = salir): ");
        scanf("%d", &n_mozo[i]);

        printf("\nIngrese cantidad clientes: ");
        scanf("%d", &n_clientes[i]);

        printf("\nIngrese facturacion del dia: ");
        scanf("%f", &n_fac[i]);

        if(flagMax == 0 || n_clientes[i] > clientesMax)
        {
            clientesMax = n_clientes;
            flagMax = 1;
        }

    }while(n_mozo != 0);


        return 0;
}
