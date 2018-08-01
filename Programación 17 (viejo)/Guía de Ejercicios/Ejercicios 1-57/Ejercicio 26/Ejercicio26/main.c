#include <stdio.h>
#include <stdlib.h>

void main()
{
    int peso, cantMayor = 0, cantMenor = 0;
    char resp = 'y';
    while(resp == 'y')
    {
        printf("Ingrese peso: ");
        scanf("%d", &peso);
        if(peso <= 80)
        {
            cantMenor += 1;
        }
            else
            {
                cantMayor += 1;
            }

                printf("Desea continuar ingresando? (y/n)\n");
                resp = getch();
    }
                printf("\n%d empleados pesan hasta 80 kgs inclusive", cantMenor);
                printf("\n%d empleados pesan mas de 80 kgs", cantMayor);
                getch();
                return 0;
}
