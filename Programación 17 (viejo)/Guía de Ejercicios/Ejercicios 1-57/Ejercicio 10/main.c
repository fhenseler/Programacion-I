#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base, altura, superficie;
    printf("Ingrese valor base: ");
    scanf("%d", &base);
    printf("Ingrese valor altura: ");
    scanf("%d", &altura);
    superficie = (base * altura)/2;
    printf("La superficie del triangulo es: %d", superficie);
    getch();
    return 0;

}
