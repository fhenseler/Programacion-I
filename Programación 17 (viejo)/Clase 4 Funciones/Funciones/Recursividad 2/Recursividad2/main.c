#include <stdio.h>
#include <stdlib.h>

int main()
{
    factorial(0);
}


int factorial(int n)
{
    int resultado;

    if(n == 0)
    {
        return 1;
    }
    else
    {
        resultado = n * factorial(n-1);
        return resultado;
    }

}
