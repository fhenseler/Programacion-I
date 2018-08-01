#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_socio, edad, deporte, edadTenis = 0, cantTenis = 0, edadPaddle = 0, cantPaddle = 0, promedioTenis, promedioPaddle;
    char nombre[31], resp = 's';

    printf("***INGRESO DE DATOS***\n");
    do
    {
        printf("\nIngrese nombre: ");
        scanf("%s", nombre);

        printf("\nIngrese numero de socio: ");
        scanf("%d", &n_socio);

        printf("\nIngrese edad: ");
        scanf("%d", &edad);

        printf("\nQue deporte practica? (1 - Tenis  2 - Paddle): ");
        scanf("%d", &deporte);

        if(deporte == 1)
        {
            edadTenis += edad;
            cantTenis++;
        }
        else
        {

        if(deporte == 2)
        {
            edadPaddle += edad;
            cantPaddle++;
        }
        }

        printf("\nContinuar ingresando? (s/n)\n");
        resp = tolower(getch(resp));

    }while(resp == 's');

        printf("\n%d socios practican Tenis y %d Paddle", cantTenis, cantPaddle);

        promedioTenis = edadTenis / cantTenis;
        promedioPaddle = edadPaddle / cantPaddle;
        printf("\n%d es la edad promedio de los socios de Tenis y %d de Paddle", promedioTenis, promedioPaddle);

        getch();
        return 0;
}
