#include "ArrayList.h"

#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#define NAME_LENGTH 51
#define LAST_NAME_LENGTH 51
#define DNI_LENGTH 51
#define DNI_LEN 10

typedef struct
{
    char nombre[NAME_LENGTH];
    char apellido[LAST_NAME_LENGTH];
    char dni[DNI_LENGTH];
    int id;
    int estado;
}Socio;
#endif // SOCIOS_H_INCLUDED

#define SOCIO_ESTADO_ACTIVO 0
#define SOCIO_ESTADO_INACTIVO 1

Socio* socio_new(void);
Socio* socio_newConst(char *nombre,char *apellido, char *dni, int id, int estado);
void socio_delete(Socio* pSocio);
int socio_setNombre(Socio* pSocio, char *nombre);
char* socio_getNombre(Socio* pSocio);
int socio_setApellido(Socio* pSocio, char *apellido);
char* socio_getApellido(Socio* pSocio);
int socio_setDNI(Socio* pSocio, char *dni);
char* socio_getDNI(Socio* pSocio);
int socio_setId(Socio* pSocio, int id);
int socio_getId(Socio* pSocio);
int socio_setEstado(Socio* pSocio, int estado);
int socio_getEstado(Socio* pSocio);
Socio* socio_findById(ArrayList* arraySocios, int id);

