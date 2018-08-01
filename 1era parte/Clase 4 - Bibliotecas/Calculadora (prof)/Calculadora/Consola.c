#include <stdio.h>
#include <stdlib.h>

int tomaNumero(char msg[], float *x, float max, float min )
{
    float aux;
    printf("%s", msg);
    scanf("%f",&aux);
    if(aux <=max && aux >= min){
        *x=aux;
        return 0;
    }
    return -1;
}
