#include <stdio.h>
#include <stdlib.h>

int calcularSuperficieRectangulo();

int main()
{
    calcularSuperficieRectangulo();
}

int calcularSuperficieRectangulo()
{
    int salir = 0, base, altura, superficie;
    do
    {
        printf("\nIngrese base: ");
        scanf("%d", &base);

        printf("\nIngrese altura: ");
        scanf("%d", &altura);

        if(base == 0 && altura == 0)
        {
            salir = 1;
        }

        superficie = base * altura;

        printf("\nLa superficie es: %d", superficie);

    }while(salir == 0);

    return superficie;
}
