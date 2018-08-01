#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int edad[MAX], edadMax, edadMin;

    for(int i = 0; i < MAX; i++)//NO NECESITO FLAG PORQUE i = 0 EN EL FOR. SI USO WHILE/DO WHILE NECESITO FLAG.
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad[i]);

        if(i == 0 || edad[i] > edadMax)
        {
            edadMax = edad[i];
        }

        if(i == 0 || edad[i] < edadMin)
        {
            edadMin = edad[i];
        }
    }

        printf("%d es la edad maxima\n", edadMax);
        printf("%d es la edad minima\n", edadMin);

        getch();
        return 0;
}
