#include <stdio.h>
#include <stdlib.h>

void inicializarDirectores(Director directores[],int largoArrayDirector[CANT_DIRECTORES]);
void inicializarPaises(Pais paises[],int largoArrayPais[CANT_PAISES]);
void inicializarPeliculas(Pelicula peliculas[],int largoArrayPelicula[CANT_PELICULAS]);

typedef struct{
int id_director;
char nombre[50];
int estado;//0 deshabilitado, 1 habilitado, 2 baja
int id_nac;
}Director;

typedef struct{
int id_nac;
char nombre[50];
int estado;
}Pais;

typedef struct{
int id_pelicula;
char titulo;
int año;
int id_nac;
int estado;
int id_director;
}Pelicula;

