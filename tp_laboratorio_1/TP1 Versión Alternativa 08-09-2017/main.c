#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()//DESARROLLO DE LA FUNCIÓN PRINCIPAL
{

    int opt = 0;//OPCIÓN DEL MENÚ
    float num1 = 0;
    float num2 = 0;
    float resultAdd, resultSub, resultDivi, resultMult, resultFact;

    do
    {
        system("cls");
        opt = menu(num1, num2);

            switch(opt)
            {

            case 1:
                    printf("Ingresar 1er operando (A=x): ");
                    scanf("%f", &num1);
                    break;

            case 2:
                    printf("Ingresar 2do operando (B=y): ");
                    scanf("%f", &num2);
                    break;

            case 3:
                    n_Add(&resultAdd, num1, num2);
                    printf("El resultado de la suma es: %f", resultAdd);
                    getch();
                    break;

            case 4:
                    n_Sub(&resultSub, num1, num2);
                    printf("El resultado de la resta es: %f", resultSub);
                    getch();
                    break;

            case 5:
                    if(num2 == 0)
                    {
                        printf("ERROR! No se puede dividir por 0.\n");
                        getch();
                        break;
                    }
                    n_Divi(&resultDivi, num1, num2);
                    printf("El resultado de la suma es: %f", resultDivi);
                    getch();
                    break;

            case 6:
                    n_Mult(&resultMult, num1, num2);
                    printf("El resultado de la multiplicacion es: %f", resultMult);
                    getch();
                    break;

            case 7:
                    if(num1 < 0)
                    {
                        printf("ERROR! No existe el factorial de un numero negativo\n");
                        getch();
                        break;
                    }
                        n_Factorial(&resultFact, num1);
                        printf("El factorial de %.0f es: %.2f", num1, resultFact);
                        getch();
                        break;

            case 8:
                    if (num1 <= 0 && num2 == 0)
                    {
                        printf("\nERROR! No se puede dividir por 0.\n");
                        printf("\nERROR! No existe el factorial de un numero negativo.\n");
                        printf("\nMULTIPLICACI%cN ( A * B) = %f", 224, resultMult);
                        printf("\nSUMA ( A + B ) = %f", resultAdd);
                        printf("\nRESTA ( A - B ) = %f", resultSub);
                        getch();
                        break;
                    }

                    if(num2 == 0)
                    {
                        printf("\nDIVISI%cN ( A / B ) = ERROR! No se puede dividir por 0.", 224);
                        printf("\nMULTIPLICACI%cN ( A * B) = %f", 224, resultMult);
                        printf("\nSUMA ( A + B ) = %f", resultAdd);
                        printf("\nRESTA ( A - B ) = %f", resultSub);
                        printf("\nFACTORIAL ( A ! ) = %f", resultFact);
                        getch();
                        break;
                    }

                    if(num1 < 0)
                    {
                        printf("\nERROR! No existe el factorial de un numero negativo\n");
                        printf("\nSUMA ( A + B ) = %f", resultAdd);
                        printf("\nMULTIPLICACION ( A * B) = %f", resultMult);
                        printf("\nSUMA ( A + B ) = %f", resultAdd);
                        printf("\nRESTA ( A - B ) = %f", resultSub);
                        printf("\nFACTORIAL ( A ! ) = %f", resultFact);
                        getch();
                        break;
                    }
                        printf("\nSUMA ( A + B ) = %f", resultAdd);
                        printf("\nMULTIPLICACION ( A * B) = %f", resultMult);
                        printf("\nSUMA ( A + B ) = %f", resultAdd);
                        printf("\nRESTA ( A - B ) = %f", resultSub);
                        printf("\nFACTORIAL ( A ! ) = %f", resultFact);
                        getch();
                        break;
            }

        }while(opt != 9);
                        return 0;
}
