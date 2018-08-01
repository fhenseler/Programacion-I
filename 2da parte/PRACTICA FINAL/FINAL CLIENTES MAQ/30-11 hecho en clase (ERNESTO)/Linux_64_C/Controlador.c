#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicio.h"
#include "SocioServicio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaSocios;
static ArrayList* listaServicios;
static ArrayList* listaSocioServicio;

static int proximoIdSocio=0;
static int proximoIdServicio=0;
static int proximoIdSocioServicio=0;

static int getNewId();
static int setNewId(int id);
static int getNewIdServ();
static int setNewIdServ(int id);
static int getNewIdSocServ();
static int setNewIdSocServ(int id);

void cont_init()
{
    nominaSocios = al_newArrayList();
    listaServicios = al_newArrayList();
    listaSocioServicio = al_newArrayList();

    setNewId(dm_readAll(nominaSocios)+1);
    setNewIdServ(dm_readAllServ(listaServicios)+1);
    setNewIdSocServ(dm_readAllSocServ(listaSocioServicio)+1);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    int contServicio = 0;
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO, contServicio);
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

int cont_listarSocios()
{
    int retorno = -1;

    if(vista_mostrarSocios(nominaSocios)==0)
    {
        retorno = 0;
    }

    return retorno;
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
    vista_printIdServicio(auxServicio);
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

    if(auxServicio != NULL && auxServicio->estado == SERVICIO_ESTADO_ACTIVO)
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
    int retorno = -1;

    if(vista_mostrarServicios(listaServicios)==0)
    {
        retorno = 0;
    }
    return retorno;
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

//-------------------------------------------------------------------------

int cont_altaSocioServicio(int idSocio, int idServicio)
{
    SocioServicio* auxSocioServicio;
    Socio* auxSocio;
    int retorno = -1;

    if(socserv_checkRelacion(listaSocioServicio, idSocio, idServicio) == -1)
    {
        if(cont_checkSocio(idSocio) == 0 && cont_checkServicio(idServicio) == 0)
        {
            auxSocioServicio = socserv_new(getNewIdSocServ(), idSocio,idServicio,SOCIOSERVICIO_ESTADO_ACTIVO);
            auxSocio = soc_findById(nominaSocios, idSocio);
            auxSocio->contServicios++;
            al_add(listaSocioServicio,auxSocioServicio);
            vista_printIdSocioServicio(auxSocioServicio);
            dm_saveAllSocServ(listaSocioServicio);
            dm_saveAll(nominaSocios);
            retorno = 0;
        }
        else
        {
            vista_printErrorSocioServicio();
        }
    }
    else
    {
        vista_printErrorSocioServicio2();
    }
    return retorno;
}


int cont_bajaSocioServicio(int id)
{
    SocioServicio* auxSocioServicio;
    Socio* auxSocio;
    auxSocio = soc_findById(nominaSocios, id);
    auxSocioServicio= socserv_findById(listaSocioServicio, id);

    if(auxSocioServicio != NULL && auxSocio != NULL)
    {
        auxSocioServicio->estado = SOCIOSERVICIO_ESTADO_INACTIVO;
        auxSocio->contServicios--;
    }
    dm_saveAllSocServ(listaSocioServicio);
    return 0;
}

int cont_checkSocioServicio(int id)
{
    int retorno = -1;
    SocioServicio* auxSocioServicio = socserv_findById(listaSocioServicio, id);

    if(auxSocioServicio != NULL && auxSocioServicio->estado == SOCIOSERVICIO_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}

int cont_listarSocioServicio()
{
    int retorno = -1;
    if(vista_mostrarSocioServicio(listaSocioServicio, nominaSocios)==0)
    {
        retorno = 0;
    }
    return retorno;
}

int cont_listarInforme()
{
    int retorno = -1;
    if(vista_mostrarInforme(nominaSocios)==0)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdSocServ()
{
    return proximoIdSocioServicio++;
}

static int setNewIdSocServ(int id)
{
    proximoIdSocioServicio = id;
    return 0;
}
