#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Venta.h"

Venta* venta_new(int idVenta,int idCliente,int codProducto,int cantidad,float p
ecioUnitario,int estado)
{
        Venta* this = malloc(sizeof(Venta));

        if(this != NULL)
        {

                venta_setIdVenta(this,idVenta);
                venta_setIdCliente(this,idCliente);
                venta_setCodProducto(this,codProducto);
                venta_setCantidad(this,cantidad);
                venta_setPrecioUnitario(this,precioUnitario);
                venta_setEstado(this,estado);
        }
        return this;
}

void venta_delete(Venta* this)
{
        free(this);
}

int venta_setIdVenta(Venta* this,int idVenta)
{
        this->idVenta = idVenta;
        return 0;
}

int venta_setIdCliente(Venta* this,int idCliente)
{
        this->idCliente = idCliente;
        return 0;
}

int venta_setCodProducto(Venta* this,int codProducto)
{
        this->codProducto = codProducto;
        return 0;
}

int venta_setCantidad(Venta* this,int cantidad)
{
        this->cantidad = cantidad;
        return 0;
}

int venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
        this->precioUnitario = precioUnitario;
        return 0;
}

int venta_setEstado(Venta* this,int estado)
{
        this->estado = estado;
        return 0;
}

int venta_getIdVenta(Venta* this)
{
        return this->idVenta;
}

int venta_getIdCliente(Venta* this)
{
        return this->idCliente;
}

int venta_getCodProducto(Venta* this)
{
        return this->codProducto;
}

int venta_getCantidad(Venta* this)
{
        return this->cantidad;
}

float venta_getPrecioUnitario(Venta* this)
{
        return this->precioUnitario;
}

int venta_getEstado(Venta* this)
{
        return this->estado;
}

Venta* venta_findByIdVenta(ArrayList* pArray,int idVenta)
{

        int i;
        Venta* aux;
        Venta* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idVenta == venta_getIdVenta(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Venta* venta_findByIdCliente(ArrayList* pArray,int idCliente)
{

        int i;
        Venta* aux;
        Venta* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idCliente == venta_getIdCliente(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Venta* venta_findByCodProducto(ArrayList* pArray,int codProducto)
{

        int i;
        Venta* aux;
        Venta* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(codProducto == venta_getCodProducto(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Venta* venta_findByCantidad(ArrayList* pArray,int cantidad)
{

        int i;
        Venta* aux;
        Venta* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(cantidad == venta_getCantidad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Venta* venta_findByPrecioUnitario(ArrayList* pArray,float precioUnitario)
{

        int i;
        Venta* aux;
        Venta* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(precioUnitario == venta_getPrecioUnitario(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Venta* venta_findByEstado(ArrayList* pArray,int estado)
{

        int i;
        Venta* aux;
        Venta* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(estado == venta_getEstado(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int venta_compareByIdVenta(void* pA ,void* pB)
{

        int retorno = 0;

        if(venta_getIdVenta(pA) > venta_getIdVenta(pB))
                retorno = 1;
        else if(venta_getIdVenta(pA) < venta_getIdVenta(pB))
                retorno = -1;

        return retorno;
}

int venta_compareByIdCliente(void* pA ,void* pB)
{

        int retorno = 0;

        if(venta_getIdCliente(pA) > venta_getIdCliente(pB))
                retorno = 1;
        else if(venta_getIdCliente(pA) < venta_getIdCliente(pB))
                retorno = -1;

        return retorno;
}

int venta_compareByCodProducto(void* pA ,void* pB)
{

        int retorno = 0;

        if(venta_getCodProducto(pA) > venta_getCodProducto(pB))
                retorno = 1;
        else if(venta_getCodProducto(pA) < venta_getCodProducto(pB))
                retorno = -1;

        return retorno;
}

int venta_compareByCantidad(void* pA ,void* pB)
{

        int retorno = 0;

        if(venta_getCantidad(pA) > venta_getCantidad(pB))
                retorno = 1;
        else if(venta_getCantidad(pA) < venta_getCantidad(pB))
                retorno = -1;

        return retorno;
}

int venta_compareByPrecioUnitario(void* pA ,void* pB)
{

        int retorno = 0;

        if(venta_getPrecioUnitario(pA) > venta_getPrecioUnitario(pB))
                retorno = 1;
        else if(venta_getPrecioUnitario(pA) < venta_getPrecioUnitario(pB))
                retorno = -1;

        return retorno;
}

int venta_compareByEstado(void* pA ,void* pB)
{

        int retorno = 0;

        if(venta_getEstado(pA) > venta_getEstado(pB))
                retorno = 1;
        else if(venta_getEstado(pA) < venta_getEstado(pB))
                retorno = -1;

        return retorno;
}
