#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Post.h"

Post* post_new(int idMensaje,int idUsuario,int popularidad,char* mensaje)
{
        Post* this = malloc(sizeof(Post));

        if(this != NULL)
        {

                post_setIdMensaje(this,idMensaje);
                post_setMensaje(this,mensaje);
                post_setPopularidad(this,popularidad);
                post_setIdUsuario(this,idUsuario);
        }
        return this;
}

void post_delete(Post* this)
{
        free(this);
}

int post_setIdMensaje(Post* this,int idMensaje)
{
        this->idMensaje = idMensaje;
        return 0;
}

int post_setMensaje(Post* this,char* mensaje)
{
        strcpy(this->mensaje,mensaje);
        return 0;
}

int post_setPopularidad(Post* this,int popularidad)
{
        this->popularidad = popularidad;
        return 0;
}

int post_setIdUsuario(Post* this,int idUsuario)
{
        this->idUsuario = idUsuario;
        return 0;
}

int post_getIdMensaje(Post* this)
{
        return this->idMensaje;
}

char* post_getMensaje(Post* this)
{
        return this->mensaje;
}

int post_getPopularidad(Post* this)
{
        return this->popularidad;
}

int post_getIdUsuario(Post* this)
{
        return this->idUsuario;
}

Post* post_findByIdMensaje(ArrayList* pArray,int idMensaje)
{

        int i;
        Post* aux;
        Post* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idMensaje == post_getIdMensaje(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Post* post_findByMensaje(ArrayList* pArray,char* mensaje)
{

        int i;
        Post* aux;
        Post* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(mensaje,post_getMensaje(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Post* post_findByPopularidad(ArrayList* pArray,int popularidad)
{

        int i;
        Post* aux;
        Post* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(popularidad == post_getPopularidad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Post* post_findByIdUsuario(ArrayList* pArray,int idUsuario)
{

        int i;
        Post* aux;
        Post* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idUsuario == post_getIdUsuario(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int post_compareByIdMensaje(void* pA ,void* pB)
{

        int retorno = 0;

        if(post_getIdMensaje(pA) > post_getIdMensaje(pB))
                retorno = 1;
        else if(post_getIdMensaje(pA) < post_getIdMensaje(pB))
                retorno = -1;

        return retorno;
}

int post_compareByMensaje(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(post_getMensaje(pA),post_getMensaje(pB));

        return retorno;
}

int post_compareByPopularidad(void* pA ,void* pB)
{

        int retorno = 0;

        if(post_getPopularidad(pA) > post_getPopularidad(pB))
                retorno = 1;
        else if(post_getPopularidad(pA) < post_getPopularidad(pB))
                retorno = -1;

        return retorno;
}

int post_compareByIdUsuario(void* pA ,void* pB)
{

        int retorno = 0;

        if(post_getIdUsuario(pA) > post_getIdUsuario(pB))
                retorno = 1;
        else if(post_getIdUsuario(pA) < post_getIdUsuario(pB))
                retorno = -1;

        return retorno;
}


void post_print(void* pPost)
{
    printf("ID MENSAJE: %d - ID USUARIO: %d\n", post_getIdMensaje(pPost), post_getIdUsuario(pPost));
}
