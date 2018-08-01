#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

int main()
{
        eProgramador plantel[MAX_PROG];
        eCategoria categorias[MAX_CAT];
        eProyecto proyectos[MAX_PROY];
        eProg_Proy progproy[MAX_PP];

        int opcion = 0;

        inicializarProgramadores(plantel, MAX_PROG);
        inicializarProyectos(proyectos, MAX_PROY);
        inicializarProgProy(progproy, MAX_PROY);

        cargarProgramadores(plantel, MAX_PROG);
        cargarProyectos(proyectos, MAX_PROY);
        cargarCategorias(categorias, MAX_CAT);

    do
    {
        system("cls");
        opcion = getInt("\n\n\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA\n4 - ASIGNAR PROGRAMADOR A PROYECTO\n5 - LISTADO DE PROGRAMADORES Y CALCULO DE TOTALES\n6 - LISTADO DE PROYECTOS\n7 - LISTAR PROYECTOS DEL PROGRAMADOR\n8 - PROYECTO DEMANDANTE\n\n9 - SALIR\n\n");

        switch(opcion)
        {
            case 1: //ALTA
                    darAlta(plantel, 1, 50, MAX_PROG, categorias, MAX_CAT);
                    printf("\n\n");
                    system("pause");
                    break;

            case 2: //MODIFICACION
                    modificarProgramador(plantel, 1, 50, MAX_PROG, categorias, MAX_CAT);
                    printf("\n\n");
                    system("pause");
                    break;

            case 3: //BAJA
                    darBaja(plantel, 1, 50, MAX_PROG);
                    printf("\n\n");
                    system("pause");
                    break;

            case 4: //ASIGNAR PROGRAMADOR A PROYECTO
                    asignarProgramador(plantel, MAX_PROG, proyectos, MAX_PROY, progproy, MAX_PP, categorias, MAX_CAT);
                    printf("\n\n");
                    system("pause");
                    break;

            case 5: //ORDENAR POR ID Y MOSTRAR
                    ordenarProgramadores(plantel, MAX_PROG, categorias, MAX_CAT);
                    mostrarProg_Proy(plantel, MAX_PROG, progproy, MAX_PP, proyectos, MAX_PROY, categorias, MAX_CAT);
                    printf("\n\n");
                    system("pause");
                    break;
            case 6: //LISTADO DE PROYECTOS
                    mostrarProyectosCant(proyectos, MAX_PROY, plantel, MAX_PROG);
                    printf("\n\n");
                    system("pause");
                    break;
            case 7: //LISTAR PROYECTOS DEL PROGRAMADOR
                    mostrarProyectosProg(plantel, MAX_PROG, proyectos, MAX_PROY, progproy, MAX_PP, categorias, MAX_CAT);
                    printf("\n\n");
                    system("pause");
                    break;
            case 8: //PROYECTO DEMANDANTE
                    proyectoDemandante(proyectos, MAX_PROY, progproy);
                    printf("\n\n");
                    system("pause");
                    break;
            case 9:
                    system("pause");
                    break;
            default:
                    printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
                    system("pause");
                    break;
        }

    }while(opcion != 9);

                return 0;
}
