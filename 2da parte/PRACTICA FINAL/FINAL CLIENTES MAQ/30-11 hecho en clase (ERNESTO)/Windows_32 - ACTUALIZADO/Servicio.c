#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicio.h"

Alquiler* alq_new(int id, int idCliente, int idEquipo, int idOperador, int tiempoReal, int tiempoEstimado, int estado)
{
    Alquiler* nuevoAlquiler = malloc(sizeof(Alquiler));

    if(nuevoAlquiler != NULL)
    {
        alq_setId(nuevoAlquiler,id);
        alq_setIdCliente(nuevoAlquiler,idCliente);
        alq_setIdEquipo(nuevoAlquiler,idEquipo);
        alq_setIdOperador(nuevoAlquiler,idOperador);
        alq_setTiempoReal(nuevoAlquiler,tiempoReal);
        alq_setTiempoEstimado(nuevoAlquiler,tiempoEstimado);
        alq_setEstado(nuevoAlquiler,estado);
    }

    return nuevoAlquiler;
}


int alq_delete(Alquiler* this)
{
    free(this);
    return 0;
}

int alq_setId(Alquiler* this,int id)
{

    this->id = id;
    return 0;
}


int alq_setIdCliente(Alquiler* this,int idCliente)
{

    this->idCliente = idCliente;
    return 0;
}

int alq_setIdEquipo(Alquiler* this,int idEquipo)
{

    this->idEquipo = idEquipo;
    return 0;
}

int alq_setIdOperador(Alquiler* this,int idOperador)
{

    this->idOperador = idOperador;
    return 0;
}

int alq_getId(Alquiler* this)
{
    return this->id;
}

int alq_getIdCliente(Alquiler* this)
{
    return this->idCliente;
}
int alq_getIdOperador(Alquiler* this)
{
    return this->idOperador;
}
int alq_getIdEquipo(Alquiler* this)
{
    return this->idEquipo;
}


int alq_setEstado(Alquiler* this,int estado)
{

    this->estado = estado;
    return 0;
}

int alq_setTiempoReal(Alquiler* this,int tiempoReal)
{

    this->tiempoReal = tiempoReal;
    return 0;
}
int alq_setTiempoEstimado(Alquiler* this,int tiempoEstimado)
{

    this->tiempoEstimado = tiempoEstimado;
    return 0;
}
int alq_getEstado(Alquiler* this)
{
    return this->estado;
}


Alquiler* alq_findById(ArrayList* pArrayAlquiler, int id)
{
    Alquiler* retorno = NULL;
    Alquiler* auxAlquiler;
    int i;

    if(pArrayAlquiler != NULL)
    {
        for(i = 0; i < pArrayAlquiler->len(pArrayAlquiler); i++)
        {
            auxAlquiler = al_get(pArrayAlquiler, i);
            if(alq_getId(auxAlquiler) == id)
            {
                retorno = auxAlquiler;
            }
        }

    }
    return retorno;
}



