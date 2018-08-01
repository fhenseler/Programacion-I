#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "validar.h"

static int modificarPorIndice(sProducto* arrayProducto, int index);

int prod_cargarProducto(sProducto* arrayProducto, int index, int longitud)
{
    int retorno = -1;
    int id;
    char bNombre[ARRAY_LENGTH];
    char bPrecio[ARRAY_LENGTH];
    char bDescripcion[ARRAY_LENGTH];

    if(arrayProducto != NULL && index >= 0 && index < longitud)
    {
        if(val_getNombre(bNombre,"\nIngrese nombre del producto: ", "\nError, reingrese nombre: ", 3, ARRAY_LENGTH)==0)
        {
            if(val_getFloat(bPrecio,"\nIngrese precio del producto: ", "\nError, reingrese precio: ", 3, ARRAY_LENGTH)==0)
            {
                if(val_getDescripcion(bDescripcion, "\nIngrese descripcion del producto: ", "Error, reingrese descripcion: ", 3, ARRAY_LENGTH)==0)
                {
                    id = prod_obtenerId(arrayProducto, longitud);
                    if(id != -1)
                    {
                        strncpy(arrayProducto[index].nombre,bNombre, ARRAY_LENGTH);
                        strncpy(arrayProducto[index].desc, bDescripcion, ARRAY_LENGTH);
                        arrayProducto[index].precio = atof(bPrecio);
                        arrayProducto[index].estado = PRODUCTO_OCUPADO;
                        arrayProducto[index].id = prod_obtenerId(arrayProducto, MAX_PRODUCTOS);
                        printf("\nPRODUCTO DADO DE ALTA\n");
                        retorno = 0;
                    }
                }
            }
        }

    }
                        return retorno;
}

int prod_initProducto(sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayProducto[i].estado = PRODUCTO_LIBRE;
        }

    }
            return retorno;
}

int prod_printProducto(sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        printf("\nID\tNombre\tPrecio\tDescripcion");
        for(i = 0; i < longitud; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                printf("\n%d\t%s\t%.2f\t%s", arrayProducto[i].id , arrayProducto[i].nombre,arrayProducto[i].precio, arrayProducto[i].desc);
            }
        }
                printf("\n\n");
    }
                return retorno;
}


int prod_buscarProductoLibre(sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
                return retorno;
}

int prod_obtenerId(sProducto* arrayProducto, int longitud)
{
    int i = 0;
    int idMax = -1;

    if(arrayProducto != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO) //&& arrayProducto[i].id > idMax)
            {
                if(idMax < arrayProducto[i].id)
                {
                    idMax = arrayProducto[i].id;
                }

            }
        }
    }
                    return idMax + 1;
}

int prod_buscarIndicePorId(sProducto* arrayProducto, int id, int longitud)
{
    int i;
    int retorno = -1;

    if(arrayProducto != NULL && longitud > 0 && id >= 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(id == arrayProducto[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
                    return retorno;
}

static int modificarPorIndice(sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[ARRAY_LENGTH];
    char bPrecio[ARRAY_LENGTH];

    if(arrayProducto != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nIngrese nuevo nombre: ","\nError. Reingrese nombre: \n", 3, ARRAY_LENGTH)==0)
        {
            if(val_getFloat(bPrecio,"\nIngrese nuevo precio: ","\nError. Reingrese precio: \n", 3, ARRAY_LENGTH)==0)
            {
                    strncpy(arrayProducto[index].nombre, bNombre, ARRAY_LENGTH);
                    arrayProducto[index].precio = atof(bPrecio);
                    retorno = 0;
            }
        }
    }
                    return retorno;
}

int prod_modificarProducto(sProducto* arrayProducto)
{
    int id;
    int retorno = -1;
    char buffer[ARRAY_LENGTH];

        val_getUnsignedInt(buffer, "Ingrese ID del producto a modificar: \n", "Error. Reingrese ID: ", 3, ARRAY_LENGTH);
        id = atoi(buffer);
        if(prod_buscarIndicePorId(arrayProducto, id, MAX_PRODUCTOS) == -1)
        {
            printf("\nError! ID Invalido\n");
        }
            modificarPorIndice(arrayProducto, prod_buscarIndicePorId(arrayProducto, id, MAX_PRODUCTOS));
            return retorno;
}

int prod_bajaProducto(sProducto* arrayProducto)
{
    int indice;
    int id;
    int retorno = -1;
    char buffer[ARRAY_LENGTH];

        val_getUnsignedInt(buffer, "Ingrese ID del producto a borrar: \n", "Error. Reingrese ID:  ", 3, ARRAY_LENGTH);
        id = atoi(buffer);
        if(prod_buscarIndicePorId(arrayProducto, id, MAX_PRODUCTOS) == -1)
        {
            printf("Error! ID Invalido\n");
        }
        else
        {
            indice = prod_buscarIndicePorId(arrayProducto, id, MAX_PRODUCTOS);
            arrayProducto[indice].estado = PRODUCTO_LIBRE;
            printf("PRODUCTO DADO DE BAJA\n");
        }
            return retorno;
}
