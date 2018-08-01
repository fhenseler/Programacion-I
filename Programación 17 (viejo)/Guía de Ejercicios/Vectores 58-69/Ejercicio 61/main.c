#include <stdio.h>
#include <stdlib.h>
#define DIAS_MES 31

int main()
{
    int gastos[DIAS_MES] = {1, 100, 0, 15, 31}, diaMax, maxGasto, flagMax = 1;

    for(int i = 0; i < DIAS_MES; i++)
    {
        int dia = i+1;

        if(flagMax == 0 || gastos[i] > maxGasto)
        {
            maxGasto = gastos[i];
            diaMax = dia;
            flagMax = 1;
        }
    }

        printf("El dia de mayor gasto fue: %d", diaMax);
}
