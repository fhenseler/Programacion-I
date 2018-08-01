#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char letras[5];

    for(i = 0; i < 5; i++)
    {
        printf("Ingrese letra en indice %d: ", i);
        fflush(stdin);
        scanf("%c", &letras[i]);
    }

    for(i = 0; i < 5; i++)
    {
        printf("\nLa letra en el indice [%d] es: %c", i, letras[i]);
    }

            getch();
            return 0;
}
