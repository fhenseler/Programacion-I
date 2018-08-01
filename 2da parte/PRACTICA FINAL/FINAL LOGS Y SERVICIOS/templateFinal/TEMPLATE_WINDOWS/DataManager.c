#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Logs.h"
#include "Servicios.h"



int dm_saveAllLogsG3(ArrayList* pArrayLogs)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("warnings.txt","w");
    Logs* pLogs=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"fecha,hora,idServicio,gravedad,mensaje\n");
        for(i=0;i<al_len(pArrayLogs);i++)
        {
            pLogs=al_get(pArrayLogs,i);
            if(pLogs->idServicio != 45)
            {
                 fprintf(pFile, "%s;%s;%d;%d;%s\n", logs_getFecha(pLogs),logs_getHora(pLogs),logs_getIdServicio(pLogs),logs_getGravedadError(pLogs),logs_getMensajeError(pLogs));
            }
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

int dm_saveAllLogsGM7(ArrayList* pArrayLogs)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("errors.txt","w");
    Logs* pLogs=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"fecha,hora,idServicio,gravedad,mensaje\n");
        for(i=0;i<al_len(pArrayLogs);i++)
        {
            pLogs=al_get(pArrayLogs,i);
            fprintf(pFile, "%s;%s;%d;%d;%s\n", logs_getFecha(pLogs),logs_getHora(pLogs),logs_getIdServicio(pLogs),logs_getGravedadError(pLogs),logs_getMensajeError(pLogs));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

int dm_readAllLogs(ArrayList* pArrayLogs)
{
    int retorno=-1;
    FILE *pFile;
	Logs* auxLog;

    char fecha[50],hora[50],idServicio[50],gravedad[50],mensaje[65];

    pFile = fopen("logs.txt","r");

	if(pFile!=NULL)
    {
//		fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",fecha,hora,idServicio,gravedad,mensaje);
        do{
            if(fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",fecha,hora,idServicio,gravedad,mensaje) >0)
			{
//				if(val_validarInt(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarDescripcion(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)
//				{
					auxLog=logs_new(fecha,hora,atoi(idServicio),atoi(gravedad),mensaje);
					al_add(pArrayLogs, auxLog);
					retorno=0;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}

int dm_readAllServicios(ArrayList* pArrayServicios)
{
    int retorno=-1;
    FILE *pFile;
	Servicios* auxServicio;

    char idServicio[50],nombreServicio[50],emailServicio[50];

    pFile = fopen("servicios.txt","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^;];%[^;];%[^\n]\n",idServicio,nombreServicio,emailServicio);
        do{
            if(fscanf(pFile,"%[^;];%[^;];%[^\n]\n",idServicio,nombreServicio,emailServicio) >0)
			{
//				if(val_validarInt(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarDescripcion(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)
//				{
					auxServicio=servicios_new(atoi(idServicio),nombreServicio,emailServicio);
					al_add(pArrayServicios, auxServicio);
					retorno=0;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}
