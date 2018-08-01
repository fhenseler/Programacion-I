#include <stdio.h>
#include <stdlib.h>
#include "Validar.h"
#include "Asociados.h"
#include "Llamadas.h"
#include "Informes.h"

#define MAX_INPUT_BUFFER 40

int main()
{
    sAsociado arrayAsociados[MAX_ASOCIADOS];
    sLlamada arrayLlamadas[MAX_LLAMADAS];
    sInformes arrayInformes[MAX_INFORMES];
    char bufferInt[MAX_INPUT_BUFFER];

    asociado_init(arrayAsociados, MAX_ASOCIADOS);
    llamadas_init(arrayLlamadas, MAX_LLAMADAS);
    informes_init(arrayInformes, MAX_INFORMES);

    asociado_cargar(arrayAsociados, MAX_ASOCIADOS);

    do
    {
        system("cls");
        printf("< ATENCION MEDICA DE EMERGENCIAS >\n");
        val_getUnsignedInt(bufferInt, "\n1- ALTA ASOCIADO\n2- MODIFICAR ASOCIADO\n3- BAJA ASOCIADO\n4- NUEVA LLAMADA\n5- ASIGNAR AMBULANCIA\n6- INFORMAR\n7- LISTAR ASOCIADOS\n8- LISTAR LLAMADAS CUMPLIDAS\n\n9- SALIR\n\nElegir Opcion: ", "\nOpciones Validas 1-9. Reingrese: \n", 2, MAX_INPUT_BUFFER);

        system("cls");

        switch(atoi(bufferInt))
        {
            case 1:
                printf("[INGRESAR DATOS DEL NUEVO ASOCIADO]\n");
                asociado_alta(arrayAsociados, asociado_buscarIndiceLibre(arrayAsociados, MAX_ASOCIADOS), MAX_ASOCIADOS);
                break;
            case 2:
                printf("[MODIFICAR DATOS DEL ASOCIADO]\n");
                printf("\n[LISTA DE ASOCIADOS]\n");
                asociado_print(arrayAsociados, MAX_ASOCIADOS);
                asociado_modificar(arrayAsociados);
                break;
            case 3:
                printf("[DAR DE BAJA A UN ASOCIADO]\n");
                printf("\n[LISTA DE ASOCIADOS]\n");
                asociado_print(arrayAsociados, MAX_ASOCIADOS);
                asociado_baja(arrayAsociados);
                break;
            case 4:
                printf("[INGRESAR NUEVA LLAMADA]\n");
                printf("\n[LISTA DE ASOCIADOS]\n");
                asociado_print(arrayAsociados, MAX_ASOCIADOS);
                llamadas_alta(arrayLlamadas, arrayAsociados, llamadas_buscarIndiceLibre(arrayLlamadas, MAX_LLAMADAS), MAX_ASOCIADOS, MAX_LLAMADAS);
                break;
            case 5:
                printf("[ASIGNAR AMBULANCIA]\n");
                printf("[LISTA DE LLAMADAS PENDIENTES]\n");
                llamadas_printPendientes(arrayLlamadas, MAX_LLAMADAS);
                llamadas_asignarAmbulancia(arrayLlamadas, arrayAsociados, MAX_LLAMADAS, MAX_ASOCIADOS);
                break;
            case 6:
                printf("[INFORMES]\n");
                val_getUnsignedInt(bufferInt, "\n1- ASOCIADO CON MAS LLAMADAS\n2- MOTIVO MAS RECURRENTE\n3- MOTIVO QUE MAS DEMORA EN SER RESUELTO (PROMEDIO)\n\n4- SALIR\nElegir Opcion: ", "Opciones Validas 1-4. Reingrese: ", 2, MAX_INPUT_BUFFER);
                switch(atoi(bufferInt))
                {
                    case 1:
                            informes_asociadoMaxLlamados(arrayLlamadas, arrayAsociados, MAX_LLAMADAS, MAX_ASOCIADOS);
                            break;
                    case 2:
                            informes_motivoMax(arrayLlamadas, MAX_LLAMADAS);
                            break;
                    case 3:
                            informes_motivoMaxDemora(arrayLlamadas, MAX_LLAMADAS);
                            break;
                    default:
                            printf("\nERROR!!! OPCION INVALIDA!!! (1-4)\n\n");
                            printf("\n\n");
                            system("pause");
                            break;
                }
                            break;
            case 7:
                printf("[LISTA DE ASOCIADOS ORDENADOS POR NOMBRE Y DNI]\n");
                asociado_ordenarPorNombreYDNI(arrayAsociados, MAX_ASOCIADOS);
                asociado_print(arrayAsociados, MAX_ASOCIADOS);
                printf("\n\n");
                system("pause");
                break;
            case 8:
                printf("[LISTA DE LLAMADAS CUMPLIDAS]\n");
                llamadas_printCumplidas(arrayLlamadas, MAX_LLAMADAS);
                break;
            default:
                printf("\nERROR!!! OPCION INVALIDA!!! (1-9)\n\n");
                printf("\n\n");
                system("pause");
                break;
        }
    }while(atoi(bufferInt) != 9);

                return 0;
}
