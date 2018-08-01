#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, numero, maximo, minimo;
        for(i = 0; i < 5; i++){
            printf("Ingrese numero: ");
            scanf("%d", &numero);
                if(i == 0){
                        maximo = numero;
                        minimo = numero;
                }
                    if(numero > maximo){
                            maximo = numero;
                    }
                        if(numero < minimo){
                                minimo = numero;
                        }
    }
                            printf("El numero maximo es: %d\n", maximo);
                            printf("El numero minimo es: %d", minimo);
                            system("Pause");
                            return 0;
}

