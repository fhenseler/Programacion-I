#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//...

#endif //FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[51];
    char descripcion[100];
    float precio;
    int estaCargado;
}eProducto; //PUNTO 1

void inicializarArray(eProducto arrayProductos[], int len);//PUNTO 2
int validarNombre(char buffer[], int len);
int validarDescripcion(char buffer[], int len);
int validarPrecio(char buffer[]);
int cargarDatos(eProducto arrayProductos[], int indice);//PUNTO 3
void imprimirProducto(eProducto arrayProductos[], int indice); //PUNTO 4
int encontrarLugarVacio(eProducto arrayProductos[], int len);//PUNTO 5
int menu(void);
void getDato(char buffer[], char msg[]);
