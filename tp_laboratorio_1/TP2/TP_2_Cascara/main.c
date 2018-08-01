#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    SPerson peopleArray[LENGTH];
    int option = 0;
    char value[LENGTH];

    setStatus(peopleArray, LENGTH, 0);

    do
    {
        system("cls");
        showMenu();
        option = getValidInt("\nSeleccione opcion (1-5): ", value, LENGTH);

        switch(option)
        {
            case 1: //AGREGAR PERSONA
                    addPerson(peopleArray, LENGTH);
                    break;
            case 2: //BORRAR PERSONA
                    removePerson(peopleArray, LENGTH);
                    break;
            case 3: //IMPRIMIR LISTA ORDENADA POR NOMBRE
                    showPeopleArray(peopleArray, LENGTH);
                    break;
            case 4: //IMPRIMIR GRÁFICO DE EDADES
                    printGraph(peopleArray, LENGTH);
                    break;
            case 5: //SALIR
                    break;
            default:
                    printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
                    system("pause");
                    break;
        }
    }while(option != 5);

                    return 0;
}
