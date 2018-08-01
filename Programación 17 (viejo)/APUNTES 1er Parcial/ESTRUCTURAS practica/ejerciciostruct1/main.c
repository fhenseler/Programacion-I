#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[50];
    int nota1;
    int nota2;
    int nota3;
    long j;
}alumno;

int ordenar(alumno alu[]);
int mostrar(alumno alu[]);

int main()
{
    alumno alu[50];
    int i;
        for(i = 0; i < 50; i+=2)
        {
                alu[i].nota1 = 10-i;
                alu[i].nota2 = 10-i;
                alu[i].nota3 = 10-i;
        }

        ordenar(alu);
        mostrar(alu);
        return 0;

int ordenar(alumno alu[])
{
    int i, j;
    alumno backup;

    for(i = 0; i < 50-1; i++)
    {
        for(j = i+1; j < 50; j++)
        {
            if(alu[i].nota1 > alu[j].nota2)
            {
                backup = alu[i];
                alu[i] = alu[j];
                alu[j] = backup;

            }
            if(alu[i].nota1 == alu[j].nota2)
            {
               if(alu[i].nota2 > alu[j].nota3)
                {
                    backup = alu[i];
                    alu[i] = alu[j];
                    alu[j] = backup;
                }
            }
        }
    }
                    return 0;
}

int mostrar(alumno alu[])
{
    int i;
    for(i=0; i<50; i++)
    {
        printf("Hello world! %d %c %d %d %d\n", alu[i].legajo, alu[i].nombre,
               alu[i].nota1, alu[i].nota2, alu[i].nota3);
    }
    return 0;
}

}

