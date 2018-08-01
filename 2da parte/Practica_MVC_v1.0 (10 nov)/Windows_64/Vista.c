#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "Servicio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();

static void opcionAltaServ();
static void opcionBajaServ();
static void opcionModificacionServ();
static void opcionListadoServ();

static int comparaSocios(void* pSocioA,void* pSocioB);


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 9)
    {
        system("cls");
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,9);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListado();
                printf("\n");
                system("pause");
                break;
            case 2:
                opcionAlta();
                printf("\n");
                system("pause");
                break;
            case 3:
                opcionBaja();
                printf("\n");
                system("pause");
                break;
            case 4:
                opcionModificacion();
                printf("\n");
                system("pause");
                break;
            case 5:
                opcionListadoServ();
                printf("\n");
                system("pause");
                break;
            case 6:
                opcionAltaServ();
                printf("\n");
                system("pause");
                break;
            case 7:
                opcionBajaServ();
                printf("\n");
                system("pause");
                break;
            case 8:
                opcionModificacionServ();
                printf("\n");
                system("pause");
                break;
        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    int cont = 0;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
    {
        al_sort(pListaSocios, comparaSocios, 1);
        auxSocio = al_get(pListaSocios,i);
        if(auxSocio->estado == SOCIO_ESTADO_ACTIVO)
        {
            cont++;
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",soc_getNombre(auxSocio),
                soc_getApellido(auxSocio),soc_getId(auxSocio),soc_getDni(auxSocio));
        }
    }
        if(cont == 0)
        {
           printf("\nNo hay socios registrados en el sistema!!!\n");
        }
}


void mostrarError(char *);

static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if(val_getString(auxNombre, "Nombre? ", "Error",1,50)== 0)
    {
        if(val_getString(auxApellido, "Apellido? ", "Error",1,50)==0)
        {
           if(val_getInt(auxDni, "DNI? ", "Error",1,50)==0)
           {
               if(cont_checkSocioByDni(auxDni)!=0)
               {
                  cont_altaSocio(auxNombre,auxApellido,auxDni);
               }
               else
               {
                   printf("\nError! Este DNI ya esta en uso");
               }
           }
        }
    }
}

static void opcionBaja()
{
    char auxId[50];
    int id;
    char resp[50];

    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        if(cont_checkSocio(atoi(auxId))==0)
        {
            printf("\nDesea dar de baja a este socio? (Y/N)");
            myFgets(resp, 50, stdin);
                if((strcmp(resp, "y")==0) || (strcmp(resp, "Y")==0))
                {
                    id = atoi(auxId);
                    cont_bajaSocio(id);
                    printf("\n***SOCIO ELIMINADO CORRECTAMENTE***");
                }
                else
                {
                    printf("\n***EL SOCIO NO FUE ELIMINADO***");
                }
        }
        else
        {
            printf("\nError! ID de socio inexistente");
        }
    }
}

static void opcionModificacion()
{
    int id;
//    int estado;
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
//    char auxEstado[50];
    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        id = atoi(auxId);
        if(cont_checkSocio(id)==0)
        {
            val_getString(auxNombre, "Nombre? ", "Error",1,50);
            val_getString(auxApellido, "Apellido? ", "Error",1,50);
            val_getInt(auxDni, "DNI? ", "Error",1,50);
//            val_getInt(auxEstado, "Estado? ", "Error",1,50);
//            estado = atoi(auxEstado);
            cont_modificarSocio(auxNombre, auxApellido, auxDni, id, 1);
            printf("\n***DATOS MODIFICADOS CORRECTAMENTE***");
        }
        else
        {
            printf("\nError! ID de socio inexistente");
        }

    }
}

static void opcionListado()
{
    cont_listarSocios();
}

//---------------------------------------------------------------------------------------

void vista_mostrarServicios(ArrayList* pListaServicios)
{
    int i;
    Servicio* auxServicio;
    for(i=0;i<al_len(pListaServicios);i++)
    {
        auxServicio = al_get(pListaServicios,i);
        if(auxServicio->estado == SERVICIO_ESTADO_ACTIVO)
        {
            printf("DESCRIPCION: %s- ID: %d\n",serv_getDescripcion(auxServicio),serv_getId(auxServicio));
        }
    }
}


void mostrarError(char *);

static void opcionAltaServ()
{
    char auxDescripcion[50];
    if(val_getString(auxDescripcion, "Descripcion? ", "Error",1,50)==0)
    {
        cont_altaServicio(auxDescripcion);
    }
}

static void opcionBajaServ()
{
    char auxId[50];
    int id;
    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        id = atoi(auxId);
        cont_bajaServicio(id);
    }
}

static void opcionModificacionServ()
{
    int id;
    int estado;
    char auxId[50];
    char auxDescripcion[50];
    char auxEstado[50];
    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        id = atoi(auxId);
        if(cont_checkServicio(id)==0)
        {
            val_getString(auxDescripcion, "Descripcion? ", "Error",1,50);
            val_getInt(auxEstado, "Estado? ", "Error",1,50);
            estado = atoi(auxEstado);
            cont_modificarServicio(auxDescripcion, id, estado);
        }
    }
}

static void opcionListadoServ()
{
    cont_listarServicios();
}

void vista_printIdSocio(Socio* auxSocio)
{
    printf("\n\n***SOCIO REGISTRADO CORRECTAMENTE!!!***\n");
    printf("***ID DEL NUEVO SOCIO: %d***", soc_getId(auxSocio));
}

static int comparaSocios(void* pSocioA,void* pSocioB)
{
    if(strcmp(((Socio*)pSocioA)->apellido, ((Socio*)pSocioB)->apellido)==1)
    {
        return 1;
    }
    if(strcmp(((Socio*)pSocioA)->apellido, ((Socio*)pSocioB)->apellido)==-1)
    {
        return -1;
    }

    else
    if(strcmp(((Socio*)pSocioA)->nombre, ((Socio*)pSocioB)->nombre)==1)
    {
        return 2;
    }
    if(strcmp(((Socio*)pSocioA)->nombre, ((Socio*)pSocioB)->nombre)==-1)
    {
        return -2;
    }
    return 0;
}
