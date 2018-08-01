#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct coordenada{
    int x;
    int y;
    int z;
    int t;
    int u;
    char color[7];
};

int main()
{
            struct coordenada aux[10];
            printf("Ingrese coord X: ");
            scanf("%d", &aux[0].x);
            printf("Ingrese coord Y: ");
            scanf("%d", &aux[0].y);
            printf("Ingrese coord Z: ");
            scanf("%d", &aux[0].z);
            printf("Ingrese coord T: ");
            scanf("%d", &aux[0].t);
            printf("Ingrese coord U: ");
            scanf("%d", &aux[0].u);
            strcpy(aux.color, "0AAB09");

            printf("Las coord ingresadas son: %d, %d, %d, %d, %d", aux[0].x, aux.y,
                   aux.z, aux.t, aux.u, aux.color);

                    return 0;
}
