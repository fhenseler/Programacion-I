#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu(int lowLimit, int hiLimit)
{
    lowLimit = 1;
    hiLimit = 8;
    int opt = 0;

    printf("1. opc 1\n");
    printf("2. opc 2\n");
    printf("3. opc 3\n");
    printf("4. opc 4\n");
    printf("5. opc 5\n");
    printf("6. opc 6\n");
    printf("7. opc 7\n");
    printf("8. Salir\n");

    do
    {
        printf("\nSeleccione opci%cn: ", 162);
        scanf("%d", &opt);
        return opt;
    }while(opt < lowLimit || opt > hiLimit);

    return 0;
}












































