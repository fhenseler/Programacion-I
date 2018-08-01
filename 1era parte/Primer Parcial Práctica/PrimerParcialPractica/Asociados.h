#ifndef EMERGENCIAS_H_INCLUDED
#define EMERGENCIAS_H_INCLUDED

#define ARRAY_LENGTH 51
#define ASOCIADO_LIBRE 1
#define ASOCIADO_OCUPADO 2

#define MAX_ASOCIADOS 5

typedef struct
{
    char nombre[ARRAY_LENGTH];
    char apellido[ARRAY_LENGTH];
    int dni;
    int edad;
    unsigned char estado;
    unsigned char idAsociado;
    int cantLlamados;
    int flagLibre;
}sAsociado;

#endif // EMERGENCIAS_H_INCLUDED

int asociado_init(sAsociado* arrayAsociados, int longitud);
int asociado_alta(sAsociado* arrayAsociados, int index, int longitud);
int asociado_baja(sAsociado* arrayAsociados);
int asociado_modificar(sAsociado* arrayAsociados);
int asociado_generarNuevoId(sAsociado* arrayAsociados, int longitud);
int asociado_buscarIndicePorId(sAsociado* arrayAsociados, int id, int longitud);
int asociado_buscarIndiceLibre(sAsociado* arrayAsociados, int longitud);
int asociado_print(sAsociado* arrayAsociados, int longitud);
void asociado_cargar(sAsociado* arrayAsociados, int longitud);
int asociado_checkDNI(sAsociado* arrayAsociados, char* buffer, char* errorMsg, int longitud);
int asociado_ordenarPorNombreYDNI(sAsociado* arrayAsociados, int longitud);

