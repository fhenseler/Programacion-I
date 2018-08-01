#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char cadena[50];

    f = fopen("prueba.txt", "w");
    if(f == NULL)
    {
        printf("No se pudo abrir el fichero");
        exit(1);
    }

        fprintf(f, "HOLA ASDSDMUNDO");

        fclose(f);

        return 0;
}
