#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, minIntervalo = 10, maxIntervalo = 100;

    printf("Ingrese numero: ");
    scanf("%d", &num);

    if(num >= minIntervalo && num <= maxIntervalo)
    {
        printf("El numero %d pertenece al intervalo entre %d y %d", num, minIntervalo, maxIntervalo);
    }
    else
    {
        printf("El numero %d no pertenece al intervalo entre %d y %d", num, minIntervalo, maxIntervalo);
    }

    getch();
    return 0;
}
