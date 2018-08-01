#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#endif // INTERFAZ_H_INCLUDED

#include "Socios.h"
#include "ArrayList.h"

int interface_menu(ArrayList* arraySocios, Socio* structSocio);

int interface_alta(ArrayList* arraySocios, Socio* structSocio);
int interface_modificar(ArrayList* arraySocios, Socio* structSocio);
int interface_baja(ArrayList* arraySocios, Socio* structSocio);

int interface_printArraySocios(ArrayList* arraySocios);
int interface_printSocio(Socio* structSocio);


