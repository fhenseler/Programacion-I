#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, a, b;
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);
    a = num1;
    b = num2;
    num1 = b;
    num2 = a;
    printf("NUM1 es: %d\n", num1);
    printf("NUM2 es: %d", num2);
    getch();
    return 0;

}
