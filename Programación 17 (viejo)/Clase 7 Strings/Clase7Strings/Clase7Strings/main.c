#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 31

int main()
{
    char nombre[MAX];

    printf("Ingrese nombre: ");
    gets(nombre);
    strlwr(nombre);
    nombre[0] = toupper(nombre[0]);

    for(int i = 0; i < MAX; i++)
    {
        if(isspace(nombre[i]) != 0)
        {
            nombre[i+1] = toupper(nombre[i+1]);
        }
    }

    printf("%s", nombre);

    return 0;
}
