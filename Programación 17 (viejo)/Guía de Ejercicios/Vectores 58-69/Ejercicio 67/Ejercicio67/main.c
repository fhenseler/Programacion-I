#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int menu(void);
void mostrarIndice(int[], int[]);
void mostrarNumero(int[], int[]);

int main()
{
    int opt = 0, vInt[MAX] = {5, 4, 18, 3, 1} , indice[MAX] = {0, 1, 2, 3, 4};

    do
    {
        system("cls");
        opt = menu();

        switch(opt)
        {
            case 1:
                    mostrarIndice(vInt, indice);
                    getch();
                    break;
            case 2:
                    mostrarNumero(indice, vInt);
                    getch();
                    break;
        }

    }while(opt != 3);

    return 0;
}

int menu(void)
{
    int opt;
    printf("\n1 - Ingresar numero y mostrar en que posicion del vector se encuentra");
    printf("\n2 - Ingresar posicion del vector y mostrar el numero que se encuentra");
    printf("\n3 - Salir");

    do
    {
        printf("\nSeleccione opcion: ");
        scanf("%d", &opt);
        return opt;
    }while(opt < 1 || opt > 3);
}

void mostrarIndice(int vInt[], int indice[])
{
    int num, flagEncontrado = 0;

    printf("\nIngrese numero: ");
    scanf("%d", &num);

    for(int i = 0; i < MAX; i++)
    {
        if(num == vInt[i])
        {
            printf("\nEl numero %d se encuentra en el indice %d", num, indice[i]);
            flagEncontrado = 1;
            break;
        }
    }

        if(flagEncontrado == 0)
        {
            printf("\nNo se encontro el numero buscado.");
        }
}

void mostrarNumero(int indice[], int vInt[])
{
    int num, flagEncontrado = 0;

    printf("\nIngrese indice: ");
    scanf("%d", &num);

    for(int i = 0; i < MAX; i++)
    {
        if(num == indice[i])
        {
            printf("\nEl numero que se encuentra en el indice %d es %d", num, vInt[i]);
            flagEncontrado = 1;
            break;
        }
    }

        if(flagEncontrado == 0)
        {
            printf("\nNo se encontro el indice buscado.");
        }
}
