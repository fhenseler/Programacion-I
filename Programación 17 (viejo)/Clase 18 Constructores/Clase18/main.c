#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[20];
    char modelo[15];
    float precio;

}eNotebook;

eNotebook* new_notebook(); //CONSTRUCTOR POR DEFECTO (NO RECIBE NADA)
eNotebook* new_notebook_param(int, char[], char[], float);
void printNotebook(eNotebook*);

int main()
{
    eNotebook* unaNotebook;
    eNotebook* otraNotebook;

    unaNotebook = new_notebook();

    if(unaNotebook == NULL)
    {
        printf("No se pudo asignar memoria");
        exit(1);
    }

    otraNotebook = new_notebook_param(123, "compaq", "hh22", 10000);

    if(otraNotebook == NULL)
    {
        printf("No se pudo asignar memoria");
        exit(1);
    }

//        unaNotebook->id = 8;
//        strcpy(unaNotebook->marca, "HP");
//        strcpy(unaNotebook->modelo, "Envy"); //Pido al usuario que cargue o hardcodeo
//        unaNotebook->precio = 30000;

        printNotebook(unaNotebook);
        printf("\n\n");
        printNotebook(otraNotebook);
        printf("\n\n");

        free(unaNotebook);
        free(otraNotebook);

        return 0;

}

eNotebook* new_notebook()
{
    eNotebook* x = (eNotebook*)malloc(sizeof(eNotebook));

    if(x != NULL)
    {
        x->id = 0;
        strcpy(x->marca, "");
        strcpy(x->modelo, ""); //Pido al usuario que cargue o hardcodeo
        x->precio = 0;
    }
        return x;
}

eNotebook* new_notebook_param(int id, char marca[], char modelo[], float precio)
{
    eNotebook* x = new_notebook(); //CLAVE (anidar constructores)

    if(x != NULL)
    {
        x->id = id;
        strcpy(x->marca, marca);
        strcpy(x->modelo, modelo);
        x->precio = precio;
    }
        return x;
}

void printNotebook(eNotebook* notebook)
{
    printf("ID: %d, Modelo: %s, Marca: %s, Precio: %.2f", notebook->id, notebook->modelo, notebook->marca, notebook->precio);
}

