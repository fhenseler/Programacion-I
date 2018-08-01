#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicio.h"

Servicio* serv_new(char* descripcion, int idServicio, int estado)
{
    Servicio* nuevoServicio = malloc(sizeof(Servicio));
    serv_setDescripcion(nuevoServicio,descripcion);
    serv_setId(nuevoServicio,idServicio);
    serv_setEstado(nuevoServicio,estado);

    return nuevoServicio;
}


int serv_delete(Servicio* this)
{
    free(this);
    return 0;
}

int serv_setDescripcion(Servicio* this,char* descripcion)
{
    strcpy(this->descripcion,descripcion);
    return 0;
}


char* serv_getDescripcion(Servicio* this)
{
    return this->descripcion;
}

int serv_setId(Servicio* this,int id)
{

    this->id = id;
    return 0;
}

int serv_getId(Servicio* this)
{
    return this->id;
}

int serv_setEstado(Servicio* this,int estado)
{

    this->estado = estado;
    return 0;
}

int serv_getEstado(Servicio* this)
{
    return this->estado;
}


Servicio* serv_findById(ArrayList* pArrayServicio, int id)
{
    Servicio* retorno = NULL;
    Servicio* auxServicio;
    int i;

    if(pArrayServicio != NULL)
    {
        for(i = 0; i < pArrayServicio->len(pArrayServicio); i++)
        {
            auxServicio = pArrayServicio->get(pArrayServicio, i);
            if(serv_getId(auxServicio) == id)
            {
                retorno = auxServicio;
            }
        }

    }
    return retorno;
}



