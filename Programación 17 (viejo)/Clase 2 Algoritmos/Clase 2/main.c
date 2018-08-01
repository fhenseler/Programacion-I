#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, cantPar = 0, cantImpar = 0, cantNum = 0, totalNum = 0, totalImpar = 0, cant3a15 = 0, cant16a29 = 0, cant30omas = 0, flagMax = 0, flagMin = 0, maxNum, minNumImpar, acumPrev = 0;
    char resp = 's';
    do
    {
            printf("Ingrese numero: ");
            scanf("%d", &num);
            if(num % 2 == 0 && num != 0)
            {
                cantPar += 1;
            }
                    if(num % 2 != 0 && num != 0)
                    {
                        cantImpar += 1;
                        totalImpar += num;
                        if(flagMin == 0 || num < minNumImpar)
                        {
                            minNumImpar = num;
                            flagMin = 1;
                        }
                    }

                        if(num >= 3 && num <= 15)
                        {
                            cant3a15 ++;
                        }
                           else
                           {
                                if(num > 15 && num < 30)
                                {
                                    cant16a29 ++;
                                }

                                else
                                {
                                    if(num >= 30)
                                    {
                                    cant30omas ++;
                                    }
                                }
                           }
                                    if(flagMax == 0 || num > maxNum)
                                    {
                                        maxNum = num;
                                        flagMax = 1;
                                    }

                                        cantNum += 1;
                                        totalNum += num;
                                        printf("Ingresar otro numero? (s/n)\n");
                                        resp = tolower(getch());

    }while(resp == 's');


            printf("\n1- Hay %d numeros pares\n", cantPar);
            printf("2- Hay %d numeros impares\n", cantImpar);
            printf("3- La suma de los impares es: %d\n", totalImpar);
            printf("4- El promedio de los numeros ingresados es: %.3f\n", (float)totalNum/cantNum);
            printf("5- El numero maximo es: %d\n", maxNum);
            printf("6- El menor impar es: %d\n", minNumImpar);
            printf("7- Hay %d numeros entre 3 y 15\n", cant3a15);
            printf("Hay %d numeros entre 16 y 29\n", cant16a29);
            printf("Hay %d numeros iguales o mayores a 30\n", cant30omas);
            printf("8- b) ");

                for(i = totalImpar; i > 0; i--)
                {
                    acumPrev += i;
                    printf("%d, ", i);
                }

            printf("\n8- a) La sumatoria de los numeros que anteceden al total de impares es: %d\n", acumPrev);

            getch();
            return 0;
}
