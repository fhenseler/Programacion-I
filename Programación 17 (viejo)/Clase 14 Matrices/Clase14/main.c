#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[6][5];

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("Ingrese numero: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d ", matriz[i][j]);
        }
            printf("\n");
    }
            getch();
            return 0;
}
