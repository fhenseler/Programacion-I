#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"


Cliente* cli_new(char* nombre, char* apellido, char* dni, int id, int estado)
{
    Cliente* nuevoCliente = malloc(sizeof(Cliente));
    cli_setNombre(nuevoCliente,nombre);
    cli_setApellido(nuevoCliente,apellido);
    cli_setDni(nuevoCliente, dni);
    cli_setId(nuevoCliente,id);
    cli_setEstado(nuevoCliente,estado);
//    cli_setContAlquileres(nuevoCliente, contAlquileres);

    return nuevoCliente;
}


int cli_delete(Cliente* this)
{
    free(this);
    return 0;
}


int cli_setNombre(Cliente* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 0;
}


char* cli_getNombre(Cliente* this)
{
    return this->nombre;
}


int cli_setApellido(Cliente* this,char* apellido)
{
    strcpy(this->apellido,apellido);
    return 0;
}


char* cli_getApellido(Cliente* this)
{
    return this->apellido;
}


int cli_setDni(Cliente* this,char* dni)
{
    strcpy(this->dni,dni);
    return 0;
}


char* cli_getDni(Cliente* this)
{
    return this->dni;
}


int cli_setId(Cliente* this,int id)
{

    this->id = id;
    return 0;
}

int cli_getId(Cliente* this)
{
    return this->id;
}

int cli_setEstado(Cliente* this,int estado)
{
    this->estado = estado;
    return 0;
}

int cli_getEstado(Cliente* this)
{
    return this->estado;
}


Cliente* cli_findById(ArrayList* pArrayCliente, int id)
{
    Cliente* retorno = NULL;
    Cliente* auxCliente;
    int i;

    if(pArrayCliente != NULL)
    {
        for(i = 0; i < pArrayCliente->len(pArrayCliente); i++)
        {
            auxCliente = al_get(pArrayCliente, i);
            if(cli_getId(auxCliente) == id)
            {
                retorno = auxCliente;
            }
        }
    }
    return retorno;
}

Cliente* cli_findByDni(ArrayList* pArrayCliente, char* dni)
{
    Cliente* retorno = NULL;
    Cliente* auxCliente;
    int i;

    if(pArrayCliente != NULL)
    {
        for(i = 0; i < pArrayCliente->len(pArrayCliente); i++)
        {
            auxCliente = al_get(pArrayCliente, i);
            if(strcmp(cli_getDni(auxCliente), dni)==0)
            {
                retorno = auxCliente;
            }
        }
    }
    return retorno;
}

int cli_setContAlquileres(Cliente* this,int cont)
{
    this->contAlquileres = cont;
    return 0;
}

int cli_getContAlquileres(Cliente* this)
{
    return this->contAlquileres;
}




