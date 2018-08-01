#include <stdio.h>
#include <stdlib.h>

inicializarDirectores(directores, CANT_DIRECTORES){
int i;
int retorno;

    if(largoArrayDirector > 0){
        for(i = 0; i < CANT_DIRECTORES; i++){
        directores[i].estado = 0;
        }
        retorno = 0;
            else
            {
            retorno = -1;
            }
                return retorno;
    }
}

inicializarPaises(paises, CANT_PAISES);
int i;
int retorno;

    if(largoArrayPais > 0){
        for(i = 0; i < CANT_PAISES; i++){
        paises[i].estado = 0;
        }
        retorno = 0;
            else
            {
            retorno = -1;
            }
                return retorno;
    }
}

inicializarPeliculas(peliculas, CANT_PELICULAS);
int i;
int retorno;

    if(largoArrayPelicula > 0){
        for(i = 0; i < CANT_PELICULAS; i++){
        peliculas[i].estado = 0;
        }
        retorno = 0;
            else
            {
            retorno = -1;
            }
                return retorno;
    }
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
