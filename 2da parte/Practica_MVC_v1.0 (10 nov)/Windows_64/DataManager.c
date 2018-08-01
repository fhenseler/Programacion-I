#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicio.h"
#include "DataManager.h"

int dm_saveAll(ArrayList* listaSocios)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    Socio* pSocio;

    pFile = fopen(ARCHIVO_SOCIOS, "wb");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(listaSocios); i++)
        {
            pSocio = al_get(listaSocios, i); //NO ACCEDER CON FLECHA, USAR LAS FUNCIONES!!
            fwrite(pSocio, sizeof(Socio), 1, pFile);
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

int dm_readAll(ArrayList* listaSocios)
{
    FILE* pFile;
    Socio auxSocio; //Creamos un aux del tipo Socio para poder acceder a los campos, NO UN PUNTERO!
    Socio* pSocio;
    int newId = 0;
    int retorno = -1;

    pFile = fopen(ARCHIVO_SOCIOS, "rb");

    if(pFile != NULL)
    {
        do
        {
            if(fread(&auxSocio, sizeof(Socio), 1, pFile)==1)
            {
                pSocio = soc_new(auxSocio.nombre, auxSocio.apellido, auxSocio.dni, auxSocio.id, auxSocio.estado);
                al_add(listaSocios, pSocio);
                if(auxSocio.id > newId)
                {
                    newId = auxSocio.id;
                }
                    retorno = newId;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}

int dm_saveAllServ(ArrayList* listaServicios)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    Servicio* pServicio;

    pFile = fopen(ARCHIVO_SERVICIOS, "wb");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(listaServicios); i++)
        {
            pServicio = al_get(listaServicios, i); //NO ACCEDER CON FLECHA, USAR LAS FUNCIONES!!
            fwrite(pServicio, sizeof(Servicio), 1, pFile);
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

int dm_readAllServ(ArrayList* listaServicios)
{
    FILE* pFile;
    Servicio auxServicio; //Creamos un aux del tipo Socio para poder acceder a los campos, NO UN PUNTERO!
    Servicio* pServicio;
    int newId = 0;
    int retorno = -1;

    pFile = fopen(ARCHIVO_SERVICIOS, "rb");

    if(pFile != NULL)
    {
        do
        {
            if(fread(&auxServicio, sizeof(Servicio), 1, pFile)==1)
            {
                pServicio = serv_new(auxServicio.descripcion, auxServicio.id, auxServicio.estado);
                al_add(listaServicios, pServicio);
                if(auxServicio.id > newId)
                {
                    newId = auxServicio.id;
                }
                    retorno = newId;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}
