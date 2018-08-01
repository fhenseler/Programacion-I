#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3


void darAlta(int[], char[][30], int[], int[], int);
void darBaja(int[], char[][30], int[], int[], int);
void modificarClientes(int[], char[][30], int[], int[], int);
void ordenarClientes(int[], char[][30], int[], int[], int);
void mostrarClientes(int[], char[][30], int[], int[], int);

int main()
{
    int legajo[MAX], edad[MAX], estado[MAX] = {};
    char nombre[MAX][30];

    int opcion;
    char seguir = 'S';

    do
    {
        system("cls");
        printf("1- Alta\n2- Baja\n3- Modificacion\n4- Ordenar\n5- Mostrar\n6- Salir\n\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                    darAlta(legajo, nombre, edad, estado, MAX);
                    break;
            case 2:
                    darBaja(legajo, nombre, edad, estado, MAX);
                    break;
            case 3:
                    modificarClientes(legajo, nombre, edad, estado, MAX);
                    break;
            case 4:
                    ordenarClientes(legajo, nombre, edad, estado, MAX);
                    break;
            case 5:
                    mostrarClientes(legajo, nombre, edad, estado, MAX);
                    getch();
                    break;
            case 6:
                    seguir = 'N';
                    break;
        }

    }while(seguir == 'S');

                    return 0;
}



void darAlta(int legajo[], char nombre[][30], int edad[], int estado[], int tam)
{
        int flagEstado = 0;
        for(int i = 0; i < MAX; i++)
        {
            if(estado[i] == 0)
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombre[i]);

                printf("Ingrese legajo: ");
                scanf("%d", &legajo[i]);

                printf("Ingrese edad: ");
                scanf("%d", &edad[i]);

                estado[i] = 1;
                flagEstado = 1;

                printf("\nCliente dado de alta!");
                getch();
                break;
            }
        }
                if(flagEstado == 0)
                {
                    printf("\nNo hay espacio!");
                    getch();
                }
}

void darBaja(int leg[], char nom[][30], int edad[], int est[], int tam)
{
    int flagEstado = 0;
    int auxInt;
    char resp;

    printf("\nIngrese legajo a dar de baja: ");
    scanf("%d", &auxInt);

    for(int i = 0; i < MAX; i++)
    {
        if(est[i] == 1 && auxInt == leg[i])
        {
            printf("%d--%s--%d\n", leg[i], nom[i], edad[i]);

            printf("\nEsta seguro de eliminar el cliente? (S/N): ");
            resp = getche();
            if(resp == 'S')
            {
                est[i] = 0;
                printf("\nCliente eliminado correctamente!");
                getch();
            }
            else
            {
                printf("\nAccion cancelada!");
                getch();
            }
                flagEstado = 1;
                break;
        }
    }


            if(flagEstado == 0)
            {
                printf("Legajo inexistente!");
                getch();
            }

 }

void modificarClientes(int legajo[], char nombre[][30], int estado[], int edad[], int tam)
{
        int flagEstado = 0, auxInt;
        char resp;

        printf("\nIngrese legajo a modificar: ");
        scanf("%d", &auxInt);

        for(int i = 0; i < MAX; i++)
        {
            if(estado[i] == 1 && auxInt == legajo[i])
            {
                printf("%d--%s--%d\n", legajo[i], nombre[i], edad[i]);
                printf("\nIngrese la nueva edad: ");
                scanf("%d", &auxInt);
                printf("\nEsta seguro de realizar la modificacion? (S/N): ");
                resp = getche();
                if(resp == 'S')
                {
                    edad[i] = auxInt;
                    printf("\nEdad modificada correctamente!");
                    getch();
                }
                else
                {
                    printf("\nAccion cancelada!");
                    getch();
                }
                flagEstado = 1;
                break;
            }
        }
                if(flagEstado == 0)
                {
                    printf("\nLegajo inexistente!");
                    getch();
                }
}


void ordenarClientes(int legajo[], char nombre[][30], int estado[], int edad[], int tam)
{
    int auxInt;
    char auxString[100];

    for(int i = 0; i < MAX-1; i++)
    {
        for(int j = i+1; j < MAX; j++)
        {
            if(estado[i] == 1 && estado[j] == 1)
            {
                if(strcmp(nombre[i], nombre[j]) > 0)
                {
                    strcpy(auxString, nombre[i]);
                    strcpy(nombre[i], nombre[j]);
                    strcpy(nombre[j], auxString);

                    auxInt = legajo[i];
                    legajo[i] = legajo[j];
                    legajo[j] = auxInt;

                    auxInt = edad[i];
                    edad[i] = edad[j];
                    edad[j] = auxInt;

                    auxInt = estado[i];
                    estado[i] = estado[j];
                    estado[j] = auxInt;

                    printf("\nOrdenado correctamente!");
                    getch();
                    break;
                }

                else
                {
                    if(strcmp(nombre[i], nombre[j]) == 0)
                    {
                        if(legajo[i] > legajo[j])
                        {
                            auxInt = legajo[i];
                            legajo[i] = legajo[j];
                            legajo[j] = auxInt;

                            auxInt = edad[i];
                            edad[i] = edad[j];
                            edad[j] = auxInt;

                            auxInt = estado[i];
                            estado[i] = estado[j];
                            estado[j] = auxInt;

                            printf("\nOrdenado correctamente!");
                            getch();
                            break;
                        }
                    }
                }
            }
        }
    }
                            printf("\nLos clientes ya estan ordenados!");
                            getch();
}

void mostrarClientes(int legajo[], char nombre[][30], int edad[], int estado[], int tam)
{
    printf("\n\nLegajo\tNombre\tEdad\t");
    printf("\n");
    for(int i = 0; i < MAX; i++)
    {
        if(estado[i] != 0)
        {
            printf("\n%d\t%s\t%d\t", legajo[i], nombre[i], edad[i]);
        }
    }
}
