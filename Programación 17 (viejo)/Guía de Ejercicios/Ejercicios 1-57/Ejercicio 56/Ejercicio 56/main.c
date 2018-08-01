#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion = 0, num1, num2, resultado;
    char salir = '0';

    printf("***CALCULADORA***\n\n");

    do
    {
        printf("\n1- SUMA\n");
        printf("2- RESTA\n");
        printf("3- MULTIPLICACION\n");
        printf("4- DIVISION\n");
        printf("\n\n0 - SALIR\n\n");
        scanf("%d", &opcion);

    }while(salir != '0');

    switch(opcion)
    {
        case 1:
                printf("Ingrese primer operando: ");
                scanf("%d", &num1);
                printf("Ingrese segundo operando: ");
                scanf("%d", &num2);
                resultado = num1 + num2;
                printf("%d", resultado);
                break;
        case 2:
                printf("Ingrese primer operando: ");
                scanf("%d", &num1);
                printf("Ingrese segundo operando: ");
                scanf("%d", &num2);
                resultado = num1 - num2;
                printf("%d", resultado);
                break;
        case 3:
                printf("Ingrese primer operando: ");
                scanf("%d", &num1);
                printf("Ingrese segundo operando: ");
                scanf("%d", &num2);
                resultado = num1 * num2;
                printf("%d", resultado);
                break;
        case 4:
                printf("Ingrese primer operando: ");
                scanf("%d", &num1);
                printf("Ingrese segundo operando: ");
                scanf("%d", &num2);
                resultado = num1 / num2;
                printf("%d", resultado);
                break;
        case 0:
                salir = '0';
                break;
    }
        getch();
        return 0;
}
