#include <stdio.h>
#include <stdlib.h>
#define MAX_FIL 5

int main()
{
    char letra;

    printf("Ingrese letra: ");
    fflush(stdin);
    scanf("%c", &letra);

    printf("%c", letra);
    printf("\n\t%c", letra);
    printf("\n\t\t%c", letra);
    printf("\n\t\t\t%c", letra);
    printf("\n\t\t\t\t%c", letra);

        return 0;
}
