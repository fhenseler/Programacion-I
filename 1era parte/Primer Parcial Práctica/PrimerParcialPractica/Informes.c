#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validar.h"
#include "Asociados.h"
#include "Informes.h"


/**
 * \brief Inicializa elementos del array de Informes en 0
 * \param arrayInformes Es el array a recorrer e inicializar
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve (-1) si el array recibido como parámetro es NULL o si la longitud es inválida, (0) si se pudo inicializar correctamente
 */
int informes_init(sInformes* arrayInformes, int longitud)
{
    int retorno = -1;
    int i;

    if(arrayInformes != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayInformes[i].idAsociado = 0;
            arrayInformes[i].idLlamada = 0;
        }
            retorno = 0;
    }
            return retorno;
}

int informes_asociadoMaxLlamados(sLlamada* arrayLlamadas, sAsociado* arrayAsociados, int longitudLlamadas, int longitudAsociados)
{
    int retorno = -1;
    int i;
    int idAsociadoMax;
    int indexAsociadoMax;
    int llamadasMax = 0;

    for(i = 0; i < longitudAsociados; i++)
    {
        if(i == 0 || arrayAsociados[0].cantLlamados > llamadasMax)
        {
            llamadasMax = arrayAsociados[i].cantLlamados;
        }

        if(arrayAsociados[i].cantLlamados > llamadasMax)
        {
            llamadasMax = arrayAsociados[i].cantLlamados;
        }
    }

    for(i = 0; i < longitudAsociados; i++)
    {
        if(arrayAsociados[i].cantLlamados == llamadasMax && llamadasMax != 0)
        {
                idAsociadoMax = arrayAsociados[i].idAsociado;
                indexAsociadoMax = asociado_buscarIndicePorId(arrayAsociados, idAsociadoMax, longitudAsociados);
                printf("\nEl asociado con mas llamados es: %s %s (ID %d) con %d llamado(s)", arrayAsociados[indexAsociadoMax].nombre, arrayAsociados[indexAsociadoMax].apellido, arrayAsociados[indexAsociadoMax].idAsociado, llamadasMax);
                retorno = 0;
        }
        if(llamadasMax == 0)
        {
                printf("\nTodavia no hay llamados");
                retorno = -1;
                break;
        }
    }
                printf("\n\n");
                system("pause");
                return retorno;
}

int informes_motivoMaxDemora(sLlamada* arrayLlamada, int longitudLlamada)
{
    int retorno = -1;
    return retorno;
}

/**
 * \brief Obtiene el/los motivo(s) más recurrente(s) y lo(s) informa por pantalla
 * \param arrayInformes Es el array a recorrer
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve (-1) si no se pudo encontrar un motivo, (0) si se pudo encontrar correctamente
 */
int informes_motivoMax(sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    int motivoMax = 0;
    int contMotivos[MAX_MOTIVOS];

    for(i = 0; i < MAX_MOTIVOS; i++)
    {
        contMotivos[i] = 0;
    }

    for(i = 0; i < longitud; i++)
    {
        if(strcmp(arrayLlamada[i].motivo, "100")==0)
        {
            contMotivos[0]++;
            continue;
        }
        if(strcmp(arrayLlamada[i].motivo, "101")==0)
        {
            contMotivos[1]++;
            continue;
        }
        if(strcmp(arrayLlamada[i].motivo, "102")==0)
        {
            contMotivos[2]++;
            continue;
        }
    }

    for(i = 0; i < MAX_MOTIVOS; i++)
    {
        if(i == 0 || contMotivos[0] > motivoMax)
        {
            motivoMax = contMotivos[0];
        }

        if(contMotivos[i] > motivoMax)
        {
            motivoMax = contMotivos[i];
        }
    }

    for(i = 0; i < MAX_MOTIVOS; i++)
    {
        if(contMotivos[i] == motivoMax && motivoMax != 0)
        {
            if(i == 0)
            {
               printf("\nMotivo mas recurrente: %d (INFARTO) con %d llamado(s)", i, motivoMax);
            }
            if(i == 1)
            {
               printf("\nMotivo mas recurrente: %d (ACV) con %d llamado(s)", i, motivoMax);
            }
            if(i == 2)
            {
               printf("\nMotivo mas recurrente: %d (GRIPE) con %d llamado(s)", i, motivoMax);
            }
               retorno = 0;
        }
        if(motivoMax == 0)
        {
                printf("\nTodavia no hay llamados");
                retorno = -1;
                break;
        }
    }
                printf("\n\n");
                system("pause");
                return retorno;
}
