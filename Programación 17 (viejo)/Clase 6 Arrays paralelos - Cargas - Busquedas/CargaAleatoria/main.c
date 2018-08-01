#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main(void)
{
int vInt[MAX], indiceArray, i;
char seguir = 's';

    for(i = 0; i < MAX; i++)
    {
        vInt[i] = 0; //Inicializamos vector
    }

    do
    {
        printf("\nIngrese indice: ");
        scanf("%d",&indiceArray);

        printf("\nIngrese valor a cargar en el vector: ");
        scanf("%d", &vInt[indiceArray]);

        printf("\nDesea ingresar otro dato S/N?\n");
        seguir = tolower(getch(seguir));

    }while(seguir == 's');

       printf("\nEl vector cargado es: ");
        for(i = 0; i < MAX; i++)
        {
            printf("%d ", vInt[i]);
        }

        getch();
        return 0;
}
