#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Movies.h"
#include "Validar.h"

static int modificarPorIndice(S_Movie* arrayMovies, int index);

/**
 * \brief Modifica datos de la pelicula según el índice
 * \param arrayMovies Es el array donde se obtienen los datos a modificar
 * \param index Índice donde se encuentra la pelicula a modificar
 * \return retorno (-1) si el array recibido como parámetro es NULL o si el índice es inválido. (0) si se pudo modificar correctamente
 */
static int modificarPorIndice(S_Movie* arrayMovies, int index)
{
    int retorno = -1;
    char bTitulo[ARRAY_LENGTH];
    char bDuracion[ARRAY_LENGTH];
    char bPuntaje[ARRAY_LENGTH];

    if(arrayMovies != NULL && index >= 0)
    {
        if(val_getNombre(bTitulo,"\nIngrese nuevo titulo: ", "\nError. Reingrese titulo: \n", 3, ARRAY_LENGTH)==0)
        {
            if(val_getUnsignedInt(bDuracion,"\nIngrese nueva duracion (en minutos): ","\nError. Reingrese duracion: \n", 3, ARRAY_LENGTH)==0)
            {
                if(val_getUnsignedInt(bPuntaje,"\nIngrese nuevo puntaje (1-5): ","\nError. Reingrese puntaje: \n", 3, ARRAY_LENGTH)==0)
                {
                    strncpy(arrayMovies[index].titulo, bTitulo, ARRAY_LENGTH);
                    arrayMovies[index].duracion = atoi(bDuracion);
                    arrayMovies[index].puntaje = atoi(bPuntaje);
                    retorno = 0;
                    movies_escribirEnBinario(arrayMovies, MAX_MOVIES, "movies.dat");
                    printf("\nDATOS ACTUALIZADOS!!!");
                }
            }
        }
    }
                    return retorno;
}


/**
 * \brief Inicializa elementos del array de Peliculas
 * \param arrayPeliculas Es el array a recorrer e inicializar
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve (-1) si el array recibido como parámetro es NULL o si la longitud es inválida, (0) si se pudo inicializar correctamente
 */
int movies_init(S_Movie* arrayMovies, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayMovies != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayMovies[i].estado = PELICULA_LIBRE;
        }
            retorno = 0;
    }
            return retorno;
}


/**
 * \brief Da de alta una nueva pelicula
 * \param arrayMovies Es el array donde se ingresan los datos
 * \param index Índice libre para dar de alta la pelicula
 * \param longitud Cantidad de elementos del array
 * \return retorno (-1) si no se cumple alguna validación. (0) si se pudo dar de alta correctamente
 */
int movies_alta(S_Movie* arrayMovies, int index, int longitud)
{
    int retorno = -1;
    int id;
    char bTitulo[ARRAY_LENGTH];
    char bGenero[ARRAY_LENGTH];
    char bDescripcion[ARRAY_LENGTH];
    char bDuracion[ARRAY_LENGTH];
    char bLinkImagen[ARRAY_LENGTH];
    char bPuntaje[ARRAY_LENGTH];

        if(arrayMovies != NULL && index >= 0 && index < longitud)
        {
            if(val_getNombre(bTitulo,"\nTitulo: ", "\nError, reingrese titulo: ", 3, ARRAY_LENGTH)==0)
            {
                if(val_getNombre(bGenero,"\nGenero: ", "\nError, reingrese genero: ", 3, ARRAY_LENGTH)==0)
                {
                        printf("\nLink imagen: ");
                        fgets(bLinkImagen, ARRAY_LENGTH, stdin);
                        strncpy(arrayMovies[index].linkImagen, bLinkImagen, ARRAY_LENGTH);

                            if(val_getUnsignedInt(bDuracion,"\nDuracion: ", "\nError, reingrese duracion: ", 3, ARRAY_LENGTH)==0)
                            {
                                if(val_getUnsignedInt(bPuntaje, "\nPuntaje (1-5): ", "Error, reingrese puntaje: ", 3, ARRAY_LENGTH)==0)
                                {
                                    if(val_validarRangoInt(bPuntaje, "\nERROR! Puntaje Incorrecto (1-5)", 1, 5)==0)
                                    {
                                        if(val_getDescripcion(bDescripcion,"\nDescripcion: ", "\nError, reingrese descripcion: ", 3, ARRAY_LENGTH)==0)
                                        {
                                            id = movies_generarNuevoId(arrayMovies, longitud);
                                            if(id != -1)
                                            {
                                                strncpy(arrayMovies[index].titulo, bTitulo, ARRAY_LENGTH);
                                                strncpy(arrayMovies[index].genero, bGenero, ARRAY_LENGTH);
                                                strncpy(arrayMovies[index].descripcion, bDescripcion, ARRAY_LENGTH);
                                                arrayMovies[index].duracion = atoi(bDuracion);
                                                arrayMovies[index].puntaje = atoi(bPuntaje);
                                                arrayMovies[index].id = id;
                                                arrayMovies[index].estado = PELICULA_OCUPADA;
                                                movies_escribirEnBinario(arrayMovies, longitud, "movies.dat");
                                                printf("\n------------------------------------------");
                                                printf("\nPELICULA DADA DE ALTA CORRECTAMENTE\n");
                                                printf("\nEL ID DE LA NUEVA PELICULA ES: %d\n", arrayMovies[index].id);
                                                printf("------------------------------------------");
                                                retorno = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            else
            if(index < 0)
            {
                printf("ERROR! No hay lugar para dar de alta!");
            }

                                                printf("\n\n");
                                                system("pause");
                                                return retorno;
}


/**
 * \brief Modifica datos de la pelicula
 * \param arrayPeliculas Es el array donde se obtienen los datos a modificar
 * \return retorno (-1) si el array recibido como parámetro es NULL. (0) si se pudo modificar correctamente
 */
int movies_modificar(S_Movie* arrayMovies)
{
    int id;
    int retorno = -1;
    char buffer[ARRAY_LENGTH];

    if(arrayMovies != NULL)
    {
        val_getUnsignedInt(buffer, "\n\nIngrese ID de la pelicula a modificar: ", "\nError. Reingrese ID: ", 3, ARRAY_LENGTH);
        id = atoi(buffer);
        if(movies_buscarIndicePorId(arrayMovies, id, MAX_MOVIES) == -1)
        {
            printf("\nError! ID Invalido\n");
        }
        else
        {
            modificarPorIndice(arrayMovies, movies_buscarIndicePorId(arrayMovies, id, MAX_MOVIES));
            retorno = 0;
        }
    }
            printf("\n\n");
            system("pause");
            return retorno;
}

/**
 * \brief Da de baja una pelicula activa
 * \param arrayMovies Es el array donde se obtiene la pelicula a dar de baja
 * \return retorno (-1) si el array recibido como parámetro es NULL. (0) si se pudo dar de baja correctamente
 */
int movies_baja(S_Movie* arrayMovies)
{
    int indice;
    int id;
    int retorno = -1;
    char buffer[ARRAY_LENGTH];

        if(arrayMovies != NULL)
        {
            val_getUnsignedInt(buffer, "\nIngrese ID de la pelicula a borrar: \n", "\nError. Reingrese ID:  ", 3, ARRAY_LENGTH);
            id = atoi(buffer);
            if(movies_buscarIndicePorId(arrayMovies, id, MAX_MOVIES) == -1)
            {
                printf("\nError! ID Invalido\n");
            }
            else
            {
                indice = movies_buscarIndicePorId(arrayMovies, id, MAX_MOVIES);
                arrayMovies[indice].estado = PELICULA_LIBRE;
                movies_escribirEnBinario(arrayMovies, MAX_MOVIES, "movies.dat");
                printf("\nPELICULA DADA DE BAJA\n");
            }
        }
                printf("\n\n");
                system("pause");
                return retorno;
}

/**
 * \brief Genera un ID autoincrementable y único
 * \param arrayMovies Es el array a recorrer para obtener el nuevo ID
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno Devuelve el nuevo ID
 */
int movies_generarNuevoId(S_Movie* arrayMovies, int longitud)
{
    int i = 0;
    int idMax = -1;

    if(arrayMovies != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayMovies[i].estado == PELICULA_OCUPADA)
            {
                if(idMax < arrayMovies[i].id)
                {
                    idMax = arrayMovies[i].id;
                }

            }
        }
    }
                    return idMax + 1;
}


/**
 * \brief Busca el índice donde está ubicado el ID pasado como parámetro
 * \param arrayMovies Es el array a recorrer para obtener el índice
 * \param id ID utilizado para encontrar el índice
 * \param longitud Cantidad de elementos del array a recorrer
 * \return retorno (-1) si el array recibido como parámetro es NULL o si el ID o la longitud son inválidos. (i - Índice) si se pudo encontrar el índice buscado
 */
int movies_buscarIndicePorId(S_Movie* arrayMovies, int id, int longitud)
{
    int i;
    int retorno = -1;

    if(arrayMovies != NULL && longitud > 0 && id >= 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayMovies[i].estado == PELICULA_OCUPADA)
            {
                if(id == arrayMovies[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
                    return retorno;
}

/**
 * \brief Busca un índice libre en el array de peliculas
 * \param arrayMovies Es el array donde se busca el índice
 * \param longitud Largo del array
 * \return retorno (-1) si el array recibido como parámetro es NULL o la longitud es inválida. (i - Índice) si se pudo obtener el índice libre
 */
int movies_buscarIndiceLibre(S_Movie* arrayMovies, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayMovies != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayMovies[i].estado == PELICULA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
                return retorno;
}

int movies_generarHTML(S_Movie* arrayMovies, char* fileName)
{
    int i;
    int retorno = -1;
    char bufferHeader[2048] = {"<!DOCTYPE html>\
                                <!-- Template by Quackit.com -->\
                                <html lang='en'>\
                                <head>\
                                <meta charset='utf-8'>\
                                <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
                                <meta name='viewport' content='width=device-width, initial-scale=1'>\
                                <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
                                <title>Lista peliculas</title>\
                                <!-- Bootstrap Core CSS -->\
                                <link href='css/bootstrap.min.css' rel='stylesheet'>\
                                <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
                                <link href='css/custom.css' rel='stylesheet'>\
                                <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
                                <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
                                <!--[if lt IE 9]>\
                                <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
                                <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
                                <![endif]-->\
                                </head>\
                                <body>\
                                <div class='container'>\
                                <div class='row'>"};
    char bufferFooter[2048] = {"</div>\
                                <!--/.row -->\
                                </div>\
                                <!-- /.container -->\
                                <!-- jQuery -->\
                                <script src='js/jquery-1.11.3.min.js'></script>\
                                <!-- Bootstrap Core JavaScript -->\
                                <script src='js/bootstrap.min.js'></script>\
                                <!-- IE10 viewport bug workaround -->\
                                <script src='js/ie10-viewport-bug-workaround.js'></script>\
                                <!-- Placeholder Images -->\
                                <script src='js/holder.min.js'></script>\
                                </body>\
                                </html>"};
    char bufferMovie[2048] = {"<article class='col-md-4 article-intro'>\
                               <a href='#'>\
                                   <img class='img-responsive img-rounded' src='%s' alt=''>\
                               </a>\
                               <h3>\
                                    <a href='#'>%s</a>\
                                </h3>\
                                <ul>\
                                    <li>Género: %s</li>\
                                    <li>Puntaje: %d</li>\
                                    <li>Duración: %d</li>\
                                    </ul>\
                                    <p>%s</p>\
                                    </article>"};

//    FILE *pHeader;
//    FILE *pFooter;
    FILE *pMovie;

//    pHeader = fopen("header.txt", "r");
//    pFooter = fopen("footer.txt", "r");
    pMovie = fopen(fileName, "w");

    if(pMovie != NULL)
    {
//            fscanf(pHeader, "%s", bufferHeader);
            fprintf(pMovie, "\n%s", bufferHeader);
//            fclose(pHeader);

            for(i = 0; i < MAX_MOVIES; i++)
            {
                if(arrayMovies[i].estado == PELICULA_OCUPADA)
                {
                    fprintf(pMovie, bufferMovie, arrayMovies[i].linkImagen, arrayMovies[i].titulo, arrayMovies[i].genero, arrayMovies[i].puntaje, arrayMovies[i].duracion, arrayMovies[i].descripcion);
                }
            }

//                fscanf(pFooter, "%s", bufferFooter);
                fprintf(pMovie, "\n%s", bufferFooter);
//                fclose(pFooter);
                fclose(pMovie);
                retorno = 0;
    }

                printf("\nPAGINA WEB GENERADA CORRECTAMENTE!!!\n");
                system("pause");
                return retorno;
}

int movies_escribirEnBinario(S_Movie* arrayMovies, int longitud, char* fileName)
{
    FILE* f;
    int retorno = -1;
    int i;

    f = fopen(fileName, "wb");

    if(f != NULL)
    {
        for(i = 0; i < longitud; i++)
        {
            if(arrayMovies[i].estado == PELICULA_OCUPADA)
            {
                fwrite(arrayMovies, sizeof(S_Movie), MAX_MOVIES, f);
            }
        }
                retorno = 0;
    }

                fclose(f);
                return retorno;
}

int movies_print(S_Movie* arrayMovies, int longitud)
{
    int i;
    int retorno = -1;
    FILE* f;

    f = fopen("movies.dat", "rb");

    if(f != NULL)
    {
        fread(arrayMovies, sizeof(S_Movie), MAX_MOVIES, f);
    }
        fclose(f);

    if(arrayMovies != NULL)
    {
        printf("\nID PELICULA\tTITULO\t\tGENERO\t\tDURACION\tPUNTAJE");
        for(i = 0; i < longitud; i++)
        {
            if(arrayMovies[i].estado == PELICULA_OCUPADA)
            {
                printf("\n%-10d\t%-10s\t%-10s\t%-10d\t%-10d", arrayMovies[i].id, arrayMovies[i].titulo, arrayMovies[i].genero, arrayMovies[i].duracion, arrayMovies[i].puntaje);
            }
        }
                retorno = 0;
    }
                return retorno;
}

void movies_cargar(S_Movie* arrayMovies)
{
    int i;
    char titulo[2][ARRAY_LENGTH] = {"Space Jam", "Scarface"};
    char genero[2][ARRAY_LENGTH] = {"Comedy", "Crime"};
    char descripcion[2][ARRAY_LENGTH] = {"In a desperate attempt to win a basketball match and earn their freedom, the Looney Tunes seek the aid of retired basketball champion, Michael Jordan.", "In Miami in 1980, a determined Cuban immigrant takes over a drug cartel and succumbs to greed."};
    char linkImagen[2][ARRAY_LENGTH] = {"https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTDLxcTh0NS6_0wVhmifeSxOUqSgJNsfXwFS3OdS3peL-enejSQ", "https://www.movieposter.com/posters/archive/main/62/MPW-31295"};
    int duracion[2] = {88, 170};
    int puntaje[2] = {3, 5};
    int id[2] = {0, 1};
    int estado[2] = {1, 1};

    for(i = 0; i < 2; i++)
    {
        strncpy(arrayMovies[i].titulo, titulo[i], ARRAY_LENGTH);
        strncpy(arrayMovies[i].genero, genero[i], ARRAY_LENGTH);
        strncpy(arrayMovies[i].descripcion, descripcion[i], ARRAY_LENGTH);
        strncpy(arrayMovies[i].linkImagen, linkImagen[i], ARRAY_LENGTH);
        arrayMovies[i].duracion = duracion[i];
        arrayMovies[i].puntaje = puntaje[i];
        arrayMovies[i].id = id[i];
        arrayMovies[i].estado = estado[i];
    }
        movies_escribirEnBinario(arrayMovies, MAX_MOVIES, "movies.dat");
}
