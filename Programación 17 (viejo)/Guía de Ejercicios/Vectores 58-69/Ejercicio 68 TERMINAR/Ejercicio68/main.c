#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int numMesa[MAX] = {}, ventas[MAX] = {}, acumVenta = 0, cantMesasLibres = 0;
    char resp = 's';

    do
    {
        for(int i = 0; i < MAX; i++)
        {
            printf("Ingrese numero de mesa: ");
            scanf("%d", &numMesa[i]);

            printf("Ingresar otra mesa? (s/n)");
            resp = tolower(getch(resp));
        }

    }while(resp == 's');

}
