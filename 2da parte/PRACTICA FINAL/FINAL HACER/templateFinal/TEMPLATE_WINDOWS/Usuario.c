#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Usuario.h"

Usuario* usuario_new(int id,char* nombre,char* email,char* sexo,char* pais,char* password,char* ipAddress)
{
        Usuario* this = malloc(sizeof(Usuario));

        if(this != NULL)
        {

                usuario_setId(this,id);
                usuario_setNombre(this,nombre);
                usuario_setEmail(this,email);
                usuario_setSexo(this,sexo);
                usuario_setPais(this,pais);
                usuario_setPassword(this,password);
                usuario_setIpAddress(this,ipAddress);
        }
        return this;
}

void usuario_delete(Usuario* this)
{
        free(this);
}

int usuario_setId(Usuario* this,int id)
{
        this->id = id;
        return 0;
}

int usuario_setNombre(Usuario* this,char* nombre)
{
        strcpy(this->nombre,nombre);
        return 0;
}

int usuario_setEmail(Usuario* this,char* email)
{
        strcpy(this->email,email);
        return 0;
}

int usuario_setSexo(Usuario* this,char* sexo)
{
        strcpy(this->sexo,sexo);
        return 0;
}

int usuario_setPais(Usuario* this,char* pais)
{
        strcpy(this->pais,pais);
        return 0;
}

int usuario_setPassword(Usuario* this,char* password)
{
        strcpy(this->password,password);
        return 0;
}

int usuario_setIpAddress(Usuario* this,char* ipAddress)
{
        strcpy(this->ipAddress,ipAddress);
        return 0;
}

int usuario_getId(Usuario* this)
{
        return this->id;
}

char* usuario_getNombre(Usuario* this)
{
        return this->nombre;
}

char* usuario_getEmail(Usuario* this)
{
        return this->email;
}

char* usuario_getSexo(Usuario* this)
{
        return this->sexo;
}

char* usuario_getPais(Usuario* this)
{
        return this->pais;
}

char* usuario_getPassword(Usuario* this)
{
        return this->password;
}

char* usuario_getIpAddress(Usuario* this)
{
        return this->ipAddress;
}

Usuario* usuario_findById(ArrayList* pArray,int id)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(id == usuario_getId(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByNombre(ArrayList* pArray,char* nombre)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nombre,usuario_getNombre(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByEmail(ArrayList* pArray,char* email)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(email,usuario_getEmail(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findBySexo(ArrayList* pArray,char* sexo)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(sexo,usuario_getSexo(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByPais(ArrayList* pArray,char* pais)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(pais,usuario_getPais(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByPassword(ArrayList* pArray,char* password)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(password,usuario_getPassword(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Usuario* usuario_findByIpAddress(ArrayList* pArray,char* ipAddress)
{

        int i;
        Usuario* aux;
        Usuario* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(ipAddress,usuario_getIpAddress(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int usuario_compareById(void* pA ,void* pB)
{

        int retorno = 0;

        if(usuario_getId(pA) > usuario_getId(pB))
                retorno = 1;
        else if(usuario_getId(pA) < usuario_getId(pB))
                retorno = -1;

        return retorno;
}

int usuario_compareByNombre(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(usuario_getNombre(pA),usuario_getNombre(pB));

        return retorno;
}

int usuario_compareByEmail(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(usuario_getEmail(pA),usuario_getEmail(pB));

        return retorno;
}

int usuario_compareBySexo(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(usuario_getSexo(pA),usuario_getSexo(pB));

        return retorno;
}

int usuario_compareByPais(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(usuario_getPais(pA),usuario_getPais(pB));

        return retorno;
}

int usuario_compareByPassword(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(usuario_getPassword(pA),usuario_getPassword(pB));

        return retorno;
}

int usuario_compareByIpAddress(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(usuario_getIpAddress(pA),usuario_getIpAddress(pB));

        return retorno;
}

void usuario_imprimir(void* pUsuario)
{

    printf("ID: %d - NOMBRE: %s - PAIS: %s\n", usuario_getId(pUsuario), usuario_getNombre(pUsuario), usuario_getPais(pUsuario));

}
