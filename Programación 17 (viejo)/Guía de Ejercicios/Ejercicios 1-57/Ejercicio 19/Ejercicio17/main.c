#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    if(num % 2 == 0)
    {
        printf("El numero ingresado es par");
    }
    if(num % 2 == 1)
    {
        printf("El numero ingresado es impar");
    }
        getch();
        return 0;
}
