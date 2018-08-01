#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int num1, num2;
    float resultDiv, resultMult, resultSuma, resultResta;

    printf("Ingrese primer operando: ");
    scanf("%d", &num1);

    printf("Ingrese segundo operando: ");
    scanf("%d", &num2);

    if(operacionesMatematicas(&resultDiv, &resultMult, &resultSuma, &resultResta, num1, num2) == -1)
    {
        printf("ERROR! No se puede dividir por 0\n");
    }
    else
    {
        printf("El resultado de la division es: %f\n", resultDiv);
    }

        printf("El resultado de la multiplicacion es: %f\n", resultMult);
        printf("El resultado de la suma es: %f\n", resultSuma);
        printf("El resultado de la resta es: %f\n", resultResta);
        return 0;
}


