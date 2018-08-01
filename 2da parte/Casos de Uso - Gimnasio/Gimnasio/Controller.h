#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Interface.h"

int controller_alta(ArrayList* arraySocios, char *nombre, char *apellido, char *dni, int id, int estado);
int controller_modificar(ArrayList* arraySocios, Socio* structSocio, char *nombre, char *apellido);
int controller_baja(ArrayList* arraySocios, int estado);

#endif // CONTROLLER_H_INCLUDED
