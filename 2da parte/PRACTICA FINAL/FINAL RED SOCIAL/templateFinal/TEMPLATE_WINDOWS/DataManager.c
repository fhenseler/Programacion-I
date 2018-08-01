#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Post.h"
#include "Usuario.h"
#include "Validaciones.h"

//int dm_saveAllPosts(ArrayList* pArrayPosts);
//int dm_readAllPosts(ArrayList* pArrayPosts);
//
//int dm_saveAllUsuarios(ArrayList* pArrayUsuarios);
//int dm_readAllUsuarios(ArrayList* pArrayUsuarios);

int dm_createFeed(ArrayList* nominaPosts, ArrayList* nominaUsuarios)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("feed.csv","w");
    void* pPosts=NULL;
    void* pUsuarios=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id_mensaje,mensaje,pop_mensaje,id_usuario,nick,pop_usuario\n");
        for(i=0;i<al_len(nominaPosts);i++)
        {
            pPosts=al_get(nominaPosts,i);
            pUsuarios = usuario_findByIdUsuario(nominaUsuarios, post_getIdUsuario(pPosts));
            fprintf(pFile, "%d,%s,%d,%d,%s,%d\n", post_getIdMensaje(pPosts),post_getMensaje(pPosts), post_getPopularidad(pPosts), usuario_getIdUsuario(pUsuarios), usuario_getNick(pUsuarios), usuario_getPopularidad(pUsuarios));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}

int dm_readAllPosts(ArrayList* nominaPosts)
{
    int retorno=-1;
    FILE *pFile;
//    int idMax = 0;
	Post* auxPost;

    char idMensaje[50],idUsuario[50],pop[50],mensaje[2000];

    pFile = fopen("Mensajes.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idMensaje,idUsuario,pop,mensaje);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idMensaje,idUsuario,pop,mensaje) >0)
			{
//				if(val_validarInt(idMensaje)!=-1 && val_validarInt(idUsuario)!=-1 && val_validarInt(pop)!=-1 && val_validarString(mensaje)!=-1)
//				{
                    auxPost=post_new(atoi(idMensaje), atoi(idUsuario), atoi(pop),mensaje);
					al_add(nominaPosts, auxPost);
//					if(atoi(idMensaje) >idMax)
//                    {
//                        idMax = atoi(idMensaje);
//                    }
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}


int dm_readAllUsuarios(ArrayList* nominaUsuarios)
{
    int retorno=-1;
    FILE *pFile;
    int idMax = 0;
	Usuario* auxUsuario;

    char idUsuario[50],nick[50],pop[50];
    int estado = USUARIO_ESTADO_ACTIVO;

    pFile = fopen("Usuarios.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idUsuario,nick,pop);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idUsuario,nick,pop) >0)
			{
//				if(val_validarInt(idMensaje)!=-1 && val_validarInt(idUsuario)!=-1 && val_validarInt(pop)!=-1 && val_validarString(mensaje)!=-1)
//				{
                    auxUsuario=usuario_new(atoi(idUsuario), nick, atoi(pop), estado);
					al_add(nominaUsuarios, auxUsuario);
					if(atoi(idUsuario) >idMax)
                    {
                        idMax = atoi(idUsuario);
                    }
                        retorno = idMax;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}
