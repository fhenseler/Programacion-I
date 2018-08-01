#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_numero, i, resultado;

    printf("Ingrese numero 0 al 10: ");
    scanf("%d", &n_numero);
    printf("\nTABLA DEL %d\n\n", n_numero);

    for(i = 0; i < 21; i++)
    {
        resultado = n_numero * i;
        printf("%d x %d = %d\n", n_numero, i, resultado);
    }
        getch();
        return 0;
}
