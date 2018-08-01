#include "ArrayList.h"

#ifndef _USUARIO_H
#define _USUARIO_H
typedef struct
{
        int idUsuario;
        char nick[100];
        int popularidad;
        int estado;
}Usuario;
#endif// _USUARIO_H

#define USUARIO_ESTADO_ACTIVO 0
#define USUARIO_ESTADO_INACTIVO 1

Usuario* usuario_new(int idUsuario,char* nick,int popularidad,int estado);
void usuario_delete(Usuario* this);
int usuario_setIdUsuario(Usuario* this,int idUsuario);
int usuario_setNick(Usuario* this,char* nick);
int usuario_setPopularidad(Usuario* this,int popularidad);
int usuario_setEstado(Usuario* this,int estado);
int usuario_getIdUsuario(Usuario* this);
char* usuario_getNick(Usuario* this);
int usuario_getPopularidad(Usuario* this);
int usuario_getEstado(Usuario* this);
Usuario* usuario_findByIdUsuario(ArrayList* pArray,int idUsuario);
Usuario* usuario_findByNick(ArrayList* pArray,char* nick);
Usuario* usuario_findByPopularidad(ArrayList* pArray,int popularidad);
Usuario* usuario_findByEstado(ArrayList* pArray,int estado);
int usuario_compareByIdUsuario(void* pA ,void* pB);
int usuario_compareByNick(void* pA ,void* pB);
int usuario_compareByPopularidad(void* pA ,void* pB);
int usuario_compareByEstado(void* pA ,void* pB);

void usuario_print(void* pUsuario);
