#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 10
#define D 3

typedef struct
{
    int id; //legajo
    char nombre[20]; //nombre
    int idCategoria;
    float sueldo;

}eProgramador;

typedef struct
{
    int id;
    char descripcion[20];

}eCategoria;

void mostrarProgramador(eProgramador, eCategoria);
void mostrarPlantel(eProgramador[], int, eCategoria[]);
int validarCategoria(eProgramador[], int, int);

int main()
{
        eProgramador plantel[C];
        eCategoria categoria[D] = {{1, "Junior"}, {2, "Semisenior"}, {3, "Senior"}};

        int opcion = 0;
        int i;
        int aux;
        int flag;
        char respuesta;
        char auxString[100];

        for(int i = 0; i < D; i++)
        {
            plantel[i].id = 0;
            plantel[i].idCategoria = 0;
        }

        do
        {
               printf("\n1.Alta\n2. Bajas\n3. Modificaciones\n4. Ordenar\n5. Mostrar Programador\n6. Mostrar Programadores\n7. Salir\nElija una opcion: ");
                scanf("%d", &opcion);

                switch(opcion)
                {
                    case 1: //ALTA
                        flag = 0;
                        for(int i = 0; i < C; i++)
                        {
                            if(plantel[i].idCategoria == 0)
                            {
                                printf("Ingrese ID: ");
                                scanf("%d", &plantel[i].id);

                                printf("Ingrese sueldo: ");
                                scanf("%f", &plantel[i].sueldo); //si no funciona guardar en un AUX
                                printf("Ingrese nombre: ");
                                fflush(stdin);
                                gets(plantel[i].nombre);
                                plantel[i].idCategoria = validarCategoria(plantel, 10, aux);
                                flag = 1;
                                break;
                            }
                        }

                        if(flag == 0)
                        {
                            printf("No hay espacio!");

                        }
                        break;

                    case 2: //BAJA
                        flag = 0;
                        printf("Ingrese ID a eliminar: ");
                        scanf("%d", &aux);

                        for(int i=0; i<C; i++)
                        {
                            if(plantel[i].idCategoria != 0 && aux == plantel[i].id)
                            {
                                printf("%d--%s--%d--%.2f\n", plantel[i].id, plantel[i].nombre, plantel[i].idCategoria, plantel[i].sueldo);

                                printf("\nEsta seguro de eliminar el programador? s/n: ");
                                respuesta = getche();
                                if(respuesta=='s')
                                {
                                    plantel[i].idCategoria = 0;
                                    printf("Programador eliminado!");
                                }
                                else
                                {
                                    printf("\nAccion cancelada!");
                                }
                                flag = 1;
                                break;

                            }
                        }

                        if(flag == 0)
                        {
                            printf("ID inexistente");
                        }


                        break;

                    case 3: //MODIFICACION
                        flag = 0;
                        printf("Ingrese ID a modificar: ");
                        scanf("%d", &aux);

                        for(int i=0; i<C; i++)
                        {
                            if(plantel[i].idCategoria != 0 && aux == plantel[i].id)
                            {
                                printf("%d--%s--%d\n", plantel[i].id, plantel[i].nombre, plantel[i].idCategoria, plantel[i].sueldo);
                                printf("Ingrese la nueva categoria: ");
                                scanf("%d", &aux);
                                printf("Esta seguro de realizar la modificacion? s/n: ");
                                respuesta = getche();
                                if(respuesta=='s')
                                {
                                    plantel[i].idCategoria = aux;
                                }
                                else
                                {
                                    printf("\nAccion cancelada!");
                                }
                                flag = 1;
                                break;

                            }
                        }
                        if(flag == 0)
                        {
                            printf("\nID inexistente");
                        }
                        break;

                    case 4: //ORDENAR

                        for(int i=0; i<C-1; i++)
                        {
                            for(int j=i+1; j<C; j++)
                            {
                                if(plantel[i].idCategoria != 0 && plantel[j].idCategoria != 0)
                                {
                                    if(strcmp(plantel[i].nombre, plantel[j].nombre)>0)
                                    {
                                        strcpy(auxString, plantel[i].nombre);
                                        strcpy(plantel[i].nombre, plantel[j].nombre);
                                        strcpy(plantel[j].nombre, auxString);

                                        aux = plantel[i].id;
                                        plantel[i].id = plantel[j].id;
                                        plantel[j].id = aux;

                                        aux = plantel[i].sueldo;
                                        plantel[i].sueldo = plantel[j].sueldo;
                                        plantel[j].sueldo = aux;

                                        aux = plantel[i].idCategoria;
                                        plantel[i].idCategoria = plantel[j].idCategoria;
                                        plantel[j].idCategoria = aux;
                                    }
                                    else
                                    {
                                        if(strcmp(plantel[i].nombre ,plantel[j].nombre)==0)
                                        {
                                            if(plantel[i].id > plantel[j].id)
                                            {
                                                aux = plantel[i].id;
                                                plantel[i].id = plantel[j].id;
                                                plantel[j].id = aux;

                                                aux = plantel[i].sueldo;
                                                plantel[i].sueldo = plantel[j].sueldo;
                                                plantel[j].sueldo = aux;

                                                aux = plantel[i].idCategoria;
                                                plantel[i].idCategoria = plantel[j].idCategoria;
                                                plantel[j].idCategoria = aux;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        break;

                    case 5: //MOSTRAR PROGRAMADOR
                            for(i = 0; i < 10; i++)
                            {
                                printf("\nID\tNombre\tCategoria\tSueldo");
                                mostrarProgramador(plantel[i], categoria[i]);
                            }
                            break;

                    case 6: //MOSTRAR PROGRAMADORES
                            printf("\nID\tNombre\tCategoria\tSueldo");
                            mostrarPlantel(plantel, C, categoria);
                            break;
                }//SWITCH

        }while(opcion != 7);
}


void mostrarProgramador(eProgramador programador, eCategoria categoria)
{
        if(programador.idCategoria == categoria.id)
        {
            printf("%s", categoria.descripcion);
        }

        if(programador.id != 0)
        {
            printf("\n%d--%s--%d--%.2f\n", programador.id, programador.nombre, programador.idCategoria, programador.sueldo);
        }
}

void mostrarPlantel(eProgramador plantel[], int cant, eCategoria categoria[])
{
    for(int i = 0; i < cant; i++)
    {
        mostrarProgramador(plantel[i], categoria[i]);
    }
}

int validarCategoria(eProgramador plantel[], int tam, int aux)
{
        printf("Ingrese ID Categoria (1 = Junior, 2 = Semisenior, 3 = Senior): ");
        scanf("%d", &aux);

        while(aux < 1 || aux > 3)
        {
            printf("ERROR! Categoria invalida. Reingrese: ");
            scanf("%d", &aux);
        }
            return aux;
}
