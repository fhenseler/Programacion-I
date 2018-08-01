#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, cantPar = 0;
    for(i = 1; i <= 100; i++)
    {
            if(i % 2 == 0){
                    cantPar++;
                    printf("%d, ", i);
            }
    }
                        printf("\nCantidad de pares: %d", cantPar);
                        getch();
                        return 0;
}

