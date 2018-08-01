#include "ArrayList.h"

#ifndef _USUARIO_H
#define _USUARIO_H
typedef struct
{
        int id;
        char nombre[50];
        char email[50];
        char sexo[5];
        char pais[50];
        char password[50];
        char ipAddress[50];
}Usuario;
#endif// _USUARIO_H

Usuario* usuario_new(int id,char* nombre,char* email,char* sexo,char* pais,char* password,char* ipAddress);
void usuario_delete(Usuario* this);
int usuario_setId(Usuario* this,int id);
int usuario_setNombre(Usuario* this,char* nombre);
int usuario_setEmail(Usuario* this,char* email);
int usuario_setSexo(Usuario* this,char* sexo);
int usuario_setPais(Usuario* this,char* pais);
int usuario_setPassword(Usuario* this,char* password);
int usuario_setIpAddress(Usuario* this,char* ipAddress);
int usuario_getId(Usuario* this);
char* usuario_getNombre(Usuario* this);
char* usuario_getEmail(Usuario* this);
char* usuario_getSexo(Usuario* this);
char* usuario_getPais(Usuario* this);
char* usuario_getPassword(Usuario* this);
char* usuario_getIpAddress(Usuario* this);
Usuario* usuario_findById(ArrayList* pArray,int id);
Usuario* usuario_findByNombre(ArrayList* pArray,char* nombre);
Usuario* usuario_findByEmail(ArrayList* pArray,char* email);
Usuario* usuario_findBySexo(ArrayList* pArray,char* sexo);
Usuario* usuario_findByPais(ArrayList* pArray,char* pais);
Usuario* usuario_findByPassword(ArrayList* pArray,char* password);
Usuario* usuario_findByIpAddress(ArrayList* pArray,char* ipAddress);
int usuario_compareById(void* pA ,void* pB);
int usuario_compareByNombre(void* pA ,void* pB);
int usuario_compareByEmail(void* pA ,void* pB);
int usuario_compareBySexo(void* pA ,void* pB);
int usuario_compareByPais(void* pA ,void* pB);
int usuario_compareByPassword(void* pA ,void* pB);
int usuario_compareByIpAddress(void* pA ,void* pB);

void usuario_imprimir(void* pUsuario);
