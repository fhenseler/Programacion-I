#include "ArrayList.h"

#ifndef _LOGS_H
#define _LOGS_H
typedef struct
{
        char fecha[50];
        char hora[50];
        int idServicio;
        int gravedadError;
        char mensajeError[65];
}Logs;
#endif// _LOGS_H

Logs* logs_new(char* fecha,char* hora,int idServicio,int gravedadError,char* mensajeError);
void logs_delete(Logs* this);
int logs_setFecha(Logs* this,char* fecha);
int logs_setHora(Logs* this,char* hora);
int logs_setIdServicio(Logs* this,int idServicio);
int logs_setGravedadError(Logs* this,int gravedadError);
int logs_setMensajeError(Logs* this,char* mensajeError);
char* logs_getFecha(Logs* this);
char* logs_getHora(Logs* this);
int logs_getIdServicio(Logs* this);
int logs_getGravedadError(Logs* this);
char* logs_getMensajeError(Logs* this);
Logs* logs_findByFecha(ArrayList* pArray,char* fecha);
Logs* logs_findByHora(ArrayList* pArray,char* hora);
Logs* logs_findByIdServicio(ArrayList* pArray,int idServicio);
Logs* logs_findByGravedadError(ArrayList* pArray,int gravedadError);
Logs* logs_findByMensajeError(ArrayList* pArray,char* mensajeError);
int logs_compareByFecha(void* pA ,void* pB);
int logs_compareByHora(void* pA ,void* pB);
int logs_compareByIdServicio(void* pA ,void* pB);
int logs_compareByGravedadError(void* pA ,void* pB);
int logs_compareByMensajeError(void* pA ,void* pB);

void logs_print(void* pLog);
int logs_filterLogs(void* item);
int logs_filterLogs2(void* item);
int logs_filterLogs3(void* item);
