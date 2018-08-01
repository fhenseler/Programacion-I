#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Ingrese numero: ");
    scanf("%d", &num);
    if(num > 0)
    {
        printf("El numero ingresado es positivo");
    }
        if(num < 0)
        {
            printf("El numero ingresado es negativo");
        }
                if(num == 0)
                {
                    printf("El numero ingresado es cero");
                }
                        getch();
                        return 0;
}
