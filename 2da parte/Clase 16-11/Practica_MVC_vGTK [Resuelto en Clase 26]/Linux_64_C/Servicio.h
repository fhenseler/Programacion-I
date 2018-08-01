#include "ArrayList.h"

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];
    int estado;
}Servicio;
#endif // SERVICIO_H_INCLUDED

#define SERVICIO_ESTADO_ACTIVO 0
#define SERVICIO_ESTADO_INACTIVO 1

Servicio* serv_new(char* descripcion, int idServicio, int estado);
int serv_delete(Servicio*);
int serv_setDescripcion(Servicio* this,char* desc);
char* serv_getDescripcion(Servicio* this);
int serv_setId(Servicio* this,int id);
int serv_getId(Servicio* this);
int serv_setEstado(Servicio* this,int estado);
int serv_getEstado(Servicio* this);

Servicio* serv_findById(ArrayList*, int);




