
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicio.h"
#include "SocioServicio.h"
#include "DataManager.h"
#include "Validaciones.h"

int dm_saveAll(ArrayList* listaClientes)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    Cliente* pCliente;

    pFile = fopen(ARCHIVO_CLIENTES, "wb");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(listaClientes); i++)
        {
            pCliente = al_get(listaClientes, i); //NO ACCEDER CON FLECHA, USAR LAS FUNCIONES!!
            fwrite(pCliente, sizeof(Cliente), 1, pFile);
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

int dm_readAll(ArrayList* listaClientes)
{
    FILE* pFile;
    Cliente auxCliente;
    Cliente* pCliente;
    int newId = 0;
    int retorno = -1;

    pFile = fopen(ARCHIVO_CLIENTES, "rb");

    if(pFile != NULL)
    {
        do
        {
            if(fread(&auxCliente, sizeof(Cliente), 1, pFile)==1)
            {
                pCliente = cli_new(auxCliente.nombre, auxCliente.apellido, auxCliente.dni, auxCliente.id, auxCliente.estado);
                al_add(listaClientes, pCliente);
                if(auxCliente.id > newId)
                {
                    newId = auxCliente.id;
                }
                    retorno = newId;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}

int dm_saveAllAlq(ArrayList* listaAlquileres)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    Alquiler* pAlquiler;

    pFile = fopen(ARCHIVO_ALQUILERES, "wb");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(listaAlquileres); i++)
        {
            pAlquiler = al_get(listaAlquileres, i);
            fwrite(pAlquiler, sizeof(Alquiler), 1, pFile);
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

int dm_readAllAlq(ArrayList* listaAlquileres)
{
    FILE* pFile;
    Alquiler auxAlquiler;
    Alquiler* pAlquiler;
    int newId = 0;
    int retorno = -1;

    pFile = fopen(ARCHIVO_ALQUILERES, "rb");

    if(pFile != NULL)
    {
        do
        {
            if(fread(&auxAlquiler, sizeof(Alquiler), 1, pFile)==1)
            {
                pAlquiler = alq_new(auxAlquiler.id, auxAlquiler.idCliente, auxAlquiler.idEquipo, auxAlquiler.idOperador, auxAlquiler.tiempoReal, auxAlquiler.tiempoEstimado, auxAlquiler.estado);
                al_add(listaAlquileres, pAlquiler);
                if(auxAlquiler.id > newId)
                {
                    newId = auxAlquiler.id;
                }
                    retorno = newId;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}

//-----------------------------------------------------------------------------------------------------


int dm_saveAllCliAlq(ArrayList* listaClienteAlquiler)
{
    int retorno = -1;
    int i;
    FILE* pFile;
    ClienteAlquiler* pClienteAlquiler;

    pFile = fopen(ARCHIVO_CLIENTEALQUILER, "wb");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(listaClienteAlquiler); i++)
        {
            pClienteAlquiler = al_get(listaClienteAlquiler, i);
            fwrite(pClienteAlquiler, sizeof(ClienteAlquiler), 1, pFile);
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

int dm_readAllCliAlq(ArrayList* listaClienteAlquiler)
{
    FILE* pFile;
    ClienteAlquiler auxClienteAlquiler;
    ClienteAlquiler* pClienteAlquiler;
    int newId = 0;
    int retorno = -1;

    pFile = fopen(ARCHIVO_CLIENTEALQUILER, "rb");

    if(pFile != NULL)
    {
        do
        {
            if(fread(&auxClienteAlquiler, sizeof(ClienteAlquiler), 1, pFile)==1)
            {
                pClienteAlquiler = clialq_new(auxClienteAlquiler.id, auxClienteAlquiler.idCliente, auxClienteAlquiler.idAlquiler, auxClienteAlquiler.estado);
                al_add(listaClienteAlquiler, pClienteAlquiler);
                if(auxClienteAlquiler.id > newId)
                {
                    newId = auxClienteAlquiler.id;
                }
                    retorno = newId;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}



int dm_dumpListaClientes(ArrayList* lista)
{
    FILE *pFile;
    int i=0;
    Cliente* Cliente;
    int retorno = -1;

    pFile = fopen("out.csv","w");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(lista); i++)
        {
            Cliente = al_get(lista, i);
            fprintf(pFile,"%d-%s-%s-%s-%d\n",cli_getId(Cliente),cli_getNombre(Cliente),cli_getApellido(Cliente),cli_getDni(Cliente),cli_getEstado(Cliente));
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
//int parserCliente(FILE* pFile , ArrayList* pArrayListCliente)
//{
//    Cliente* pCliente;
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
//            pCliente = cli_new(name, lastName, id, age, estado);
//            al_add(pArrayListCliente, pCliente);
//        }
//    }
//    return 0;
//}


//int dm_readAll(ArrayList* pArrayLogs)
//{
//    FILE* pArchivoClientes;
//    Cliente auxCliente;
//    Cliente* pCliente = NULL;
//    int newId = 0;
//    int retorno = -1;
//
//    pArchivoClientes = fopen("logs.txt", "r");
//
//    if(pArchivoClientes != NULL)
//    {
//        do
//        {
//            if(fscanf(pArchivoClientes, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",var1,var2,var3,var4,var5)
//            {
////               logEntry* log = log_new(var1, var2, var3, var4, var5);
////              al_add(pArrayLogs, log); LAS UNICAS 2 LINEAS QUE VARIAN, TRAER HECHO! (BINARIO-TEXTO)
//                pCliente = cli_new(auxCliente.nombre, auxCliente.apellido, auxCliente.dni, auxCliente.id, auxCliente.estado, auxCliente.contAlquileres);
//                al_add(listaClientes, pCliente);
//                if(auxCliente.id > newId)
//                {
//                    newId = auxCliente.id;
//                }
//                    retorno = newId;
//            }
//        }while(!feof(pFile));
//        fclose(pFile);
//    }
//    return retorno;
//}
