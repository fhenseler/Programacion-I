#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int opcion = 0, vInt[MAX] = {};

    do{

    system("cls");
    printf("\n1 - CARGAR EL VECTOR");
    printf("\n2 - ORDENAR EL VECTOR");
    printf("\n3 - MOSTRAR EL VECTOR");
    printf("\n\n4 - SALIR\n\n");

    printf("\nSeleccione opcion: ");
    scanf("%d", &opcion);

    switch(opcion)
        {
            case 1:
                    printf("***CARGA DEL VECTOR***\n");
                    for(int i = 0; i < MAX; i++)
                    {
                        printf("\nIngrese valor indice [%d]: ", i);
                        scanf("%d", &vInt[i]);
                    }
                    break;
            case 2:
                    printf("***VECTOR ORDENADO***\n");
                    for(int i = 0; i< MAX - 1; i++)
                    {
                        for(int j = i + 1; j < MAX; j++)
                        {
                            if(vInt[i]>vInt[j])
                            {
                                int aux = vInt[i];
                                vInt[i] = vInt[j];
                                vInt[j] = aux;
                            }
                        }
                    }
                    getch();
                    break;

            case 3:
                    printf("***MUESTRA DEL VECTOR***\n");
                    for(int i = 0; i < MAX; i++)
                    {
                        printf("%d ", vInt[i]);
                    }
                    getch();
                    break;
            case 4:
                    break;
        }

    }while(opcion != 4);

    getch();
    return 0;
}
