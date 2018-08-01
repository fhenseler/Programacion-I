#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"

static ArrayList* nominaUsuarios;
static ArrayList* nominaTemas;


void cont_init()
{
    nominaUsuarios = al_newArrayList();
    dm_readAllUsuarios(nominaUsuarios);

    nominaTemas = al_newArrayList();
    dm_readAllTemas(nominaTemas);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_listarUsuarios ()
{
    vista_mostrarUsuario(nominaUsuarios);
    return 0;
}

int cont_listarTemas ()
{
    vista_mostrarTemas(nominaTemas);
    return 0;
}


int cont_escucharTema(char* nombreUsuario,char* claveUsuario,int idTema)
{
    int idTema = getNewIdAlquiler();
    int tiempoReal = 0;
    Alquiler *auxAlquiler;

    auxAlquiler = alquiler_new(idCliente,idEquipo,tiempoReal,tiempoEstimado, id,ALQUILER_ESTADO_ALTA);
    al_add(nominaAlquileres,auxAlquiler);
    dm_saveAllAlquileres(nominaAlquileres);
   // printf("NOMBRE_%s / QTY %d" , cliente_getApellido(auxCliente),al_len(nominaClientes));

    return 0;
}
