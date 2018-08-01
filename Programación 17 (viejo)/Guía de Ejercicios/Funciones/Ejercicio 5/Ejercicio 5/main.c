#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 5

int menu(void);
int cargaArray(int[]);
void muestraArray(int[]);

int main()
{
    int opt = 0;
    int arrayNum[ARRAY_MAX] = {};

    do
    {
         system("cls");
         opt = menu();

            switch(opt)
            {
                case 1:
                        cargaArray(arrayNum);
                        break;

                case 2:
                        muestraArray(arrayNum);
                        getch();
                        break;
            }

    }while(opt != 3);

                        return 0;
}

int menu(void)
{
    int opt;
    printf("1- Ingreso de datos\n");
    printf("2- Mostrar\n");
    printf("3- Salir\n");

    do
    {
        printf("\nSeleccione opci%cn: ", 162);
        scanf("%d", &opt);
        return opt;

    }while(opt < 1 || opt > 2);

}

int cargaArray(int arrayNum[])
{
    int aux;
    for(int i = 0; i < ARRAY_MAX; i++)
    {
       printf("Ingresar numero en el indice %d: ", i);
       scanf("%d", &aux);
       arrayNum[i] = aux;
    }
        return 0;
}

void muestraArray(int arrayNum[]){

 for(int i = 0; i < ARRAY_MAX; i++){

        printf("%d ", arrayNum[i]);
    }
}


