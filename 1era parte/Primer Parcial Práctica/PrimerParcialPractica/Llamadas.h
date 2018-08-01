#ifndef LLAMADAS_H_INCLUDED
#define LLAMADAS_H_INCLUDED

#define INFARTO 0
#define ACV 1
#define GRIPE 2

#define LLAMADA_LIBRE 0
#define LLAMADA_PENDIENTE 1
#define LLAMADA_CUMPLIDA 2

#define ARRAY_LENGTH 51

#define MAX_LLAMADAS 5
#define MAX_MOTIVOS 3

#include "Asociados.h"


typedef struct
{
   unsigned char idLlamada;
   unsigned char idAsociado;
   unsigned char idAmbulancia;
   char motivo[ARRAY_LENGTH];
   unsigned char estado;
   int tiempo; //En minutos
   int flagLibre;
   int cont;

}sLlamada;

#endif // LLAMADAS_H_INCLUDED

int llamadas_init(sLlamada* arrayLlamadas, int longitud);
int llamadas_generarId(sLlamada* arrayLlamadas, int longitud);
int llamadas_alta(sLlamada* arrayLlamadas, sAsociado* arrayAsociados, int index, int longitudAsociados, int longitudLlamadas);
int llamadas_buscarIndiceLibre(sLlamada* arrayLlamadas, int longitud);
int llamadas_asignarAmbulancia(sLlamada* arrayLlamadas, sAsociado* arrayAsociados, int longitudLlamadas, int longitudAsociados);
int llamadas_buscarIndicePorId(sLlamada* arrayLlamadas, int id, int longitud);
int llamadas_encontrarIDAsociado(sAsociado* arrayAsociados, int longitudAsociados);
int llamadas_encontrarIDLlamada(sLlamada* arrayLlamadas, int longitud);
void llamadas_printMotivos(void);
int llamadas_printPendientes(sLlamada* arrayLlamadas, int longitud);
int llamadas_printCumplidas(sLlamada* arrayLlamadas, int longitud);
int llamadas_mostrarCantMotivos(sAsociado* arrayAsociados, int longitudAsociados, sLlamada* arrayLlamadas, int longitudLlamadas);
int llamadas_motivosRecurrentes(sAsociado* arrayAsociados, int longitudAsociados, sLlamada* arrayLlamadas, int longitudLlamadas);
int llamadas_checkAmbulancia(sLlamada* arrayLlamadas, char* buffer, char* errorMsg, int longitud);
int llamadas_checkAsociado(sLlamada* arrayLlamadas, int buffer, char* errorMsg, int longitud);

