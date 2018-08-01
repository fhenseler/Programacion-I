#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2, resultado, cuadrado;
    system("cls");
    printf("Ingrese numero 1: ");
    scanf("%d", &numero1);
    printf("Ingrese numero 2: ");
    scanf("%d", &numero2);
    if(numero1 != 0 && numero2 != 0){
            resultado = numero1 * numero2;
            printf("El resultado de la multiplicacion es: %d\n", resultado);
            cuadrado = numero1 * numero1;
            printf("El cuadrado de numero1 es: %d", cuadrado);
    }
            getch();
            return 0;
}
