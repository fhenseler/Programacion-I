#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define PELICULA_LIBRE 0
#define PELICULA_OCUPADA 1

#define ARRAY_LENGTH 1024
#define MAX_MOVIES 10

typedef struct{

    char titulo[ARRAY_LENGTH];
    char genero[ARRAY_LENGTH];
    char descripcion[ARRAY_LENGTH];
    char linkImagen[ARRAY_LENGTH];
    int duracion;
    int puntaje;
    int id;
    int estado;

}S_Movie;

#endif // FUNCIONES_H_INCLUDED

int movies_init(S_Movie* arrayMovies, int longitud);
int movies_alta(S_Movie* arrayMovies, int index, int longitud);
int movies_baja(S_Movie* arrayMovies);
int movies_modificar(S_Movie* arrayMovies);
int movies_print(S_Movie* arrayMovies, int longitud);
void movies_cargar(S_Movie* arrayMovies);

int movies_generarNuevoId(S_Movie* arrayMovies, int longitud);
int movies_buscarIndicePorId(S_Movie* arrayMovies, int id, int longitud);
int movies_buscarIndiceLibre(S_Movie* arrayMovies, int longitud);
int movies_generarHTML(S_Movie* arrayMovies, char* fileName);
int movies_escribirEnBinario(S_Movie* arrayMovies, int longitud, char* fileName);
