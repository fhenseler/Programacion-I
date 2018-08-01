#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Tema.h"

Tema* tema_new(int id,char* nombreTema,char* artista)
{
        Tema* this = malloc(sizeof(Tema));

        if(this != NULL)
        {

                tema_setId(this,id);
                tema_setNombreTema(this,nombreTema);
                tema_setArtista(this,artista);
        }
        return this;
}

void tema_delete(Tema* this)
{
        free(this);
}

int tema_setId(Tema* this,int id)
{
        this->id = id;
        return 0;
}

int tema_setNombreTema(Tema* this,char* nombreTema)
{
        strcpy(this->nombreTema,nombreTema);
        return 0;
}

int tema_setArtista(Tema* this,char* artista)
{
        strcpy(this->artista,artista);
        return 0;
}

int tema_getId(Tema* this)
{
        return this->id;
}

char* tema_getNombreTema(Tema* this)
{
        return this->nombreTema;
}

char* tema_getArtista(Tema* this)
{
        return this->artista;
}

Tema* tema_findById(ArrayList* pArray,int id)
{

        int i;
        Tema* aux;
        Tema* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(id == tema_getId(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Tema* tema_findByNombreTema(ArrayList* pArray,char* nombreTema)
{

        int i;
        Tema* aux;
        Tema* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nombreTema,tema_getNombreTema(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Tema* tema_findByArtista(ArrayList* pArray,char* artista)
{

        int i;
        Tema* aux;
        Tema* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(artista,tema_getArtista(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int tema_compareById(void* pA ,void* pB)
{

        int retorno = 0;

        if(tema_getId(pA) > tema_getId(pB))
                retorno = 1;
        else if(tema_getId(pA) < tema_getId(pB))
                retorno = -1;

        return retorno;
}

int tema_compareByNombreTema(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(tema_getNombreTema(pA),tema_getNombreTema(pB));

        return retorno;
}

int tema_compareByArtista(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(tema_getArtista(pA),tema_getArtista(pB));

        return retorno;
}

void tema_imprimir(void* pTema)
{

    printf("ID: %d - NOMBRE: %s - ARTISTA: %s\n", tema_getId(pTema), tema_getNombreTema(pTema), tema_getArtista(pTema));
}
