#include <stdio.h>
#include <stdlib.h>

int validaPositivo(int);

int main()
{
    int numPos, cantPar = 0, cantImpar = 0, cantTotal = 0, acumTotal = 0, acumImpar = 0;
    int numMax, numMinImpar, flagMax = 0, flagMinImpar = 0, sumAntecedentes = 0;
    int cant3_15 = 0, cant16_29 = 0, cant30Mas = 0;
    float promedioTotal;
    char resp = 's';

    do
    {
        printf("\nIngrese numero positivo: ");
        scanf("%d", &numPos);
        validaPositivo(numPos);

        if(numPos > 0)
        {
            cantTotal++;
            acumTotal += numPos;


            if(flagMax == 0 || numPos > numMax)
            {
                numMax = numPos;
                flagMax = 1;
            }

            if(numPos % 2 == 0)
            {
                cantPar++;
            }
            else
            {
                if(flagMinImpar == 0 || numPos < numMinImpar)
                {
                    numMinImpar = numPos;
                    flagMinImpar = 1;
                }

                    cantImpar++;
                    acumImpar += numPos;
            }
        }

        if(numPos >= 3 && numPos <= 15)
        {
            cant3_15++;
        }

        else
        {
            if(numPos >= 16 && numPos <= 29)
            {
                cant16_29++;
            }
                if(numPos >= 30)
                {
                    cant30Mas++;
                }
        }

        printf("\nContinuar? (s/n)");
        resp = tolower(getch(resp));

    }while(resp == 's');

    promedioTotal = (float)acumTotal / cantTotal;

    printf("\n1- Cantidad de numeros pares: %d", cantPar);
    printf("\n2- Cantidad de numeros impares: %d", cantImpar);
    printf("\n3- Sumatoria de numeros impares: %d", acumImpar);
    printf("\n4- Promedio de todos los numeros: %f", promedioTotal);
    printf("\n5- Numero mayor ingresado: %d", numMax);
    printf("\n6- Numero impar menor ingresado: %d", numMinImpar);
    printf("\n7- A- Cantidad numeros entre 3-15: %d\nB- Cantidad numeros entre 16-29: %d\nC- Cantidad numeros 30+: %d\n", cant3_15, cant16_29, cant30Mas);

    printf("\n8- B- ");
    for(int i = acumImpar; i > 0; i--)
    {
        sumAntecedentes += i;
        printf("%d ", i);
    }

    printf("\n8- A- Sumatoria de numeros que anteceden al total de numeros impares: %d", sumAntecedentes);

    return 0;
}

int validaPositivo(int num)
{
    if(num <= 0)
    {
        printf("ERROR! Solo se admiten numeros positivos mayores a 0.");
    }
        return 0;
}
