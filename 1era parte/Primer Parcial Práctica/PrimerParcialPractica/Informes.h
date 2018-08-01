#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#define ARRAY_LENGTH 51
#define MAX_INFORMES 5

#include "Asociados.h"
#include "Llamadas.h"

typedef struct
{
   unsigned char idLlamada;
   unsigned char idAsociado;
}sInformes;

#endif // INFORMES_H_INCLUDED

int informes_init(sInformes* arrayInformes, int longitud);
int informes_asociadoMaxLlamados(sLlamada* arrayLlamada, sAsociado* arrayAsociado, int longitudLlamadas, int longitudAsociados);
int informes_motivoMaxDemora(sLlamada* arrayLlamada, int longitudLlamada);
int informes_motivoMax(sLlamada* arrayLlamada, int longitud);
int informes_asociadoMaxLlamados(sLlamada* arrayLlamadas, sAsociado* arrayAsociados, int longitudLlamadas, int longitudAsociados);
