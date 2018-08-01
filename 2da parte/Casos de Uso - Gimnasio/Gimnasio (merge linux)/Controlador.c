#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaSocios;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);


void cont_init()
{
    nominaSocios = al_newArrayList();
    setNewId(dm_readAll(nominaSocios));//if dm_readall == -1 -> setId(0)
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_bajaSocio (int id)
{
    Socio* auxSocio;
    auxSocio = soc_findById(nominaSocios, id);
    if(auxSocio != NULL)
    {
        auxSocio->estado = SOCIO_ESTADO_INACTIVO;
    }
    dm_saveAll(nominaSocios);
    return 0;
}


int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Socio* auxSocio;
    auxSocio = soc_findById(nominaSocios, id);
    if(auxSocio != NULL)
    {
        strcpy(auxSocio->nombre, nombre);
        strcpy(auxSocio->apellido, apellido);
        strcpy(auxSocio->dni, dni);
        auxSocio->id = id;
//        auxSocio->estado = estado;
    }
    else
    {
        printf("\nError ");
    }
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}


static int getNewId()
{
    return proximoIdSocio++;
}

static int setNewId(int id)
{
    proximoIdSocio = id;
    return 0;
}

int cont_checkSocio(int id)
{
    int retorno = -1;
    Socio* auxSocio = soc_findById(nominaSocios, id);

    if(auxSocio != NULL)
    {
        retorno = 0;
    }
        return retorno;
}
