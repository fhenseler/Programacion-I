#include <stdio.h>
#include <stdlib.h>

//void validarInt(int);
float calcularTotal(float[][3]);
void mostrarMatriz(float[][3]);

int main()
{
    float matriz[4][13];
    float total;
    float auxF, auxC;
    int i, j;
    char resp = 's';

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 3; j++)
        {
            matriz[i][j] = 0;
        }
    }


    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 3; j++)
        {
            while(resp == 's')
            {
                printf("Ingrese numero de coche: ");
                scanf("%f", &auxC);

                if(auxC < 1 || auxC > 12)
                {
                    printf("ERROR! Ingrese numero de coche, de 1 a 12: ");
                    scanf("%f", &auxC);
                }

                matriz[i][j] = auxC;

                printf("Ingrese numero de linea: ");
                scanf("%f", &auxF);

                if(auxF < 1 || auxF > 3)
                {
                    printf("ERROR! Ingrese numero de linea, de 1 a 3: ");
                    scanf("%f", &auxF);
                }

                matriz[][] = auxF;

                printf("Ingrese recaudacion del viaje: ");
                scanf("%f", &matriz[i][j]);

                printf("Ingresar otro viaje? (s/n): ");
                fflush(stdin);
                scanf("%c", &resp);
            }
        }
    }
//                total = calcularTotal(matriz);
                mostrarMatriz(matriz);
                getch();
                return 0;
}

float calcularTotal(float matriz[][3])
{
       int i, j;
       float total;

       for(i = 0; i < 4; i++)
       {
            for(j = 0; j < 3; j++)
            {
                total = matriz[i][j]++;
            }
       }
                return total;
}

void mostrarMatriz(float matriz[][3])
{
      int i, j;
      for(i = 0; i < 4; i++)
       {
            for(j = 0; j < 3; j++)
            {
                printf("%.2f ", matriz[i][j]);
            }
                printf("\n");
       }
}
