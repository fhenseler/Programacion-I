#include <stdio.h>
#include <stdlib.h>

#define LEN 5

void insercion(int arrayInt[], int tam);
void imprimir(int arrayInt[], int tam);

int main()
{
    int miArray[5] = {5, 1, 2, 3, 7};
    insercion(miArray, LEN);
    imprimir(miArray, LEN);
    return 0;
}

void insercion(int arrayInt[], int tam)
{
    int i, j, aux;

    for(i = 1; i < tam; i++)
    {
        aux = arrayInt[i];

        for(j = i-1; j >= 0; j--)
        {
            if(aux < arrayInt[j])
            {
                arrayInt[j+1] = arrayInt[j];
            }
            else
            {
                arrayInt[j+1] = aux;
                break;
            }
        }
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
