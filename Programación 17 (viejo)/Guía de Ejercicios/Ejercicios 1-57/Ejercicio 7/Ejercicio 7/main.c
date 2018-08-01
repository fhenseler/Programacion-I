#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, cuadrado;
    printf("Ingrese numero: ");
    scanf("%d", &numero);
    while(numero <= 0)
    {
        printf("ERROR! El numero debe ser mayor a cero.\n Reingrese: ");
        scanf("%d", &numero);
    }
        cuadrado = numero * numero;
        printf("El cuadrado del numero es: %d", cuadrado);
        getch();
        return 0;
}
