#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Logs.h"
#include "Servicios.h"


static ArrayList* nominaLogs;
static ArrayList* listaG3;
static ArrayList* listaG47;
static ArrayList* listaGM7;
static ArrayList* nominaServicios;

void cont_init()
{
    nominaLogs = al_newArrayList();

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_leerLogs()
{
    dm_readAllLogs(nominaLogs);
    dm_readAllServicios(nominaServicios);
    return 0;
}

int cont_listarLogs()
{
    vista_mostrarLogs(nominaLogs);
    return 0;
}

int cont_procesarInformacion()
{
    listaG3 = al_filter(nominaLogs, logs_filterLogs);
    listaG47 = al_filter(nominaLogs, logs_filterLogs2);
    listaGM7 = al_filter(nominaLogs, logs_filterLogs3);

    dm_saveAllLogsG3(listaG3);
//    dm_saveAllLogsG47(listaG47);
    dm_saveAllLogsGM7(listaGM7);

    return 0;
}

int cont_listarEstadisticas()
{
    printf("Cant == 3:%d --- Cant => 4 && Cant <= 7: %d --- Cant > 7: %d", al_len(listaG3), al_len(listaG47), al_len(listaGM7));
    return 0;
}
