#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"
#include "Consola.h"

int main()
{
    float rSuma,rResta,rMulti,rDivision,num2,num1;
    if(getFloat("Ingrese numero: ", "\nINTENTOS AGOTADOS!\n", &num1, -100, 100, 2) == -1)
    {
        exit(EXIT_FAILURE);
    }
    if(getFloat("Ingrese otro numero: ", "\nINTENTOS AGOTADOS!\n", &num2, -100, 100, 2) == -1)
    {
        exit(EXIT_FAILURE);
    }

    if(calculadora(&rDivision,&rSuma,&rResta,&rMulti,num1,num2)== -1)
    {
        printf("Error");
    }
    else
    {
        printf("La division es : %.2f",rDivision);
    }
    printf("\nLa suma es: %.2f", rSuma);
    printf("\nLa resta es: %.2f",rResta);
    printf("\nLa multiplicacion es %.2f", rMulti);
    //****************************************************
    calculadora2(&rDivision,num1,num2,DIVISION);
    printf("\n\n\nLa division es : %.2f",rDivision);

    calculadora2(&rSuma,num1,num2,SUMA);
    printf("\nLa division es : %.2f",rSuma);

    return 0;
}
