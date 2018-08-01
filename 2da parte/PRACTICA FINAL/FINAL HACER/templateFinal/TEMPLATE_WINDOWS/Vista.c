#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Usuario.h"
#include "Tema.h"

static void opcionListadoUsuarios();
static void opcionListadoTemas();
static void opcionEscucharTema();

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

    while(option != 10)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListadoUsuarios();
                break;
            case 2:
                break;
            case 3:
                opcionListadoTemas();
                break;
            case 4:
                opcionEscucharTema();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
        }
    }

    return 0;
}

void vista_mostrarUsuario(ArrayList* pListaUsuarios)
{
    al_sort(pListaUsuarios, usuario_compareByNombre, 2);
    al_map(pListaUsuarios,usuario_imprimir);
}

void vista_mostrarTemas(ArrayList* pListaTemas)
{
    al_sort(pListaTemas, tema_compareByArtista, 2);
    al_map(pListaTemas,tema_imprimir);
}

void mostrarError(char * mensaje)
{

    printf("\nIMPRIMO ERROR\n");

}

static void opcionListadoUsuarios()
{
    cont_listarUsuarios();
}

static void opcionListadoTemas()
{
    cont_listarTemas();
}

static void opcionEscucharTema()
{
    char nombreUsuario[50];
    char claveUsuario[50];
    char idTema[50];
    char tiempoEstimado[50];

    if(val_getNombre(nombreUsuario, "nombreUsuario? ", "Error",2,50) == 0 &&
       val_getDescripcion(claveUsuario, "claveUsuario? ", "Error",2,50) == 0 &&
       val_getUnsignedInt(idTema, "idTema? ", "Error",2,50) == 0)
    {
        cont_escucharTema(nombreUsuario,claveUsuario,idTema);
    }

}
