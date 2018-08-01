#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "validar.h"

#define MAX_INPUT_BUFFER 40

int main()
{
    sProducto arrayProductos[MAX_PRODUCTOS];
    char bufferInt[MAX_INPUT_BUFFER];

    prod_initProducto(arrayProductos, MAX_PRODUCTOS);

    do
    {
        val_getUnsignedInt(bufferInt, "\n1-Alta\n2-Listar\n3-Modificar\n4-Baja\n\n8-Salir\n", "\nSolo 1, 2 y 3\n", 2, MAX_INPUT_BUFFER);
        switch(atoi(bufferInt))
        {
            case 1:
                prod_cargarProducto(arrayProductos, prod_buscarProductoLibre(arrayProductos, MAX_PRODUCTOS), MAX_PRODUCTOS);
                break;
            case 2:
                prod_printProducto(arrayProductos, MAX_PRODUCTOS);
                break;
            case 3:
                prod_modificarProducto(arrayProductos);
                break;
            case 4:
                prod_bajaProducto(arrayProductos);
                break;
        }

    }while(atoi(bufferInt) != 8);

                return 0;
}
