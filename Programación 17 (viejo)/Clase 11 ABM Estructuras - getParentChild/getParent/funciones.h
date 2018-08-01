#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idCategoria;
    float sueldo;

}eProgramador;

typedef struct
{
    int id;
    char descripcion[20];

}eCategoria;

int menu();//
void inicializarProgramadores(eProgramador[], int);//
int buscarLibre(eProgramador[], int);//
int buscarPorId(eProgramador[], int, int);//
int buscarCategoria(eCategoria[], int, int);//
void mostrarCategorias(eCategoria[], int);
void mostrarCategoria(eCategoria);//
int altaProgramador(eProgramador[], int, eCategoria[], int);//
void obtenerDescripcion(char[], eCategoria[], int, int);//
int cantidadPorCategoria(eProgramador[], int, eCategoria[], int, char[]);//
void mostrarProgramadores(eProgramador[], int, eCategoria[], int);
void mostrarProgramador(eProgramador, eCategoria[], int);

#endif //FUNCTIONS_H_INCLUDED
