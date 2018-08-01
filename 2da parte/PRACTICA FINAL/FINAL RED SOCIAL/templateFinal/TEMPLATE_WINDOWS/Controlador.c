#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"

static ArrayList* nominaUsuarios;
//static int proximoIdUsuario=0;
//static int getNewIdUsuario();
//static int setNewIdUsuario(int id);

static ArrayList* nominaPosts;
//static int proximoIdPost=0;
//static int getNewIdPost();
//static int setNewIdPost(int id);

void cont_init()
{
    nominaUsuarios = al_newArrayList();
    dm_readAllUsuarios(nominaUsuarios);

    nominaPosts = al_newArrayList();
    dm_readAllPosts(nominaPosts);

    dm_createFeed(nominaPosts, nominaUsuarios);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_listarMensajes ()
{
    vista_mostrarMensaje(nominaPosts);
    return 0;
}

int cont_listarUsuarios ()
{
    vista_mostrarUsuario(nominaUsuarios);
    return 0;
}

void cont_importarMensajes()
{
    dm_readAllPosts(nominaPosts);
}
//static int getNewIdUsuario()
//{
//    return proximoIdUsuario++;
//}
//
//static int setNewIdUsuario(int id)
//{
//    proximoIdUsuario = id;
//    return 0;
//}
//
//static int getNewIdPost()
//{
//    return proximoIdPost++;
//}
//
//static int setNewIdPost(int id)
//{
//    proximoIdPost = id;
//    return 0;
//}
