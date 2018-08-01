#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()//DESARROLLO DE LA FUNCIÓN PRINCIPAL
{

int opt = 0;//OPCIÓN DEL MENÚ
float num1 = 0;
float num2 = 0;

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
                    printAdd(num1, num2);
                    getch();
                    break;

            case 4:
                    printSub(num1, num2);
                    getch();
                    break;

            case 5:
                    if(num2 == 0)
                    {
                        printf("ERROR! No se puede dividir por 0.\n");
                        getch();
                        break;
                    }
                    printDivi(num1, num2);
                    getch();
                    break;

            case 6:
                    printMult(num1, num2);
                    getch();
                    break;

            case 7:
                    if(num1 < 0)
                    {
                        printf("ERROR! No existe el factorial de un numero negativo\n");
                        getch();
                        break;
                    }
                        printFactorial(num1);
                        getch();
                        break;

            case 8:
                    if (num1 < 0 && num2 == 0)
                    {
                        printf("ERROR! No se puede dividir por 0.\n");
                        printf("ERROR! No existe el factorial de un numero negativo\n");
                        getch();
                        break;
                    }

                    if(num2 == 0)
                    {
                        printf("ERROR! No se puede dividir por 0.\n");
                        getch();
                        break;
                    }

                    if(num1 < 0)
                    {
                        printf("ERROR! No existe el factorial de un numero negativo\n");
                        getch();
                        break;
                    }
                        printAdd(num1, num2);
                        printSub(num1, num2);
                        printDivi(num1, num2);
                        printMult(num1, num2);
                        printFactorial(num1);
                        getch();
                        break;
            }

        }while(opt != 9);
                        return 0;
}
