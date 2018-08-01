#include <stdio.h>
#include <stdlib.h>

int main()
{
    int radio;
    float area, longitud, pi;
    pi = 3.14159;
    printf("Ingrese radio del circulo: ");
    scanf("%d", &radio);
    longitud = 2 * pi * radio;
    area = pi * radio * radio;
    printf("La longitud es: %.4f\n", longitud);
    printf("El area es %.4f", area);
    getch();
    return 0;
}
