#include <stdio.h>
#include <stdlib.h>

typedef struct         //DEFINICION DE LA ESTRUCTURA
{
    int legajo;
    char nombre[30];
    char apellido[30];
    float promedio;

}eAlumno;

int main()
{
    eAlumno unAlumno; //DECLARACION DE LA VARIABLE "unAlumno" DEL TIPO DE DATO "eAlumno"

    unAlumno.legajo = 827;
    unAlumno.promedio = 7;
    strcpy(unAlumno.nombre, "Juan");
    strcpy(unAlumno.apellido, "Perez");

    printf("Datos del alumno: \n\n");
    printf("Legajo: %d", unAlumno.legajo);
    printf("\nNombre: %s", unAlumno.nombre);
    printf("\nApellido: %s", unAlumno.apellido);
    printf("\nPromedio: %.2f", unAlumno.promedio);

    getch();
    return 0;
}
