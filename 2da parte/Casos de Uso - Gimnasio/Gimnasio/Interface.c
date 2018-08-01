#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"
#include "Validar.h"
#include "Controller.h"

#define MAX_INPUT_BUFFER 40
#define ARRAY_LENGTH 51

static int interface_generarNuevoId(Socio* structSocio);
static int interface_checkDNI(ArrayList* arraySocios, int len, char* buffer, Socio* structSocio);
static int interface_checkID(ArrayList* arraySocios, int len, int id, Socio* structSocio);

int interface_menu(ArrayList* arraySocios, Socio* structSocio)
{
    int retorno = 0;
    char bufferInt[MAX_INPUT_BUFFER];

    do
    {
        system("cls");
        printf("< GIMNASIO >\n");
        val_getUnsignedInt(bufferInt, "\n1- ALTA DE SOCIO\n2- BAJA DE SOCIO\n3- MODIFICAR SOCIO\n4- LISTAR SOCIOS\n\n5- SALIR\n\nElegir Opcion: ", "\nOpciones Validas 1-5. Reingrese: \n", 2, MAX_INPUT_BUFFER);

        system("cls");

        switch(atoi(bufferInt))
        {
            case 1:
                printf("[ALTA DE SOCIO - Presione *ESC* para cancelar]\n");
                if(interface_alta(arraySocios, structSocio)==0)
                {
                    controller_alta(arraySocios, structSocio->nombre, structSocio->apellido, structSocio->dni, structSocio->id, structSocio->estado);
                }
                break;
            case 2:
                printf("[BAJA DE SOCIO]\n");
                printf("\n[LISTA DE SOCIOS]\n");
                interface_printArraySocios(arraySocios);
                if(interface_baja(arraySocios, structSocio)==0)
                {
                    controller_baja(arraySocios, structSocio->estado);
                }
                break;
            case 3:
                printf("[MODIFICAR SOCIO]\n");
                printf("\n[LISTA DE SOCIOS]\n");
                interface_printArraySocios(arraySocios);
                if(interface_modificar(arraySocios, structSocio)==0)
                {
                    controller_modificar(arraySocios, structSocio, structSocio->nombre, structSocio->apellido);
                }
                break;
            case 4:
                printf("[LISTA DE SOCIOS]\n");
                interface_printArraySocios(arraySocios);
                break;
            case 5:
                break;
            default:
                printf("\nERROR!!! OPCION INVALIDA!!! (1-5)\n\n");
                printf("\n\n");
                system("pause");
                break;
        }
    }while(atoi(bufferInt) != 5);

                return retorno;
}

int interface_alta(ArrayList* arraySocios, Socio* structSocio)
{
    int retorno = -1;
    int id;
    char bNombre[NAME_LENGTH];
    char bApellido[LAST_NAME_LENGTH];
    char bDNI[DNI_LENGTH];

        if(structSocio != NULL && arraySocios != NULL)
        {
            if(val_getNombre(bNombre,"\nNombre: ", "\nError, reingrese nombre: ", 3, NAME_LENGTH)==0)
            {
                if(val_getNombre(bApellido,"\nApellido: ", "\nError, reingrese apellido: ", 3, LAST_NAME_LENGTH)==0)
                {
                    if(val_getDNI(bDNI,"\nDNI: ", "\nError, reingrese DNI: ", 3, DNI_LENGTH)==0)
                    {
                        if(val_validarRangoDNI(bDNI, "\nError, DNI invalido", DNI_LEN)==0)
                        {
                            if(interface_checkDNI(arraySocios, arraySocios->len(arraySocios), bDNI, structSocio)==0)
                            {
                                id = interface_generarNuevoId(structSocio);
                                if(id != -1)
                                {
                                    strncpy(structSocio->nombre, bNombre, NAME_LENGTH);
                                    strncpy(structSocio->apellido, bApellido, LAST_NAME_LENGTH);
                                    strncpy(structSocio->dni, bDNI, DNI_LENGTH);
                                    structSocio->id = id;
                                    structSocio->estado = SOCIO_ESTADO_ACTIVO;
                                    printf("\n------------------------------------------");
                                    printf("\nSOCIO DADO DE ALTA\n");
                                    printf("\nEL ID DEL NUEVO SOCIO ES: %d\n", structSocio->id);
                                    printf("------------------------------------------");
                                    retorno = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
                                    printf("\n\n");
                                    system("pause");
                                    return retorno;
}

int interface_generarNuevoId(Socio* structSocio)
{
    int i = 0;
    int idMax = -1;

    if(structSocio != NULL)
    {
        for(i = 0; i < 100; i++)
        {
            if(structSocio->estado == SOCIO_ESTADO_ACTIVO)
            {
                if(idMax < structSocio->id)
                {
                    idMax = structSocio->id;
                }

            }
        }
    }
                    return idMax + 1;
}

int interface_printArraySocios(ArrayList* lista)
{
    int retorno = -1;
    int i;
    Socio* auxSocio;

    if(lista != NULL)
    {
        printf("\nID\tNOMBRE\t\tAPELLIDO\tDNI");
        for(i = 0; i < lista->len(lista); i++)
        {
            auxSocio = lista->get(lista, i);
            if(auxSocio->estado == SOCIO_ESTADO_ACTIVO)
            {
                interface_printSocio(auxSocio);
                retorno = 0;
            }
        }
    }
                printf("\n\n");
                return retorno;
}

int interface_printSocio(Socio* structSocio)
{
        int retorno = -1;

        if(structSocio != NULL)
        {
            printf("\n%-5d\t%-5s\t%-5s\t%-5s\t", structSocio->id, structSocio->nombre, structSocio->apellido, structSocio->dni);
            retorno = 0;
        }

            return retorno;
}

int interface_checkDNI(ArrayList* arraySocios, int len, char* buffer, Socio* structSocio)
{
    int retorno = 0;
    int i;

    for(i = 0; i < len; i++)
    {
        if((strcmp(structSocio->dni, buffer)==0))
        {
            retorno = -1;
            printf("\nERROR! Ya hay un socio registrado con este DNI!!!\n\n");
            printf("***OPERACION CANCELADA***");
            break;
        }
    }
            return retorno;
}

int interface_modificar(ArrayList* arraySocios, Socio* structSocio)
{
    int retorno = -1;
    char bNombre[NAME_LENGTH];
    char bApellido[LAST_NAME_LENGTH];

    if(arraySocios != NULL && structSocio != NULL)
    {
        if(val_getNombre(bNombre,"\nIngrese nuevo nombre: ", "\nError. Reingrese nombre: \n", 3, ARRAY_LENGTH)==0)
        {
            if(val_getNombre(bApellido,"\nIngrese nuevo apellido: ","\nError. Reingrese apellido: \n", 3, ARRAY_LENGTH)==0)
            {
                    strncpy(structSocio->nombre, bNombre, ARRAY_LENGTH);
                    strncpy(structSocio->apellido, bApellido, ARRAY_LENGTH);
                    retorno = 0;
                    printf("\n-------------------------------------------");
                    printf("\nDATOS ACTUALIZADOS CORRECTAMENTE!!!");
                    printf("\n-------------------------------------------");
            }
        }
    }
                    printf("\n\n");
                    system("pause");
                    return retorno;
}


int interface_baja(ArrayList* arraySocios, Socio* structSocio)
{
    int id;
    int retorno = -1;
    char buffer[ARRAY_LENGTH];

        if(arraySocios != NULL && structSocio != NULL)
        {
            val_getUnsignedInt(buffer, "Ingrese ID del socio a borrar: ", "\nError. Reingrese ID:  ", 3, ARRAY_LENGTH);
            id = atoi(buffer);
            if(interface_checkID(arraySocios, arraySocios->len(arraySocios), id, structSocio) == -1)
            {
                printf("Error! ID Invalido\n");
            }
            else
            {
                printf("\nDesea dar de baja a este socio? (Y/N)");
                myFgets(buffer, ARRAY_LENGTH, stdin);
                if((strcmp(buffer, "Y")==0) || (strcmp(buffer, "y")==0))
                {
                    structSocio->estado = SOCIO_ESTADO_INACTIVO;
                    retorno = 0;
                    printf("\n-------------------------------------------");
                    printf("\nSOCIO DADO DE BAJA CORRECTAMENTE");
                    printf("\n-------------------------------------------");
                }
            }
        }
                    printf("\n\n");
                    system("pause");
                    return retorno;
}

int interface_checkID(ArrayList* arraySocios, int len, int id, Socio* structSocio)
{
    int retorno = -1;
    int i;

    for(i = 0; i < len; i++)
    {
        if(structSocio->id == id && structSocio->estado == SOCIO_ESTADO_ACTIVO)
        {
            retorno = 0;
            break;
        }
    }
            return retorno;
}
