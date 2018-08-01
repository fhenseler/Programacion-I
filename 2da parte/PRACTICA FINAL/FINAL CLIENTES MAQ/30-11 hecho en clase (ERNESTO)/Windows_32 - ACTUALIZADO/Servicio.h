#include "ArrayList.h"

#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct
{
    int id;
    int idCliente;
    int idEquipo;
    int idOperador;
    int tiempoEstimado;
    int tiempoReal;
    int estado;
}Alquiler;
#endif // ALQUILER_H_INCLUDED

#define ALQUILER_ESTADO_ACTIVO 0
#define ALQUILER_ESTADO_INACTIVO 1

Alquiler* alq_new(int id, int idCliente, int idEquipo, int idOperador, int tiempoReal, int tiempoEstimado, int estado);
int alq_delete(Alquiler*);
int alq_setIdCliente(Alquiler* this,int idCliente);
int alq_setIdOperador(Alquiler* this,int idOperador);
int alq_setIdEquipo(Alquiler* this,int idEquipo);
int alq_setId(Alquiler* this,int id);
int alq_getId(Alquiler* this);
int alq_getIdCliente(Alquiler* this);
int alq_getIdEquipo(Alquiler* this);
int alq_getIdOperador(Alquiler* this);
int alq_setEstado(Alquiler* this,int estado);
int alq_getEstado(Alquiler* this);

int alq_setTiempoEstimado(Alquiler* this,int tiempoEstimado);
int alq_getTiempoEstimado(Alquiler* this);
int alq_setTiempoReal(Alquiler* this,int tiempoReal);
int alq_getTiempoReal(Alquiler* this);

Alquiler* alq_findById(ArrayList*, int);




