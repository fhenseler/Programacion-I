#include <stdio.h>
#include <stdlib.h>

void sumar(int, int);

int main()
{
    int num1, num2;
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese un numero: ");
    scanf("%d", &num2);

    sumar(num1, num2);

    getch();
    return 0;

}

void sumar(int x, int y)
{
    int resultado;
    resultado = x + y;
    printf("\nLa suma es: %d\n", resultado);
}
