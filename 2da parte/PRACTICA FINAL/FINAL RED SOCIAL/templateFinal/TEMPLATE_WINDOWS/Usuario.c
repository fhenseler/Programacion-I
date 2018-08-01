#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Usuario.h"

Usuario* usuario_new(int idUsuario,char* nick,int popularidad,int estado)
{
        Usuario* this = malloc(sizeof(Usuario));

        if(this != NULL)
        {

                usuario_setIdUsuario(this,idUsuario);
                usuario_setNick(this,nick);
                usuario_setPopularidad(this,popularidad);
                usuario_setEstado(this,estado);
        }
        return this;
}

void usuario_delete(Usuario* this)
{
        free(this);
}

int usuario_setIdUsuario(Usuario* this,int idUsuario)
{
        this->idUsuario = idUsuario;
        return 0;
}

int usuario_setNick(Usuario* this,char* nick)
{
        strcpy(this->nick,nick);
        return 0;
}

int usuario_setPopularidad(Usuario* this,int popularidad)
{
        this->popularidad = popularidad;
        return 0;
}

int usuario_setEstado(Usuario* this,int estado)
{
        this->estado = estado;
        return 0;
}

int usuario_getIdUsuario(Usuario* this)
{
        return this->idUsuario;
}

char* usuario_getNick(Usuario* this)
{
        return this->nick;
}

int usuario_getPopularidad(Usuario* this)
{
        return this->popularidad;
}

int usuario_getEstado(Usuario* this)
{
        return this->estado;
}

Usuario* usuario_findByIdUsuario(ArrayList* pArray,int idUsuario)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idUsuario == usuario_getIdUsuario(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByNick(ArrayList* pArray,char* nick)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nick,usuario_getNick(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByPopularidad(ArrayList* pArray,int popularidad)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(popularidad == usuario_getPopularidad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByEstado(ArrayList* pArray,int estado)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(estado == usuario_getEstado(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int usuario_compareByIdUsuario(void* pA ,void* pB)
{

        int retorno = 0;

        if(usuario_getIdUsuario(pA) > usuario_getIdUsuario(pB))
                retorno = 1;
        else if(usuario_getIdUsuario(pA) < usuario_getIdUsuario(pB))
                retorno = -1;

        return retorno;
}

int usuario_compareByNick(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(usuario_getNick(pA),usuario_getNick(pB));

        return retorno;
}

int usuario_compareByPopularidad(void* pA ,void* pB)
{

        int retorno = 0;

        if(usuario_getPopularidad(pA) > usuario_getPopularidad(pB))
                retorno = 1;
        else if(usuario_getPopularidad(pA) < usuario_getPopularidad(pB))
                retorno = -1;

        return retorno;
}

int usuario_compareByEstado(void* pA ,void* pB)
{

        int retorno = 0;

        if(usuario_getEstado(pA) > usuario_getEstado(pB))
                retorno = 1;
        else if(usuario_getEstado(pA) < usuario_getEstado(pB))
                retorno = -1;

        return retorno;
}

void usuario_print(void* pUsuario)
{
    printf("ID USUARIO: %d - NICK: %s\n", usuario_getIdUsuario(pUsuario), usuario_getNick(pUsuario));
}
