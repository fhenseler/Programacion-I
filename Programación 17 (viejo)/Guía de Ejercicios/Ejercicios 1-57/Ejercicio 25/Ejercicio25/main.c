#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, max = 0;
    printf("Ingrese num 1: ");
    scanf("%d", &num1);
    printf("Ingrese num 2: ");
    scanf("%d", &num2);
    printf("Ingrese num 3: ");
    scanf("%d", &num3);
    if(num1 > num2 && num1 > num3)
    {
        max = num1;
    }
        if(num2 > num1 && num2 > num3)
        {
            max = num2;
        }
                if(num3 > num1 && num3 > num2)
                {
                    max = num3;
                }
                    printf("El numero mayor es %d", max);
}
