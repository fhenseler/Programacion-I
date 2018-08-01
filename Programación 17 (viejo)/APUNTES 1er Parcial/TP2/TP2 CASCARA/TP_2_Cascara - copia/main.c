#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define LEN 20

int main()
{
SPerson APerson[LEN];
int opt = 0;
initializeArray(APerson, LEN);

    do
    {
        system("cls");
        opt = menu(opt);

        switch(opt)
        {
            case 1:
                    addPerson(APerson, LEN);
                    break;
            case 2:
                    removePerson(APerson, LEN);
                    break;
            case 3:
                    sortByName(APerson, LEN);
                    printList(APerson, LEN);
                    break;
            case 4:
                    printGraph(APerson, LEN);
                    break;
        }

    }while(opt != 5);

                    return opt;
}


