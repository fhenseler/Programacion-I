#include <stdio.h>
#include <stdlib.h>

#include "Calculadora.h"
#include "Consola.h"


int main()
{
    float rSuma,rResta,rMulti,rDivision,y,x;
    if(tomaNumero("Ingrese el primer numero: ", &x, 100,-100) == -1)
    {
        printf("Error");
    }
    if(tomaNumero("Ingrese el segundo numero: ", &y, 100,-100) == -1)
    {
        printf("Error");
    }

    //printf("Ingrese el primer numero :\n");
    //scanf("%f",&x);
    //printf("Ingrese el segundo numero : \n");
    //scanf("%f",&y);

    if(calculadora(&rDivision,&rSuma,&rResta,&rMulti,x,y)== -1)
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
    calculadora2(&rDivision,x,y,DIVISION);
    printf("\n\n\nLa division es : %.2f",rDivision);

    calculadora2(&rSuma,x,y,SUMA);
    printf("\nLa division es : %.2f",rSuma);



    return 0;
}

