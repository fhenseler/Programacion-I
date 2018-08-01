#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct  //DEFINICION DE LA ESTRUCTURA
{
    int legajo;
    char nombre[30];
    char apellido[30];
    float promedio;
    eFecha fechaNac; //Variable "fechaNac" del tipo "eFecha" (estructura anidada, por eso declaro eFecha ANTES de eAlumno)

}eAlumno;

void mostrarAlumno(eAlumno);

int main()
{
    eAlumno unAlumno;    //DECLARACION DE LA VARIABLE "unAlumno" DEL TIPO DE DATO "eAlumno"
    eAlumno otroAlumno;

    printf("Ingrese Nombre: ");
    fflush(stdin);
    scanf("%s", unAlumno.nombre);

    printf("Ingrese Apellido: ");
    fflush(stdin);
    scanf("%s", unAlumno.apellido);

    printf("Ingrese Legajo: ");
    scanf("%d", &unAlumno.legajo);

    printf("Ingrese Promedio: ");
    scanf("%f", &unAlumno.promedio);

    printf("Ingrese Fecha de Nacimiento (dd/mm/aa): ");
    scanf("%d %d %d", &unAlumno.fechaNac.dia, &unAlumno.fechaNac.mes, &unAlumno.fechaNac.anio);

    otroAlumno = unAlumno;

    printf("\n\nunAlumno: \n");
    mostrarAlumno(unAlumno);
    printf("\n\notroAlumno: \n");
    mostrarAlumno(otroAlumno);

    getch();
    return 0;
}

void mostrarAlumno(eAlumno alumno)
{
    printf("\n\nDatos del alumno: \n\n");
    printf("Legajo: %d", alumno.legajo);
    printf("\nNombre: %s", alumno.nombre);
    printf("\nApellido: %s", alumno.apellido);
    printf("\nPromedio: %.2f", alumno.promedio);
    printf("\nFecha de Nacimiento: %d/%d/%d", alumno.fechaNac.dia, alumno.fechaNac.mes, alumno.fechaNac.anio);
}
