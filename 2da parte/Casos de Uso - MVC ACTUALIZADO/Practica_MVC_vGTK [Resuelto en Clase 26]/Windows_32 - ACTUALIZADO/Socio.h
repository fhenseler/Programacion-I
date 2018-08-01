#include "ArrayList.h"

#ifndef Socio_H_INCLUDED
#define Socio_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    int estado;
    int contServicios;
}Socio;
#endif // Socio_H_INCLUDED

#define Socio_ESTADO_ACTIVO 0
#define Socio_ESTADO_INACTIVO 1

Socio* soc_new(char* nombre, char* apellido, char* dni, int id, int estado, int contServicios);
int soc_delete(Socio*);
int soc_setNombre(Socio*,char* nombre);
char* soc_getNombre(Socio*);
int soc_setApellido(Socio* this,char* apellido);
char* soc_getApellido(Socio* this);
int soc_setDni(Socio* this,char* dni);
char* soc_getDni(Socio* this);
int soc_setId(Socio* this,int id);
int soc_getId(Socio* this);
int soc_setEstado(Socio* this,int estado);
int soc_getEstado(Socio* this);

Socio* soc_findById(ArrayList*, int id);
Socio* soc_findByDni(ArrayList* pArraySocio, char* dni);

int soc_setContServicios(Socio* this,int estado);
int soc_getContServicios(Socio* this);

int soc_filterSocio(void* item);




