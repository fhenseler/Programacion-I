#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

Empleado* empleado_new()
{
    return malloc(sizeof(Empleado));
}

Empleado* empleado_newConstructor(char *nombre, char *apellido, int idSector)
{
    Empleado* pEmpleado = malloc(sizeof(Empleado));

    if(pEmpleado != NULL)
    {
       empleado_setNombre(pEmpleado, nombre);
       empleado_setApellido(pEmpleado, apellido);
       empleado_setIdSector(pEmpleado, idSector);
    }
       return pEmpleado;
}

void empleado_delete(Empleado* pEmpleado)
{
    if(pEmpleado != NULL)
    {
       free(pEmpleado);
    }
}

int empleado_setNombre(Empleado* pEmpleado, char *nombre)
{
    int retorno = -1;

    if(pEmpleado != NULL)
    {
        retorno = 0;
        strncpy(pEmpleado->nombre, nombre, NAME_LENGTH);
    }
        return retorno;
}


char* empleado_getNombre(Empleado* pEmpleado)
{
    char* retorno = NULL;

    if(pEmpleado != NULL)
    {
        retorno = pEmpleado->nombre;
    }
        return retorno;
}

int empleado_setApellido(Empleado* pEmpleado, char *apellido)
{
    int retorno = -1;

    if(pEmpleado != NULL)
    {
        retorno = 0;
        strncpy(pEmpleado->apellido, apellido, LASTNAME_LENGTH);
    }
        return retorno;
}


char* empleado_getApellido(Empleado* pEmpleado)
{
    char* retorno = NULL;

    if(pEmpleado != NULL)
    {
        retorno = pEmpleado->apellido;
    }
        return retorno;
}

int empleado_setIdSector(Empleado* pEmpleado, int idSector)
{
    int retorno = -1;

    if(pEmpleado != NULL)
    {
        retorno = 0;
        pEmpleado->idSector = idSector;
    }
        return retorno;
}


int empleado_getIdSector(Empleado* pEmpleado)
{
    int retorno = -1;

    if(pEmpleado != NULL)
    {
        retorno = pEmpleado->idSector;
    }
        return retorno;
}

void empleado_debugPrint(Empleado* pEmpleado)
{
    if(pEmpleado != NULL && (DEBUG_MODE == 1))
    {
        printf("\n[DEBUG]%-5s  %-5s  %-5d", pEmpleado->nombre, pEmpleado->apellido, pEmpleado->idSector);
    }
}
