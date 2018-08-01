#include <stdio.h>
#include <stdlib.h>

#define LEN 5

int main()
{
    int arrayInt[LEN] = {5, 1, 7, 9, 2};

    ordenar(arrayInt, LEN);
    imprimir(arrayInt, LEN);

    return 0;
}

