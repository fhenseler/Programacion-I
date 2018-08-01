#include <stdio.h>
#include <stdlib.h>
#include "Entidad.h"
#include "Entidad2.h"
#include "Validar.h"

#define LEN_ENTIDADES1 50
#define LEN_ENTIDADES2 50

int main()
{
    sEntidad1 listaEntidades1[LEN_ENTIDADES1];
    sEntidad2 listaEntidades2[LEN_ENTIDADES2];

    ent1_init(listaEntidades1, LEN_ENTIDADES1);
    ent2_init(listaEntidades2, LEN_ENTIDADES2);

    while(1)
    {
        char opcion[50];

        printf("1) Opcion 1");
        printf("2) Opcion 2");
        printf("3) Opcion 3");

        if(val_getUnsignedInt(opcion, "Elija opcion: ", "ERROR", 3, 50)==0)
        {
            int opc = atoi(opcion);
            switch(opc)
            {
                case 1:
                        break;
            }
        }
    }
                        return 0;
}
