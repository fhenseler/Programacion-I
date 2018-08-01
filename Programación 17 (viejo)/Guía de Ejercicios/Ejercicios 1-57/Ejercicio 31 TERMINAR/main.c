#include <stdlib.h>
#include <stdio.h>
#define MAX 100

int main()
{
    int i, mult5[MAX] = {};

    for(i = 0; i < MAX; i++)
    {
        if(i % 5 == 0)
        {
            mult5[i] = i;
        }
    }

    for(i = 0; i < MAX; i++)
    {
        printf("%d ", mult5[i]);
    }

        return 0;
}
