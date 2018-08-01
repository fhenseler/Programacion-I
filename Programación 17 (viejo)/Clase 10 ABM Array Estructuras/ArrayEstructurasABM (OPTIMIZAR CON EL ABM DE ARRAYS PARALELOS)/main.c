#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 100

typedef struct         //DEFINICION DE LA ESTRUCTURA
{
    int legajo;
    char nombre[30];
    int estado;
    int edad;

}EAlumno;

void mostrarAlumno(EAlumno);
void mostrarCurso(EAlumno[], int);

int main()
{
        EAlumno unAlumno[C]; //DECLARACION DE LA VARIABLE "unAlumno" DEL TIPO DE DATO "EAlumno"
        int opcion = 0;
        int aux;
        int flag;
        char respuesta;
        char auxString[100];

        for(int i = 0; i < C; i++)
        {
            unAlumno[i].estado = 0;
        }

        do
        {
               printf("\n1.Alta\n2. Bajas\n3. Modificaciones\n4. Ordenar\n5. Mostrar\n6. Salir\nElija una opcion: ");
                scanf("%d", &opcion);

                switch(opcion)
                {
                    case 1: //ALTA
                        flag = 0;
                        for(int i = 0; i < C; i++)
                        {
                            if(unAlumno[i].estado == 0)
                            {
                                printf("Ingrese legajo: ");
                                scanf("%d", &unAlumno[i].legajo);

                                printf("Ingrese edad: ");
                                scanf("%d", &unAlumno[i].edad);
                                printf("Ingrese nombre: ");
                                fflush(stdin);
                                gets(unAlumno[i].nombre);

                                unAlumno[i].estado = 1;
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
                        printf("Ingrese legajo a eliminar: ");
                        scanf("%d", &aux);

                        for(int i=0; i<C; i++)
                        {
                            if(unAlumno[i].estado == 1 && aux == unAlumno[i].legajo)
                            {
                                printf("%d--%s--%d\n", unAlumno[i].legajo, unAlumno[i].nombre, unAlumno[i].edad);

                                printf("\nEsta seguro de eliminar el cliente? s/n: ");
                                respuesta = getche();
                                if(respuesta=='s')
                                {
                                    unAlumno[i].estado = 0;
                                    printf("Cliente eliminado!");
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
                            printf("Legajo inexistente");
                        }


                        break;

                    case 3: //MODIFICACION
                        flag = 0;
                        printf("Ingrese legajo a modificar: ");
                        scanf("%d", &aux);

                        for(int i=0; i<C; i++)
                        {
                            if(unAlumno[i].estado == 1 && aux == unAlumno[i].legajo)
                            {
                                printf("%d--%s--%d\n", unAlumno[i].legajo, unAlumno[i].nombre, unAlumno[i].edad);
                                printf("Ingrese la nueva edad: ");
                                scanf("%d", &aux);
                                printf("Esta seguro de realizar la modificacion? s/n: ");
                                respuesta = getche();
                                if(respuesta=='s')
                                {
                                    unAlumno[i].edad = aux;
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
                            printf("\nLegajo inexistente");
                        }
                        break;

                    case 4: //ORDENAR

                        for(int i=0; i<C-1; i++)
                        {
                            for(int j=i+1; j<C; j++)
                            {
                                if(unAlumno[i].estado == 1 && unAlumno[j].legajo == 1)
                                {
                                    if(strcmp(unAlumno[i].nombre, unAlumno[j].nombre)>0)
                                    {
                                        strcpy(auxString, unAlumno[i].nombre);
                                        strcpy(unAlumno[i].nombre, unAlumno[j].nombre);
                                        strcpy(unAlumno[j].nombre, auxString);

                                        aux = unAlumno[i].legajo;
                                        unAlumno[i].legajo = unAlumno[j].legajo;
                                        unAlumno[j].legajo = aux;

                                        aux = unAlumno[i].edad;
                                        unAlumno[i].edad = unAlumno[j].edad;
                                        unAlumno[j].edad = aux;

                                        aux = unAlumno[i].estado;
                                        unAlumno[i].estado = unAlumno[j].estado;
                                        unAlumno[j].estado = aux;
                                    }
                                    else
                                    {
                                        if(strcmp(unAlumno[i].nombre ,unAlumno[j].nombre)==0)
                                        {
                                            if(unAlumno[i].legajo > unAlumno[j].legajo)
                                            {
                                                aux = unAlumno[i].legajo;
                                                unAlumno[i].legajo = unAlumno[j].legajo;
                                                unAlumno[j].legajo = aux;

                                                aux = unAlumno[i].edad;
                                                unAlumno[i].edad = unAlumno[j].edad;
                                                unAlumno[j].edad = aux;

                                                aux = unAlumno[i].estado;
                                                unAlumno[i].estado = unAlumno[j].estado;
                                                unAlumno[i].estado = unAlumno[i].estado;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        break;
                    case 5: //MOSTRAR
                            printf("\nLegajo\tNombre\tEdad");
                            mostrarCurso(unAlumno, C);
                            break;
                }//SWITCH

        }while(opcion != 6);
}


void mostrarAlumno(EAlumno alumno)
{
    if(alumno.estado == 1)
    {
        printf("\n%d--%s--%d\n", alumno.legajo, alumno.nombre, alumno.edad);
    }
}

void mostrarCurso(EAlumno curso[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        mostrarAlumno(curso[i]);
    }
}
