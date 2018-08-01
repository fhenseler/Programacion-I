#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[21], apellido[21], apellidoYNombre[50];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);

    while(strlen(nombre) > 19)
    {
        printf("ERROR! El nombre es muy largo. Reingrese: ");
        gets(nombre);
    }

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    while(strlen(apellido) > 19)
    {
        printf("ERROR! El apellido es muy largo. Reingrese: ");
        gets(apellido);
    }

    strcpy(apellidoYNombre, apellido); //Para pisar la basura hago STRCPY antes del STRCAT
    strcat(apellidoYNombre, ", ");
    strcat(apellidoYNombre, nombre);

    strlwr(apellidoYNombre);

    apellidoYNombre[0] = toupper(apellidoYNombre[0]);

    for(int i = 0; i < strlen(apellidoYNombre); i++)
    {
        if(isspace(apellidoYNombre[i]))
        {
            apellidoYNombre[i+1] = toupper(apellidoYNombre[i+1]);
        }
    }

    printf("%s", apellidoYNombre);
    return 0;
}
