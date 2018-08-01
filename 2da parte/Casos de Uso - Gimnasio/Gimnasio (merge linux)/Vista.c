#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 5)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListado();
                break;
            case 2:
                opcionAlta();
                break;
            case 3:
                opcionBaja();
                break;
            case 4:
                opcionModificacion();
                break;
        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
    {
        auxSocio = al_get(pListaSocios,i);
        if(auxSocio->estado == SOCIO_ESTADO_ACTIVO)
        {
            printf("NOMBRE: %s- ID: %d\n",soc_getNombre(auxSocio),soc_getId(auxSocio));
        }
    }
}


void mostrarError(char *);

static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaSocio(auxNombre,auxApellido,auxDni);

}

static void opcionBaja()
{
    char auxId[50];
    int id;
    val_getInt(auxId, "ID? ", "Error",2,50);
    id = atoi(auxId);
    cont_bajaSocio(id);
}

static void opcionModificacion()
{
    int id;
    int estado;
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    char auxEstado[50];
    val_getInt(auxId, "ID? ", "Error",2,50);
    id = atoi(auxId);
    if(cont_checkSocio(id)==0)
    {
        val_getString(auxNombre, "Nombre? ", "Error",2,50);
        val_getString(auxApellido, "Apellido? ", "Error",2,50);
        val_getInt(auxDni, "DNI? ", "Error",2,50);
    //    val_getInt(auxEstado, "Estado? ", "Error",2,50);
        estado = atoi(auxEstado);
        cont_modificarSocio(auxNombre, auxApellido, auxDni, id, estado);
    }
    else
    {
        printf("Error");
    }
}

static void opcionListado()
{
    cont_listarSocios();
}
