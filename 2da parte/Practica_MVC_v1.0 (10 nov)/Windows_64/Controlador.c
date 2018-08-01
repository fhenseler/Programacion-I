#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaSocios;
static ArrayList* listaServicios;
static int proximoIdSocio=0;
static int proximoIdServicio=0;
static int getNewId();
static int setNewId(int id);
static int getNewIdServ();
static int setNewIdServ(int id);


void cont_init()
{
    nominaSocios = al_newArrayList();
    listaServicios = al_newArrayList();

    setNewId(dm_readAll(nominaSocios)+1);
    setNewIdServ(dm_readAllServ(listaServicios)+1);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    vista_printIdSocio(auxSocio);
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

    if(auxSocio != NULL && auxSocio->estado == SOCIO_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
        return retorno;
}

int cont_checkSocioByDni(char* dni)
{
    int retorno = -1;
    Socio* auxSocio = soc_findByDni(nominaSocios, dni);

    if(auxSocio != NULL && auxSocio->estado == SOCIO_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
        return retorno;
}
//-------------------------------------------------------------------------


int cont_altaServicio(char* descripcion)
{
    Servicio* auxServicio;
    auxServicio = serv_new(descripcion,getNewIdServ(),SERVICIO_ESTADO_ACTIVO);
    al_add(listaServicios,auxServicio);
    dm_saveAllServ(listaServicios);
    return 0;
}

int cont_bajaServicio (int id)
{
    Servicio* auxServicio;
    auxServicio= serv_findById(listaServicios, id);
    if(auxServicio != NULL)
    {
        auxServicio->estado = SERVICIO_ESTADO_INACTIVO;
    }
    dm_saveAllServ(listaServicios);
    return 0;
}

int cont_checkServicio(int id)
{
    int retorno = -1;
    Servicio* auxServicio = serv_findById(listaServicios, id);

    if(auxServicio != NULL)
    {
        retorno = 0;
    }
        return retorno;
}


int cont_modificarServicio (char* descripcion, int id, int estado)
{
    int retorno = -1;
    Servicio* auxServicio;
    auxServicio = serv_findById(listaServicios, id);
    if(auxServicio != NULL && cont_checkServicio(id)==0)
    {
        strcpy(auxServicio->descripcion, descripcion);
        auxServicio->id = id;
//        auxServicio->estado = estado;
        retorno = 0;
    }
    dm_saveAllServ(listaServicios);
    return retorno;
}

int cont_listarServicios()
{
    vista_mostrarServicios(listaServicios);
    return 0;
}

static int getNewIdServ()
{
    return proximoIdServicio++;
}

static int setNewIdServ(int id)
{
    proximoIdServicio = id;
    return 0;
}


