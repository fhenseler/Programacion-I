#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, numero, factorial = 1;

    printf("Ingrese numero para calcular su factorial: ");
    scanf("%d", &numero);

    for(i = numero; i > 1; i--)
    {
        factorial *= i;
    }

    printf("El factorial de %d es: %d", numero, factorial);
    getch();
    return 0;
}
