#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, acumulador = 0;
        for(i = 3; i < 100; i++){
                if(i % 3 == 0){
                printf("%d", i);
                acumulador+=i;
                }
        }
                printf("La suma es %d: ", acumulador);
                return 0;
}

