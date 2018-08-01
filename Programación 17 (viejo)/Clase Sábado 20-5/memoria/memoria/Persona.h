

typedef struct
{
    int dni;
    char nombre[30];


} ePersona;

ePersona* newPersona(); //Constructor por defecto
ePersona* newPersonaParametros(int, char[]);//Constructor parametrizado

void personaToString(ePersona*);
