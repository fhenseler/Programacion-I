#include "ArrayList.h"

#ifndef CLIENTEALQUILER_H_INCLUDED
#define CLIENTEALQUILER_H_INCLUDED
typedef struct
{
    int id;
    int estado;
    int idCliente;
    int idAlquiler;
}ClienteAlquiler;
#endif // CLIENTE_H_INCLUDED

#define CLIENTEALQUILER_ESTADO_ACTIVO 0
#define CLIENTEALQUILER_ESTADO_INACTIVO 1

ClienteAlquiler* clialq_new(int idclialq, int idCli, int idAlq, int estado);
int clialq_delete(ClienteAlquiler*);

int clialq_setId(ClienteAlquiler* this,int id);
int clialq_getId(ClienteAlquiler* this);

int clialq_setIdCliAlq(ClienteAlquiler* this,int id);
int clialq_getIdCliAlq(ClienteAlquiler* this);

int clialq_setIdCliente(ClienteAlquiler* this,int idCliente);
int clialq_getIdCliente(ClienteAlquiler* this);

int clialq_setIdAlquiler(ClienteAlquiler* this,int idAlquiler);
int clialq_getIdAlquiler(ClienteAlquiler* this);

int clialq_setEstado(ClienteAlquiler* this,int estado);
int clialq_getEstado(ClienteAlquiler* this);

ClienteAlquiler* clialq_findById(ArrayList*, int id);
int clialq_checkRelacion(ArrayList* pArrayClienteAlquiler, int idCli, int idAlq);
int clialq_checkIdCliente(ArrayList* pArrayClienteAlquiler, int idCli);





