#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, fecha, fechaMax, fechaMin, temp, tempAlta, tempBaja, tempMax, flagMax = 0, tempMin, flagMin = 0;

    printf("***INGRESO DE DATOS***\n");
    for(i = 0; i < 5; i++)
    {
        printf("\nIngrese fecha dia [%d]: ", i+1);
        scanf("%d", &fecha);

        printf("\nIngrese temperatura maxima dia [%d]: ", i+1);
        scanf("%d", &tempAlta);

        printf("\nIngrese temperatura minima dia [%d]: ", i+1);
        scanf("%d", &tempBaja);

        if(flagMax == 0 || tempAlta > tempMax)
        {
            tempMax = tempAlta;
            fechaMax = fecha;
            flagMax = 1;
        }

        if(flagMin == 0 || tempBaja < tempMin)
        {
            tempMin = tempBaja;
            fechaMin = fecha;
            flagMin = 1;
        }

    }
        printf("\n\nCONCLUSIONES: \n");
        printf("\nLa temperatura maxima fue %d el dia %d\n", tempMax, fechaMax);
        printf("La temperatura minima fue %d el dia %d", tempMin, fechaMin);
        getch();
        return 0;
}
