#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Controller.h"

ArrayList* arraySocios;

int controller_alta(ArrayList* arraySocios, char *nombre, char *apellido, char *dni, int id, int estado)
{
    int retorno = -1;
    Socio* auxSocio;

    if(arraySocios != NULL)
    {
        auxSocio = socio_newConst(nombre, apellido, dni, id, estado);
        arraySocios->add(arraySocios, auxSocio);
        retorno = 0;
    }
        return retorno;
}

int controller_modificar(ArrayList* arraySocios, Socio* structSocio, char *nombre, char *apellido)
{
    int retorno = -1;

    if(arraySocios != NULL && structSocio != NULL)
    {
        socio_setNombre(structSocio, nombre);
        socio_setApellido(structSocio, apellido);
        al_add(arraySocios, structSocio);
        retorno = 0;
    }
        return retorno;
}

int controller_baja(ArrayList* arraySocios, int estado)
{
    int retorno = -1;
//    Socio* auxSocio;

    if(arraySocios != NULL)
    {
//        socio_findById(arraySocios, socio_getId(auxSocio));
//        socio_setEstado(auxSocio, estado);
    }
        return retorno;
}
