#include <stdio.h>
#include <stdlib.h>
#include "Entidad.h"
#include "Entidad2.h"
#include "Informes.h"

void imprimirTodo(Entidad1* arrayEntidad1, int lenEntidad1, Entidad2* arrayEntidad2, int lenEntidad2)
{
    int indexE2;
    for(indexE2 = 0; indexE2 < lenEntidad2; i++)
    {
        if(arrayEntidad2[i].flagOcupado == 1)
        {
            int idE1 = arrayEntidad2[i].idEntidad1;
            int indexE1 = ent1_buscarIndicePorID(arrayEntidad1, lenEntidad1, idE1);

            printf("%d\t%s | %d\t%s", arrayEntidad1[indexE1].id, arrayEntidad1[indexE1].a,
                   arrayEntidad2[indexE2].id, arrayEntidad2[indexE2].a);
        }
    }
}
