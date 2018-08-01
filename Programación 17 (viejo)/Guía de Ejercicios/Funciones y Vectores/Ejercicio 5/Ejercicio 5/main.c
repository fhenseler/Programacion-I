#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5

void cargaArray(int[]);
void obtenerMax(int[]);
void ordenAscendente(int[]);
void printArray(int[]);
void sumaArray(int[]);
void busquedaArray(int[]);

int main()
{
    int vInt[MAX_ARRAY];

    cargaArray(vInt);
    obtenerMax(vInt);
    ordenAscendente(vInt);
    printArray(vInt);
    sumaArray(vInt);
    busquedaArray(vInt);

    getch();
    return 0;
}

void cargaArray(int vInt[])
{
    printf("\n\nCARGA ARRAY\n");
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("\nIngrese numero en el indice [%d]: ", i);
        scanf("%d", &vInt[i]);
    }

    printf("\nEl array cargado es: ");
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("%d ", vInt[i]);
    }
}

void obtenerMax(int vInt[])
{
    int numMax;
    printf("\n\nNUMERO MAXIMO\n");
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        if(i == 0 || vInt[i] > numMax)
        {
            numMax = vInt[i];
        }
    }
        printf("\n%d es el numero maximo\n", numMax);
}

void ordenAscendente(int vInt[])
{
    int aux;
    printf("\n\n***ARRAY ORDENADO***\n");
    for(int i = 0; i < MAX_ARRAY - 1; i++)
    {
        for(int j = i+1; j < MAX_ARRAY; j++)
        {
            if(vInt[i] > vInt[j])
            {
                aux = vInt[i];
                vInt[i] = vInt[j];
                vInt[j] = aux;
            }
        }
    }
}

void printArray(int vInt[])
{
    printf("\n\nMUESTRA ARRAY ORDENADO EN FORMA ASCENDENTE\n");
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("%d ", vInt[i]);
    }
}

void sumaArray(int vInt[])
{
    int acumArray = 0;
    printf("\n\nSUMA ARRAY\n");
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        acumArray += vInt[i];
    }
        printf("\nLa suma de los elementos del array es: %d", acumArray);
}

void busquedaArray(int vInt[])
{
    int numBuscado, flagEncontrado = 0;
    printf("\n\nBUSQUEDA DE NUMERO DENTRO DEL ARRAY\n");
    printf("\nIngrese numero buscado: ");
    scanf("%d", &numBuscado);

    do
    {
        for(int i = 0; i < MAX_ARRAY; i++)
        {
            if(numBuscado == vInt[i])
            {
               printf("\nNumero encontrado: %d en el indice: %d", vInt[i], i);
               flagEncontrado = 1;
               break;
            }
        }

            if(flagEncontrado == 0)
            {
                printf("\nNo se encontro el numero buscado. Reingrese: ");
                scanf("%d", &numBuscado);
            }

    }while(flagEncontrado == 0);

}
