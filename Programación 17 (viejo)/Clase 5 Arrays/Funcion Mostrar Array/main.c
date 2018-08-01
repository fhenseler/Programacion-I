#include <stdio.h>
#include <stdlib.h>

void MostrarVectorEnteros(int[], int);

int main()
{
     int numeros[5];
     int numeros2[5];

     for(int i=0; i<5; i++){
        printf("Ingrese un numero:");
        scanf("%d", &numeros[i]);
    }

     for(int i=0; i<5; i++){
        numeros2[i] = 2 * numeros[i];
    }
    printf("\nVector numeros\n");

    MostrarVectorEnteros(numeros, 5);

     printf("\nVector numeros2\n");

     MostrarVectorEnteros(numeros2, 5);

     printf("\n\n");

    return 0;
}

void MostrarVectorEnteros(int x[], int tam ){

 for(int i=0; i<tam; i++){

        printf("%d ", x[i]);
    }
}
