#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"


/**
 * \brief Lee como entero un dato ingresado por el usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado en pantalla
 * \return auxInt Devuelve el dato transformado a entero
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

/**
 * \brief Inicializa campos del array de estructuras "eProgramador"
 * \param lista Es el array de estructuras donde están los campos a ser inicializados
 * \param tam es el tamaño del array de estructuras
 * \return void
 */
void inicializarProgramadores(eProgramador lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].estado = 0;
        lista[i].idProgramador = 0;
    }
}

/**
 * \brief Inicializa campos del array de estructuras "eProyecto"
 * \param proyectos Es el array de estructuras donde están los campos a ser inicializados
 * \param tam es el tamaño del array de estructuras
 * \return void
 */
void inicializarProyectos(eProyecto proyectos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        proyectos[i].cantidadProg1 = 0;
        proyectos[i].cantidadProg2 = 0;
        proyectos[i].cantidadProg3 = 0;
        proyectos[i].estado = 0;
    }
}

/**
 * \brief Inicializa campos del array de estructuras "eProg_Proy"
 * \param progproy Es el array de estructuras donde están los campos a ser inicializados
 * \param tam es el tamaño del array de estructuras
 * \return void
 */
void inicializarProgProy(eProg_Proy progproy[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        progproy[i].idProgramador = 0;
        progproy[i].idProyecto = 0;
        progproy[i].estado = 0;
    }
}


/**
 * \brief Carga datos en el array de estructuras "eProgramador" (hardcodeado)
 * \param lista Es el array a cargar
 * \param tam es el tamaño del array de estructuras
 * \return void
 */
void cargarProgramadores(eProgramador lista[], int tam)
{
    int id[MAX_PROG] = {1, 2, 3, 4, 5};
    char nombres[MAX_PROG][30] = {"juan","maria","pedro","luis","romina"};
    char apellidos[MAX_PROG][30] = {"juarez","martinez","perez","argento","ramirez"};
    int idCategoria[MAX_PROG] = {1, 2, 3, 1, 2};
    int estados[MAX_PROG] = {1, 1, 1, 1, 1};
//    int horas[MAX_PROG] = {200, 300, 400, 500, 600};

    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].idProgramador = id[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apellidos[i]);
        lista[i].estado = estados[i];
        lista[i].idCategoria = idCategoria[i];
//        lista[i].cantidadHoras = horas[i];
    }
}


/**
 * \brief Carga datos en el array de estructuras "eProyecto" (hardcodeado)
 * \param proyectos Es el array a cargar
 * \param tam es el tamaño del array de estructuras
 * \return void
 */
void cargarProyectos(eProyecto proyectos[], int tam)
{
    int id[MAX_PROY] = {100, 101, 102, 103, 104};
    char nombres[MAX_PROY][30] = {"Calculadora", "App Celular", "Office 2018", "Videojuego", "App Chat"};
    int estados[MAX_PROY] = {1, 1, 1, 1, 1};

    int i;

    for(i=0; i<tam; i++)
    {
        proyectos[i].idProyecto = id[i];
        strcpy(proyectos[i].nombre, nombres[i]);
        proyectos[i].estado = estados[i];
    }
}

/**
 * \brief Carga datos en el array de estructuras "eCategoria" (hardcodeado)
 * \param categorias Es el array a cargar
 * \param tam es el tamaño del array de estructuras
 * \return void
 */
void cargarCategorias(eCategoria categorias[], int tam)
{
    int id[MAX_CAT] = {1, 2, 3};
    char descripcion[MAX_CAT][15] = {"Junior", "SemiSenior", "Senior"};
    int pagoPorHora[MAX_CAT] = {10, 20, 30};

    int i;

    for(i=0; i<tam; i++)
    {
        categorias[i].idCategoria = id[i];
        strcpy(categorias[i].descripcion, descripcion[i]);
        categorias[i].pagoPorHora = pagoPorHora[i];
    }
}

/**
 * \brief Toma datos ingresados por el usuario, los valida y los guarda en el array de estructuras "eProgramador"
 * \param lista Es el array a cargar
 * \param lowLim Es el límite mínimo del rango a validar
 * \param hiLim Es el límite máximo del rango a validar
 * \param tam es el tamaño del array de estructuras "eProgramador"
 * \param categorias es el array de categorías
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void darAlta(eProgramador lista[], int lowLim, int hiLim, int tam, eCategoria categorias[], int tamC)
{
        printf("\n[DAR DE ALTA]\n");
        int indiceLibre;
        int aux;
        char inputAux[200];

        indiceLibre = findEmptyPlace(lista, tam);

        if(indiceLibre == -1)
        {
            printf("\n\nERROR! NO QUEDAN LUGARES LIBRES!\n\n");
            system("pause");
        }

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estado == 0)
            {
                lista[i].idProgramador = getValidInt("Ingrese ID: ", inputAux, tam);
                lista[i].idProgramador = validateRangeInt(lista[i].idProgramador, "ERROR! El ID puede ir de 1 a 50. Reingrese: ", 1, 50);

                i = buscarPorID(lista, lista[i].idProgramador, tam);

                if(i != -1 && lista[i].estado == 1)
                {
                    printf("\n\nERROR! Este ID ya fue registrado.\n\n");
                    break;
                }

                getStringAlpha("\nIngrese nombre: ", inputAux, 200);
                strcpy(lista[i].nombre, inputAux);
                validateRangeStr("Reingrese nombre: ", lista[i].nombre, 20);

                getStringAlpha("\nIngrese apellido: ", inputAux, 200);
                strcpy(lista[i].apellido, inputAux);
                validateRangeStr("Reingrese apellido: ", lista[i].apellido, 20);

                aux = getValidInt("Ingrese categoria (1- Junior, 2- Semisenior, 3- Senior): ", inputAux, tam);
                aux = validateRangeInt(aux, "ERROR! El ID de la categoria debe ser 1, 2 o 3. Reingrese: ", 1, 3);

                lista[i].idCategoria = aux;
                categorias[i].idCategoria = aux;

                if(lista[i].idCategoria == 1)
                {
                    categorias[i].pagoPorHora = 10;
                }
                if(lista[i].idCategoria == 2)
                {
                    categorias[i].pagoPorHora = 20;
                }
                if(lista[i].idCategoria == 3)
                {
                    categorias[i].pagoPorHora = 30;
                }


//                printf("Ingrese ID: ");
//                scanf("%d", &aux);
//
//                if(aux < lowLim || aux > hiLim)
//                {
//                    printf("\nERROR! El numero debe estar entre %d y %d. Reingrese: ", lowLim, hiLim);
//                    scanf("%d", &aux);
//                }
//
//                        lista[i].idProgramador = aux;

//                        printf("Ingrese nombre: ");
//                        fflush(stdin);
//                        gets(lista[i].nombre);
//
//                        printf("Ingrese apellido: ");
//                        fflush(stdin);
//                        gets(lista[i].apellido);
//
//                        printf("Ingrese categoria (1- Junior, 2- Semisenior, 3- Senior): ");
//                        scanf("%d", &aux);
//
//                        if(aux < 1 || aux > 3)
//                        {
//                            printf("ERROR! Reingresar categoria de 1 a 3: ");
//                            scanf("%d", &aux);
//                        }
//
//
//
//                        lista[i].idCategoria = aux;
//                        categorias[i].idCategoria = aux;
//                        if(lista[i].idCategoria == 1)
//                        {
//                            categorias[i].pagoPorHora = 10;
//                        }
//                        if(lista[i].idCategoria == 2)
//                        {
//                            categorias[i].pagoPorHora = 20;
//                        }
//                        if(lista[i].idCategoria == 3)
//                        {
//                            categorias[i].pagoPorHora = 30;
//                        }


                        lista[i].estado = 1;
                        printf("\n\n***PROGRAMADOR AGREGADO AL SISTEMA***\n");
                        break;
            }
        }
}


/**
 * \brief Hace una baja lógica de los datos guardados en un índice (ID) del array "eProgramador"
 * \param lista Es el array donde están los datos
 * \param lowLim Es el límite mínimo del rango a validar
 * \param hiLim Es el límite máximo del rango a validar
 * \param tam es el tamaño del array de estructuras "eProgramador"
 * \return void
 */
void darBaja(eProgramador lista[], int lowLim, int hiLim, int tam)
{
        int flag = 0;
        int aux;
        char resp;

        printf("Ingrese ID a eliminar: ");
        scanf("%d", &aux);

        if(aux < lowLim || aux > hiLim)
        {
            printf("\nERROR! El numero debe estar entre %d y %d. Reingrese: ", lowLim, hiLim);
            scanf("%d", &aux);
        }

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].estado == 1 && aux == lista[i].idProgramador)
            {

                printf("\nID\t Nombre\t Apellido\t Categoria\t");
                printf("\n%d\t %s\t %s\t %d\t\n", lista[i].idProgramador, lista[i].nombre, lista[i].apellido, lista[i].idCategoria);

                printf("\nEsta seguro de eliminar el programador? S/N: ");
                resp = toupper(getche());
                if(resp != 'S' && resp != 'N')
                {
                    printf("\nRespuesta Incorrecta! Ingrese (S/N): ");
                    resp = toupper(getche());
                }
                if(resp == 'S')
                {
                    lista[i].estado = 0;
                    printf("\n***PROGRAMADOR ELIMINADO!***");
                }
                else
                {
                    printf("\n***ACCION CANCELADA!***");
                }

                    flag = 1;
                    break;
            }
        }

                    if(flag == 0)
                    {
                        printf("\n***ID INEXISTENTE!***");
                    }
}

/**
 * \brief Modifica datos ubicados en un índice (ID) del array de estructuras "eProgramador"
 * \param lista Es el array donde están los datos a modificar
 * \param lowLim Es el límite mínimo del rango a validar
 * \param hiLim Es el límite máximo del rango a validar
 * \param tam es el tamaño del array de estructuras "eProgramador"
 * \param categorias es el array de categorías
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void modificarProgramador(eProgramador lista[], int lowLim, int hiLim, int tam, eCategoria categorias[], int tamC)
{
            int aux;
            int opcion;
            char resp;
            char auxString[100];

            printf("Ingrese ID a modificar: ");
            scanf("%d", &aux);

            if(aux < lowLim || aux > hiLim)
            {
                printf("\nERROR! El numero debe estar entre %d y %d. Reingrese: ", lowLim, hiLim);
                scanf("%d", &aux);
            }

            printf("\nID\t Nombre\t Apellido\t Categoria\t");
            for(int i = 0; i < tam; i++)
            {
                i = buscarPorID(lista, lista[i].idProgramador, tam);

                if(!(i != -1 && lista[i].estado == 1))
                {
                    printf("\n\nERROR! ID inexistente.\n\n");
                    break;
                }

                if(lista[i].estado == 1 && aux == lista[i].idProgramador)
                {
                    printf("\n%d\t %s\t %s\t\t %d\t\n", lista[i].idProgramador, lista[i].nombre, lista[i].apellido, lista[i].idCategoria);
                    printf("Que desea modificar? (1- ID / 2- Nombre / 3- Categoria)");
                    scanf("%d", &opcion);

                    if(opcion == 1)
                    {
                        printf("\nIngrese el nuevo ID: ");
                        scanf("%d", &aux);
                        printf("\nEsta seguro de realizar la modificacion? (S/N): ");
                            resp = toupper(getche());
                            if(resp != 'S' && resp != 'N')
                            {
                                printf("\nRespuesta Incorrecta! Ingrese S o N: ");
                                resp = toupper(getche());
                            }
                            if(resp == 'S')
                            {
                                lista[i].idProgramador = aux;
                                printf("\n***ID MODIFICADO***\n");
                                break;
                            }
                            else
                            {
                                printf("\n***ACCION CANCELADA***\n");
                                break;
                            }
                    }

                    else
                    {
                        if(opcion == 2)
                        {
                            printf("\nIngrese el nuevo nombre: ");
                            fflush(stdin);
                            gets(auxString);

                                    printf("\nEsta seguro de realizar la modificacion? (S/N): ");
                                    resp = toupper(getche());
                                    if(resp != 'S' && resp != 'N')
                                    {
                                        printf("\nRespuesta Incorrecta! Ingrese S o N: ");
                                        resp = toupper(getche());
                                    }
                                    if(resp == 'S')
                                    {
                                        strcpy(lista[i].nombre, auxString);
                                        printf("\n***NOMBRE MODIFICADO***\n");
                                        break;
                                    }
                                    else
                                    {
                                        printf("\n***ACCION CANCELADA***\n");
                                        break;
                                    }
                        }

                        if(opcion == 3)
                        {
                                printf("\nIngrese la nueva categoria: ");
                                scanf("%d", &aux);

                                if(aux < 1 || aux > 3)
                                {
                                    printf("ERROR! Reingresar categoria de 1 a 3: ");
                                    scanf("%d", &aux);
                                }

                                printf("\nEsta seguro de realizar la modificacion? (S/N): ");
                                resp = toupper(getche());
                                if(resp != 'S' && resp != 'N')
                                {
                                    printf("\nRespuesta Incorrecta! Ingrese S o N: ");
                                    resp = toupper(getche());
                                }
                                if(resp == 'S')
                                {
                                    lista[i].idCategoria = aux;
                                    categorias[i].idCategoria = aux;
                                    printf("\n***CATEGORIA MODIFICADA***\n");
                                    break;
                                }
                                else
                                {
                                    printf("\n***ACCION CANCELADA***");
                                    break;
                                }
                            }
                    }

                }

            }
}


/**
 * \brief Ordena datos del array de estructuras "eProgramador" por ID
 * \param lista Es el array a ordenar
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \param categorias es el array de categorías
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void ordenarProgramadores(eProgramador lista[], int tamL, eCategoria categorias[], int tamC)
{
    int aux;
    char auxString[100];

    for(int i = 0; i < tamL-1; i++)
    {
        for(int j = i+1; j < tamL; j++)
        {
            if(lista[i].estado == 1 && lista[j].estado == 1)
            {
                if(lista[i].idProgramador > lista[j].idProgramador)
                {
                    aux = lista[i].idProgramador;
                    lista[i].idProgramador = lista[j].idProgramador;
                    lista[j].idProgramador = aux;

                    strcpy(auxString, lista[i].nombre);
                    strcpy(lista[i].nombre, lista[j].nombre);
                    strcpy(lista[j].nombre, auxString);

                    strcpy(auxString, lista[i].apellido);
                    strcpy(lista[i].apellido, lista[j].apellido);
                    strcpy(lista[j].apellido, auxString);

                    aux = lista[i].idCategoria;
                    lista[i].idCategoria = lista[j].idCategoria;
                    lista[j].idCategoria = aux;

                    aux = categorias[i].idCategoria;
                    categorias[i].idCategoria = lista[j].idCategoria;
                    categorias[j].idCategoria = aux;

                    strcpy(auxString, categorias[i].descripcion);
                    strcpy(categorias[i].descripcion, categorias[j].descripcion);
                    strcpy(categorias[j].descripcion, auxString);
                    break;
                }
            }
        }
    }
}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProgramador" y "eCategoria"
 * \param lista Es el array donde están los datos de las estructuras a mostrar
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \param categoria es el array de categorías
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void mostrarProgramador(eProgramador programador[], int tamL, eCategoria categoria[], int tamC)
{
    char descripcionCat[20];

    for(int i = 0; i < tamL; i++)
    {
        if(programador[i].estado == 1)
        {
            obtenerDescripcion(descripcionCat, categoria, tamC, programador[i].idCategoria);
            printf("\n%d      %s       %s        %s", programador[i].idProgramador, programador[i].nombre, programador[i].apellido, descripcionCat);
        }
    }
}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProgramador" y "eCategoria"
 * \param lista Es el array a mostrar
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \param categoria es el array de categorías
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void mostrarProgramadores(eProgramador lista[], int tamL , eCategoria categorias[], int tamC)
{
    int flag = 0;
    printf("\n[LISTA DE PROGRAMADORES ORDENADOS POR ID]\n");
    printf("\n\n*ID*   *NOMBRE*   *APELLIDO*   *CATEGORIA*\t\n");
    for(int i = 0; i < tamL; i++)
    {
            if(lista[i].estado == 1 && flag == 0)
            {
                mostrarProgramador(lista, tamL, categorias, tamC);
                flag = 1;
            }
    }
}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProyecto"
 * \param proyecto Es el array a mostrar
 * \param tamY es el tamaño del array de estructuras "eProyecto"
 * \param lista es el array de programadores
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \return void
 */
void mostrarProyecto(eProyecto proyecto[], int tamY, eProgramador lista[], int tamL)
{
    for(int i = 0; i < tamY; i++)
    {
        if(proyecto[i].estado == 1)
        {
            printf("\n%d\t %s\t", proyecto[i].idProyecto, proyecto[i].nombre);
        }
    }
}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProyecto"
 * \param proyecto Es el array a mostrar
 * \param tamY es el tamaño del array de estructuras "eProyecto"
 * \param lista es el array de programadores
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \return void
 */
void mostrarProyectos(eProyecto proyectos[], int tamY, eProgramador lista[], int tamL)
{
    int flag = 0;
    printf("\n[LISTA DE PROYECTOS]\n");
    printf("\n\n*ID*\t*NOMBRE*\t");
    for(int i = 0; i < tamY; i++)
    {
            if(proyectos[i].estado == 1 && flag == 0)
            {
                mostrarProyecto(proyectos, tamY, lista, tamL);
                flag = 1;
            }
    }
}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProyecto"
 * \param proyecto Es el array a mostrar
 * \param tamY es el tamaño del array de estructuras "eProyecto"
 * \param lista es el array de programadores
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \return void
 */
void mostrarProyectoCant(eProyecto proyecto[], int tamY, eProgramador lista[], int tamL)
{
    for(int i = 0; i < tamY; i++)
    {
        if(proyecto[i].estado == 1)
        {
            printf("\n%d\t %s\t   %d\t   %d\t %d\t", proyecto[i].idProyecto, proyecto[i].nombre, proyecto[i].cantidadProg1, proyecto[i].cantidadProg2, proyecto[i].cantidadProg3);
        }
    }

}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProyecto"
 * \param proyecto Es el array a mostrar
 * \param tamY es el tamaño del array de estructuras "eProyecto"
 * \param lista es el array de programadores
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \return void
 */
void mostrarProyectosCant(eProyecto proyectos[], int tamY, eProgramador lista[], int tamL)
{
    int flag = 0;
    printf("\n[LISTA DE PROYECTOS]\n");
    printf("\n\n*ID*\t*NOMBRE*\t*C1*\t*C2*\t*C3*\t");
    for(int i = 0; i < tamY; i++)
    {
        if(proyectos[i].estado == 1 && flag == 0)
        {
            mostrarProyectoCant(proyectos, tamY, lista, tamL);
            flag = 1;
        }
    }
}


/**
 * \brief Asocia un índice del array de estructuras "eProgramador" a uno de "eProyecto" por medio de "eProgProy"
 * \param lista Es el array de programadores
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \param proyectos es el array de proyectos
 * \param tamY es el tamaño del array de estructuras "eProyecto"
 * \param progproy es el array de programadores y proyectos (asignados)
 * \param tamPP es el tamaño del array de estructuras "eProg_Proy"
 * \param categorias es el array de categorías
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void asignarProgramador(eProgramador lista[], int tamL, eProyecto proyectos[], int tamY, eProg_Proy progproy[], int tamPP, eCategoria categorias[], int tamC)
{
        int aux, aux2;
        int aux3;
        int flag = 0;

        ordenarProgramadores(lista, tamL, categorias, tamC);
        mostrarProgramadores(lista, tamL, categorias, tamC);

        printf("\n\nIngresar ID del programador elegido: ");
        scanf("%d", &aux);

        if(aux < 1 || aux > 50)
        {
            printf("ERROR! ID de programador invalido. Reingresar (1-50): ");
            scanf("%d", &aux);
        }

        mostrarProyectos(proyectos, tamY, lista, tamL);

        printf("\n\nIngresar ID del proyecto: ");
        scanf("%d", &aux2);

        if(aux2 < 100 || aux2 > 1100)
        {
            printf("ERROR! ID de proyecto invalido. Reingresar (100-1100): ");
            scanf("%d", &aux2);
        }

        printf("\n\nIngresar cantidad de horas a trabajar: ");
        scanf("%d", &aux3);

        for(int i = 0; i < tamL; i++)
        {
            if(lista[i].estado == 1 && lista[i].idProgramador == aux)
            {
                for(int j = 0; j < tamY; j++)
                {
                    if(proyectos[j].idProyecto == aux2)
                    {
                        for(int k = 0; k < tamPP; k++)
                        {
                                if(progproy[k].estado == 0)
                                {
                                   progproy[k].idProgramador = aux;
                                   progproy[k].idProyecto = aux2;
                                   lista[i].cantidadHoras = aux3;

                                   if(lista[i].idCategoria == 1)
                                   {
                                       proyectos[j].cantidadProg1++;
                                   }
                                   if(lista[i].idCategoria == 2)
                                   {
                                       proyectos[j].cantidadProg2++;
                                   }
                                   if(lista[i].idCategoria == 3)
                                   {
                                       proyectos[j].cantidadProg3++;
                                   }

                                   printf("El programador %d fue asignado al proyecto %d. Debera trabajar %d horas.", progproy[k].idProgramador, progproy[k].idProyecto, lista[i].cantidadHoras);
                                   progproy[k].estado = 1;
                                   flag = 1;
                                   break;
                                }
                            }

//                            else
//                            {
//                                printf("ERROR! Este programador ya fue asignado al proyecto.\n\n");
//                                flag = 1;
//                                break;
//                            }
                        }
                    }
                }
            }
                               if(flag == 0)
                               {
                                    printf("NO HAY ESPACIO!!!");
                               }
}



/**
 * \brief Obtiene la descripción de ID del array de estructuras "eCategoria" y la copia en un auxiliar
 * \param descripcion Es el array auxiliar donde se guarda el dato obtenido
 * \param categorias Es el array de categorías donde se busca la descripción
 * \param tam es el tamaño del array de estructuras "eCategoria"
 * \param idCat es el ID correspondiente a la descripción buscada
 * \return void
 */
void obtenerDescripcion(char descripcion[], eCategoria categorias[], int tam, int idCat)
{
    int flag = 0;
    int i;
    for(i=0; i< tam; i++)
    {
        if(flag == 0 && categorias[i].idCategoria == idCat)
        {
            strcpy(descripcion, categorias[i].descripcion);
            flag = 1;
        }
    }
}


/**
 * \brief Obtiene el pago por hora del array de estructuras "eCategoria" y lo copia en un auxiliar
 * \param suma Es el entero auxiliar donde se guarda el dato obtenido
 * \param categorias Es el array de categorías donde se busca el valor
 * \param tam es el tamaño del array de estructuras "eCategoria"
 * \param idCat es el ID correspondiente al valor buscado
 * \return void
 */
int obtenerSumaACobrar(int suma, eCategoria categorias[], int tam, int idCat)
{
    int i;
    for(i=0; i< tam; i++)
    {
        if(categorias[i].idCategoria == idCat)
        {
            suma = categorias[i].pagoPorHora;
            return suma;
        }
    }
            return 0;
}

int obtenerCantHoras(int cant, eProgramador lista[], int tam, int cantHoras)
{
    int i;
    for(i=0; i< tam; i++)
    {
        if(lista[i].cantidadHoras == cantHoras)
        {
            cant = lista[i].cantidadHoras;
            return cant;
        }
    }
            return 0;
}

/**
 * \brief Muestra por pantalla datos del array de estructuras "eProgramador" asociados a "eProyecto" por medio de "eProgProy"
 * \param lista Es el array a mostrar
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \param progproy es el array de programadores y proyectos (asignados)
 * \param tamPP es el tamaño del array de estructuras "eProg_Proy"
 * \param proyectos es el array de proyectos
 * \param tamY es el tamaño del array de estructuras "eProyecto"
 * \param categorias es el array de categorias
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void mostrarProg_Proy(eProgramador lista[], int tamL, eProg_Proy progproy[], int tamPP, eProyecto proyectos[], int tamY, eCategoria categorias[], int tamC)
{
    int i, j, k;
    char descripcionCat[20];
    int suma;
    int cantHoras;
    mostrarProgramadores(lista, tamL, categorias, tamC);

    printf("\n\n[LISTA DE PROGRAMADORES ORDENADOS POR ID Y SUS PROYECTOS]\n");
    printf("\n\n*ID*   *NOMBRE*   *APELLIDO*   *CATEGORIA*   *PROYECTO*    *SUMA A COBRAR*\t\n");
    for(i = 0; i < tamL; i++)
    {
        for(j = 0; j < tamPP; j++)
        {
            if(lista[i].estado == 1 && lista[i].idProgramador == progproy[j].idProgramador)
            {
                for(k = 0; k < tamY; k++)
                {
                    if(proyectos[k].estado == 1 && proyectos[k].idProyecto == progproy[j].idProyecto)
                    {
                        obtenerDescripcion(descripcionCat, categorias, tamC, lista[i].idCategoria);
                        suma = obtenerSumaACobrar(suma, categorias, tamC, lista[i].idCategoria);
                        cantHoras = obtenerCantHoras(cantHoras, lista, tamL, lista[i].cantidadHoras);

                        printf("\n%d    %s     %s     %s     %s     %d", lista[i].idProgramador, lista[i].nombre, lista[i].apellido, descripcionCat, proyectos[k].nombre, (suma * cantHoras));
                    }
                }
            }
        }
    }
}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProgramador" y "eProyecto"
 * \param lista Es el array a mostrar
 * \param tamL es el tamaño del array de estructuras "eProgramador"
 * \param proyectos es el array de proyectos
 * \param tamY es el tamaño del array de estructuras "eProyecto"
 * \param progproy es el array de programadores y proyectos (asignados)
 * \param tamPP es el tamaño del array de estructuras "eProg_Proy"
 * \param categorias es el array de categorias
 * \param tamC es el tamaño del array de estructuras "eCategoria"
 * \return void
 */
void mostrarProyectosProg(eProgramador lista[], int tamL, eProyecto proyectos[], int tamY, eProg_Proy progproy[], int tamPP, eCategoria categorias[], int tamC)
{
    int i, j, k;
    int aux;

    ordenarProgramadores(lista, tamL, categorias, tamC);
    mostrarProgramadores(lista, tamL, categorias, tamC);

    printf("\n\nIngrese ID del programador: ");
    scanf("%d", &aux);

    printf("\n\nID PROGRAMADOR    NOMBRE   APELLIDO     PROYECTO     CANT HORAS");
    for(i = 0; i < tamL; i++)
    {
        if(lista[i].idProgramador == aux)
        {
            for(j = 0; j < tamY; j++)
            {
                if(lista[i].estado == 1 && lista[i].idProgramador == progproy[j].idProgramador)
                {
                    for(k = 0; k < tamY; k++)
                    {
                        if(proyectos[k].idProyecto == progproy[j].idProyecto)
                        {
                            printf("\n%d                   %s     %s     %s    %d", lista[i].idProgramador, lista[i].nombre, lista[i].apellido, proyectos[k].nombre, lista[i].cantidadHoras);
                        }
                    }
                }
            }
        }
    }
}


/**
 * \brief Muestra por pantalla datos del array de estructuras "eProyecto" y "eProgramador" e informa cuál es el proyecto con más programadores asignados
 * \param proyectos Es el array a mostrar
 * \param tam es el tamaño del array de estructuras "eProyecto"
 * \param progproy es el array de estructuras "eProg_Proy"
 * \return void
 */
void proyectoDemandante(eProyecto proyectos[], int tam, eProg_Proy progproy[])
{
    eProyecto proyectoMax[5];
    int i, j, k;
    int max;
    int proyMax = 0;
    char nproyMax[30];

    for(i = 0; i < 5; i++)
    {
        proyectoMax[i].idProyecto = proyectos[i].idProyecto;
        proyectoMax[i].cont = 0;
    }

    for(j = 0; j < 5; j++)
    {
        for(k = 0; k < 5; k++)
        {
            if(proyectos[j].idProyecto == progproy[k].idProyecto)
            {
                proyectoMax[j].cont++;
            }
        }
            if(j == 0 || proyectoMax[j].cont > max)
            {
                max = proyectoMax[j].cont;
                proyMax = proyectoMax[j].idProyecto;
                strcpy(nproyMax, proyectos[j].nombre);
            }
    }

            printf("PROYECTO     CANT PROGRAMADORES");
            for(j = 0; j < 5; j++)
            {
                printf("\n%d            %d\n", proyectoMax[j].idProyecto, proyectoMax[j].cont);
            }

            if(max == 0)
            {
                printf("\nNo hay programadores asignados a ningun proyecto.\n");
            }
            else
            {
                printf("\nEl proyecto con mas programadores es: %s %d con %d programador(es)\n", nproyMax, proyMax, max);
            }
}


/**
 * \brief Busca en el array de programadores un índice que contenga determinado ID y devuelve el índice encontrado
 * \param lista Es el array donde se busca el índice por ID
 * \param idAux es el ID auxiliar que se busca en el array de estructuras "eProgramador"
 * \param tam es el tamaño del array de estructuras "eProgramador"
 * \return index El índice si fue encontrado, si no -1
 */
int buscarPorID(eProgramador lista[], int idAux, int tam)
{
        int index = -1;

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].idProgramador == idAux)
            {
                index = i;
                break;
            }
        }
                return index;
}


/**
 * \brief Solicita un texto al usuario y lo guarda, verificando que solo contenga letras
 * \param requestMessage Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \param arrayLength Valor que indica el largo del array
 * \return void
 */
void getStringAlpha(char requestMessage[], char input[], int arrayLength)
{
    char aux[256];
    getString(requestMessage, aux);
    if(itsAlpha(aux))
    {
        strcpy(input, aux);
        strlwr(input);
        input[0] = toupper(input[0]);
        for(int i = 0; i < arrayLength; i++)
        {
            if(isspace(input[i]) != 0)
            {
                input[i+1] = toupper(input[i+1]);
            }
        }
    }
    else
    {
        printf("ERROR! Nombre invalido.\n");
        getString(requestMessage, aux);
        strcpy(input, aux);
        strlwr(input);
        input[0] = toupper(input[0]);
        for(int i = 0; i < arrayLength; i++)
        {
            if(isspace(input[i]) != 0)
            {
                input[i+1] = toupper(input[i+1]);
            }
        }
    }
}

/**
 * \brief Valida que el dato ingresado por el usuario no exceda el tamaño del array
 * \param requestMessage Es el mensaje que se muestra en pantalla para reingresar en caso de error
 * \param input Es el dato a validar
 * \param arrayLength Es el tamaño del array
 * \return void
 */
void validateRangeStr(char requestMessage[], char input[], int arrayLength)
{
        if(strlen(input) > arrayLength - 1)
        {
            printf("ERROR! El nombre es muy largo.\n");
            getString(requestMessage, input);
        }
            strlwr(input);
            input[0] = toupper(input[0]);
            for(int i = 0; i < arrayLength; i++)
            {
                if(isspace(input[i]) != 0)
                {
                    input[i+1] = toupper(input[i+1]);
                }
            }
}

/**
 * \brief Toma un dato tipo string ingresado por el usuario, valida que los caracteres sean dígitos, transforma el string a entero y lo devuelve
 * \param requestMessage Es el mensaje que se muestra en pantalla
 * \param input Es el dato ingresado por el usuario
 * \param arrayLength Es el tamaño del string
 * \return auxInt Devuelve el dato transformado a entero
 */
int getValidInt(char requestMessage[], char input[], int arrayLength)
{
    int flag, auxInt;

    printf("%s", requestMessage);
    scanf("%s", input);

    flag = 0;
    arrayLength = strlen(input);
    for(int i = 0; i < arrayLength; i++)
    {
        if(!isdigit(input[i]))
        {
            flag = 1;
            break;
        }
    }
           if(flag == 0)
           {
                auxInt = atoi(input);
           }
                return auxInt;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si tiene otro tipo de caracteres
 */
int itsAlpha(char str[])
{
        int i = 0;

        while(str[i] != '\0')
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
                return 0;
                i++;
        }
                return 1;
}

/**
 * \brief Solicita un texto al usuario y lo guarda
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[], char input[])
{
        printf("%s", mensaje);
        fflush(stdin);
        gets(input);
}


/**
 * \brief Valida que el dato pasado por parámetro esté dentro del rango deseado y lo devuelve
 * \param value Es el dato entero a validar
 * \param errorMessage Es el mensaje que se muestra en pantalla si el número no está dentro del rango
 * \param lowLim Es el límite inferior del rango a validar
 * \return hiLim Es el límite superior del rango a validar
 */
int validateRangeInt(int value, char errorMessage[], int lowLim, int hiLim)
{
    if(value >= lowLim && value <= hiLim)
    {
        return value;
    }
    else
    {
        printf("%s", errorMessage);
        scanf("%d", &value);
        return value;
    }
}

/**
 * \brief Obtiene el primer índice libre del array y lo devuelve
 * \param peopleArray Es el array que se pasa como parametro.
 * \param arrayLength Es el tamaño del array "peopleArray"
 * \return index El primer lugar disponible
 */
int findEmptyPlace(eProgramador lista[], int arrayLength)
{
        int index = -1;

        for(int i = 0; i < arrayLength; i++)
        {
            if(lista[i].estado == 0)
            {
                index = i;
                break;
            }
        }
                return index;
}
