#include "ArrayList.h"

#ifndef SocioSERVICIO_H_INCLUDED
#define SocioSERVICIO_H_INCLUDED
typedef struct
{
    int id;
    int estado;
    int idSocio;
    int idServicio;
}SocioServicio;
#endif // Socio_H_INCLUDED

#define SocioSERVICIO_ESTADO_ACTIVO 0
#define SocioSERVICIO_ESTADO_INACTIVO 1

SocioServicio* socserv_new(int idSocServ, int idSoc, int idServ, int estado);
int socserv_delete(SocioServicio*);
int socserv_setId(SocioServicio* this,int id);
int socserv_getId(SocioServicio* this);
int socserv_setIdSocio(SocioServicio* this,int id);
int socserv_getIdSocio(SocioServicio* this);
int socserv_setIdServicio(SocioServicio* this,int id);
int socserv_getIdServicio(SocioServicio* this);
int socserv_setEstado(SocioServicio* this,int estado);
int socserv_getEstado(SocioServicio* this);

SocioServicio* socserv_findById(ArrayList*, int id);
int socserv_checkRelacion(ArrayList* pArraySocioServicio, int idSoc, int idServ);
int socserv_checkIdSocio(ArrayList* pArraySocioServicio, int idSoc);





