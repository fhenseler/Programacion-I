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

static void opcionAltaAlq();
static void opcionBajaAlq();
static void opcionModificacionAlq();
static int opcionListadoAlq();

static void opcionAltaCliAlq();
static void opcionBajaCliAlq();
static int opcionListadoCliAlq();

static int opcionListadoInforme();

static int comparaClientes(void* pClienteA,void* pClienteB);


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
                    opcionListadoAlq();
                    printf("\n");
                    getchar();
                    break;
                case 2:
                    opcionAltaAlq();
                    printf("\n");
                    getchar();
                    break;
                case 3:
                    if(opcionListadoAlq()==0)
                    {
                       opcionBajaAlq();
                    }
                    printf("\n");
                    getchar();
                    break;
                case 4:
                    if(opcionListadoAlq()==0)
                    {
                        opcionModificacionAlq();
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
                        opcionListadoCliAlq();
                        printf("\n");
                        getchar();
                        break;
                    case 2:
                        printf("\n***ClienteS***\n");
                        if(opcionListado()==0)
                        {
                            printf("\n***Alquileres***\n");
                            if(opcionListadoAlq()==0)
                            {
                                opcionAltaCliAlq();
                            }
                        }
                        printf("\n");
                        getchar();
                        break;
                    case 3:
                        if(opcionListadoCliAlq()==0)
                        {
                            opcionBajaCliAlq();
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

int vista_mostrarClientes(ArrayList* pListaClientes)
{
    int retorno = 0;
    int i;
    int cont = 0;
    Cliente* auxCliente;
    printf("\nID\t\tNOMBRE\t\tAPELLIDO\tDNI\t\n");
    for(i=0;i<al_len(pListaClientes);i++)
    {
        al_sort(pListaClientes, comparaClientes, 1);
        auxCliente = al_get(pListaClientes,i);
        if(auxCliente->estado == CLIENTE_ESTADO_ACTIVO)
        {
            cont++;
            printf("\n%-10d\t%-10s\t%-10s\t%-10s\t\n",cli_getId(auxCliente),
                    cli_getNombre(auxCliente),cli_getApellido(auxCliente),cli_getDni(auxCliente));
        }
    }
        if(cont == 0)
        {
           printf("\nNo hay Clientes registrados en el sistema!!!\n");
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
               if(cont_checkClienteByDni(auxDni)!=0)
               {
                  cont_altaCliente(auxNombre,auxApellido,auxDni);
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
        if(cont_checkCliente(atoi(auxId))==0)
        {
            printf("\nDesea dar de baja a este Cliente? (Y/N)");
            myFgets(resp, 50, stdin);
                if((strcmp(resp, "y")==0) || (strcmp(resp, "Y")==0))
                {
                    id = atoi(auxId);
                    cont_bajaCliente(id);
                    printf("\n***Cliente ELIMINADO CORRECTAMENTE***");
                }
                else
                {
                    printf("\n***EL Cliente NO FUE ELIMINADO***");
                }
        }
        else
        {
            printf("\nError! ID de Cliente inexistente");
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
        if(cont_checkCliente(id)==0)
        {
            val_getString(auxNombre, "Nombre? ", "Error",1,50);
            val_getString(auxApellido, "Apellido? ", "Error",1,50);
            val_getInt(auxDni, "DNI? ", "Error",1,50);
//            val_getInt(auxEstado, "Estado? ", "Error",1,50);
//            estado = atoi(auxEstado);
            cont_modificarCliente(auxNombre, auxApellido, auxDni, id, 1);
            printf("\n***DATOS MODIFICADOS CORRECTAMENTE***");
        }
        else
        {
            printf("\nError! ID de Cliente inexistente");
        }

    }
}

static int opcionListado()
{
    int retorno = -1;

    if(cont_listarClientes()==0)
    {
        retorno = 0;
    }

    return retorno;
}

//---------------------------------------------------------------------------------------

int vista_mostrarAlquileres(ArrayList* pListaAlquileres)
{
    int retorno = 0;
    int i;
    int contAlquileres = 0;
    Alquiler* auxAlquiler;
    printf("\nID ALQ\t\n");
    for(i=0;i<al_len(pListaAlquileres);i++)
    {
        auxAlquiler = al_get(pListaAlquileres,i);
        if(auxAlquiler->estado == ALQUILER_ESTADO_ACTIVO)
        {
            printf("\n%-10d\n",alq_getId(auxAlquiler));
            contAlquileres++;
        }
    }
        if(contAlquileres == 0)
        {
            printf("No hay ningun Alquiler activo!");
            retorno = -1;
        }
            return retorno;
}


void mostrarError(char *);

static void opcionAltaAlq()
{
    char auxDescripcion[50];
    if(val_getString(auxDescripcion, "Descripcion? ", "Error",1,50)==0)
    {
        cont_altaAlquiler(auxDescripcion);
    }
}

static void opcionBajaAlq()
{
    char auxId[50];
    int id;
    char resp[50];

    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        if(cont_checkAlquiler(atoi(auxId))==0)
        {
            printf("\nDesea dar de baja a este Alquiler? (Y/N)");
            myFgets(resp, 50, stdin);
                if((strcmp(resp, "y")==0) || (strcmp(resp, "Y")==0))
                {
                    id = atoi(auxId);
                    cont_bajaAlquiler(id);
                    printf("\n***Alquiler ELIMINADO CORRECTAMENTE***");
                }
                else
                {
                    printf("\n***EL Alquiler NO FUE ELIMINADO***");
                }
        }
        else
        {
            printf("\nError! ID de Alquiler inexistente");
        }
    }
}

static void opcionModificacionAlq()
{
    int id;
    int estado = 1;
    char auxId[50];
    char auxDescripcion[50];
//    char auxEstado[50];
    if(val_getInt(auxId, "ID? ", "Error",1,50)==0)
    {
        id = atoi(auxId);
        if(cont_checkAlquiler(id)==0)
        {
            val_getString(auxDescripcion, "Descripcion? ", "Error",1,50);
//            val_getInt(auxEstado, "Estado? ", "Error",1,50);
//            estado = atoi(auxEstado);
            cont_modificarAlquiler(auxDescripcion, id, estado);
            printf("\n***DATOS MODIFICADOS CORRECTAMENTE***");
        }
        else
        {
            printf("\nError! ID de Alquiler inexistente");
        }
    }
}

static int opcionListadoAlq()
{
    int retorno = -1;
    if(cont_listarAlquileres()==0)
    {
        retorno = 0;
    }
        return retorno;
}

void vista_printIdCliente(Cliente* auxCliente)
{
    printf("\n\n***Cliente REGISTRADO CORRECTAMENTE!!!***\n");
    printf("***ID DEL NUEVO Cliente: %d***", cli_getId(auxCliente));
}

void vista_printIdAlquiler(Alquiler* auxAlquiler)
{
    printf("\n\n***Alquiler REGISTRADO CORRECTAMENTE!!!***\n");
    printf("***ID DEL NUEVO Alquiler: %d***", alq_getId(auxAlquiler));
}

static int comparaClientes(void* pClienteA,void* pClienteB)
{
    if(strcmp(((Cliente*)pClienteA)->apellido, ((Cliente*)pClienteB)->apellido)==1)
    {
        return 1;
    }
    if(strcmp(((Cliente*)pClienteA)->apellido, ((Cliente*)pClienteB)->apellido)==-1)
    {
        return -1;
    }

    else
    if(strcmp(((Cliente*)pClienteA)->nombre, ((Cliente*)pClienteB)->nombre)==1)
    {
        return 2;
    }
    if(strcmp(((Cliente*)pClienteA)->nombre, ((Cliente*)pClienteB)->nombre)==-1)
    {
        return -2;
    }
    return 0;
}

//---------------------------------------------------------------------------------------


int vista_mostrarClienteAlquiler(ArrayList* pListaClienteAlquiler, ArrayList* pListaCliente)
{
    int retorno = 0;
    int i;
    int cont = 0;
    ClienteAlquiler* auxClienteAlquiler;
    Cliente* auxCliente;
    int idcli;
    printf("\nID Cliente\tID Alquiler\tID RELACION\t\n");
    for(i=0;i<al_len(pListaClienteAlquiler);i++)
    {
        auxClienteAlquiler = al_get(pListaClienteAlquiler, i);
        if(auxClienteAlquiler->estado == CLIENTEALQUILER_ESTADO_ACTIVO)
        {
            idcli = clialq_getIdCliente(auxClienteAlquiler);
            auxCliente = cli_findById(pListaCliente, idcli);
            if(auxCliente->estado == CLIENTE_ESTADO_ACTIVO)
            {
                 printf("\n%-10d\t%-10d\t%-10d\t\n",clialq_getIdCliente(auxClienteAlquiler),clialq_getIdAlquiler(auxClienteAlquiler),clialq_getId(auxClienteAlquiler));
            }
            cont++;
        }
    }
        if(cont == 0)
        {
            printf("\nNo hay Clientes inscriptos a ningun Alquiler!!\n");
            retorno = -1;
        }
            return retorno;
}

int vista_mostrarInforme(ArrayList* pListaCliente)
{
    int retorno = 0;
    int i;
    int cont = 0;
    Cliente* auxCliente;
    int max = 0;
    int idClienteMax;

    printf("\nID Cliente\tCANT Alquileres\t\n");
    for(i=0;i<al_len(pListaCliente);i++)
    {
            auxCliente = al_get(pListaCliente, i);
            if(auxCliente->estado == CLIENTE_ESTADO_ACTIVO)
            {
               printf("\n%-10d\t%-10d\t\n",cli_getId(auxCliente), cli_getContAlquileres(auxCliente));
               if(cli_getContAlquileres(auxCliente) > max)
               {
                   max = cli_getContAlquileres(auxCliente);
                   idClienteMax = cli_getId(auxCliente);
               }
                    cont++;
            }
    }
        if(cont == 0)
        {
            printf("\nNo hay Clientes inscriptos a ningun Alquiler!!\n");
            retorno = -1;
        }
        else
        {
            printf("\nEl ID del Cliente con mas Alquileres es: %d con %d suscripciones\n", idClienteMax, max);
        }
        return retorno;
}


void mostrarError(char *);

static void opcionAltaCliAlq()
{
    char auxIdCliente[50];
    char auxIdAlquiler[50];
    int idcli;
    int idAlq;

    if(val_getInt(auxIdCliente, "\nID Cliente? ", "Error",1,50)==0)
    {
        idcli = atoi(auxIdCliente);
        if(val_getInt(auxIdAlquiler, "\nID Alquiler? ", "Error",1,50)==0)
        {
            idAlq = atoi(auxIdAlquiler);
            cont_altaClienteAlquiler(idcli, idAlq);
        }
    }
}

static void opcionBajaCliAlq()
{
    char auxId[50];
    int id;
    char resp[50];

    if(val_getInt(auxId, "\nID Relacion? ", "\nError",1,50)==0)
    {
        if(cont_checkClienteAlquiler(atoi(auxId))==0)
        {
            printf("\nDesea dar de baja a este Cliente de este Alquiler? (Y/N)");
            myFgets(resp, 50, stdin);
                if((strcmp(resp, "y")==0) || (strcmp(resp, "Y")==0))
                {
                    id = atoi(auxId);
                    cont_bajaClienteAlquiler(id);
                    printf("\n***Cliente DADO DE BAJA CORRECTAMENTE DEL Alquiler***\n");
                }
                else
                {
                    printf("\n***EL Cliente NO FUE DADO DE BAJA DEL Alquiler***\n");
                }
        }
        else
        {
            printf("\nError! ID de relacion inexistente\n");
        }
    }
}


static int opcionListadoCliAlq()
{
    int retorno = -1;

    if(cont_listarClienteAlquiler()==0)
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

void vista_printIdClienteAlquiler(ClienteAlquiler* auxClienteAlquiler)
{
    printf("\n\n***Cliente ANOTADO CORRECTAMENTE AL Alquiler!!!***\n");
    printf("\n***ID DE LA RELACION: %d***\n", clialq_getId(auxClienteAlquiler));
}

void vista_printErrorClienteAlquiler()
{
    printf("\n***ERROR! ID DE Cliente O ID DE Alquiler INVALIDO***\n");
}

void vista_printErrorClienteAlquiler2()
{
    printf("\nError! El Cliente ya esta anotado a ese Alquiler!\n");
}
