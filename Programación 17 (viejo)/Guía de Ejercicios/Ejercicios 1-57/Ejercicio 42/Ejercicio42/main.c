#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n_lluvia, t_lluvia, c_lluvia = 0, maxLluvia, minLluvia, flagMax = 0, flagMin = 0, n_promedio;

    for(i = 0; i < 31; i++)
    {
        printf("\nIngresar cantidad de lluvia dia %d: ", i);
        scanf("%d", &n_lluvia);

        if(flagMax == 0 || n_lluvia > maxLluvia)
        {
            maxLluvia = n_lluvia;
            flagMax = 1;
        }

        if(flagMin == 0 || n_lluvia < minLluvia)
        {
            minLluvia = n_lluvia;
            flagMin = 1;
        }

        c_lluvia += n_lluvia;
        system("cls");
    }

        printf("\nEl dia de mayor lluvia fue: %d", maxLluvia);
        printf("\nEl dia de menor lluvia fue: %d", minLluvia);

        n_promedio = c_lluvia / i;

        printf("\nEl promedio de lluvia fue: %d", n_promedio);

}
