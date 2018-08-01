
#include "ArrayList.h"

#ifndef _VENTA_H
#define _VENTA_H
typedef struct
{
        int idVenta;
        int idCliente;
        int codProducto;
        int cantidad;
        float precioUnitario;
        int estado;
}Venta;
#endif// _VENTA_H

Venta* venta_new(int idVenta,int idCliente,int codProducto,int cantidad,float precioUnitario,int estado);
void venta_delete(Venta* this);
int venta_setIdVenta(Venta* this,int idVenta);
int venta_setIdCliente(Venta* this,int idCliente);
int venta_setCodProducto(Venta* this,int codProducto);
int venta_setCantidad(Venta* this,int cantidad);
int venta_setPrecioUnitario(Venta* this,float precioUnitario);
int venta_setEstado(Venta* this,int estado);
int venta_getIdVenta(Venta* this);
int venta_getIdCliente(Venta* this);
int venta_getCodProducto(Venta* this);
int venta_getCantidad(Venta* this);
float venta_getPrecioUnitario(Venta* this);
int venta_getEstado(Venta* this);
Venta* venta_findByIdVenta(ArrayList* pArray,int idVenta);
Venta* venta_findByIdCliente(ArrayList* pArray,int idCliente);
Venta* venta_findByCodProducto(ArrayList* pArray,int codProducto);
Venta* venta_findByCantidad(ArrayList* pArray,int cantidad);
Venta* venta_findByPrecioUnitario(ArrayList* pArray,float precioUnitario);
Venta* venta_findByEstado(ArrayList* pArray,int estado);
int venta_compareByIdVenta(void* pA ,void* pB);
int venta_compareByIdCliente(void* pA ,void* pB);
int venta_compareByCodProducto(void* pA ,void* pB);
int venta_compareByCantidad(void* pA ,void* pB);
int venta_compareByPrecioUnitario(void* pA ,void* pB);
int venta_compareByEstado(void* pA ,void* pB);
