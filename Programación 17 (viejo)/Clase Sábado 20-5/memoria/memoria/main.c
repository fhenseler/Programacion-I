#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"


int main()
{
    ePersona* lista[3];
    ePersona* persona1;
    int i;
    int auxInt;
    char auxString[20];


    for(i=0;i<3;i++)
    {
        printf("Ingrese dni: ");
        scanf("%d", &auxInt);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxString);

        persona1 = newPersonaParametros(auxInt,auxString);

        lista[i] = persona1;



    }

     for(i=0;i<3;i++)
    {

    personaToString(lista[i]);

    }


    return 0;
}

