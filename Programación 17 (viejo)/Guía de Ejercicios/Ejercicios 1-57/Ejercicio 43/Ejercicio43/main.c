#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, maxNum, minNum, flagMax = 0, flagMin = 0;

    for(i = 0; i < 5; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &num);

        if(flagMax == 0 || num > maxNum)
        {
            maxNum = num;
            flagMax = 1;
        }

        if(flagMin == 0 || num < minNum)
        {
            minNum = num;
            flagMin = 1;
        }
    }

        printf("\n%d es el mayor numero\n", maxNum);
        printf("%d es el menor numero", minNum);
        getch();
        return 0;
}
