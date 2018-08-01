#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Cliente.h"
#include "Alquiler.h"

static ArrayList* nominaClientes;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

static ArrayList* nominaX;
static int proximoIdX=0;
static int getNewIdX();
static int setNewIdX(int id);

void cont_init()
{
    nominaX = al_newArrayList();
    setNewIdX(dm_readAllX(nominaX) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
    setNewIdCliente(0);
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    int id = getNewIdCliente();
    Cliente* auxCliente;

    auxCliente = cliente_new(id, nombre, apellido, dni, CLIENTE_ESTADO_ACTIVO);
    al_add(nominaClientes, auxCliente);
    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente;

    auxCliente = cliente_findByIdCliente(nominaClientes, id);

    if(auxCliente != NULL)
    {
        cliente_setEstado(auxCliente, CLIENTE_ESTADO_INACTIVO);
    }
    else
    {
        vista_mostrarError("\nEl cliente no existe");
    }

    return 0;
}


int cont_modificarCliente (int id, char* a,char* b,int c)
{

    Cliente* auxCliente;

    auxCliente = cliente_findByIdCliente(nominaClientes, id);

    if(auxCliente != NULL)
    {
        cliente_setEstado(auxCliente, CLIENTE_ESTADO_INACTIVO);
    }

    return 0;
}

int cont_listarCliente ()
{
    vista_mostrarCliente(nominaClientes);
    return 0;
}

int cont_ordenarCliente ()
{

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

//****************************************************

int cont_altaX (char* a,char* b,int c)
{

    return 0;
}

int cont_bajaX (int id)
{


    return 0;
}


int cont_modificarX (int id, char* a,char* b,int c)
{

    return 0;
}

int cont_listarX ()
{
    //vista_mostrarX(nominaX);
    return 0;
}

int cont_ordenarX ()
{

    return 0;
}

static int getNewIdX()
{
    return proximoIdX++;
}

static int setNewIdX(int id)
{
    proximoIdX = id;
    return 0;
}
