#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, cantPar = 0, cantImpar = 0, cantTotal = 0, sumImpar = 0, sumTotal = 0;
    float promedio;
    int maxNum, minNumImpar, flagMax = 0, flagMin = 0;
    int cant3_15 = 0, cant16_29 = 0, cant30mas = 0;
    char resp = 's';

    do
    {
        printf("\nIngrese numero: ");
        scanf("%d", &num);

        cantTotal++;
        sumTotal += num;

        if(num % 2 == 0 && num != 0)
        {
            cantPar++;
        }
        if(num % 2 != 0 && num != 0)
        {
            cantImpar++;
            sumImpar += num;

            if(flagMin == 0 || num < minNumImpar)
            {
                minNumImpar = num;
                flagMin = 1;
            }
        }
        if(flagMax == 0 || num > maxNum)
        {
            maxNum = num;
            flagMax = 1;
        }
        if(num >= 3 && num <= 15)
        {
            cant3_15++;
        }
        if(num >= 16 && num <= 29)
        {
            cant16_29++;
        }
        if(num >= 30)
        {
            cant30mas++;
        }
        printf("\nContinuar? (s/n)\n");
        resp = tolower(getch(resp));

    }while(resp == 's');

    promedio = (float)sumTotal / cantTotal;

    printf("\n1) Hay %d numeros pares\n", cantPar);
    printf("2) Hay %d numeros impares\n", cantImpar);
    printf("3) La sumatoria de todos los numeros es: %d\n", sumImpar);
    printf("4) El promedio de todos los numeros es: %.2f\n", promedio);
    printf("5) El numero mayor ingresado es: %d\n", maxNum);
    printf("6) El numero impar menor ingresado es: %d\n", minNumImpar);
    printf("7) A) Hay %d numeros entre 3 y 15\n  B) Hay %d numeros entre 16 y 29\n  C) Hay %d numeros iguales a 30 o mayores\n", cant3_15, cant16_29, cant30mas);

    for(i = sumImpar; i < sumImpar; i--)
    {
        printf("8) %d, ", sumImpar);
    }

    getch();
    return 0;
}
