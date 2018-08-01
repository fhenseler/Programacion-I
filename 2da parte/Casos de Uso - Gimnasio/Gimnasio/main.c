#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"

int main()
{
    Socio* structSocio = socio_new();

    ArrayList* arraySocios = al_newArrayList();

    interface_menu(arraySocios, structSocio);

	return EXIT_SUCCESS;
}
