#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[30];
    char apellido[30];
    float promedio;
    eFecha fechaNac;
}eAlumno;

void mostrarAlumno(eAlumno);
void mostrarCurso(eAlumno[], int);

int main()
{
    eAlumno curso[5] = {{1111, "Juan", "Perez", 7, {4, 11, 1995}},
                    {2222, "Jorge", "Suarez", 8.5, {12, 8, 1996}},
                    {3333, "Juan", "Rodriguez", 5.5, {5, 10, 1990}},
                    {4444, "Federico", "Henseler", 10, {12, 9, 1990}},
                    {5555, "Joaquin", "Rodriguez", 8, {5, 10, 1990}}};

                    mostrarCurso(curso, 5);
                    return 0;
}


void mostrarAlumno(eAlumno alumno)
{
    printf("\nLegajo: %d", alumno.legajo);
    printf("\nNombre: %s", alumno.nombre);
    printf("\nApellido: %s", alumno.apellido);
    printf("\nPromedio: %.2f", alumno.promedio);
    printf("\nFecha nacimiento: %d %d %d", alumno.fechaNac.dia, alumno.fechaNac.mes, alumno.fechaNac.anio);
}

void mostrarCurso(eAlumno curso[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
       mostrarAlumno(curso[i]);
       printf("\n");
    }
}
