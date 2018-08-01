#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validar.h"
#include "Llamadas.h"

/**
 * \brief Inicializa elementos del array de Llamadas en 0
 * \param arrayLlamadas Es el array a recorrer e inicializar
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve (-1) si el array recibido como parámetro es NULL o si la longitud es inválida, (0) si se pudo inicializar correctamente
 */
int llamadas_init(sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;

    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayLlamada[i].flagLibre = 1;
            arrayLlamada[i].estado = LLAMADA_LIBRE;
        }
    }
            return retorno;
}

/**
 * \brief Genera un ID autoincrementable
 * \param arrayLlamadas Es el array a recorrer para obtener el nuevo ID
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve el nuevo ID
 */
int llamadas_generarId(sLlamada* arrayLlamadas, int longitud)
{
    int i = 0;
    int idMax = -1;

    if(arrayLlamadas != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayLlamadas[i].estado == LLAMADA_PENDIENTE)
            {
                if(idMax < arrayLlamadas[i].idLlamada)
                {
                    idMax = arrayLlamadas[i].idLlamada;
                }
            }
        }
    }
                    return idMax + 1;
}

/**
 * \brief Busca un índice libre en el array de llamadas
 * \param arrayLlamadas Es el array donde se busca el índice
 * \param longitud Largo del array
 * \return retorno (-1) si el array recibido como parámetro es NULL o la longitud es inválida. (i - Índice) si se pudo obtener el índice libre
 */
int llamadas_buscarIndiceLibre(sLlamada* arrayLlamadas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamadas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamadas[i].flagLibre == 1)
            {
                retorno = i;
                break;
            }
        }
    }
                return retorno;
}

/**
 * \brief Da de alta una nueva llamada
 * \param arrayLlamadas Es el array donde se ingresan los datos de la nueva llamada
 * \param arrayAsociados Es el array del asociado que realiza la llamada
 * \param index Índice libre para dar de alta la llamada
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si no se cumple alguna validación. (0) si se pudo dar de alta correctamente
 */
int llamadas_alta(sLlamada* arrayLlamada, sAsociado* arrayAsociados, int index, int longitudAsociados, int longitudLlamadas)
{
    int retorno = -1;
    int idLlamada;
    char bMotivo[ARRAY_LENGTH];
    int idAsociadoAux;
    int indexAsociado;

    if(arrayLlamada != NULL && index >= 0 && index < longitudLlamadas)
    {
            idAsociadoAux = llamadas_encontrarIDAsociado(arrayAsociados, longitudAsociados);
            indexAsociado = asociado_buscarIndicePorId(arrayAsociados, idAsociadoAux, longitudAsociados);
            idLlamada = llamadas_generarId(arrayLlamada, longitudLlamadas);

            if(idLlamada != -1 && idAsociadoAux != -1 && indexAsociado != -1)
            {
                llamadas_printMotivos();
                if(val_getUnsignedInt(bMotivo,"\nIngrese motivo de la llamada: ", "\nError, reingrese motivo: ", 3, ARRAY_LENGTH)==0)
                {
                    if(val_validarRangoInt(bMotivo, "\nError, motivo invalido (100-101-102)", 100, 102)==0)
                    {
                        if(llamadas_checkAsociado(arrayLlamada, idAsociadoAux, "\nERROR! Este asociado esta en otra llamada!!!", longitudLlamadas)==0)
                        {
                            strncpy(arrayLlamada[index].motivo, bMotivo, ARRAY_LENGTH);
                            arrayLlamada[index].estado = LLAMADA_PENDIENTE;
//                          arrayLlamada[index].idLlamada = idLlamada;
                            arrayLlamada[index].flagLibre = 0;
                            arrayAsociados[indexAsociado].cantLlamados++;

                            printf("\n--------------------------------------------------");
                            printf("\nLLAMADA INGRESADA CORRECTAMENTE - ESTADO PENDIENTE\n");
                            printf("\nEL ID DE LA LLAMADA ES: %d", arrayLlamada[index].idLlamada);
                            printf("\n--------------------------------------------------");
                            retorno = 0;
                        }
                    }
                }
        }
        else
        if(indexAsociado == -1)
        {
            printf("ERROR! Asociado inexistente");
            retorno = -1;
        }
    }
                                printf("\n\n");
                                system("pause");
                                return retorno;
}


/**
 * \brief Asigna una ambulancia a una llamada pendiente
 * \param arrayLlamadas
 * \param arrayAsociados
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si no se cumple alguna validación. (0) si se pudo asignar correctamente
 */
int llamadas_asignarAmbulancia(sLlamada* arrayLlamada, sAsociado* arrayAsociados, int longitudLlamadas, int longitudAsociados)
{
    int retorno = -1;
    char bTiempo[ARRAY_LENGTH];
    char bIdAmbulancia[ARRAY_LENGTH];
    int idLlamada;
    int indexLlamada;
//    int idAsociado;
//    int indexAsociado;

    if(arrayLlamada != NULL && longitudLlamadas > 0 && longitudAsociados > 0)
    {
        idLlamada = llamadas_encontrarIDLlamada(arrayLlamada, longitudLlamadas);
//        idAsociado = llamadas_encontrarIDAsociado(arrayAsociados, longitudAsociados);
        if(idLlamada >= 0)
        {
            indexLlamada = llamadas_buscarIndicePorId(arrayLlamada, idLlamada, longitudLlamadas);
//            indexAsociado = emerg_buscarIndicePorId(arrayAsociados, idAsociado, longitudAsociados);
            if(indexLlamada >= 0)
            {
                if(val_getUnsignedInt(bIdAmbulancia,"\nIngrese ID de la ambulancia: ", "\nError, reingrese ID de la ambulancia: ", 3, ARRAY_LENGTH)==0)
                {
                    if(llamadas_checkAmbulancia(arrayLlamada, bIdAmbulancia, "\nERROR! Esta ambulancia esta ocupada!!!", longitudLlamadas)==0)
                    {
                        if(val_getUnsignedInt(bTiempo,"\nIngrese demora para asignar la ambulancia(minutos): ", "\nError, reingrese tiempo: ", 3, ARRAY_LENGTH)==0)
                        {
                            arrayLlamada[indexLlamada].idAmbulancia = atoi(bIdAmbulancia);
                            arrayLlamada[indexLlamada].estado = LLAMADA_CUMPLIDA;
                            arrayLlamada[indexLlamada].tiempo = atoi(bTiempo);
                            arrayLlamada[indexLlamada].idLlamada = idLlamada;
                            printf("\n----------------------------------------------------------------------");
                            printf("\nAMBULANCIA ASIGNADA CORRECTAMENTE - LLAMADA CUMPLIDA - DEMORA DE LA ASIGNACION: %d MINUTOS\n", arrayLlamada[indexLlamada].tiempo);
                            printf("\nEL ID DE LA LLAMADA ES: %d, Y EL DE LA AMBULANCIA ASIGNADA: %d", idLlamada, arrayLlamada[indexLlamada].idAmbulancia);
                            printf("\n----------------------------------------------------------------------");
                            retorno = 0;
                        }
                    }
                }
            }
        }
        else
        {
            printf("ERROR! ID Llamada inexistente");
            retorno = -1;
        }

    }

                        printf("\n\n");
                        system("pause");
                        return retorno;
}

/**
 * \brief Busca el índice donde está ubicado el ID pasado como parámetro
 * \param arrayLlamadas Es el array a recorrer para obtener el índice
 * \param id ID utilizado para encontrar el índice
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno (-1) si el array recibido como parámetro es NULL o si el ID o la longitud son inválidos. (i - Índice) si se pudo encontrar el índice buscado
 */
int llamadas_buscarIndicePorId(sLlamada* arrayLlamadas, int id, int longitud)
{
    int i;
    int retorno = -1;

    if(arrayLlamadas != NULL && longitud > 0 && id >= 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayLlamadas[i].flagLibre == 0)
            {
                if(id == arrayLlamadas[i].idLlamada)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
                   return retorno;
}


/**
 * \brief Busca el ID de un asociado en el array de Asociados
 * \param arrayAsociados Es el array a recorrer para obtener el ID
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno (-1) si no se encuentra el ID del asociado. (idAux) si se pudo encontrar el ID buscado
 */
int llamadas_encontrarIDAsociado(sAsociado* arrayAsociados, int longitudAsociados)
{
        int i;
        int retorno = -1;
        int idAux;
        char bIdAsociado[ARRAY_LENGTH];

        if(val_getUnsignedInt(bIdAsociado,"\nIngrese ID del asociado: ", "\nError, reingrese ID del asociado: ", 3, ARRAY_LENGTH)==0)
        {
            idAux = atoi(bIdAsociado);
            for(i = 0; i < longitudAsociados; i++)
            {
                if(arrayAsociados[i].estado == ASOCIADO_OCUPADO) //&& arrayAsociados[i].idAsociado == idAux)
                {
                    retorno = idAux;
//                    contador llamadas++
                    break;
                }
                else
                {
                    printf("ERROR! El asociado no existe");
                    break;
                }
            }
        }
                    return retorno;
}

/////**
// * \brief Busca el ID de un asociado en el array de Asociados
// * \param arrayAsociados Es el array a recorrer para obtener el ID
// * \param longitud Cantidad de elementos del array a recorrer
// * \return retorno (-1) si no se encuentra el ID del asociado. (idAux) si se pudo encontrar el ID buscado
// */
int llamadas_encontrarIDLlamada(sLlamada* arrayLlamada, int longitudLlamadas)
{
        int i;
        int retorno = -1;
        int idAux;
        char bIdLlamada[ARRAY_LENGTH];

        if(val_getUnsignedInt(bIdLlamada,"\nIngrese ID de la llamada: ", "\nError, reingrese ID: ", 3, ARRAY_LENGTH)==0)
        {
            idAux = atoi(bIdLlamada);
            for(i = 0; i < longitudLlamadas; i++)
            {
                if(arrayLlamada[i].estado == LLAMADA_PENDIENTE)
                {
                    retorno = idAux;
                    //contador llamadas++
                    break;
                }
//                else
//                {
//                    printf("ERROR! ID de llamada inexistente o ya asignado!!!");
//                    break;
//                }
            }
        }
                    return retorno;
}


/**
 * \brief Imprime los motivos de la llamada (HARDCODEADOS)
 * \return void
 */
void llamadas_printMotivos()
{
    printf("\n\n[LISTA DE MOTIVOS]\n");
    printf("\n-----------------------------");
    printf("\nCODIGO\tMOTIVO\n");
    printf("-----------------------------\n");
    printf("INFARTO\t100\nACV\t101\nGRIPE\t102\n");
}

/**
 * \brief Imprime las llamadas cuyo estado es "PENDIENTE"
 * \param arrayLlamada Es el array donde están los elementos a imprimir
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si el array es NULL o la longitud es inválida. (0) si se pudo imprimir correctamente
 */
int llamadas_printPendientes(sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        printf("\nID LLAMADA\tMOTIVO\n");
        for(i = 0; i < longitud; i++)
        {
            if(arrayLlamada[i].estado == LLAMADA_PENDIENTE && arrayLlamada[i].flagLibre == 0)
            {
                printf("\n%d\t\t%s", arrayLlamada[i].idLlamada, arrayLlamada[i].motivo);
                retorno = 0;
            }
        }
    }
                printf("\n\n");
                return retorno;
}

/**
 * \brief Imprime las llamadas cuyo estado es "CUMPLIDA"
 * \param arrayLlamada Es el array donde están los elementos a imprimir
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si el array es NULL o la longitud es inválida. (0) si se pudo imprimir correctamente
 */
int llamadas_printCumplidas(sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        printf("\nID LLAMADA  ID AMBULANCIA   MOTIVO   DURACION(MINUTOS)\n");
        for(i = 0; i < longitud; i++)
        {
            if(arrayLlamada[i].estado == LLAMADA_CUMPLIDA)
            {
                printf("\n%-10d\t%-10d\t%-5s\t%-2d", arrayLlamada[i].idLlamada, arrayLlamada[i].idAmbulancia, arrayLlamada[i].motivo, arrayLlamada[i].tiempo);
                retorno = 0;
            }
        }
    }
                printf("\n\n");
                system("pause");
                return retorno;
}

/**
 * \brief Imprime datos del asociado y motivos de llamada
 * \param arrayLlamadas/Asociados Es el array donde están los elementos a imprimir
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si no se pudo imprimir. (0) si se pudo imprimir correctamente
 */
int llamadas_mostrarCantMotivos(sAsociado* arrayAsociados, int longitudAsociados, sLlamada* arrayLlamadas, int longitudLlamadas)
{
    int retorno = -1;
    int indexAsociado;
    int i;

    for(i = 0; i < longitudAsociados; i++)
    {
        if(arrayLlamadas[i].estado == LLAMADA_CUMPLIDA)
        {
            indexAsociado = asociado_buscarIndicePorId(arrayAsociados, llamadas_encontrarIDAsociado(arrayAsociados, longitudAsociados), longitudAsociados);
            printf("\n%d\t%s\t%s\t%s", arrayAsociados[indexAsociado].idAsociado, arrayAsociados[indexAsociado].nombre, arrayAsociados[indexAsociado].apellido, arrayLlamadas[i].motivo);
            retorno = 0;
        }
    }
            return retorno;
}


/**
 * \brief Imprime datos del asociado y motivos de llamada
 * \param arrayLlamadas/Asociados Es el array donde están los elementos a imprimir
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si no se pudo imprimir. (0) si se pudo imprimir correctamente
 */
int llamadas_motivosRecurrentes(sAsociado* arrayAsociados, int longitudAsociados, sLlamada* arrayLlamadas, int longitudLlamadas)
{
    int retorno = -1;
    int flag = 0;
    int i;
    printf("\n[LISTA DE ASOCIADOS Y MOTIVOS]\n");
    printf("\n\n*ID*\t*NOMBRE*\t*APELLIDO*\t*M1*\t*M2*\t*M3*\t");
    for(i = 0; i < longitudLlamadas; i++)
    {
        if(arrayLlamadas[i].estado == LLAMADA_CUMPLIDA && flag == 0)
        {
            llamadas_mostrarCantMotivos(arrayAsociados, longitudAsociados, arrayLlamadas, longitudLlamadas);
            flag = 1;
            retorno = 0;
        }
    }
            printf("\n\n");
            system("pause");
            return retorno;
}


/**
 * \brief Verifica que el ID de Ambulancia recibido como parámetro no está siendo usado en el array de Llamadas
 * \param arrayLlamadas Es el array donde se busca el ID
 * \param buffer ID a evaluar
 * \param errorMsg Mensaje de error si el ID ya está siendo usado
 * \param longitud Largo del array
 * \return (0) si el ID no está en uso. (-1) si el ID está siendo usado
 */
int llamadas_checkAmbulancia(sLlamada* arrayLlamadas, char* buffer, char* errorMsg, int longitud)
{
    int i;
    int retorno = 0;
    int value;

    value = atoi(buffer);
    for(i = 0; i < longitud; i++)
    {
        if(arrayLlamadas[i].idAmbulancia == value)
        {
            retorno = -1;
            printf(errorMsg);
        }
    }
            return retorno;
}


/**
 * \brief Verifica que el ID de Asociado recibido como parámetro no está siendo usado en el array de Llamadas
 * \param arrayLlamadas Es el array donde se busca el ID
 * \param buffer ID a evaluar
 * \param errorMsg Mensaje de error si el ID ya está siendo usado
 * \param longitud Largo del array
 * \return (0) si el ID no está en uso. (-1) si el ID está siendo usado
 */
int llamadas_checkAsociado(sLlamada* arrayLlamadas, int buffer, char* errorMsg, int longitud)
{
    int i;
    int retorno = 0;

    for(i = 0; i < longitud; i++)
    {
        if(arrayLlamadas[i].idAsociado == buffer && arrayLlamadas[i].estado == LLAMADA_PENDIENTE)
        {
            retorno = -1;
            printf(errorMsg);
            break;
        }
    }
            return retorno;
}
