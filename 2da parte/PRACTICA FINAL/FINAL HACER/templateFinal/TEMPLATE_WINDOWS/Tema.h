#include "ArrayList.h"

#ifndef _TEMA_H
#define _TEMA_H
typedef struct
{
        int id;
        char nombreTema[50];
        char artista[50];
        int estado;
}Tema;
#endif// _TEMA_H

#define TEMA_ESTADO_DISPONIBLE 0
#define TEMA_ESTADO_OCUPADO 1

Tema* tema_new(int id,char* nombreTema,char* artista);
void tema_delete(Tema* this);
int tema_setId(Tema* this,int id);
int tema_setNombreTema(Tema* this,char* nombreTema);
int tema_setArtista(Tema* this,char* artista);
int tema_getId(Tema* this);
char* tema_getNombreTema(Tema* this);
char* tema_getArtista(Tema* this);
Tema* tema_findById(ArrayList* pArray,int id);
Tema* tema_findByNombreTema(ArrayList* pArray,char* nombreTema);
Tema* tema_findByArtista(ArrayList* pArray,char* artista);
int tema_compareById(void* pA ,void* pB);
int tema_compareByNombreTema(void* pA ,void* pB);
int tema_compareByArtista(void* pA ,void* pB);

void tema_imprimir(void* pTema);

