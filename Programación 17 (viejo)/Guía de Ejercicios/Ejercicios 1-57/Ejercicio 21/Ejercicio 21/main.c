#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, acum = 0;
    printf("Ingrese numero: ");
    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        acum += i;
    }
            printf("La suma de los numeros que anteceden al numero ingresado es: %d", acum);
            getch();
            return 0;
}
