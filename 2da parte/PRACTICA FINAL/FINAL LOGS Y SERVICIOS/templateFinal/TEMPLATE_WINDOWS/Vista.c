#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Logs.h"
#include "Servicios.h"

static void opcionLeerLogs();
static void opcionListarLogs();
static void opcionProcesarInformacion();
static void opcionMostrarEstadisticas();

static int idiomaVista;

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
                opcionLeerLogs();
                break;
            case 2:
                opcionListarLogs();
                break;
            case 3:
                opcionProcesarInformacion();
            case 4:
                opcionMostrarEstadisticas();
                break;
        }
    }

    return 0;
}

void vista_mostrarLogs(ArrayList* pListaLogs)
{

    al_map(pListaLogs, logs_print);

}


void mostrarError(char * mensaje)
{

    printf("\nIMPRIMO ERROR\n");

}

static void opcionLeerLogs()
{
    cont_leerLogs();
}

static void opcionListarLogs()
{
    cont_listarLogs();
}


static void opcionProcesarInformacion()
{
    cont_procesarInformacion();
}

static void opcionMostrarEstadisticas()
{
   cont_listarEstadisticas();
}
