#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
    char color[7];
    long j;

}Coordenada;

int ordenar(Coordenada aux[]);
int mostrar(Coordenada aux[]);

int main()
{
    Coordenada aux[10];
    int i;


    for(i=0; i<10; i=i+2)
    {
        aux[i].x = 10-i;
        aux[i+1].x = 10-i;
        aux[i].y = 8;
        aux[i+1].y = 7;


        strcpy(aux[i].color,"0AAB09");
        strcpy(aux[i+1].color,"0AAB09");
    }

    ordenar(aux);
    mostrar(aux);


    return 0;
}
int ordenar(Coordenada aux[])
{
    int i,j;
    Coordenada bkp;

    for(i=0; i<10-1; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if(aux[i].x > aux[j].x)
            {
                bkp = aux[i];
                aux[i] = aux[j];
                aux[j] = bkp;

            }
            else if(aux[i].x == aux[j].x)
            {
               if(aux[i].y > aux[j].y)
                {
                    bkp = aux[i];
                    aux[i] = aux[j];
                    aux[j] = bkp;

                }
            }

        }
    }


    return 0;
}

int mostrar(Coordenada aux[])
{
    int i;
    for(i=0; i<10; i++)
    {
        printf("Hello world! %d %d %s\n",aux[i].x,aux[i].y,aux[i].color);
    }
    return 0;
}

