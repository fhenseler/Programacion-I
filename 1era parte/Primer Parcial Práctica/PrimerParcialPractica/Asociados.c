#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validar.h"
#include "Asociados.h"

static int modificarPorIndice(sAsociado* arrayAsociados, int index);

/**
 * \brief Modifica datos del asociado según el índice
 * \param arrayAsociados Es el array donde se obtienen los datos a modificar
 * \param index Índice donde se encuentra el asociado a modificar
 * \return retorno (-1) si el array recibido como parámetro es NULL o si el índice es inválido. (0) si se pudo modificar correctamente
 */
static int modificarPorIndice(sAsociado* arrayAsociados, int index)
{
    int retorno = -1;
    char bNombre[ARRAY_LENGTH];
    char bApellido[ARRAY_LENGTH];

    if(arrayAsociados != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nIngrese nuevo nombre: ", "\nError. Reingrese nombre: \n", 3, ARRAY_LENGTH)==0)
        {
            if(val_getNombre(bApellido,"\nIngrese nuevo apellido: ","\nError. Reingrese apellido: \n", 3, ARRAY_LENGTH)==0)
            {
                    strncpy(arrayAsociados[index].nombre, bNombre, ARRAY_LENGTH);
                    strncpy(arrayAsociados[index].apellido, bApellido, ARRAY_LENGTH);
                    retorno = 0;
                    printf("DATOS ACTUALIZADOS!!!");
            }
        }
    }
                    return retorno;
}


/**
 * \brief Inicializa elementos del array de Asociados
 * \param arrayAsociados Es el array a recorrer e inicializar
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve (-1) si el array recibido como parámetro es NULL o si la longitud es inválida, (0) si se pudo inicializar correctamente
 */
int asociado_init(sAsociado* arrayAsociados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayAsociados[i].estado = ASOCIADO_LIBRE;
            arrayAsociados[i].cantLlamados = 0;
            arrayAsociados[i].flagLibre = 1;
        }
            retorno = 0;
    }
            return retorno;
}


/**
 * \brief Da de alta a un nuevo asociado
 * \param arrayAsociados Es el array donde se ingresan los datos del nuevo asociado
 * \param index Índice libre para dar de alta al asociado
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si no se cumple alguna validación. (0) si se pudo dar de alta correctamente
 */
int asociado_alta(sAsociado* arrayAsociados, int index, int longitud)
{
    int retorno = -1;
    int idAsociado;
    char bNombre[ARRAY_LENGTH];
    char bApellido[ARRAY_LENGTH];
    char bEdad[ARRAY_LENGTH];
    char bDNI[ARRAY_LENGTH];

        if(arrayAsociados != NULL && index >= 0 && index < longitud)
        {
            if(val_getNombre(bNombre,"\nNombre: ", "\nError, reingrese nombre: ", 3, ARRAY_LENGTH)==0)
            {
                if(val_getNombre(bApellido,"\nApellido: ", "\nError, reingrese apellido: ", 3, ARRAY_LENGTH)==0)
                {
                    if(val_getUnsignedInt(bEdad,"\nEdad: ", "\nError, reingrese edad: ", 3, ARRAY_LENGTH)==0)
                    {
                        if(val_validarRangoInt(bEdad, "\nERROR! Edad incorrecta. (0-125)", 0, 125)==0)
                        {
                            if(val_getUnsignedInt(bDNI, "\nDNI: ", "Error, reingrese DNI: ", 3, ARRAY_LENGTH)==0)
                            {
                                if(val_validarRangoInt(bDNI, "\nERROR! DNI Incorrecto (10000000-40000000)", 10000000, 40000000)==0)
                                {
                                    if(asociado_checkDNI(arrayAsociados, bDNI, "\nERROR! Este DNI ya fue registrado", longitud)==0)
                                    {
                                        idAsociado = asociado_generarNuevoId(arrayAsociados, longitud);
                                        if(idAsociado != -1)
                                        {
                                            strncpy(arrayAsociados[index].nombre, bNombre, ARRAY_LENGTH);
                                            strncpy(arrayAsociados[index].apellido, bApellido, ARRAY_LENGTH);
                                            arrayAsociados[index].edad = atoi(bEdad);
                                            arrayAsociados[index].dni = atoi(bDNI);
                                            arrayAsociados[index].estado = ASOCIADO_OCUPADO;
                                            arrayAsociados[index].idAsociado = idAsociado;
                                            printf("\n------------------------------------------");
                                            printf("\nASOCIADO DADO DE ALTA\n");
                                            printf("\nEL ID DEL NUEVO ASOCIADO ES: %d\n", arrayAsociados[index].idAsociado);
                                            printf("------------------------------------------");
                                            retorno = 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        if(index < 0)
        {
            printf("ERROR! No hay lugar para dar de alta!");
        }

                                            printf("\n\n");
                                            system("pause");
                                            return retorno;
}


/**
 * \brief Modifica datos del asociado
 * \param arrayAsociados Es el array donde se obtienen los datos a modificar
 * \return retorno (-1) si el array recibido como parámetro es NULL. (0) si se pudo modificar correctamente
 */
int asociado_modificar(sAsociado* arrayAsociados)
{
    int id;
    int retorno = -1;
    char buffer[ARRAY_LENGTH];

    if(arrayAsociados != NULL)
    {
        val_getUnsignedInt(buffer, "Ingrese ID del asociado a modificar: ", "\nError. Reingrese ID: ", 3, ARRAY_LENGTH);
        id = atoi(buffer);
        if(asociado_buscarIndicePorId(arrayAsociados, id, MAX_ASOCIADOS) == -1)
        {
            printf("\nError! ID Invalido\n");
        }
        else
        {
            modificarPorIndice(arrayAsociados, asociado_buscarIndicePorId(arrayAsociados, id, MAX_ASOCIADOS));
            retorno = 0;
        }
    }
            printf("\n\n");
            system("pause");
            return retorno;
}

/**
 * \brief Da de baja un asociado activo
 * \param arrayAsociados Es el array donde se obtiene el asociado a dar de baja
 * \return retorno (-1) si el array recibido como parámetro es NULL. (0) si se pudo dar de baja correctamente
 */
int asociado_baja(sAsociado* arrayAsociados)
{
    int indice;
    int id;
    int retorno = -1;
    char buffer[ARRAY_LENGTH];

        if(arrayAsociados != NULL)
        {
            val_getUnsignedInt(buffer, "Ingrese ID del asociado a borrar: \n", "Error. Reingrese ID:  ", 3, ARRAY_LENGTH);
            id = atoi(buffer);
            if(asociado_buscarIndicePorId(arrayAsociados, id, MAX_ASOCIADOS) == -1)
            {
                printf("Error! ID Invalido\n");
            }
            else
            {
                indice = asociado_buscarIndicePorId(arrayAsociados, id, MAX_ASOCIADOS);
                arrayAsociados[indice].estado = ASOCIADO_LIBRE;
                printf("\nASOCIADO DADO DE BAJA\n");
            }
        }
                printf("\n\n");
                system("pause");
                return retorno;
}

/**
 * \brief Genera un ID autoincrementable y único
 * \param arrayAsociados Es el array a recorrer para obtener el nuevo ID
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve el nuevo ID
 */
int asociado_generarNuevoId(sAsociado* arrayAsociados, int longitud)
{
    int i = 0;
    int idMax = -1;

    if(arrayAsociados != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayAsociados[i].estado == ASOCIADO_OCUPADO) //&& arrayAsociado[i].idAsociado > idMax)
            {
                if(idMax < arrayAsociados[i].idAsociado)
                {
                    idMax = arrayAsociados[i].idAsociado;
                }

            }
        }
    }
                    return idMax + 1;
}


/**
 * \brief Busca el índice donde está ubicado el ID pasado como parámetro
 * \param arrayAsociados Es el array a recorrer para obtener el índice
 * \param id ID utilizado para encontrar el índice
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno (-1) si el array recibido como parámetro es NULL o si el ID o la longitud son inválidos. (i - Índice) si se pudo encontrar el índice buscado
 */
int asociado_buscarIndicePorId(sAsociado* arrayAsociados, int id, int longitud)
{
    int i;
    int retorno = -1;

    if(arrayAsociados != NULL && longitud > 0 && id >= 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayAsociados[i].estado == ASOCIADO_OCUPADO)
            {
                if(id == arrayAsociados[i].idAsociado)
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
 * \brief Imprime datos del asociado por pantalla
 * \param arrayAsociados Es el array donde se obtienen los datos a imprimir
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si el array recibido como parámetro es NULL o si la longitud es inválida. (0) si se pudo imprimir correctamente
 */
int asociado_print(sAsociado* arrayAsociados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociados != NULL && longitud > 0)
    {
        printf("\nID\tNombre\tApellido\tDNI\tEdad\tCantidad Llamados");
        for(i = 0; i < longitud; i++)
        {
            if(arrayAsociados[i].estado == ASOCIADO_OCUPADO)
            {
                printf("\n%d\t%s  %s\t\t%d %d\t %d", arrayAsociados[i].idAsociado , arrayAsociados[i].nombre, arrayAsociados[i].apellido, arrayAsociados[i].dni, arrayAsociados[i].edad, arrayAsociados[i].cantLlamados);
                retorno = 0;
            }
        }
    }
                printf("\n\n");
                return retorno;
}

/**
 * \brief Busca un índice libre en el array de asociados
 * \param arrayAsociados Es el array donde se busca el índice
 * \param longitud Largo del array
 * \return retorno (-1) si el array recibido como parámetro es NULL o la longitud es inválida. (i - Índice) si se pudo obtener el índice libre
 */
int asociado_buscarIndiceLibre(sAsociado* arrayAsociados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociados[i].estado == ASOCIADO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
                return retorno;
}

/**
 * \brief Carga datos en el array de asociados (HARDCODEADOS)
 * \param arrayAsociados Es el array donde se cargan los datos
 * \param longitud Largo del array
 * \return void (-1)
 */
void asociado_cargar(sAsociado* arrayAsociados, int longitud)
{
    char nombres[MAX_ASOCIADOS][30] = {"Carmen","Luis","Pedro","Luis"};
    char apellidos[MAX_ASOCIADOS][30] = {"Juarez","Rodriguez","Perez","Rodriguez"};
    int idAsociado[MAX_ASOCIADOS] = {1, 2, 3, 4};
    int estado[MAX_ASOCIADOS] = {2, 2, 2, 2};
    int dni[MAX_ASOCIADOS] = {25000000, 20000000, 30000000, 22000000};
    int edad[MAX_ASOCIADOS] = {25, 30, 35, 20};
    int i;

    for(i=0; i<longitud; i++)
    {
        arrayAsociados[i].idAsociado = idAsociado[i];
        strcpy(arrayAsociados[i].nombre, nombres[i]);
        strcpy(arrayAsociados[i].apellido, apellidos[i]);
        arrayAsociados[i].estado = estado[i];
        arrayAsociados[i].dni = dni[i];
        arrayAsociados[i].edad = edad[i];
    }
}

/**
 * \brief Verifica que el DNI recibido como parámetro no está siendo usado en el array de Asociados
 * \param arrayAsociados Es el array donde se busca el DNI
 * \param buffer DNI a evaluar
 * \param errorMsg Mensaje de error si el DNI ya está siendo usado
 * \param longitud Largo del array
 * \return (0) si el DNI no está en uso. (-1) si el DNI está siendo usado
 */
int asociado_checkDNI(sAsociado* arrayAsociados, char* buffer, char* errorMsg, int longitud)
{
    int i;
    int retorno = 0;
    int value;

    value = atoi(buffer);
    for(i = 0; i < longitud; i++)
    {
        if(arrayAsociados[i].dni == value && arrayAsociados[i].estado == ASOCIADO_OCUPADO)
        {
            retorno = -1;
            printf(errorMsg);
        }
    }
            return retorno;
}

/**
 * \brief Ordena el array de asociados por 2 criterios
 * \param arrayAsociados Es el array a ordenar
 * \param longitud Largo del array
 * \return (-1) si no se pudo ordenar. (0) si se ordenó correctamente
 */
int asociado_ordenarPorNombreYDNI(sAsociado* arrayAsociados, int longitud)
{
    int i, j;
    int retorno = -1;
    sAsociado auxiliar;

    for(i = 0; i < longitud-1; i++)
    {
        for(j = i+1; j < longitud; j++)
        {
            if(arrayAsociados[i].estado == ASOCIADO_OCUPADO && arrayAsociados[j].estado == ASOCIADO_OCUPADO)
            {
                if(strcmp(arrayAsociados[i].nombre, arrayAsociados[j].nombre)>0)
                {
                    auxiliar = arrayAsociados[i];
                    arrayAsociados[i] = arrayAsociados[j];
                    arrayAsociados[j] = auxiliar;
                    retorno = 0;
                    break;
                }

                if(strcmp(arrayAsociados[i].nombre, arrayAsociados[j].nombre)==0)
                {
                    if(arrayAsociados[i].dni > arrayAsociados[j].dni)
                    {
                        auxiliar = arrayAsociados[i];
                        arrayAsociados[i] = arrayAsociados[j];
                        arrayAsociados[j] = auxiliar;
                        retorno = 0;
                        break;
                    }
                }
            }
        }
     }
                        return retorno;
}

