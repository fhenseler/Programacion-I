#include <stdio.h>
#include <stdlib.h>
#define CANT_NUM 5

/*/CLASE 2

Comillas simples = char
Comillas dobles = string

Tipos de Variables: int, float, char, long, double..
Funciones: Parte del codigo

char c = 41; //(parentesis en ASCII). Imprime dependiendo la mascara que ponga en el printf.
char c = '(';

EJERCICIO - CLASE 2
Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.

/*/

int main()
{
    int numeroIngresado, max, min, acumNumerosIngresados = 0, cantNumerosIngresados = 0;
    //int i;
    float promedio;
    char respuesta = 's';

//    for(i = 0; i < CANT_NUM; i++)
//    {
        do
        {
            printf("Ingrese numero: ");
            scanf("%d", &numeroIngresado);

            acumNumerosIngresados += numeroIngresado;

            if(cantNumerosIngresados == 0)//La i vale 0 solo una vez (el primer valor es max y min), la alternativa es hacer un flagOnce = 0.
            {
                max = numeroIngresado;
                min = numeroIngresado;
            }

            if(numeroIngresado > max)
            {
                max = numeroIngresado;
            }

            if(numeroIngresado < min)
            {
                min = numeroIngresado;
            }

                cantNumerosIngresados++;
                printf("\nIngresar otro numero? (s/n): ");
                fflush(stdin);
                scanf("%c", &respuesta);

        }while(respuesta == 's');

        promedio = (float)acumNumerosIngresados / cantNumerosIngresados;
        printf("\nEl promedio es: %.2f", promedio);
        printf("\nEl maximo es: %d", max);
        printf("\nEl minimo es: %d\n", min);

        return 0;
}
