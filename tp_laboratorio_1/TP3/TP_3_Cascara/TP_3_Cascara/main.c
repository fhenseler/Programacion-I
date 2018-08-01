#include <stdio.h>
#include <stdlib.h>
#include "Movies.h"
#include "Validar.h"

#define MAX_INPUT_BUFFER 40

int main()
{
    S_Movie arrayMovies[MAX_MOVIES];
    char bufferInt[MAX_INPUT_BUFFER];

    movies_init(arrayMovies, MAX_MOVIES);
    movies_cargar(arrayMovies);

    do
    {
        system("cls");
        printf("<< ABM PELICULAS EN ARCHIVO BINARIO >>\n");
        val_getUnsignedInt(bufferInt, "\n1- AGREGAR PELICULA\n2- BORRAR PELICULA\n3- MODIFICAR PELICULA\n4- GENERAR PAGINA WEB\n\n5- SALIR\n\nElegir Opcion: ", "\nOpciones Validas 1-5. Reingrese: \n", 2, MAX_INPUT_BUFFER);

        system("cls");

        switch(atoi(bufferInt))
        {
            case 1:
                printf("[INGRESAR DATOS DE LA NUEVA PELICULA]\n");
                movies_alta(arrayMovies, movies_buscarIndiceLibre(arrayMovies, MAX_MOVIES), MAX_MOVIES);
                break;
            case 2:
                printf("[DAR DE BAJA UNA PELICULA]\n");
                printf("\n[LISTA DE PELICULAS]\n");
                movies_print(arrayMovies, MAX_MOVIES);
                movies_baja(arrayMovies);
                break;
            case 3:
                printf("[MODIFICAR DATOS DE LAS PELICULAS]\n");
                printf("\n[LISTA DE PELICULAS]\n");
                movies_print(arrayMovies, MAX_MOVIES);
                movies_modificar(arrayMovies);
                break;
            case 4:
                printf("[GENERAR PAGINA WEB]\n");
                movies_generarHTML(arrayMovies, "movies.html");
                break;
            case 5:
                break;
            default:
                printf("\nERROR!!! OPCION INVALIDA!!! (1-5)\n\n");
                printf("\n\n");
                system("pause");
                break;
        }
    }while(atoi(bufferInt) != 5);

                return 0;
}
