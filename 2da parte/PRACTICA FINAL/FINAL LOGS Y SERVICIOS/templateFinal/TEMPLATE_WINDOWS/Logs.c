#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Logs.h"
#include "DataManager.h"

ArrayList* listaG3;
ArrayList* listaG47;
ArrayList* listaGM7;

Logs* logs_new(char* fecha,char* hora,int idServicio,int gravedadError,char* mensajeError)
{
        Logs* this = malloc(sizeof(Logs));

        if(this != NULL)
        {

                logs_setFecha(this,fecha);
                logs_setHora(this,hora);
                logs_setIdServicio(this,idServicio);
                logs_setGravedadError(this,gravedadError);
                logs_setMensajeError(this,mensajeError);
        }
        return this;
}

void logs_delete(Logs* this)
{
        free(this);
}

int logs_setFecha(Logs* this,char* fecha)
{
        strcpy(this->fecha,fecha);
        return 0;
}

int logs_setHora(Logs* this,char* hora)
{
        strcpy(this->hora,hora);
        return 0;
}

int logs_setIdServicio(Logs* this,int idServicio)
{
        this->idServicio = idServicio;
        return 0;
}

int logs_setGravedadError(Logs* this,int gravedadError)
{
        this->gravedadError = gravedadError;
        return 0;
}

int logs_setMensajeError(Logs* this,char* mensajeError)
{
        strcpy(this->mensajeError,mensajeError);
        return 0;
}

char* logs_getFecha(Logs* this)
{
        return this->fecha;
}

char* logs_getHora(Logs* this)
{
        return this->hora;
}

int logs_getIdServicio(Logs* this)
{
        return this->idServicio;
}

int logs_getGravedadError(Logs* this)
{
        return this->gravedadError;
}

char* logs_getMensajeError(Logs* this)
{
        return this->mensajeError;
}

Logs* logs_findByFecha(ArrayList* pArray,char* fecha)
{

        int i;
        Logs* aux;
        Logs* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(fecha,logs_getFecha(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Logs* logs_findByHora(ArrayList* pArray,char* hora)
{

        int i;
        Logs* aux;
        Logs* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(hora,logs_getHora(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Logs* logs_findByIdServicio(ArrayList* pArray,int idServicio)
{

        int i;
        Logs* aux;
        Logs* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idServicio == logs_getIdServicio(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Logs* logs_findByGravedadError(ArrayList* pArray,int gravedadError)
{

        int i;
        Logs* aux;
        Logs* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(gravedadError == logs_getGravedadError(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Logs* logs_findByMensajeError(ArrayList* pArray,char* mensajeError)
{

        int i;
        Logs* aux;
        Logs* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(mensajeError,logs_getMensajeError(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int logs_compareByFecha(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(logs_getFecha(pA),logs_getFecha(pB));

        return retorno;
}

int logs_compareByHora(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(logs_getHora(pA),logs_getHora(pB));

        return retorno;
}

int logs_compareByIdServicio(void* pA ,void* pB)
{

        int retorno = 0;

        if(logs_getIdServicio(pA) > logs_getIdServicio(pB))
                retorno = 1;
        else if(logs_getIdServicio(pA) < logs_getIdServicio(pB))
                retorno = -1;

        return retorno;
}

int logs_compareByGravedadError(void* pA ,void* pB)
{

        int retorno = 0;

        if(logs_getGravedadError(pA) > logs_getGravedadError(pB))
                retorno = 1;
        else if(logs_getGravedadError(pA) < logs_getGravedadError(pB))
                retorno = -1;

        return retorno;
}

int logs_compareByMensajeError(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(logs_getMensajeError(pA),logs_getMensajeError(pB));

        return retorno;
}

void logs_print(void* pLog)
{
    printf("ID SERVICIO: %d\n", logs_getIdServicio(pLog));
}

int logs_filterLogs(void* item)
{
    int retorno = 0;
    Logs* auxLog = (Logs*)item;

    if(auxLog->gravedadError == 3)
    {
        retorno = 1;
    }
//    if(auxLog->gravedadError >= 4 && auxLog->gravedadError <= 7)
//    {
//        retorno = 1;
//    }
//    if(auxLog->gravedadError > 7)
//    {
//        retorno = 2;
//    }
    return retorno;
}

int logs_filterLogs2(void* item)
{
    int retorno = 0;
    Logs* auxLog = (Logs*)item;

//    if(auxLog->gravedadError == 3)
//    {
//        retorno = 0;
//    }
    if(auxLog->gravedadError >= 4 && auxLog->gravedadError <= 7)
    {
        retorno = 1;
    }
//    if(auxLog->gravedadError > 7)
//    {
//        retorno = 2;
//    }
    return retorno;
}

int logs_filterLogs3(void* item)
{
    int retorno = 0;
    Logs* auxLog = (Logs*)item;

//    if(auxLog->gravedadError == 3)
//    {
//        retorno = 0;
//    }
//    if(auxLog->gravedadError >= 4 && auxLog->gravedadError <= 7)
//    {
//        retorno = 1;
//    }
    if(auxLog->gravedadError > 7)
    {
        retorno = 1;
    }
    return retorno;
}
