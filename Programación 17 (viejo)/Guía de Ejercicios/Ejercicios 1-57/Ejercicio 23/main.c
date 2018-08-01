#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num;
    printf("Ingrese numero: ");
    scanf("%d", &num);
    for(i = 1; i < num; i++)
    {
        if(i % 3 == 0 && i != 0)
        {
            printf("%d, ", i);
        }
    }
        getch();
        return 0;
}

