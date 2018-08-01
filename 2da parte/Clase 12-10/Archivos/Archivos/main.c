#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
//-------------------------------ESCRITURA-------------------------------------
    FILE *pArchivo;//Flujo de informacion
    int i;

    pArchivo = fopen("prueba.txt", "w");
    if(pArchivo != NULL)
    {
        for(i = 1; i <= 100; i++)
        {
            fprintf(pArchivo, "\nLINEA: %d", i);
        }
            printf("TODO OK!");
    }
    else
    {
        printf("\nERROR! No se pudo abrir el archivo!!!");
    }
        fclose(pArchivo);

//-------------------------------LECTURA-------------------------------------

        char textoLinea[50];
        pArchivo = fopen("prueba.txt", "r");
        if(pArchivo != NULL)
        {
            while(!feof(pArchivo))
            {
//                fread(textoLinea, sizeof(char), 50, pArchivo);
                if(fgets(textoLinea, 50, pArchivo)!=NULL)
                {
                   printf("->>>%s", textoLinea);
                }
            }
        }
                fclose(pArchivo);
                return 0;
}
