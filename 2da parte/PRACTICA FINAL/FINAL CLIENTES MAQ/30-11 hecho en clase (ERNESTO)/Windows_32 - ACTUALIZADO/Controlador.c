#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicio.h"
#include "SocioServicio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaClientes;
static ArrayList* listaAlquileres;
static ArrayList* listaClienteAlquiler;

static int proximoIdCliente=0;
static int proximoIdAlquiler=0;
static int proximoIdClienteAlquiler=0;

static int getNewId();
static int setNewId(int id);
static int getNewIdAlq();
static int setNewIdAlq(int id);
static int getNewIdCliAlq();
static int setNewIdCliAlq(int id);

void cont_init()
{
    nominaClientes = al_newArrayList();
    listaAlquileres = al_newArrayList();
    listaClienteAlquiler = al_newArrayList();

    setNewId(dm_readAll(nominaClientes)+1);
    setNewIdAlq(dm_readAllAlq(listaAlquileres)+1);
    setNewIdCliAlq(dm_readAllCliAlq(listaClienteAlquiler)+1);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
//    int contAlquiler = 0;
    Cliente* auxCliente;
    auxCliente = cli_new(nombre,apellido,dni,getNewId(),CLIENTE_ESTADO_ACTIVO);
    al_add(nominaClientes,auxCliente);
    vista_printIdCliente(auxCliente);
    dm_saveAll(nominaClientes);
    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente;
    auxCliente = cli_findById(nominaClientes, id);
    if(auxCliente != NULL)
    {
        auxCliente->estado = CLIENTE_ESTADO_INACTIVO;
    }
    dm_saveAll(nominaClientes);
    return 0;
}


int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Cliente* auxCliente;
    auxCliente = cli_findById(nominaClientes, id);
    if(auxCliente != NULL)
    {
        strcpy(auxCliente->nombre, nombre);
        strcpy(auxCliente->apellido, apellido);
        strcpy(auxCliente->dni, dni);
        auxCliente->id = id;
//        auxCliente->estado = estado;
    }
    dm_saveAll(nominaClientes);
    return 0;
}

int cont_listarClientes()
{
    int retorno = -1;

    if(vista_mostrarClientes(nominaClientes)==0)
    {
        retorno = 0;
    }

    return retorno;
}


static int getNewId()
{
    return proximoIdCliente++;
}

static int setNewId(int id)
{
    proximoIdCliente = id;
    return 0;
}

int cont_checkCliente(int id)
{
    int retorno = -1;
    Cliente* auxCliente = cli_findById(nominaClientes, id);

    if(auxCliente != NULL && auxCliente->estado == CLIENTE_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
        return retorno;
}

int cont_checkClienteByDni(char* dni)
{
    int retorno = -1;
    Cliente* auxCliente = cli_findByDni(nominaClientes, dni);

    if(auxCliente != NULL && auxCliente->estado == CLIENTE_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
        return retorno;
}
//-------------------------------------------------------------------------


int cont_altaAlquiler(int id, int idCliente, int idEquipo, int idOperador, int tiempoReal, int tiempoEstimado, int estado)
{
    Alquiler* auxAlquiler;
    auxAlquiler = alq_new(getNewIdAlq(), idCliente, idEquipo, idOperador, tiempoReal, tiempoEstimado, estado);
    al_add(listaAlquileres,auxAlquiler);
    vista_printIdAlquiler(auxAlquiler);
    dm_saveAllAlq(listaAlquileres);
    return 0;
}

int cont_bajaAlquiler (int id)
{
    Alquiler* auxAlquiler;
    auxAlquiler= alq_findById(listaAlquileres, id);
    if(auxAlquiler != NULL)
    {
        auxAlquiler->estado = ALQUILER_ESTADO_INACTIVO;
    }
    dm_saveAllAlq(listaAlquileres);
    return 0;
}

int cont_checkAlquiler(int id)
{
    int retorno = -1;
    Alquiler* auxAlquiler = alq_findById(listaAlquileres, id);

    if(auxAlquiler != NULL && auxAlquiler->estado == ALQUILER_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
        return retorno;
}


int cont_modificarAlquiler (int idCliente, int idEquipo, int estado)
{
    int retorno = -1;
    Alquiler* auxAlquiler;
    auxAlquiler = alq_findById(listaAlquileres, idCliente);
    if(auxAlquiler != NULL && cont_checkAlquiler(idCliente)==0)
    {
        auxAlquiler->idCliente = idCliente;
        auxAlquiler->idEquipo = idEquipo;
//        auxAlquiler->estado = estado;
        retorno = 0;
    }
    dm_saveAllAlq(listaAlquileres);
    return retorno;
}

int cont_listarAlquileres()
{
    int retorno = -1;

    if(vista_mostrarAlquileres(listaAlquileres)==0)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdAlq()
{
    return proximoIdAlquiler++;
}

static int setNewIdAlq(int id)
{
    proximoIdAlquiler = id;
    return 0;
}

//-------------------------------------------------------------------------

int cont_altaClienteAlquiler(int idCliente, int idAlquiler)
{
    ClienteAlquiler* auxClienteAlquiler;
    Cliente* auxCliente;
    int retorno = -1;

    if(clialq_checkRelacion(listaClienteAlquiler, idCliente, idAlquiler) == -1)
    {
        if(cont_checkCliente(idCliente) == 0 && cont_checkAlquiler(idAlquiler) == 0)
        {
            auxClienteAlquiler = clialq_new(getNewIdCliAlq(), idCliente,idAlquiler,CLIENTEALQUILER_ESTADO_ACTIVO);
            auxCliente = cli_findById(nominaClientes, idCliente);
            auxCliente->contAlquileres++;
            al_add(listaClienteAlquiler,auxClienteAlquiler);
            vista_printIdClienteAlquiler(auxClienteAlquiler);
            dm_saveAllCliAlq(listaClienteAlquiler);
            dm_saveAll(nominaClientes);
            retorno = 0;
        }
        else
        {
            vista_printErrorClienteAlquiler();
        }
    }
    else
    {
        vista_printErrorClienteAlquiler2();
    }
    return retorno;
}


int cont_bajaClienteAlquiler(int id)
{
    ClienteAlquiler* auxClienteAlquiler;
    Cliente* auxCliente;
    auxCliente = cli_findById(nominaClientes, id);
    auxClienteAlquiler= clialq_findById(listaClienteAlquiler, id);

    if(auxClienteAlquiler != NULL && auxCliente != NULL)
    {
        auxClienteAlquiler->estado = CLIENTEALQUILER_ESTADO_INACTIVO;
        auxCliente->contAlquileres--;
    }
    dm_saveAllCliAlq(listaClienteAlquiler);
    return 0;
}

int cont_checkClienteAlquiler(int id)
{
    int retorno = -1;
    ClienteAlquiler* auxClienteAlquiler = clialq_findById(listaClienteAlquiler, id);

    if(auxClienteAlquiler != NULL && auxClienteAlquiler->estado == CLIENTEALQUILER_ESTADO_ACTIVO)
    {
        retorno = 0;
    }
    return retorno;
}

int cont_listarClienteAlquiler()
{
    int retorno = -1;
    if(vista_mostrarClienteAlquiler(listaClienteAlquiler, nominaClientes)==0)
    {
        retorno = 0;
    }
    return retorno;
}

int cont_listarInforme()
{
    int retorno = -1;
    if(vista_mostrarInforme(nominaClientes)==0)
    {
        retorno = 0;
    }
    return retorno;
}

static int getNewIdCliAlq()
{
    return proximoIdClienteAlquiler++;
}

static int setNewIdCliAlq(int id)
{
    proximoIdClienteAlquiler = id;
    return 0;
}
