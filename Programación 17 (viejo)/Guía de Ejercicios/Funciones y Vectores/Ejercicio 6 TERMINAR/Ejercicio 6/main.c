#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5
#define JUBX 0.12
#define OSX 0.035

float calculoSN(float[], int[]);

int main()
{
    int legajo[MAX_ARRAY] = {132, 138, 135, 131, 136}, antiguedad[MAX_ARRAY] = {15, 5, 25, 30, 19};
    float sueldoN[MAX_ARRAY], sueldoB[MAX_ARRAY] = {1500, 2000, 3000, 1000, 1900}, sueldoAux;

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        sueldoAux = calculoSN(sueldoB, antiguedad);
        sueldoN[i] = sueldoAux;
    }

    printf("Legajo\t Sueldo Basico\t Sueldo Neto");
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("\n%d\t %.2f\t %.2f", legajo[i], sueldoB[i], sueldoN[i]);
    }

    getch();
    return 0;
}

float calculoSN(float sueldoB[], int antiguedad[])
{
    float bonus, sueldoAux;
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        if(antiguedad[i] >= 10 && antiguedad[i] <= 20)
        {
            bonus = 0.015;
        }
        if(antiguedad[i] > 20 && antiguedad[i] <= 30)
        {
            bonus = 0.030;
        }
        if(antiguedad[i] > 30 && antiguedad[i] <= 50)
        {
                bonus = 0.040;
        }
                sueldoAux = sueldoB[i] - (sueldoB[i] * JUBX) - (sueldoB[i] * OSX) + (sueldoB[i] * bonus);
    }
                return sueldoAux;
}



