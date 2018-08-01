#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5

int buscar(float num);

int main()
{
    int cantEncontrados;
    float num = 3.14;

    cantEncontrados = buscar(num);
    if(cantEncontrados == 0)
    {
        printf("El numero %f NO SE ENCONTRO EN EL ARRAY", num);
    }
    else
    {
        printf("El numero %f se encontro %d veces", num, cantEncontrados);
    }

    getch();
    return 0;
}

int buscar(float num)
{
    float numAux = 3.14;
    int cantEncontrados = 0;
    float arrayNum[MAX_ARRAY] = {3.14, 2, 3.14, 5, 5.1};

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        if(numAux == arrayNum[i])
        {
            cantEncontrados++;
        }
    }

        if(cantEncontrados == 0)
        {
            return 0;
        }
            return cantEncontrados;
}
