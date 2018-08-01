#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5

void mostrarArray();

int main()
{
    mostrarArray();
}

void mostrarArray(void)
{
    int vInt[MAX_ARRAY] = {5, 18, 6, -1, 2};

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("%d ", vInt[i]);
    }
}
