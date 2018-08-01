#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

// getche toma y muestra caracter
// getch toma caracter pero no lo muestra

int main()
{
    long int dni;
    char nombre[41];
    char apellido[41];
    char direccion[41];
    char localidad[41];
    int edad;
    char categoria[41];
    int horasTrabajadas;
    int opt = 0;

    do
    {
        system("cls");
        opt = menu();

        switch(opt){
            case 1:
                printf("Ingrese DNI: ");
                scanf("%ld", &dni);
                printf("\nIngrese Nombre: ");
                fflush(stdin);
                scanf("%c", nombre);
                printf("\nIngrese Apellido: ");
                fflush(stdin);
                scanf("%c", apellido);
                printf("\nIngrese Direccion: ");
                fflush(stdin);
                scanf("%c", direccion);
                printf("\nIngrese Localidad: ");
                fflush(stdin);
                scanf("%c", localidad);
                printf("\nIngrese Edad: ");
                scanf("%d", &edad);
                    if (edad <= 18){
                        printf("ERROR! Debe ser mayor a 18.");
                        getch();
                    }
                printf("\nIngrese Categoria [A, B, C]: ");
                fflush(stdin);
                scanf("%c", categoria);
                    if (categoria != 'a' && categoria != 'b' && categoria != 'c')
                    {
                        printf("ERROR! Debe ingresar categoria [A, B, C]");
                        getch();
                    }
                printf("\nIngrese Cantidad de horas trabajadas: ");
                scanf("%d", &horasTrabajadas);
                getch();
            break;

            case 2:
                printf("Ingrese DNI: ");
                scanf("%ld", &dni);
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;
        }
      }while(opt != 7);
            return 0;
}


