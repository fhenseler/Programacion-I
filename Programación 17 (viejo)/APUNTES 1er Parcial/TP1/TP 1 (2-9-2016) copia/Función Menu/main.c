#include <stdio.h>
#include <stdlib.h>

int main(void){
int opcion;
    do{
        system("cls");
        opcion = menu();
    }while(opcion != 9);
        return 0;


int menu(void);
int menu(void){
    printf("1. Ingresar 1er operando (A=x)");
    printf("2. Ingresar 2do operando (B=y)");
    printf("3. Calcular la suma (A+B)");
    printf("4. Calcular la resta (A-B)");
    printf("5. Calcular la division (A/B)");
    printf("6. Calcular la multiplicacion (A*B)");
    printf("7. Calcular el factorial (A!)");
    printf("8. Calcular todas las operaciones");
    printf("9. Salir");
    do{
        printf("\nSeleccione opción");
        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > 9);
        return opcion;
}

