#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"

int main()
{
    ArrayList* listaEmpleados;

    listaEmpleados = al_new();
    al_add(listaEmpleados, empleado_newConstructor());
    al_add(listaEmpleados, empleado_newConstructor());
    al_add(listaEmpleados, empleado_newConstructor());

    al_debugShow(listaEmpleados);

    return 0;
}
