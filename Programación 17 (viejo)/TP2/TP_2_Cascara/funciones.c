#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/**
 * \brief Muestra el menú de opciones
 * \return void
 */
void showMenu(void)
{
    printf("-----------MENU DE OPCIONES-----------");
    printf("\n--------------------------------------");
    printf("\n1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
    printf("--------------------------------------");
    printf("\n--------------------------------------");
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
 * \brief Inicializa el campo de estado para poder utilizarlo como flag e indicar si el ítem del array esta ocupado o no.
 * \param peopleArray Es el array a inicializar
 * \param arrayLength Es el tamaño del array "peopleArray"
 * \param value Es el valor que se asignará al campo de estado (1- Activo, 0- Inactivo)
 * \return void
 */
void setStatus(SPerson peopleArray[], int arrayLength, int value)
{
    for(int i = 0; i < arrayLength; i++)
    {
        peopleArray[i].status = value;
    }
}


/**
 * \brief Toma datos ingresados por el usuario, los valida y al cargar cada ítem del array de estructuras cambia el flag de estado para avisar que dicho ítem está ocupado.
 * \param peopleArray Es el array a cargar
 * \param arrayLength Es el tamaño del array "peopleArray"
 * \return returnValue 1 si el ítem del array fue cargado satisfactoriamente
 */
int addPerson(SPerson peopleArray[], int arrayLength)
{
        printf("\n[DAR DE ALTA]\n");
        int freeIndex;
        char inputAux[200];
        int returnValue = 0;

        freeIndex = findEmptyPlace(peopleArray, LENGTH);
        if(freeIndex == -1)
        {
            printf("\n\nERROR! NO QUEDAN LUGARES LIBRES!\n\n");
            system("pause");
        }

        for(int i = 0; i < arrayLength; i++)
        {
            if(peopleArray[i].status == 0)
            {
                getStringAlpha("\nIngrese nombre: ", inputAux, 200);
                strcpy(peopleArray[i].name, inputAux);

                validateRangeStr("Reingrese nombre: ", peopleArray[i].name, 20);

                peopleArray[i].age = getValidInt("Ingrese edad: ", inputAux, LENGTH);
                peopleArray[i].age = validateRangeInt(peopleArray[i].age, "ERROR! La edad puede ir de 1 a 120. Reingrese: ", 1, 120);

                peopleArray[i].id = getValidInt("Ingrese DNI: ", inputAux, LENGTH);
                peopleArray[i].id = validateRangeInt(peopleArray[i].id, "ERROR! El DNI consta de 7 u 8 digitos. Reingrese: ", 1000000, 100000000);

                i = findPersonById(peopleArray, peopleArray[i].id, LENGTH);
                if(i != -1 && peopleArray[i].status== 1)
                {
                    printf("ERROR! Este DNI ya fue registrado.\n\n");
                    system("pause");
                    break;
                }

                    peopleArray[i].status = 1;
                    returnValue = 1;
                    printf("\n\n***PERSONA AGREGADA AL SISTEMA***\n\n");
                    system("pause");
                    break;
            }
        }
                    return returnValue;
}


/**
 * \brief Busca un DNI ingresado por el usuario, si lo encuentra, realiza una baja lógica del mismo cambiando el campo de estado
 * \param peopleArray Es el array a ser dado de baja
 * \param arrayLength Es el tamaño del array "persona"
 * \return returnValue 1 si el ítem del array fue dado de baja satisfactoriamente
 */
int removePerson(SPerson peopleArray[], int arrayLength)
{
        printf("\n[DAR DE BAJA]\n");
        char input[10];
        int aux;
        char answer;
        int returnValue = 0;

        aux = getValidInt("Ingrese DNI a eliminar: ", input, LENGTH);
        aux = validateRangeInt(aux, "ERROR! El DNI consta de 7 u 8 digitos. Reingrese: ", 1000000, 100000000);

        for(int i = 0; i < arrayLength; i++)
        {
            i = findPersonById(peopleArray, aux, LENGTH);
            if(i == -1)
            {
                printf("ERROR! DNI INVALIDO");
                aux = getValidInt("\nIngrese DNI a eliminar: ", input, LENGTH);
                aux = validateRangeInt(aux, "ERROR! El DNI consta de 7 u 8 digitos. Reingrese: ", 1000000, 100000000);
                continue;
            }

            if(i != -1 && peopleArray[i].status == 1)
            {
                printf("\n\n*DNI*     *Nombre*   *Edad*\n\n");
                printf("%d  %s    %d\n", peopleArray[i].id, peopleArray[i].name, peopleArray[i].age);

                printf("\nEsta seguro de realizar esta accion? (S/N): ");
                fflush(stdin);
                answer = toupper(getchar());

                if(answer != 'S' && answer != 'N')
                {
                    printf("\nRespuesta Incorrecta! Ingrese (S/N): ");
                    fflush(stdin);
                    answer = toupper(getchar());
                }
                if(answer == 'S')
                {
                    peopleArray[i].status = 0;
                    returnValue = 1;
                    printf("\n***PERSONA ELIMINADA!***\n\n");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\n***ACCION CANCELADA!***\n\n");
                    system("pause");
                    break;
                }
            }
        }
                    return returnValue;
}

/**
 * \brief Ordena a las personas (elementos del array de estructuras) por nombre (1er criterio) o DNI (2do criterio)
 * \param peopleArray Es el array donde están las personas a ser ordenadas
 * \param arrayLength Es el tamaño del array "peopleArray"
 * \return void
 */
void sortPeopleArray(SPerson peopleArray[], int arrayLength)
{
    int aux;
    char auxString[100];

    for(int i = 0; i < arrayLength-1; i++)
    {
        for(int j = i+1; j < arrayLength; j++)
        {
            if(peopleArray[i].status == 1 && peopleArray[j].status == 1)
            {
                if(strcmp(peopleArray[i].name, peopleArray[j].name)>0)
                {
                    strcpy(auxString, peopleArray[i].name);
                    strcpy(peopleArray[i].name, peopleArray[j].name);
                    strcpy(peopleArray[j].name, auxString);

                    aux = peopleArray[i].id;
                    peopleArray[i].id = peopleArray[j].id;
                    peopleArray[j].id = aux;

                    aux = peopleArray[i].age;
                    peopleArray[i].age = peopleArray[j].age;
                    peopleArray[j].age = aux;

                    aux = peopleArray[i].status;
                    peopleArray[i].status = peopleArray[j].status;
                    peopleArray[j].status = aux;
                    break;
                }
                else
                {
                    if(strcmp(peopleArray[i].name, peopleArray[j].name)==0)
                    {
                        if(peopleArray[i].id > peopleArray[j].id)
                        {
                            aux = peopleArray[i].id;
                            peopleArray[i].id = peopleArray[j].id;
                            peopleArray[j].id = aux;

                            aux = peopleArray[i].age;
                            peopleArray[i].age = peopleArray[j].age;
                            peopleArray[j].age= aux;

                            aux = peopleArray[i].status;
                            peopleArray[i].status = peopleArray[j].status;
                            peopleArray[j].status = aux;
                            break;
                        }
                    }
                }
            }
        }
    }
}


/**
 * \brief Muestra la lista de personas ordenadas por nombre
 * \param peopleArray Es el array donde están los elementos a ser mostrados
 * \param arrayLength Es el tamaño del array "peopleArray"
 * \return void
 */
void showPeopleArray(SPerson peopleArray[], int arrayLength)
{
    printf("\n[LISTA DE PERSONAS ORDENADAS POR NOMBRE]\n");
    printf("\n    DNI   |         NOMBRE       |    EDAD   |\n");
    printf("----------+----------------------+-----------|");
    for(int i = 0; i < arrayLength; i++)
    {
        if(peopleArray[i].id != 0 && peopleArray[i].status == 1)
        {
            sortPeopleArray(peopleArray, LENGTH);
            printf("\n %d | %-20s |    %3d    |", peopleArray[i].id, peopleArray[i].name, peopleArray[i].age);
        }
    }
            printf("\n----------+----------------------+-----------|");
            printf("\n\n");
            system("pause");
}

/**
 * \brief Obtiene el primer índice libre del array y lo devuelve
 * \param peopleArray Es el array que se pasa como parametro.
 * \param arrayLength Es el tamaño del array "peopleArray"
 * \return index El primer lugar disponible
 */
int findEmptyPlace(SPerson peopleArray[], int arrayLength)
{
        int index = -1;

        for(int i = 0; i < arrayLength; i++)
        {
            if(peopleArray[i].status == 0)
            {
                index = i;
                break;
            }
        }
                return index;
}


/**
 * \brief Obtiene el índice que coincide con el DNI pasado por parametro y lo devuelve.
 * \param peopleArray Es el array que se pasa como parametro.
 * \param idAux Es el DNI a ser buscado en el array.
 * \param arrayLength Es el largo del array "peopleArray"
 * \return index Es el índice en donde se encuentra el elemento que coincide con el parámetro DNI
 */
int findPersonById(SPerson peopleArray[], int idAux, int arrayLength)
{
        int index = -1;

        for(int i = 0; i < arrayLength; i++)
        {
            if(peopleArray[i].id == idAux)
            {
                index = i;
                break;
            }
        }
                return index;
}

/**
 * \brief Imprime un gráfico de barras, ordenando los datos del array por rango etario
 * \param peopleArray Es el array que provee los datos del gráfico
 * \param arrayLength Es la cantidad de elementos del array
 * \return void
 */
void printGraph(SPerson peopleArray[], int arrayLength)
{
    int upTo18 = 0, from19To35 = 0, over35 = 0, flag = 0, max;

     printf("\n[GRAFICO DE BARRAS]\n\n\n");
     for(int i = 0; i < arrayLength; i++)
     {
        if(peopleArray[i].status == 1)
        {
            if(peopleArray[i].age <= 18)
            {
                upTo18++;
            }
                else
                {
                    if(peopleArray[i].age >= 19 && peopleArray[i].age <= 35)
                    {
                        from19To35++;
                    }
                    else
                    {
                        over35++;
                    }
                }
        }
    }

                    if(upTo18 >= from19To35 && upTo18 >= over35)
                    {
                        max = upTo18;
                    }
                    else
                    {
                        if(from19To35 >= upTo18 && from19To35 >= over35)
                        {
                            max = from19To35;
                        }
                            else
                            {
                                max = over35;
                            }
                    }

                            for(int i = max; i > 0; i--)
                            {
                                printf("%02d|", i);

                                if(i <= upTo18)
                                {
                                    printf("%c", 219);
                                }
                                if(i <= from19To35)
                                {
                                    flag = 1;
                                    printf("\t%c", 219);
                                }
                                if(i <= over35)
                                {
                                    if(flag == 0)
                                    {
                                        printf("\t\t%c", 219);
                                    }
                                    if(flag == 1)
                                    {
                                        printf("\t%c", 219);
                                    }
                                }
                                        printf("\n");
                            }

                                        printf("--+-----------------");
                                        printf("\n  |<18\t19-35\t>35");
                                        printf("\n   %d\t%d\t%d", upTo18, from19To35, over35);
                                        printf("\n\n");
                                        system("pause");
}
