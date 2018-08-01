#include <stdio.h>
#include <stdlib.h>

int dividirEnteros(float*, int, int);

int main()
{
    int num1, num2;
    float result;

    printf("Ingrese dividendo: ");
    scanf("%d", &num1);

    printf("Ingrese divisor: ");
    scanf("%d", &num2);

    if(dividirEnteros(&result, num1, num2) == -1)
    {
        printf("ERROR! No se puede dividir por 0");
    }
    else
    {
        printf("El resultado es: %f", result);
    }

        return 0;
}


/** \brief División
 *
 * \param resultado Resultado de la división
 * \param a Dividendo
 * \param b Divisor
 * \return (0) ok - (-1) error
 *
 */
int dividirEnteros(float* resultado, int a, int b)
{
    int retorno = -1;

    if(b != 0)
    {
        *resultado = (float)a / b;
        retorno = 0;
    }

        return retorno;
}
