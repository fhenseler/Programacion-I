#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char x;

    f = fopen("prueba.txt", "w");
    if(f == NULL)
    {
        printf("No se pudo abrir el fichero");
        exit(1);
    }

    while(x != feof)
    {
        x = fgetc(f);
        printf("%c", x);
    }

        fclose(f);

        return 0;
}
