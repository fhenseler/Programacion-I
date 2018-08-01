#include "Persona.h"
#include <stdlib.h>
ePersona* newPersona()
{
    ePersona* persona;

    persona =  (ePersona*) malloc(sizeof(ePersona));


    return persona;
}

ePersona* newPersonaParametros(int dni, char nombre[])
{
    ePersona* persona;

    persona = newPersona();

    if(persona!=NULL)
    {
         persona->dni=dni;
        strcpy(persona->nombre, nombre);
    }



    return persona;
}

void personaToString(ePersona* this)
{
    printf("%d--%s\n", this->dni, this->nombre);
}
