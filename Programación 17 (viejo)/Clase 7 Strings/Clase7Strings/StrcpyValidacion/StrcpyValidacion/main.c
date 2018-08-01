#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main()
{
    char nombre[LEN];
    char auxString[100];

    printf("Ingrese nombre: ");
    gets(auxString);

    while(strlen(auxString) > LEN - 1)
    {
        printf("ERROR! El string es muy largo. Reingrese: ");
        gets(auxString);
    }

    strcpy(nombre, auxString);

    printf("\nnombre = %s", nombre);
    printf("\nauxString = %s", auxString);

    return 0;

}
