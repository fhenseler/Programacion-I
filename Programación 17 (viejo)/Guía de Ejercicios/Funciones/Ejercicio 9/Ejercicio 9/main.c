#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY 5
#define MIN_PPA 50.3
#define MAX_PPA 80.5
#define MIN_PESO 40
#define MAX_PESO 200
#define MIN_ALTURA 1.4
#define MAX_ALTURA 2.4

void validaPeso(float);
void validaAltura(float);

int main()
{
    int cant50_80 = 0;
    float pesoAux, peso[MAX_ARRAY] = {}, porcentaje, altura[MAX_ARRAY] = {}, productoP_A, alturaAux;

    for(int i = 0; i < MAX_ARRAY; i++)
    {
        printf("Ingrese peso: ");
        scanf("%f", &pesoAux);
        validaPeso(pesoAux);
        peso[i] = pesoAux;

        printf("Ingrese altura: ");
        scanf("%f", &alturaAux);
        validaAltura(alturaAux);
        altura[i] = alturaAux;

        productoP_A = peso[i] * altura[i];

        if(productoP_A >= MIN_PPA && productoP_A <= MAX_PPA)
        {
            cant50_80++;
        }
    }

        porcentaje = ((float)cant50_80 / MAX_ARRAY) * 100;
        printf("%.2f es el porcentaje de personas cuyo peso por altura se encuentra entre 50.3 y 80.5", porcentaje);
        getch();
        return 0;
}

void validaPeso(float pesoAux)
{
    if(pesoAux < MIN_PESO || pesoAux > MAX_PESO)
    {
        printf("ERROR! Peso incorrecto. Reingrese: ");
        scanf("%f", &pesoAux);
    }
}

void validaAltura(float alturaAux)
{
    if(alturaAux < MIN_ALTURA || alturaAux > MAX_ALTURA)
    {
        printf("ERROR! Altura incorrecta. Reingrese: ");
        scanf("%f", &alturaAux);
    }
}
