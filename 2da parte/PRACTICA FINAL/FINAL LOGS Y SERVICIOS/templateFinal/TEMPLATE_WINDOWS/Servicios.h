#include "ArrayList.h"

#ifndef _SERVICIOS_H
#define _SERVICIOS_H
typedef struct
{
        int idServicio;
        char nombreServicio[35];
        char emailSoporte[65];
}Servicios;
#endif// _SERVICIOS_H

Servicios* servicios_new(int idServicio,char* nombreServicio,char* emailSoporte)
;
void servicios_delete(Servicios* this);
int servicios_setIdServicio(Servicios* this,int idServicio);
int servicios_setNombreServicio(Servicios* this,char* nombreServicio);
int servicios_setEmailSoporte(Servicios* this,char* emailSoporte);
int servicios_getIdServicio(Servicios* this);
char* servicios_getNombreServicio(Servicios* this);
char* servicios_getEmailSoporte(Servicios* this);
Servicios* servicios_findByIdServicio(ArrayList* pArray,int idServicio);
Servicios* servicios_findByNombreServicio(ArrayList* pArray,char* nombreServicio
);
Servicios* servicios_findByEmailSoporte(ArrayList* pArray,char* emailSoporte);
int servicios_compareByIdServicio(void* pA ,void* pB);
int servicios_compareByNombreServicio(void* pA ,void* pB);
int servicios_compareByEmailSoporte(void* pA ,void* pB);
