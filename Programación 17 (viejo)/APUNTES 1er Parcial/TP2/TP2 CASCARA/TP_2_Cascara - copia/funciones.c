#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

/**
 * \brief Muestra un menú de opciones y solicita al usuario que ingrese la opción elegida
 * \return Devuelve la opción seleccionada por el usuario
 */
int menu()
{
        int opt;
        printf("-----------MEN%c DE OPCIONES-----------", 233);
        printf("\n--------------------------------------");
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir gr%cfico de edades\n\n", 160);
        printf("5- Salir\n");
        printf("--------------------------------------");
        printf("\n--------------------------------------");

        do
        {
            printf("\n\nSeleccione opci%cn: ", 162);
            scanf("%d", &opt);
            return opt;
        }while(opt < 1 || opt > 5);
            return 0;
}

/**
 * \brief Inicializa el array de personas en 0
 * \param APerson Es el array de personas a inicializar
 * \param LEN Es la cantidad de elementos del array
 * \return void
 */
void initializeArray(SPerson APerson[], int LEN)
{
        int i;
        for(i = 0; i < LEN; i++)
        {
            APerson[i].stateFlag = 0;
        }
            return;
}


/**
 * \brief Busca un índice libre en el array y al encontrarlo lo retorna
 * \param APerson Es el array donde se busca el espacio libre
 * \param LEN Es la cantidad de elementos del array
 * \return Indice espacio libre
 */
int getFreeIndex(SPerson APerson[],int LEN)
{
    int i;
    for(i=0; i < LEN; i++)
    {
        if(APerson[i].stateFlag == 0)
        {
            return i;
        }
    }
            return -1;
}

/**
 * \brief Carga una persona al array de personas, validando que se ingresen correctamente los datos
 * \param APerson Es el array donde se agrega la persona
 * \param LEN Es la cantidad de elementos del array
 * \return void
 */
void addPerson(SPerson APerson[], int LEN)
{
        int i;
        int freeIndex;
        char auxNameStr[50];
        char auxAgeStr[50];
        char auxIdStr[50];
        int auxId;
        int auxAge;

        freeIndex = getFreeIndex(APerson, LEN);
        if(freeIndex == -1)
        {
            printf("\n\nERROR! NO QUEDAN LUGARES LIBRES!\n");
            getch();
            return;
        }
        else{
            if(!getStringLetras("NOMBRE: ", auxNameStr)){
                printf("ERROR! El nombre debe estar compuesto solo por letras.\n");
                getch();
                return;
               }
            if(!getStringNumeros("EDAD: ", auxAgeStr))
            {
                printf("ERROR! La edad debe estar compuesta solo por n%cmeros", 163);
                getch();
                return;
            }
            if(!getStringNumeros("DNI: ", auxIdStr))
            {
                printf("ERROR! El DNI debe estar compuesto solo por n%cmeros", 163);
                getch();
                return;
            }

            auxAge = atoi(auxAgeStr);
            auxId = atoi(auxIdStr);

            for(i = 0; i < LEN; i++)
            {
                if(auxId == APerson[i].id)
                {
                        printf("\n\nERROR! ESTE DNI YA FUE DADO DE ALTA!\n");
                        getch();
                        return;
                }
            }
        }
                        strcpy(APerson[freeIndex].name, auxNameStr);
                        APerson[freeIndex].age = auxAge;
                        APerson[freeIndex].id = auxId;
                        APerson[freeIndex].stateFlag = 1;
                        return;
}


/**
 * \brief Busca el DNI correspondiente al índice del array
 * \param APerson Es el array donde se busca el DNI
 * \param auxId Es el DNI que se busca en el array
 * \param LEN Es la cantidad de elementos del array
 * \return Si encuentra el DNI correspondiente al índice lo devuelve, si no devuelve -1
 */
int idSearch(SPerson APerson[], int auxId, int LEN)
{
    int i;

    for(i = 0; i < LEN; i++)
    {
        if(APerson[i].id == auxId)
        {
            return i;
        }
    }
            return -1;
}


/**
 * \brief Borra una persona del array de personas por medio del DNI(ID)
 * \param APerson Es el array donde se encuentra la persona a borrar
 * \param LEN Es la cantidad de elementos del array
 * \return void
 */
void removePerson(SPerson APerson[], int LEN)
{
    int i, auxId;

    printf("Ingrese DNI a borrar: ");
    scanf("%d", &auxId);
    i = idSearch(APerson, auxId, LEN);
            if(i == -1)
            {
                printf("ERROR! DNI INV%cLIDO", 181);
                getch();
                return;
            }
            else{
                    if(APerson[i].stateFlag == 1)
                    {
                        APerson[i].stateFlag = 2;
                        printf("EL DNI FUE DADO DE BAJA");
                        getch();
                        return;
                    }
                        if(APerson[i].stateFlag == 2)
                        {
                            printf("ERROR! ESTE DNI YA HAB%cA SIDO DADO DE BAJA", 214);
                            getch();
                            return;
                        }
            }
                            return;
}

/**
 * \brief Ordena a las personas (elementos del array) por nombre
 * \param APerson Es el array donde están las personas a ser ordenadas
 * \param LEN Es la cantidad de elementos del array
 * \return void
 */
void sortByName(SPerson APerson[], int LEN)
{
    int i, j;
    SPerson aux;
    for(i = 0; i < LEN - 1; i++)
    {
        for(j = i+1; j < LEN; j++)
        {
            if(strcmp(APerson[i].name, APerson[j].name) > 0)
            {
                aux = APerson[i];
                APerson[i] = APerson[j];
                APerson[j] = aux;
            }
        }
    }
                return;
}

/**
 * \brief Imprime la lista de personas ordenadas por nombre
 * \param APerson Es el array a ser impreso por pantalla
 * \param LEN Es la cantidad de elementos del array
 * \return void
 */
void printList(SPerson APerson[], int LEN)
{
    int i;
    printf("\nNOMBRE -- EDAD -- DNI\t\n");
    for(i = 0; i < LEN; i++)
    {
        if(APerson[i].stateFlag == 1)
        {
            printf("\n%s -- %d -- %ld\t\n", APerson[i].name, APerson[i].age, APerson[i].id);
        }
    }
        getch();
        return;
}


/**
 * \brief Imprime un gráfico de barras, ordenando los datos del array por edades
 * \param APerson Es el array que provee los datos del gráfico
 * \param LEN Es la cantidad de elementos del array
 * \return void
 */
void printGraph(SPerson APerson[], int LEN)
{
    int i, upTo18 = 0, from19To35 = 0, over35 = 0, flag = 0, max;

     for(i = 0; i < LEN; i++)
     {
        if(APerson[i].stateFlag == 1)
        {
            if(APerson[i].age <= 18)
            {
                upTo18++;
            }
                else
                {
                    if(APerson[i].age >= 19 && APerson[i].age <= 35)
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


    if(upTo18 >= from19To35 && upTo18 >= over35){
        max = upTo18;
    }
        else{
            if(from19To35 >= upTo18 && from19To35 >= over35)
            {
                max = from19To35;
            }
                else
                {
                max = over35;
                }
        }

    for(i = max; i > 0; i--)
    {
        printf("%02d|", i);

        if(i <= upTo18)
        {
            printf("*");
        }
        if(i <= from19To35)
        {
            flag = 1;
            printf("\t*");
        }
        if(i <= over35)
        {
            if(flag == 0)
            {
                printf("\t\t*");
            }
            if(flag == 1)
            {
                printf("\t*");
            }
        }
                printf("\n");
    }

                printf("--+-----------------");
                printf("\n  |<18\t19-35\t>35");
                printf("\n   %d\t%d\t%d", upTo18, from19To35, over35);
                getch();
                return;
}


