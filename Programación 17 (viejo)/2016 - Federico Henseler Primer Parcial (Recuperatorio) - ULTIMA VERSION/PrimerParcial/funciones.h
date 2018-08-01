#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define MAX_PROG 50
#define MAX_PROY 1000
#define MAX_CAT 3
#define MAX_PP 5000

typedef struct
{
    int idProgramador;
    int idCategoria;
    char nombre[20];
    char apellido[20];
    int estado;

}eProgramador;

typedef struct
{
    int idCategoria;
    char descripcion[20];
    int pagoPorHora;

}eCategoria;

typedef struct
{
    int idProyecto;
    char nombre[20];
    int cantidadProg1;
    int cantidadProg2;
    int cantidadProg3;
    int proyectoMax;
    int cont;
    int estado;

}eProyecto;

typedef struct
{
    int idProgramador;
    int idProyecto;
    int estado;
    int cantidadHoras;

}eProg_Proy;


int getInt(char[]);
int getValidInt(char[], char[], int);
void getString(char[], char[]);
int itsAlpha(char[]);
int validateRangeInt(int, char[], int, int);
void getStringAlpha(char[], char[], int);
void validateRangeStr(char[], char[], int);
int findEmptyPlace(eProgramador[], int);
int findEmptyPlace2(eProg_Proy[], int);

void inicializarProgramadores(eProgramador[], int);
void inicializarProyectos(eProyecto[], int);
void inicializarProgProy(eProg_Proy[], int);

void cargarProgramadores(eProgramador[], int);
void cargarProyectos(eProyecto[], int);
void cargarCategorias(eCategoria[], int);

void darAlta(eProgramador[], int, int, int, eCategoria[], int);
void darBaja(eProgramador[], int, int, int);
void modificarProgramador(eProgramador[], int, int, int, eCategoria[], int);

void obtenerDescripcion(char[], eCategoria[], int, int);
int obtenerSumaACobrar(int, eCategoria[], int, int);
int obtenerCantHoras(int, eProg_Proy[], int, int);
int buscarPorID(eProgramador[], int, int);
//int buscarPorID2(eProg_Proy[], int, int);

void ordenarProgramadores(eProgramador[], int, eCategoria[], int);
void mostrarProgramador(eProgramador[], int, eCategoria[], int);
void mostrarProgramadores(eProgramador[], int, eCategoria[], int);

void mostrarProyecto(eProyecto[], int, eProgramador[], int);
void mostrarProyectos(eProyecto[], int, eProgramador[], int);

void mostrarProg_Proy(eProgramador[], int, eProg_Proy[], int, eProyecto[], int, eCategoria[], int);
void mostrarProyectosProg(eProgramador[], int, eProyecto[], int, eProg_Proy[], int, eCategoria[], int);

void mostrarProyectoCant(eProyecto[], int, eProgramador[], int);
void mostrarProyectosCant(eProyecto[], int, eProgramador[], int);

void asignarProgramador(eProgramador[], int, eProyecto[], int, eProg_Proy[], int, eCategoria[], int);

void proyectoDemandante(eProyecto[], int, eProg_Proy[]);

#endif //FUNCTIONS_H_INCLUDED
