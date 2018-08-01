#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Post.h"
#include "Usuario.h"

//static void opcionAltaUsuario();
//static void opcionBajaUsuario();
//static void opcionModificacionUsuario();
static void opcionListadoUsuarios();
//static void opcionOrdenarUsuario();
static int idiomaVista;

static void opcionListadoMensajes();
//static void opcionImportarMensajes();

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 4)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListadoMensajes();
                break;
            case 2:
                opcionListadoUsuarios();
                break;
//            case 3:
//                opcionGenerarFeed();
//                break;
        }
    }

    return 0;
}


void mostrarError(char * mensaje)
{

    printf("\nIMPRIMO ERROR\n");

}

//static void opcionAltaUsuario()
//{
//    char a[50];
//    char b[50];
//    char c[50];
//    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
//       val_getString(b, "B? ", "Error",2,50) == 0 &&
//       val_getInt(c, "C? ", "Error",2,50) == 0)
//    {
//        cont_altaUsuario(a,b,atoi(c));
//    }
//
//
//}
//
//static void opcionBajaUsuario()
//{
//    char auxId[10];
//    int id;
//
//    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        cont_bajaUsuario(id);
//    }
//
//}
//
//static void opcionModificacionUsuario()
//{
//    char auxId[10];
//    int id;
//    char a[50];
//    char b[50];
//    char c[50];
//
//    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
//           val_getString(b, "B? ", "Error",2,50) == 0 &&
//           val_getInt(c, "C? ", "Error",2,50) == 0)
//        {
//            cont_modificarUsuario(id,a,b,atoi(c));
//        }
//    }
//
//
//}

static void opcionListadoMensajes()
{
    cont_listarMensajes();
}

static void opcionListadoUsuarios()
{
    cont_listarUsuarios();
}

//static void opcionOrdenarUsuario()
//{
//    cont_ordenarUsuario();
//}

//static void opcionImportarUsuarios()
//{
//    cont_importarUsuarios();
//}

//***********************************************************************************

void vista_mostrarMensaje(ArrayList* nominaPosts)
{
    al_map(nominaPosts,post_print);
}

void vista_mostrarUsuario(ArrayList* nominaUsuarios)
{
    al_map(nominaUsuarios,usuario_print);
}

//static void opcionAltaUsuario()
//{
//    char a[50];
//    char b[50];
//    char c[50];
//    if(val_getString(a, "A? ", "Error",2,50) == 0 &&
//       val_getString(b, "B? ", "Error",2,50) == 0 &&
//       val_getInt(c, "C? ", "Error",2,50) == 0)
//    {
//        cont_altaUsuario(a,b,atoi(c));
//    }
//
//
//}
//
//static void opcionBajaUsuario()
//{
//    char auxId[10];
//    int id;
//
//    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        cont_bajaUsuario(id);
//    }
//
//}
//
//static void opcionModificacionUsuario()
//{
//    char auxId[10];
//    int id;
//    char a[50];
//    char b[50];
//    char c[50];
//
//    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
//    {
//        id = atoi(auxId);
//        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
//           val_getString(b, "B? ", "Error",2,50) == 0 &&
//           val_getInt(c, "C? ", "Error",2,50) == 0)
//        {
//            cont_modificarUsuario(id,a,b,atoi(c));
//        }
//    }
//
//
//}

//static void opcionListadoPosts()
//{
//    cont_listarMensajes();
//}

//static void opcionOrdenarUsuario()
//{
//    cont_ordenarUsuario();
//}

