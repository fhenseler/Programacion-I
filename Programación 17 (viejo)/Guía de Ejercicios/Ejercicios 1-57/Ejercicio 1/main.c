#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int i;
    int acum = 0;
    float promedio;
    for(i = 0; i < 5; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &num);
        acum += num;
    }
        promedio = (float) acum/5;    //Hice un CASTING sobre acum para poder dividir.
        printf("El promedio es: %.2f\n", promedio);
        system("pause");

        return 0;
}
