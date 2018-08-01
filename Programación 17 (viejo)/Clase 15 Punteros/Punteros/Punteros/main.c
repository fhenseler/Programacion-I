#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[25];
} eAlumno;

void cargarAlumnos(eAlumno*, int);
void mostrarListado(eAlumno*, int);
void mostrarAlumno(eAlumno);
void ordenarAlumnos(eAlumno*, int);

int main()
{
    eAlumno alumno[3];

    cargarAlumnos(alumno,3);
    ordenarAlumnos(alumno, 3);
    mostrarListado(alumno,3);

    return 0;
}
void cargarAlumnos(eAlumno* alumnos, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &((alumnos+i)->legajo));

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets((alumnos+i)->nombre);

    }
}

void mostrarListado(eAlumno* alumnos, int tam)
{
    int i;
    for(i=0; i<tam ; i++)
    {
        mostrarAlumno(*(alumnos+i));
    }
}
void mostrarAlumno(eAlumno alumno)
{
    printf("%d--%s\n", alumno.legajo,alumno.nombre);

}

void ordenarAlumnos(eAlumno* alumnos, int tam)
{
    int i, j;
    eAlumno aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if((alumnos+i)->legajo > (alumnos+j)->legajo)
            {
                aux = *(alumnos+i);
                *(alumnos+i) = *(alumnos+j);
                *(alumnos+j) = aux;
            }
        }
    }
}
