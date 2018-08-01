#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#define LF 10

void inicializarArray(eProducto arrayProductos[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        arrayProductos[i].estaCargado=0;
    }
}

int menu(void)
{
    int opt;

    printf("---------------MENU DE OPCIONES---------------");
    printf("\n1. Cargar un producto");
    printf("\n2. Imprimir el producto cargado");
    printf("\n3. Salir");
    printf("\n----------------------------------------------");

    do{
        printf("\nSeleccione opci%cn: ", 162);
        scanf("%d", &opt); //getInt
        return opt;
    }while(opt < 1 || opt > 9);
}


int validarNombre(char buffer[], int len)
{
    int retorno = 1;
    return retorno;
}

int validarDescripcion(char buffer[], int len)
{
    int retorno = 1;
    return retorno;
}

int validarPrecio(char buffer[])
{
    int retorno = 0;
    int i = 0;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != LF  && buffer[i] != '.')
        {
            retorno = -1;
            break;
        }
            i++;
    }
            return retorno;
}

void getDato(char buffer[], char msg[])
{
    printf(msg);
    fflush(stdin);
    fgets(buffer, 4096, stdin);
    buffer[4094]= LF;
    buffer[4095]= '\0';
}

int cargarDatos(eProducto arrayProductos[], int indice)
{
    char auxiliarNombre[4096];
    char auxiliarDescripcion[4096];
    char auxiliarPrecio[4096];

    getDato(auxiliarNombre, "Ingrese nombre del producto: ");

    if(validarNombre(auxiliarNombre, 200) == 1)
    {
        strncpy(arrayProductos[indice].nombre, auxiliarNombre, 200);
    }

    getDato(auxiliarDescripcion, "Ingrese descripcion del producto: ");
    if(validarDescripcion(auxiliarDescripcion, 200) == 1)
    {
        strncpy(arrayProductos[indice].descripcion, auxiliarDescripcion, 200);
    }

    getDato(auxiliarPrecio, "Ingrese precio del producto: ");
    if(validarPrecio(auxiliarPrecio) == 0)
    {
        arrayProductos[indice].precio = atof(auxiliarPrecio);
    }
    else
    {
        printf("PRECIO INVALIDO!!!");
        getch();
    }

        arrayProductos[indice].estaCargado = 1;
        return 0;
}

void imprimirProducto(eProducto arrayProductos[], int indice)
{
    printf("\nNombre --- Descripcion --- Precio\n");
    printf(" %s --- %s --- %.2f\n\n", arrayProductos[indice].nombre, arrayProductos[indice].descripcion, arrayProductos[indice].precio);
}

int encontrarLugarVacio(eProducto arrayProductos[], int len)
{
    int i;
    int retorno = -1;
    for(i = 0; i < len; i++)
    {
        if(arrayProductos[i].estaCargado == 0)
        {
            retorno = i;
            break;
        }
    }
            return retorno;
}


