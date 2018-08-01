#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Cliente.h"
#include "Alquiler.h"
#include "Validaciones.h"

int dm_saveAllClientes(ArrayList* nominaClientes)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("clientes.csv","w");
    Cliente* pCliente = NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"idCliente,nombre,apellido,DNI,estado\n");
        for(i=0;i<al_len(nominaClientes);i++)
        {
            pCliente=al_get(nominaClientes,i);
            fprintf(pFile, "%d,%s,%s,%s,%d\n", cliente_getIdCliente(pCliente),
                    cliente_getNombre(pCliente), cliente_getApellido(pCliente),
                    cliente_getDni(pCliente), cliente_getEstado(pCliente));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}

int dm_readAllClientes(ArrayList* nominaClientes)
{
    FILE *pFile;
	Cliente* auxCliente;
	int idMax = 0;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("clientes.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarString(var2)!=-1 && val_validarString(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)
				{
//					auxEmployee=employee_new(atoi(var1), var2, var3,atoi(var4), atoi(var5));
                    auxCliente = cliente_new(atoi(var1), var2, var3, var4, atoi(var5));
					al_add(nominaClientes, auxCliente);
					if(atoi(var1) >idMax)
                    {
                        idMax = atoi(var1);
                    }
                        retorno = idMax;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}


//***************************************************************************************************************

int dm_saveAllAlquileres(ArrayList* nominaAlquileres)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("alquileres.csv","w");
    Alquiler* pAlquiler = NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"idCliente,idEquipo,tiempoReal,tiempoEstimado,idAlquiler,estado\n");
        for(i=0;i<al_len(nominaAlquileres);i++)
        {
            pAlquiler=al_get(nominaAlquileres,i);
            fprintf(pFile, "%d,%d,%d,%d,%d,%d\n", alquiler_getIdCliente(pAlquiler),
                    alquiler_getIdEquipo(pAlquiler), alquiler_getTiempoReal(pAlquiler),
                    alquiler_getTiempoEstimado(pAlquiler), alquiler_getIdAlquiler(pAlquiler), alquiler_getEstado(pAlquiler));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}

int dm_readAllAlquileres(ArrayList* nominaAlquileres)
{
    FILE *pFile;
	Alquiler* auxAlquiler;
	int idMax = 0;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];

    pFile = fopen("alquileres.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6) >0)
			{
//				if(val_validarInt(var1)!=-1 && val_validarString(var2)!=-1 && val_validarString(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)
//				{
//					auxEmployee=employee_new(atoi(var1), var2, var3,atoi(var4), atoi(var5));
                    auxAlquiler = alquiler_new(atoi(var1), atoi(var2), atoi(var3), atoi(var4), atoi(var5),atoi(var6));
					al_add(nominaAlquileres, auxAlquiler);
					if(atoi(var1) >idMax)
                    {
                        idMax = atoi(var1);
                    }
                        retorno = idMax;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}
