#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, cantImp = 0;
    for(i = 1; i <= 100; i++)
    {
            if(i % 2 == 1){
                    cantImp++;
                    printf("%d, ", i);
            }
    }
                        printf("\nCantidad de impares: %d", cantImp);
                        getch();
                        return 0;
}
