#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicios.h"

Servicios* servicios_new(int idServicio,char* nombreServicio,char* emailSoporte)

{
        Servicios* this = malloc(sizeof(Servicios));

        if(this != NULL)
        {

                servicios_setIdServicio(this,idServicio);
                servicios_setNombreServicio(this,nombreServicio);
                servicios_setEmailSoporte(this,emailSoporte);
        }
        return this;
}

void servicios_delete(Servicios* this)
{
        free(this);
}

int servicios_setIdServicio(Servicios* this,int idServicio)
{
        this->idServicio = idServicio;
        return 0;
}

int servicios_setNombreServicio(Servicios* this,char* nombreServicio)
{
        strcpy(this->nombreServicio,nombreServicio);
        return 0;
}

int servicios_setEmailSoporte(Servicios* this,char* emailSoporte)
{
        strcpy(this->emailSoporte,emailSoporte);
        return 0;
}

int servicios_getIdServicio(Servicios* this)
{
        return this->idServicio;
}

char* servicios_getNombreServicio(Servicios* this)
{
        return this->nombreServicio;
}

char* servicios_getEmailSoporte(Servicios* this)
{
        return this->emailSoporte;
}

Servicios* servicios_findByIdServicio(ArrayList* pArray,int idServicio)
{

        int i;
        Servicios* aux;
        Servicios* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idServicio == servicios_getIdServicio(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Servicios* servicios_findByNombreServicio(ArrayList* pArray,char* nombreServicio
)
{

        int i;
        Servicios* aux;
        Servicios* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nombreServicio,servicios_getNombreServicio(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Servicios* servicios_findByEmailSoporte(ArrayList* pArray,char* emailSoporte)
{

        int i;
        Servicios* aux;
        Servicios* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(emailSoporte,servicios_getEmailSoporte(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int servicios_compareByIdServicio(void* pA ,void* pB)
{

        int retorno = 0;

        if(servicios_getIdServicio(pA) > servicios_getIdServicio(pB))
                retorno = 1;
        else if(servicios_getIdServicio(pA) < servicios_getIdServicio(pB))
                retorno = -1;

        return retorno;
}

int servicios_compareByNombreServicio(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(servicios_getNombreServicio(pA),servicios_getNombreServicio(pB));

        return retorno;
}

int servicios_compareByEmailSoporte(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(servicios_getEmailSoporte(pA),servicios_getEmailSoporte(pB));

        return retorno;
}

