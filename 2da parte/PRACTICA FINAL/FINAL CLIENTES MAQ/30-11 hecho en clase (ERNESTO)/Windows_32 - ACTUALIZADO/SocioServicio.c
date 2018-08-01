#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "SocioServicio.h"


ClienteAlquiler* clialq_new(int idClienteAlquiler, int idCliente, int idAlquiler, int estado)
{
    ClienteAlquiler* nuevoClienteAlquiler = malloc(sizeof(ClienteAlquiler));
    clialq_setId(nuevoClienteAlquiler,idClienteAlquiler);
    clialq_setIdCliente(nuevoClienteAlquiler,idCliente);
    clialq_setEstado(nuevoClienteAlquiler,estado);
    clialq_setIdAlquiler(nuevoClienteAlquiler,idAlquiler);

    return nuevoClienteAlquiler;
}


int clialq_delete(ClienteAlquiler* this)
{
    free(this);
    return 0;
}


int clialq_setId(ClienteAlquiler* this,int id)
{

    this->id = id;
    return 0;
}

int clialq_getId(ClienteAlquiler* this)
{
    return this->id;
}

int clialq_setIdCliente(ClienteAlquiler* this,int idCliente)
{
    this->idCliente = idCliente;
    return 0;
}

int clialq_getIdCliente(ClienteAlquiler* this)
{
    return this->idCliente;
}

int clialq_setIdAlquiler(ClienteAlquiler* this,int idAlquiler)
{

    this->idAlquiler = idAlquiler;
    return 0;
}

int clialq_getIdAlquiler(ClienteAlquiler* this)
{
    return this->idAlquiler;
}

int clialq_setEstado(ClienteAlquiler* this,int estado)
{
    this->estado = estado;
    return 0;
}

int clialq_getEstado(ClienteAlquiler* this)
{
    return this->estado;
}


ClienteAlquiler* clialq_findById(ArrayList* pArrayClienteAlquiler, int id)
{
    ClienteAlquiler* retorno = NULL;
    ClienteAlquiler* auxClienteAlquiler;
    int i;

    if(pArrayClienteAlquiler != NULL)
    {
        for(i = 0; i < pArrayClienteAlquiler->len(pArrayClienteAlquiler); i++)
        {
            auxClienteAlquiler = al_get(pArrayClienteAlquiler, i);
            if(clialq_getId(auxClienteAlquiler) == id)
            {
                retorno = auxClienteAlquiler;
            }
        }
    }
    return retorno;
}

int clialq_checkRelacion(ArrayList* pArrayClienteAlquiler, int idSoc, int idServ)
{
    int retorno = -1;
    ClienteAlquiler* auxClienteAlquiler;
    int i;

    if(pArrayClienteAlquiler != NULL)
    {
        for(i = 0; i < pArrayClienteAlquiler->len(pArrayClienteAlquiler); i++)
        {
            auxClienteAlquiler = al_get(pArrayClienteAlquiler, i);
            if(auxClienteAlquiler->estado == CLIENTEALQUILER_ESTADO_ACTIVO)
            {
                if(clialq_getIdAlquiler(auxClienteAlquiler) == idServ && clialq_getIdCliente(auxClienteAlquiler) == idSoc)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int clialq_checkIdCliente(ArrayList* pArrayClienteAlquiler, int idSoc)
{
    int retorno = -1;
    ClienteAlquiler* auxClienteAlquiler;
    int i;

    if(pArrayClienteAlquiler != NULL)
    {
        for(i = 0; i < pArrayClienteAlquiler->len(pArrayClienteAlquiler); i++)
        {
            auxClienteAlquiler = al_get(pArrayClienteAlquiler, i);
            if(auxClienteAlquiler->estado == CLIENTEALQUILER_ESTADO_ACTIVO)
            {
                if(clialq_getIdCliente(auxClienteAlquiler) == idSoc)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}


