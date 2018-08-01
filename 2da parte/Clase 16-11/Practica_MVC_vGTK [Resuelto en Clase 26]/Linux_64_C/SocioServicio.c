#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "SocioServicio.h"


SocioServicio* socserv_new( int idSocioServicio, int idSocio, int idServicio, int estado)
{
    SocioServicio* nuevoSocioServicio = malloc(sizeof(SocioServicio));
    socserv_setId(nuevoSocioServicio,idSocioServicio);
    socserv_setEstado(nuevoSocioServicio,estado);

    socserv_setIdSocio(nuevoSocioServicio,idSocio);
    socserv_setEstado(nuevoSocioServicio,estado);

    socserv_setIdServicio(nuevoSocioServicio,idServicio);
    socserv_setEstado(nuevoSocioServicio,estado);

    return nuevoSocioServicio;
}


int socserv_delete(SocioServicio* this)
{
    free(this);
    return 0;
}


int socserv_setId(SocioServicio* this,int id)
{

    this->id = id;
    return 0;
}

int socserv_getId(SocioServicio* this)
{
    return this->id;
}

int socserv_setIdSocio(SocioServicio* this,int idSocio)
{
    this->idSocio = idSocio;
    return 0;
}

int socserv_getIdSocio(SocioServicio* this)
{
    return this->idSocio;
}

int socserv_setIdServicio(SocioServicio* this,int idServicio)
{

    this->idServicio = idServicio;
    return 0;
}

int socserv_getIdServicio(SocioServicio* this)
{
    return this->idServicio;
}

int socserv_setEstado(SocioServicio* this,int estado)
{
    this->estado = estado;
    return 0;
}

int socserv_getEstado(SocioServicio* this)
{
    return this->estado;
}


SocioServicio* socserv_findById(ArrayList* pArraySocioServicio, int id)
{
    SocioServicio* retorno = NULL;
    SocioServicio* auxSocioServicio;
    int i;

    if(pArraySocioServicio != NULL)
    {
        for(i = 0; i < pArraySocioServicio->len(pArraySocioServicio); i++)
        {
            auxSocioServicio = pArraySocioServicio->get(pArraySocioServicio, i);
            if(socserv_getId(auxSocioServicio) == id)
            {
                retorno = auxSocioServicio;
            }
        }
    }
    return retorno;
}

int socserv_checkIds(ArrayList* pArraySocioServicio, int idSoc, int idServ)
{
    int retorno = -1;
    SocioServicio* auxSocioServicio;
    int i;

    if(pArraySocioServicio != NULL)
    {
        for(i = 0; i < pArraySocioServicio->len(pArraySocioServicio); i++)
        {
            auxSocioServicio = pArraySocioServicio->get(pArraySocioServicio, i);
            if(auxSocioServicio->estado != SOCIOSERVICIO_ESTADO_INACTIVO)
            {
                if(socserv_getIdServicio(auxSocioServicio) == idServ && socserv_getIdSocio(auxSocioServicio) == idSoc)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
