#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, cantP = 0, cantN = 0;
    for(i = 0; i < 10; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &num);
        if(num > 0)
        {
            cantP++;
        }
            if(num < 0)
            {
            cantN++;
            }
    }
            printf("La cantidad de numeros positivos es: %d\n", cantP);
            printf("La cantidad de numeros negativos es: %d", cantN);
            getch();
            return 0;
}

