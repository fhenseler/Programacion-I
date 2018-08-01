#include "ArrayList.h"

#ifndef _POST_H
#define _POST_H
typedef struct
{
        int idMensaje;
        int idUsuario;
        int popularidad;
        char mensaje[2000];
}Post;
#endif// _POST_H

Post* post_new(int idMensaje,int idUsuario,int popularidad,char* mensaje);
void post_delete(Post* this);
int post_setIdMensaje(Post* this,int idMensaje);
int post_setMensaje(Post* this,char* mensaje);
int post_setPopularidad(Post* this,int popularidad);
int post_setIdUsuario(Post* this,int idUsuario);
int post_getIdMensaje(Post* this);
char* post_getMensaje(Post* this);
int post_getPopularidad(Post* this);
int post_getIdUsuario(Post* this);
Post* post_findByIdMensaje(ArrayList* pArray,int idMensaje);
Post* post_findByMensaje(ArrayList* pArray,char* mensaje);
Post* post_findByPopularidad(ArrayList* pArray,int popularidad);
Post* post_findByIdUsuario(ArrayList* pArray,int idUsuario);
int post_compareByIdMensaje(void* pA ,void* pB);
int post_compareByMensaje(void* pA ,void* pB);
int post_compareByPopularidad(void* pA ,void* pB);
int post_compareByIdUsuario(void* pA ,void* pB);

void post_print(void* pPost);
