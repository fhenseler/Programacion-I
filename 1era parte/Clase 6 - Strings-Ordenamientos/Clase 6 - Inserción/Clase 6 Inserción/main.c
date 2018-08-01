#include <stdio.h>
#include <stdlib.h>

#define LEN 5

void insertion(int arrayInt[], int tam);
void imprimir(int arrayInt[], int tam);

int main()
{
    int arrayInt[LEN] = {5, 1, 2, 3, 7};

    insertion(arrayInt, LEN);
    imprimir(arrayInt, LEN);

    return 0;

}

void insertion(int data[],int len)
{
    int i,j;
    int aux;
    for(i = 1; i < len; i++)
    {
        aux = data[i];
        j = i-1;

        while(aux<data[j] && j>=0) // aux < data[j] o aux > data[j]
        {
            data[j+1] = data[j];
            j--;
        }
            data[j+1]=aux; // inserción
    }
}

void imprimir(int arrayInt[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("%d ", arrayInt[i]);
    }
}
