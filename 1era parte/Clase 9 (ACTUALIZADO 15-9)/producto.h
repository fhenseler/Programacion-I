#ifndef _PRODUCTO
#define _PRODUCTO
#define ARRAY_LENGTH 51

typedef struct{
    char nombre[ARRAY_LENGTH];
    char desc[ARRAY_LENGTH];
    float precio;
    unsigned char estado;
    unsigned char id;
    //unsigned char indiceID;
}sProducto;

#endif // _PRODUCTO

#define PRODUCTO_LIBRE 0
#define PRODUCTO_OCUPADO 1
#define MAX_PRODUCTOS 200

int prod_cargarProducto(sProducto* arrayProducto, int index, int longitud);
int prod_printProducto(sProducto* arrayProducto, int longitud);
int prod_initProducto(sProducto* arrayProducto, int longitud);
int prod_buscarProductoLibre(sProducto* arrayProducto, int longitud);
int prod_obtenerId(sProducto* arrayProducto, int longitud);
int prod_buscarIndicePorId(sProducto* arrayProducto, int id, int longitud);
int prod_modificarProducto(sProducto* arrayProducto);
int prod_bajaProducto(sProducto* arrayProducto);
