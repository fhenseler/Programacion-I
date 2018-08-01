#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lado1, lado2, lado3;
    printf("Ingrese valor lado1: ");
    scanf("%d", &lado1);
    printf("Ingrese valor lado2: ");
    scanf("%d", &lado2);
    printf("Ingrese valor lado3: ");
    scanf("%d", &lado3);
    if(lado1 + lado2 > lado3)
    {
        printf("Es un triangulo");
    }
        if(lado1 + lado2 < lado3)
        {
            printf("No es un triangulo");
        }

            getch();
            return 0;
}
