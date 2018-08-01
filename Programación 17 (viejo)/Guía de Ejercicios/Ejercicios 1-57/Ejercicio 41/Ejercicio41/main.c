#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n_numero, numMax, flag = 0;

    for(i = 0; i < 4; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &n_numero);

        if(flag == 0 || n_numero > numMax)
        {
            numMax = n_numero;
            flag = 1;
        }
    }

            printf("\n\n%d es el numero maximo", numMax);
            getch();
            return 0;
}
