#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int edad[MAX], edadAux, flagEncontrado = 0;

    for(int i = 0; i < MAX; i++)
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad[i]);
    }

    printf("Ingrese dato a buscar: ");
    scanf("%d", &edadAux);

    for(int i = 0; i < MAX; i++)
    {
        if(edadAux == edad[i])
        {
            printf("Edad encontrada: %d", edad[i]);
            flagEncontrado = 1;
            break;
        }
    }

        if(flagEncontrado == 0)
        {
            printf("No se encontro la edad buscada. Reingrese: ");
            scanf("%d", &edadAux);
        }

        getch();
        return 0;
}

