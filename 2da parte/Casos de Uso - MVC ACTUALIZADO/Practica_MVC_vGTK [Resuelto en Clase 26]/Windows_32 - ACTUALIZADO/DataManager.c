
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicio.h"
#include "SocioServicio.h"
#include "DataManager.h"
#include "Validaciones.h"

int dm_saveAll(ArrayList* listaSocios)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    Socio* pSocio;

    pFile = fopen(ARCHIVO_SocioS, "wb");

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
    Socio auxSocio;
    Socio* pSocio;
    int newId = 0;
    int retorno = -1;

    pFile = fopen(ARCHIVO_SocioS, "rb");

    if(pFile != NULL)
    {
        do
        {
            if(fread(&auxSocio, sizeof(Socio), 1, pFile)==1)
            {
                pSocio = soc_new(auxSocio.nombre, auxSocio.apellido, auxSocio.dni, auxSocio.id, auxSocio.estado, auxSocio.contServicios);
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
            pServicio = al_get(listaServicios, i);
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
    Servicio auxServicio;
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

//-----------------------------------------------------------------------------------------------------


int dm_saveAllSocServ(ArrayList* listaSocioServicio)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    SocioServicio* pSocioServicio;

    pFile = fopen(ARCHIVO_SocioSERVICIO, "wb");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(listaSocioServicio); i++)
        {
            pSocioServicio = al_get(listaSocioServicio, i);
            fwrite(pSocioServicio, sizeof(SocioServicio), 1, pFile);
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

int dm_readAllSocServ(ArrayList* listaSocioServicio)
{
    FILE* pFile;
    SocioServicio auxSocioServicio;
    SocioServicio* pSocioServicio;
    int newId = 0;
    int retorno = -1;

    pFile = fopen(ARCHIVO_SocioSERVICIO, "rb");

    if(pFile != NULL)
    {
        do
        {
            if(fread(&auxSocioServicio, sizeof(SocioServicio), 1, pFile)==1)
            {
                pSocioServicio = socserv_new(auxSocioServicio.id, auxSocioServicio.idSocio, auxSocioServicio.idServicio, auxSocioServicio.estado);
                al_add(listaSocioServicio, pSocioServicio);
                if(auxSocioServicio.id > newId)
                {
                    newId = auxSocioServicio.id;
                }
                    retorno = newId;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}



int dm_dumpListaSocios(ArrayList* lista)
{
    FILE *pFile;
    int i=0;
    Socio* Socio;
    int retorno = -1;

    pFile = fopen("out.csv","w");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(lista); i++)
        {
            Socio = al_get(lista, i);
            fprintf(pFile,"%d-%s-%s-%s-%d\n",soc_getId(Socio),soc_getNombre(Socio),soc_getApellido(Socio),soc_getDni(Socio),soc_getEstado(Socio));
        }
            retorno = 0;
    }
    return retorno;
}


/////** \brief Reads all the employees from a file, then adds them to the list
// * \param pFile Pointer to File
// * \param pArrayListEmployee ArrayList* Pointer to list
// * \return int Return (-1) if Error [pFile is NULL pointer] - (0) if Ok
// *
// */
//int parserSocio(FILE* pFile , ArrayList* pArrayListSocio)
//{
//    Socio* pSocio;
//    char var1[50];
//    char var2[50];
//    char var3[50];
//    char var4[50];
//    char var5[50];
//    int id;
//    int estado;
//    int age;
//    char name[50];
//    char lastName[50];
//
//    if(pFile != NULL)
//    {
//        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
//        while(!feof(pFile))
//        {
//            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
//            if(val_validarUnsignedInt(var1)==0)
//            {
//               id = atoi(var1);
//            }
//            if(val_validarNombre(var2)==0)
//            {
//               strcpy(name, var2);
//            }
//            if(val_validarNombre(var3)==0)
//            {
//               strcpy(lastName, var3);
//            }
//            if(val_validarUnsignedInt(var4)==0)
//            {
//               age = atoi(var4);
//            }
//            if(val_validarUnsignedInt(var5)==0)
//            {
//               estado = atoi(var5);
//            }
//            pSocio = soc_new(name, lastName, id, age, estado);
//            al_add(pArrayListSocio, pSocio);
//        }
//    }
//    return 0;
//}


//int dm_readAll(ArrayList* pArrayLogs)
//{
//    FILE* pArchivoSocios;
//    Socio auxSocio;
//    Socio* pSocio = NULL;
//    int newId = 0;
//    int retorno = -1;
//
//    pArchivoSocios = fopen("logs.txt", "r");
//
//    if(pArchivoSocios != NULL)
//    {
//        do
//        {
//            if(fscanf(pArchivoSocios, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",var1,var2,var3,var4,var5)
//            {
////               logEntry* log = log_new(var1, var2, var3, var4, var5);
////              al_add(pArrayLogs, log); LAS UNICAS 2 LINEAS QUE VARIAN, TRAER HECHO! (BINARIO-TEXTO)
//                pSocio = soc_new(auxSocio.nombre, auxSocio.apellido, auxSocio.dni, auxSocio.id, auxSocio.estado, auxSocio.contServicios);
//                al_add(listaSocios, pSocio);
//                if(auxSocio.id > newId)
//                {
//                    newId = auxSocio.id;
//                }
//                    retorno = newId;
//            }
//        }while(!feof(pFile));
//        fclose(pFile);
//    }
//    return retorno;
//}
