#include <stdio.h>
#include <stdlib.h>

int sumar(int, int);

int main()
{
    int resultado, num1, num2;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese un numero: ");
    scanf("%d", &num2);

    resultado = sumar(num1, num2);
    printf("\nLa suma es: %d", resultado);

    return 0;
}

int sumar(int x, int y)
{
    int resultado;          //return x + y es lo mismo
    resultado = x + y;
    return resultado;
}
