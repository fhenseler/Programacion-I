#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{

int opt;
long long int num1 = 0;
long long int num2 = 0;
long long int result = 0;
double resultDouble;

    do{
        system("cls");
        opt = menu(num1, num2);

            switch(opt){

            case 1:
                    printf("Ingresar 1er operando (A=x): ");
                    scanf("%I64d", &num1);
                    break;

            case 2:
                    printf("Ingresar 2do operando (B=y): ");
                    scanf("%I64d", &num2);
                    break;

            case 3:
                    result = add(num1, num2);
                    printf("SUMA (A+B) = %I64d", result);
                    getch();
                    break;

            case 4:
                    result = sub(num1, num2);
                    printf("RESTA (A-B) = %I64d", result);
                    getch();
                    break;

            case 5:
                    if(num2 == 0)
                    {
                        printf("ERROR! No se puede dividir por 0.\n");
                        return 0;
                    }

                    resultDouble = divi(num1, num2);
                    printf("DIVISION (A/B) = %.2f", resultDouble);
                    getch();
                    break;

            case 6:
                    result = mult(num1, num2);
                    printf("MULTIPLICACION (A*B) = %I64d", result);
                    getch();
                    break;

            case 7:
                    if(num1 < 0)
                    {
                        printf("ERROR! No existe el factorial de un numero negativo\n");
                        return 0;
                    }

                    result = factorial(num1);
                    printf("FACTORIAL (A!) = %I64d", result);
                    getch();
                    break;

            case 8:
                    result = add(num1, num2);
                    printf("\nSUMA (A+B) = %I64d", result);
                    result = sub(num1, num2);
                    printf("\nRESTA (A-B) = %I64d", result);
                    result = divi(num1, num2);
                    printf("\nDIVISION (A/B) = %.2f", resultDouble);
                    result = mult(num1, num2);
                    printf("\nMULTIPLICACION (A*B) = %I64d", result);
                    result = factorial(num1);
                    printf("\nFACTORIAL (A!) = %I64d", result);
                    getch();
                    break;
            }

    }while(opt != 9);
                    return 0;
}
