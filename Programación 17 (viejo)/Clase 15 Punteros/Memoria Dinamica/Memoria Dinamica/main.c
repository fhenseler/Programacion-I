#include <stdio.h>
#include <stdlib.h>

#define T 5
typedef struct
{
    int a,b,c;
    char* nombre;
} aalal;
int main()
{
    int* pInt;
    int* pAux;
    int i;


    int x[10]= {};

    for(i=0; i<10; i++)
      {
    printf("%d\n", x[i]);
      }



    pInt = (int*) calloc(T,sizeof(int));
    for(i=0; i<T; i++)
    {
        printf("%d\n", *(pInt+i));
    }


        if(pInt!=NULL)
        {
            printf("Donde apunta el puntero: %p, la dire del puntero %p\n", pInt, &pInt);
            for(i=0; i<T; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", pInt+i);
            }

            for(i=0; i<T; i++)
            {
                printf("dire del elemento:%p -- %d\n",pInt+i, *(pInt+i));

            }

            pAux = realloc(pInt,sizeof(int)*(T+5));
            if(pAux!=NULL)
            {
                pInt= pAux;

                for(i=T; i<T+5; i++)
                {
                    printf("Ingrese un numero: ");
                    scanf("%d", pInt+i);
                }

                for(i=0; i<T+5; i++)
                {
                    printf("dire del elemento:%p -- %d\n",pInt+i, *(pInt+i));

                }
                pAux = realloc(pInt,sizeof(int)*(T-2));
                if(pAux!=NULL)
                {
                    pInt= pAux;
                    for(i=0; i<T; i++)
                    {
                        printf("dire del elemento:%p -- %d\n",pInt+i, *(pInt+i));

                    }
                     free(pAux);
                }
            }
        }




    return 0;
}
