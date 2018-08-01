#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EXIT_SUCCESS 0

float cuadratica_ejeX();

int main (void)
{
    float resultado;

    resultado = cuadratica_ejeX();
    printf("%f", resultado);
    getch();
    return 0;
}


float cuadratica_ejeX()
{
    float a, b, c, x1, x2;
    printf ("Ingrese el valor de a: ");
    scanf ("%f", &a);
    printf ("Ingrese el valor de b: ");
    scanf ("%f", &b);
    printf ("Ingrese el valor de c: ");
    scanf ("%f", &c);
    x1=(-b+sqrt(b*b-4.0*a*c))/2.0/a;
    x2=(-b-sqrt(b*b-4.0*a*c))/2.0/a;
    printf ("Valor de x1: %g\n", x1);
    printf ("Valor de x2: %g\n", x2);
    putchar ('\n');
    system ("pause");
    return EXIT_SUCCESS;
}
