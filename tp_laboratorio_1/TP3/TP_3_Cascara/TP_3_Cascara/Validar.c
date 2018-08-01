#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validar.h"

#define MAX_INPUT_BUFFER 4096


void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i = 0;
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';

    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
            i++;
    }
}

int val_getNombre(char* destino, char* mensaje, char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

        if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
        {
            printf(mensaje);
            for( ; intentos > 0; intentos--)
            {
                myFgets(buffer, limite ,stdin);

                if(val_validarNombre(buffer) == -1)
                {
                    if(intentos == 1)
                    {
                        printf("\nERROR!!! INTENTOS AGOTADOS!!!\n");
                        break;
                    }
                    else
                    {
                        printf(mensajeError);
                        continue;
                    }
                }
                else
                {
                    strncpy(destino,buffer,limite);
                    retorno = 0;
                    break;
                }
            }
        }
                    return retorno;
}


int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos > 0; intentos--)
        {
            myFgets(buffer, limite ,stdin);

                if(val_validarDescripcion(buffer) == -1)
                {
                    if(intentos == 1)
                    {
                        printf("\nERROR!!! INTENTOS AGOTADOS!!!\n");
                        break;
                    }
                    else
                    {
                        printf(mensajeError);
                        continue;
                    }
                }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }

    }
                return retorno;
}

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos > 0; intentos--)
        {
            myFgets(buffer, limite ,stdin);

                if(val_validarFloat(buffer) == -1)
                {
                    if(intentos == 1)
                    {
                        printf("\nERROR!!! INTENTOS AGOTADOS!!!\n");
                        break;
                    }
                    else
                    {
                        printf(mensajeError);
                        continue;
                    }
                }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
                return retorno;
}


int val_validarNombre(char* buffer)
{
    int i = 0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] != 32))
        {
            if(buffer[0] < 'A' || buffer[0] > 'Z')
            {
                retorno = -1;
                break;
            }
        }
                i++;
    }
                return retorno;
}

int val_validarDescripcion(char* buffer)
{
    int i = 0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] != '.') && (buffer[i] != ',') && (buffer[i] != 32) && (buffer[i] != ':') && (buffer[i] != '/'))
        {
            retorno = -1;
            break;
        }
            i++;
    }
            return retorno;
}

int val_validarFloat(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
                    i++;
    }
                    return retorno;
}


int val_getUnsignedInt(char* destino, char* mensaje, char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos > 0; intentos--)
        {
            myFgets(buffer, limite ,stdin);

                if(val_validarUnsignedInt(buffer) == -1)
                {
                    if(intentos == 1)
                    {
                        printf("\nERROR!!! INTENTOS AGOTADOS!!!\n");
                        break;
                    }
                    else
                    {
                        printf(mensajeError);
                        continue;
                    }
                }
                else
                {
                    strncpy(destino,buffer,limite);
                    retorno = 0;
                    break;
                }
        }
    }
                return retorno;
}


int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
                    i++;
    }
                    return retorno;
}

int val_validarRangoInt(char* buffer, char* errorMessage, int lowLim, int hiLim)
{
    int retorno = 0;
    int value;

    value = atoi(buffer);
    if(value < lowLim || value > hiLim)
    {
        retorno = -1;
        printf(errorMessage);
    }

        return retorno;
}
