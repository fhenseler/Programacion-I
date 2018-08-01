#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, acumPos = 0, acumNeg = 1, flag = 0;
    for(i = 0; i < 10; i++)
    {
        printf("Ingrese numero distinto a cero: ");
        scanf("%d", &num);
            if(num == 0)
            {
                printf("ERROR! Ingrese numero distinto a cero: \n ");
            }
                if(num > 0)
                {
                    acumPos += num;
                }
                        if(num < 0)
                        {
                            acumNeg *= num;
                            flag = 1;
                        }
    }
            printf("La suma de los positivos es: %d\n", acumPos);
            printf("La multiplicacion de los negativos es: %d", acumNeg);
            getch();
            return 0;
}
