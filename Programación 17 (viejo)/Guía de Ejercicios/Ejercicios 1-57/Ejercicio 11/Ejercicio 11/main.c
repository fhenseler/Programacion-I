#include <stdio.h>
#include <stdlib.h>

int main()
{
    char i, caracter, cantA = 0, cantEIOU = 0;
    for(i = 0; i < 20; i++)
    {
        printf("Ingrese letra: ");
        scanf("%c", &caracter);
        fflush(stdin);
            if(caracter == 'a')
            {
                cantA++;
            }
                if(caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')
                {
                    cantEIOU++;
                }
    }
                    printf("Se ingresaron %d 'A'\n", cantA);
                    printf("Se ingresaron %d 'E, I, O, U'", cantEIOU);
                    getch();
                    return 0;
}
