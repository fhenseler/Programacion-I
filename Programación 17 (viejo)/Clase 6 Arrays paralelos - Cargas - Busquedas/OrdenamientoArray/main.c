#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int vInt[MAX] = {18, 6, 10, 3, 5}, aux;

    for(int i = 0; i < MAX-1; i++)
    {
        for(int j = i+1; j < MAX; j++)
        {
            if(vInt[i]> vInt[j])
            {
                aux = vInt[i];
                vInt[i] = vInt[j];
                vInt[j] = aux;
            }
        }
    }
            printf("El array ordenado es: ");
            for(int i = 0; i < MAX; i++)
            {
                printf("%d ", vInt[i]);
            }

            getch();
            return 0;
}
