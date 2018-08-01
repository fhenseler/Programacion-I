#include "ArrayList.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    int estado;
    int contAlquileres;
}Cliente;
#endif // CLIENTE_H_INCLUDED

#define CLIENTE_ESTADO_ACTIVO 0
#define CLIENTE_ESTADO_INACTIVO 1

Cliente* cli_new(char* nombre, char* apellido, char* dni, int id, int estado);
int cli_delete(Cliente*);
int cli_setNombre(Cliente*,char* nombre);
char* cli_getNombre(Cliente*);
int cli_setApellido(Cliente* this,char* apellido);
char* cli_getApellido(Cliente* this);
int cli_setDni(Cliente* this,char* dni);
char* cli_getDni(Cliente* this);
int cli_setId(Cliente* this,int id);
int cli_getId(Cliente* this);
int cli_setEstado(Cliente* this,int estado);
int cli_getEstado(Cliente* this);

int cli_setContAlquileres(Cliente* this,int contAlquileres);
int cli_getContAlquileres(Cliente* this);

Cliente* cli_findById(ArrayList*, int id);
Cliente* cli_findByDni(ArrayList* pArray, char* dni);

int cli_setContServicios(Cliente* this,int estado);
int cli_getContServicios(Cliente* this);





