#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "Servicio.h"
#include "SocioServicio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static int opcionListado();

static void opcionAltaServ();
static void opcionBajaServ();
static void opcionModificacionServ();
static int opcionListadoServ();

static void opcionAltaSocServ();
static void opcionBajaSocServ();
static int opcionListadoSocServ();

static int opcionListadoInforme();

static int comparaSocios(void* pSocioA,void* pSocioB);


int vista_init(int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 5)
    {
        system("cls");
        val_getInt(buffer, MENU_PPAL_ES2, MENU_PPAL_ERROR_ES,2,9);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                val_getInt(buffer, MENU_PPAL_ES3, MENU_PPAL_ERROR_ES,2,9);
                option = atoi(buffer);
                switch(option)
                {
                    case 1:
                        opcionListado();
                        printf("\n");
                        getchar();
                        break;
                    case 2:
                        opcionAlta();
                        printf("\n");
                        getchar();
                        break;
                    case 3:
                        if(opcionListado()==0)
                        {
                           opcionBaja();
                        }
                        printf("\n");
                        getchar();
                        break;
                    case 4:
                        if(opcionListado()==0)
                        {
                           opcionModificacion();
                        }
                        printf("\n");
                        getchar();
                        break;
                    default:
                        break;
                }
                        break;
            case 2:
                val_getInt(buffer, MENU_PPAL_ES4, MENU_PPAL_ERROR_ES,2,9);
                option = atoi(buffer);
                switch(option)
                {
                case 1:
                    opcionListadoServ();
                    printf("\n");
                    getchar();
                    break;
                case 2:
                    opcionAltaServ();
                    printf("\n");
                    getchar();
                    break;
                case 3:
                    if(opcionListadoServ()==0)
                    {
                       opcionBajaServ();
                    }
                    printf("\n");
                    getchar();
                    break;
                case 4:
                    if(opcionListadoServ()==0)
                    {
                        opcionModificacionServ();
                    }
                        printf("\n");
                        getchar();
                        break;
                default:
                        break;
                }
                        break;
            case 3:
                val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,9);
                option = atoi(buffer);
                switch(option)
                {
                    case 1:
                        opcionListadoSocServ();
                        printf("\n");
                        getchar();
                        break;
                    case 2:
                        printf("\n***SOCIOS***\n");
                        if(opcionListado()==0)
                        {
                            printf("\n***SERVICIOS***\n");
                            if(opcionListadoServ()==0)
                            {
                                opcionAltaSocServ();
                            }
                        }
                        printf("\n");
                        getchar();
                        break;
                    case 3:
                        if(opcionListadoSocServ()==0)
                        {
                            opcionBajaSocServ();
                        }
                        printf("\n");
                        getchar();
                        break;
                    default:
                        break;
                }
                        break;
            case 4:
                val_getInt(buffer, MENU_PPAL_ES5, MENU_PPAL_ERROR_ES,2,9);
                option = atoi(buffer);
                switch(option)
                {
                    case 1:
                        opcionListadoInforme();
                        printf("\n");
                        getchar();
                        break;
                    default:
                        break;
                }
                        break;
            }
    }
    return 0;
}

int vista_mostrarSocios(ArrayList* pListaSocios)
{
    int retorno = 0;
    int i;
    int cont = 0;
    Socio* auxSocio;
    printf("\nNOMBRE\t\tAPELLIDO\tID\t\tDNI\t\n");
    for(i=0;i<al_len(pListaSocios);i++)
    {
        al_sort(pListaSocios, comparaSocios, 1);
        auxSocio = al_get(pListaSocios,i);
        if(auxSocio->estado == SOCIO_ESTADO_ACTIVO)
        {
            cont++;
            printf("\n%-10s\t%-10s\t%-10d\t%-10s\t\n",soc_getNombre(auxSocio),
                    soc_getApellido(auxSocio),soc_getId(auxSocio),soc_getDni(auxSocio));
        }
    }
        if(cont == 0)
        {
           printf("\nNo hay socios registrados en el sistema!!!\n");
           retorno = -1;
        }
           return retorno;
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

static int opcionListado()
{
    int retorno = -1;

    if(cont_listarSocios()==0)
    {
        retorno = 0;
    }

    return retorno;
}

//---------------------------------------------------------------------------------------

int vista_mostrarServicios(ArrayList* pListaServicios)
{
    int retorno = 0;
    int i;
    int contServicios = 0;
    Servicio* auxServicio;
    printf("\nDESCRIPCION\tID\t\n");
    for(i=0;i<al_len(pListaServicios);i++)
    {
        auxServicio = al_get(pListaServicios,i);
        if(auxServicio->estado == SERVICIO_ESTADO_ACTIVO)
        {
            printf("\n%-10s\t%-10d\n",serv_getDescripcion(auxServicio),serv_getId(auxServicio));
            contServicios++;
        }
    }
        if(contServicios == 0)
        {
            printf("No hay ningun servicio activo!");
            retorno = -1;
        }
            return retorno;
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
    char resp[50];

    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        if(cont_checkServicio(atoi(auxId))==0)
        {
            printf("\nDesea dar de baja a este servicio? (Y/N)");
            myFgets(resp, 50, stdin);
                if((strcmp(resp, "y")==0) || (strcmp(resp, "Y")==0))
                {
                    id = atoi(auxId);
                    cont_bajaServicio(id);
                    printf("\n***SERVICIO ELIMINADO CORRECTAMENTE***");
                }
                else
                {
                    printf("\n***EL SERVICIO NO FUE ELIMINADO***");
                }
        }
        else
        {
            printf("\nError! ID de servicio inexistente");
        }
    }
}

static void opcionModificacionServ()
{
    int id;
    int estado = 1;
    char auxId[50];
    char auxDescripcion[50];
//    char auxEstado[50];
    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        id = atoi(auxId);
        if(cont_checkServicio(id)==0)
        {
            val_getString(auxDescripcion, "Descripcion? ", "Error",1,50);
//            val_getInt(auxEstado, "Estado? ", "Error",1,50);
//            estado = atoi(auxEstado);
            cont_modificarServicio(auxDescripcion, id, estado);
            printf("\n***DATOS MODIFICADOS CORRECTAMENTE***");
        }
        else
        {
            printf("\nError! ID de servicio inexistente");
        }
    }
}

static int opcionListadoServ()
{
    int retorno = -1;
    if(cont_listarServicios()==0)
    {
        retorno = 0;
    }
        return retorno;
}

void vista_printIdSocio(Socio* auxSocio)
{
    printf("\n\n***SOCIO REGISTRADO CORRECTAMENTE!!!***\n");
    printf("***ID DEL NUEVO SOCIO: %d***", soc_getId(auxSocio));
}

void vista_printIdServicio(Servicio* auxServicio)
{
    printf("\n\n***SERVICIO REGISTRADO CORRECTAMENTE!!!***\n");
    printf("***ID DEL NUEVO SERVICIO: %d***", serv_getId(auxServicio));
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

//---------------------------------------------------------------------------------------


int vista_mostrarSocioServicio(ArrayList* pListaSocioServicio, ArrayList* pListaSocio)
{
    int retorno = 0;
    int i;
    int cont = 0;
    SocioServicio* auxSocioServicio;
    Socio* auxSocio;
    int idSoc;
    printf("\nID SOCIO\tID SERVICIO\tID RELACION\t\n");
    for(i=0;i<al_len(pListaSocioServicio);i++)
    {
        auxSocioServicio = al_get(pListaSocioServicio, i);
        if(auxSocioServicio->estado == SOCIOSERVICIO_ESTADO_ACTIVO)
        {
            idSoc = socserv_getIdSocio(auxSocioServicio);
            auxSocio = soc_findById(pListaSocio, idSoc);
            if(auxSocio->estado == SOCIO_ESTADO_ACTIVO)
            {
                 printf("\n%-10d\t%-10d\t%-10d\t\n",socserv_getIdSocio(auxSocioServicio),socserv_getIdServicio(auxSocioServicio),socserv_getId(auxSocioServicio));
            }
            cont++;
        }
    }
        if(cont == 0)
        {
            printf("\nNo hay socios inscriptos a ningun servicio!!\n");
            retorno = -1;
        }
            return retorno;
}

int vista_mostrarInforme(ArrayList* pListaSocio)
{
    int retorno = 0;
    int i;
    int cont = 0;
    Socio* auxSocio;
    int max = 0;
    int idSocioMax;

    printf("\nID SOCIO\tCANT SERVICIOS\t\n");
    for(i=0;i<al_len(pListaSocio);i++)
    {
            auxSocio = al_get(pListaSocio, i);
            if(auxSocio->estado == SOCIO_ESTADO_ACTIVO)
            {
               printf("\n%-10d\t%-10d\t\n",soc_getId(auxSocio), soc_getContServicios(auxSocio));
               if(soc_getContServicios(auxSocio) > max)
               {
                   max = soc_getContServicios(auxSocio);
                   idSocioMax = soc_getId(auxSocio);
               }
                    cont++;
            }
    }
        if(cont == 0)
        {
            printf("\nNo hay socios inscriptos a ningun servicio!!\n");
            retorno = -1;
        }
        else
        {
            printf("\nEl ID del socio con mas servicios es: %d con %d suscripciones\n", idSocioMax, max);
        }
        return retorno;
}


void mostrarError(char *);

static void opcionAltaSocServ()
{
    char auxIdSocio[50];
    char auxIdServicio[50];
    int idSoc;
    int idServ;

    if(val_getInt(auxIdSocio, "\nID Socio? ", "Error",1,50)==0)
    {
        idSoc = atoi(auxIdSocio);
        if(val_getInt(auxIdServicio, "\nID Servicio? ", "Error",1,50)==0)
        {
            idServ = atoi(auxIdServicio);
            cont_altaSocioServicio(idSoc, idServ);
        }
    }
}

static void opcionBajaSocServ()
{
    char auxId[50];
    int id;
    char resp[50];

    if(val_getInt(auxId, "\nID Relacion? ", "\nError",1,50)==0)
    {
        if(cont_checkSocioServicio(atoi(auxId))==0)
        {
            printf("\nDesea dar de baja a este socio de este servicio? (Y/N)");
            myFgets(resp, 50, stdin);
                if((strcmp(resp, "y")==0) || (strcmp(resp, "Y")==0))
                {
                    id = atoi(auxId);
                    cont_bajaSocioServicio(id);
                    printf("\n***SOCIO DADO DE BAJA CORRECTAMENTE DEL SERVICIO***\n");
                }
                else
                {
                    printf("\n***EL SOCIO NO FUE DADO DE BAJA DEL SERVICIO***\n");
                }
        }
        else
        {
            printf("\nError! ID de relacion inexistente\n");
        }
    }
}


static int opcionListadoSocServ()
{
    int retorno = -1;

    if(cont_listarSocioServicio()==0)
    {
        retorno = 0;
    }
    return retorno;
}

static int opcionListadoInforme()
{
    int retorno = -1;

    if(cont_listarInforme()==0)
    {
        retorno = 0;
    }
    return retorno;
}

void vista_printIdSocioServicio(SocioServicio* auxSocioServicio)
{
    printf("\n\n***SOCIO ANOTADO CORRECTAMENTE AL SERVICIO!!!***\n");
    printf("\n***ID DE LA RELACION: %d***\n", socserv_getId(auxSocioServicio));
}

void vista_printErrorSocioServicio()
{
    printf("\n***ERROR! ID DE SOCIO O ID DE SERVICIO INVALIDO***\n");
}

void vista_printErrorSocioServicio2()
{
    printf("\nError! El socio ya esta anotado a ese servicio!\n");
}
