#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Cliente.h"
#include "Alquiler.h"

static ArrayList* nominaClientes;
static ArrayList* nominaAlquileres;

static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static int proximoIdAlquiler=0;
static int getNewIdAlquiler();
static int setNewIdAlquiler(int id);

void cont_init()
{
    nominaAlquileres = al_newArrayList();
    setNewIdAlquiler(dm_readAllAlquileres(nominaAlquileres) + 1);

    nominaClientes = al_newArrayList();
    setNewIdCliente(dm_readAllClientes(nominaClientes) + 1);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaAlquiler (int idCliente,int idEquipo,int tiempoEstimado)
{
    int id = getNewIdAlquiler();
    int tiempoReal = 0;
    Alquiler *auxAlquiler;

    auxAlquiler = alquiler_new(idCliente,idEquipo,tiempoReal,tiempoEstimado, id,ALQUILER_ESTADO_ALTA);
    al_add(nominaAlquileres,auxAlquiler);
    dm_saveAllAlquileres(nominaAlquileres);
   // printf("NOMBRE_%s / QTY %d" , cliente_getApellido(auxCliente),al_len(nominaClientes));

    return 0;
}

int cont_bajaAlquiler (int id)
{
    Alquiler *auxAlquiler;
    auxAlquiler = alquiler_findByIdAlquiler(nominaAlquileres,id);
    if(auxAlquiler != NULL)
    {
        if(alquiler_getEstado(auxAlquiler)==ALQUILER_ESTADO_ALTA)
        {
           alquiler_setEstado(auxAlquiler,ALQUILER_ESTADO_BAJA);
           dm_saveAllAlquileres(nominaAlquileres);
        }

        else
            vista_mostrarError("el alquiler ya fue dado de baja!!!\n");
    }
    else
    {
        vista_mostrarError("el alquiler no existe!!!\n");

    }
    return 0;
}


int cont_modificarAlquiler (int id, char* a,char* b,int c)
{

    return 0;
}

int cont_listarAlquiler ()
{
    //vista_mostrarAlquiler(nominaAlquiler);
    return 0;
}

int cont_ordenarAlquiler ()
{

    return 0;
}

//static int getNewIdAlquiler()
//{
//    return proximoIdAlquiler++;
//}
//
//static int setNewIdAlquiler(int id)
//{
//    proximoIdAlquiler = id;
//    return 0;
//}




int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    int id = getNewIdCliente();
    Cliente *auxCliente;

    auxCliente = cliente_new(id,nombre,apellido,dni,CLIENTE_ESTADO_ALTA);
    al_add(nominaClientes,auxCliente);
    dm_saveAllClientes(nominaClientes);
   // printf("NOMBRE_%s / QTY %d" , cliente_getApellido(auxCliente),al_len(nominaClientes));

    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente *auxCliente;
    auxCliente = cliente_findByIdCliente(nominaClientes,id);
    if(auxCliente != NULL)
    {
        if(cliente_getEstado(auxCliente)==CLIENTE_ESTADO_ALTA)
        {
           cliente_setEstado(auxCliente,CLIENTE_ESTADO_BAJA);
           dm_saveAllClientes(nominaClientes);
        }

        else
            vista_mostrarError("el cliente ya fue dado de baja!!!\n");
    }
    else
    {
        vista_mostrarError("el cliente no existe!!!\n");

    }
    return 0;
}


int cont_modificarCliente (int id, char* nombre,char* apellido,char * dni)
{
    Cliente *auxCliente;
    auxCliente = cliente_findByIdCliente(nominaClientes,id);
    if(auxCliente != NULL)
    {
        if(cliente_getEstado(auxCliente)==CLIENTE_ESTADO_ALTA)
        {
            cliente_setNombre(auxCliente,nombre);
            cliente_setApellido(auxCliente,apellido);
            cliente_setDni(auxCliente,dni);
            dm_saveAllClientes(nominaClientes);
        }

    }
    return 0;
}



int cont_existeCliente (int id)
{
    Cliente *auxCliente;
    int retorno = 0;
    auxCliente = cliente_findByIdCliente(nominaClientes,id);
    if(auxCliente != NULL)
    {
        if(cliente_getEstado(auxCliente)==CLIENTE_ESTADO_ALTA)
            retorno = 1;

    }

    return retorno;
}


int cont_listarCliente()
{
    vista_mostrarCliente(nominaClientes);
    return 0;
}

int cont_ordenarCliente ()
{
    al_sort(nominaClientes,cliente_compareByNombre,0);
    return 0;
}

static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

static int getNewIdAlquiler()
{
    return proximoIdAlquiler++;
}

static int setNewIdAlquiler(int id)
{
    proximoIdAlquiler = id;
    return 0;
}
