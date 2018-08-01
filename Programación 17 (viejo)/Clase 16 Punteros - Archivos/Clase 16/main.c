#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* num;
    int i;
    int aux;
    num = (int*)malloc(sizeof(int)*5);

    if(num == NULL)
    {
        printf("No se consiguio espacio en memoria");
        exit(1);
    }

        for(i = 0; i < 5; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", num+i);
        }

        for(i = 0; i < 5; i++)
        {
            printf("\n%d", *(num+i));
        }

            printf("\n\n");

            aux = (int*)realloc(num, sizeof(int)*10);

            if(aux != NULL)
            {
                num = aux;
            }
            else
            {
                printf("No se pudo redimensionar el array");
            }

                for(i = 0; i < 10; i++)
                {
                    printf("Ingrese un numero: ");
                    scanf("%d", num+i);
                }

                for(i = 0; i < 10; i++)
                {
                    printf("\n%d", *(num+i));
                }

                    printf("\n\n");

                    free(num);

                    return 0;
}
