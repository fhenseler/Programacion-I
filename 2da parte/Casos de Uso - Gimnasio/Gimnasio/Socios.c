#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Socios.h"

Socio* socio_new(void)
{
    return malloc(sizeof(Socio));
}

Socio* socio_newConst(char *nombre,char *apellido, char *dni, int id, int estado)
{
    Socio* pSocio = malloc(sizeof(Socio));
    if(pSocio != NULL)
    {
        socio_setNombre(pSocio,nombre);
        socio_setApellido(pSocio,apellido);
        socio_setDNI(pSocio,dni);
        socio_setId(pSocio,id);
        socio_setEstado(pSocio,estado);
    }
        return pSocio;
}

void socio_delete(Socio* pSocio)
{
    if(pSocio != NULL)
        free(pSocio);
}

int socio_setNombre(Socio* pSocio, char *nombre)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        strncpy(pSocio->nombre,nombre,NAME_LENGTH);
    }
    return retorno;

}

char* socio_getNombre(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->nombre;
    }
    return retorno;
}

int socio_setApellido(Socio* pSocio, char *apellido)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        strncpy(pSocio->apellido,apellido,LAST_NAME_LENGTH);
    }
    return retorno;
}


char* socio_getApellido(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->apellido;
    }
    return retorno;
}

int socio_setDNI(Socio* pSocio, char *dni)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        strncpy(pSocio->dni,dni,DNI_LENGTH);
    }
    return retorno;
}


char* socio_getDNI(Socio* pSocio)
{
    char* retorno = NULL;
    if(pSocio != NULL)
    {
        retorno = pSocio->dni;
    }
    return retorno;
}


int socio_setId(Socio* pSocio, int id)
{

    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        pSocio->id = id;
    }
    return retorno;
}

int socio_getId(Socio* pSocio)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = pSocio->id;
    }
    return retorno;
}

int socio_setEstado(Socio* pSocio, int estado)
{

    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = 0;
        pSocio->estado = estado;
    }
    return retorno;
}

int socio_getEstado(Socio* pSocio)
{
    int retorno = -1;
    if(pSocio != NULL)
    {
        retorno = pSocio->estado;
    }
    return retorno;
}

//Socio* socio_findById(ArrayList* arraySocios, int id)
//{
//    void* returnAux = NULL;
//    Socio* pSocio;
//
//    if(arraySocios != NULL && id > 0)
//    {
//        if(pSocio->estado == SOCIO_OCUPADO)
//        {
//            if(pSocio->id == id)
//            {
//                returnAux = pSocio;
//            }
//        }
//    }
//                return returnAux;
//}
