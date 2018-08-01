#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int edad;
    char nombre[20];
}S_Persona;

//struct S_Persona
//{
//    int edad;
//    char nombre[20];
//};
//typedef struct S_Persona Persona;

int cargarPersona(S_Persona* pPersona)
{
    pPersona->edad = 25;
    strncpy(pPersona->nombre, "Federico", 20);
    return 1;
}

void printPersona(S_Persona* pPersona)
{
    printf("\n%d --- %s", pPersona->edad, pPersona->nombre);
}

int main()
{
    S_Persona persona;

    cargarPersona(&persona);

    printf("EDAD --- NOMBRE");
    printPersona(&persona);

    return 0;
}
