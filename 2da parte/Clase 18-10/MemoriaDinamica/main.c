#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"

//GESTION DE MEMORIA DINAMICA

int main()
{
//    Empleado *pEmpleado[50];
    void *pGenerico[50]; //ARRAY DE PUNTEROS A VOID

    int i;

    for(i = 0; i < 50; i++)
    {
//        pEmpleado[i] = empleado_newConstructor("Juan", "Perez", i);
        pGenerico[i] = empleado_newConstructor("Juan", "Perez", i);
    }
//        empleado_debugPrint(pEmpleado[33]);
//        empleado_debugPrint(pEmpleado[42]);

        empleado_debugPrint(pGenerico[33]);
        empleado_debugPrint(pGenerico[42]);

        return 0;
}
