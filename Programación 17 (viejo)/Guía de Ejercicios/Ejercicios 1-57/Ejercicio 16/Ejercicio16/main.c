#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, acum;
    for(i = 3; i < 100; i++)
    {
        if(i % 3 == 0)
        {
                printf("%d\n", i);
                acum += i;
        }
    }
            printf("La suma de la serie es: %d", acum);
            getch();
            return 0;
}
