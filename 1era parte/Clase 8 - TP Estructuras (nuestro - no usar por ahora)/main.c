#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int main()
{
    int opcion = 0;
    int indice;
    eProducto arrayProductos[200];

    inicializarArray(arrayProductos, 200);
    indice = encontrarLugarVacio(arrayProductos, 200);

    do
    {
        system("cls");
        opcion = menu();
        switch(opcion)
        {
            case 1:
                    cargarDatos(arrayProductos, indice);
                    break;
            case 2:
                    imprimirProducto(arrayProductos, indice);
                    getch();
                    break;
        }
    }while(opcion != 3);

                return 0;
}
