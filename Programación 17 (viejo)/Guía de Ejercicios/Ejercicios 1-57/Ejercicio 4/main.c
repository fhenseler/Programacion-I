#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, result;
    system("cls");
    num1 = 1;
    num2 = 2;
    result = num1 - num2;
    if(result > 0)
    {
        printf("Resultado positivo");
    }
        if(result < 0)
        {
            printf("Resultado negativo");
        }
            if(result = 0)
            {
                printf("El resultado es %d", result);
            }
                getch();
                return 0;
}
