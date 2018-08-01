#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entidad.h"
#include "Validar.h"

static int ent1_buscarIndicePorID(sEntidad1* entidad, int len, int id);
static int ent1_generarProximoID(sEntidad1* entidad, int len);
static int ent1_buscarIndiceLibre(sEntidad1* entidad, int len);

int ent1_init(sEntidad1* entidad, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        entidad[i].flagOcupado = 0; //LIBRE
    }
        return 0;
}

static int ultimoValorIDAutoincrementable = -1;
int ent1_generarProximoID(sEntidad1* entidad, int len)
{
    //otra manera
    ultimoValorIDAutoincrementable++;
    return ultimoValorIDAutoincrementable;
}


int ent1_buscarIndiceLibre(sEntidad1* entidad, int len)
{
    //Me devuelve el index del primer item vacio del array. La voy a usar para el ALTA
    int i;
    int retorno = -1;
    for(i = 0; i < len; i++)
    {
        if(entidad[i].flagOcupado == 0)
        {
            retorno = i;
            break;
        }
    }
            return retorno;
}

int ent1_alta(sEntidad1* entidad, int len)
{
    int retorno = -1;
    //  1) Obtener index libre para poder guardar los datos (ALTA)
    //  2) Generar ID
    //  3) Pedir datos al usuario (VALIDAR)
    //  4) Cargar datos en item vacio

    int indexVacio = ent1_buscarIndiceLibre(entidad, len); //1)
    if(indexVacio >= 0)
    {
        int idNuevo = ent1_generarProximoID(entidad, len); //2)
        //3) Pido datos al usuario (depende del problema)

        char bufferAuxNombre[50];
        if(val_getNombre(bufferAuxNombre, "Ingrese Nombre", "Nombre invalido", 3, 50)!= -1)
        {
            //Campo bien cargado
            //Cargo datos en el item
            entidad[indexVacio].flagOcupado = 1;
            entidad[indexVacio].id = idNuevo;
            strncpy(entidad[indexVacio].a, bufferAuxNombre, 50);
            retorno = 0;
        }
    }
            return retorno;
}

int ent1_buscarIndicePorID(sEntidad1* entidad, int len, int id)
{
    int i;
    int retorno = -1;

        if(entidad != NULL && len > 0 && id >= 0)
        {
            for(i = 0; i < len; i++)
            {
                if(entidad[i].flagOcupado == 1)//ocupado
                {
                    if(id == entidad[i].id)
                    {
                        retorno = i;
                        break;
                    }
                }
            }
        }
                        return retorno;
}

int ent1_modificar(sEntidad1* entidad, int len, int id)
{
    int retorno = -1;
    //1) Busco la posicion donde esta el ID
    //2) Pido datos nuevos
    //3) Cargo en los campos

    int index = ent1_buscarIndicePorID(entidad, len, id);
    if(index >= 0)
    {
        //El ID esta!!
        //Pido datos a modificar
        char bufferAux[50];
        if(val_getUnsignedInt(bufferAux, "Ingrese edad: ", "ERROR", 3, 50) != -1)
        {
            entidad[index].b = atoi(bufferAux);
            retorno = 0;
        }
    }
            return retorno;
}

int ent1_baja(sEntidad1* entidad, int len, int id)
{
    int retorno = -1;
    int index = ent1_buscarIndicePorID(entidad, len, id);
    if(index >= 0)
    {
        entidad[index].flagOcupado = 0;//FALSE -> EL INDEX ESTA LIBRE
        retorno = 0;
    }
        return retorno;
}

int ent1_buscarIndicePorDNI(sEntidad1* entidad, int len, char* DNI)
{
    int i;
    int retorno = -1;

    for(i = 0; i < len; i++)
    {
        if(entidad[i].flagOcupado == 1)
        {
            if(strcmp(entidad[i].a, DNI) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
                return retorno;
}
