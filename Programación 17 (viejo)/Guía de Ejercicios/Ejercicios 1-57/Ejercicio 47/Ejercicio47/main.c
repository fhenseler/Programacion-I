#include <stdio.h>
#include <stdlib.h>


int main()
{
    char nombre[31], nombreMax[31];
    int i, pInteligencia = 0, pCultura = 0, pBelleza = 0, pAcumInteligencia = 0, pAcumCultura = 0, pAcumBelleza = 0, pTotal = 0, pMax, flagMax = 0;

    printf("***INGRESO DE DATOS DEL CONCURSO DE BELLEZA***\n\n");

    for(i = 0; i < 20; i++)
    {
        printf("\nIngrese nombre participante [%d]: ", i+1);
        scanf("%s", nombre);

        printf("\nIngrese puntos Inteligencia: ");
        scanf("%d", &pInteligencia);

        pAcumInteligencia += pInteligencia;

        printf("\nIngrese puntos Cultura General: ");
        scanf("%d", &pCultura);

        pAcumCultura += pCultura;

        printf("\nIngrese puntos Belleza: ");
        scanf("%d", &pBelleza);

        pAcumBelleza += pBelleza;

        pTotal = pInteligencia + pCultura + pBelleza;

        if(flagMax == 0 || pTotal > pMax)
        {
            pMax = pTotal;
            strcpy(nombreMax, nombre);
            flagMax = 1;
        }

    }

        printf("\n\nLa participante con mayor puntaje general fue: %s", nombreMax);
        printf("\nEl puntaje acumulado por todas las participantes en todas las categorias fue:\n %d en Inteligencia\n %d en Cultura\n %d en Belleza", pAcumInteligencia, pAcumCultura, pAcumBelleza);
        getch();
        return 0;
}
