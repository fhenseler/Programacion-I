#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANT 10

int main()
{
    int flag = 1;
    eProgramador plantel[CANT];
    eCategoria categorias[]= {{1, "Junior"},{2,"SemiSenior"},{3,"Senior"}};
    int cantJunior = 0;
    int cantSemiSenior = 0;
    int cantSenior = 0;

    inicializarProgramadores(plantel, CANT);

    do
    {

    switch(menu())
    {
    case 1:
        if(altaProgramador(plantel, CANT, categorias, 3))
        {
            printf("Alta exitosa!!!\n\n");
        }
        else
        {
            printf("No se pudo efectuar el alta\n\n");
        }
        system("pause");
        break;

    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        mostrarProgramadores(plantel, CANT, categorias, 3);
        break;

    case 6:
        cantJunior = cantidadPorCategoria(plantel, CANT, categorias, 3, "Junior");
        cantSemiSenior = cantidadPorCategoria(plantel, CANT, categorias, 3, "SemiSenior");
        cantSenior = cantidadPorCategoria(plantel, CANT, categorias, 3, "Senior");

        printf("\nJunior: %d   SemiSenior: %d   Senior: %d\n\n", cantJunior, cantSemiSenior, cantSenior);

        system("pause");

        break;

    case 7:

        break;

    case 8:
        flag = 0;
        break;

    default:
        printf("\nOpcion invalida\n");
        system("pause");

        break;
    }

     }while(flag);

    return 0;
}








