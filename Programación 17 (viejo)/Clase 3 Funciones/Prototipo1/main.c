#include <stdio.h>
#include <stdlib.h>

void sumar(void); //PROTOTIPO (antes del main)

int main()
{
    sumar();  //LLAMADA (dentro del main)
    return 0;
}


void sumar(void)
{
    int num1, num2, resultado;  //DESARROLLO (después del main)

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = num1 + num2;

    printf("La suma es: %d", resultado);
}
