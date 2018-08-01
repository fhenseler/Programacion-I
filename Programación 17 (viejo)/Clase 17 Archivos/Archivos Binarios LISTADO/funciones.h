#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define A 3

typedef struct
{
	int legajo;
	char apellido[25];
	char nombre[20];
	float promedio;
}alumno;


char menu(void);

void alta(alumno*);
void listar(alumno*);
void modificar(alumno*);
void baja(alumno*);

//void mayorPromedio(alumno*);

int buscaLegajo(alumno*, int leg);
int buscarLibre(alumno*);
void toString(alumno*);
int guardarEnArchivo(alumno *);
int cargarDesdeArchivo(alumno *);
void crearTxt(alumno *);


#endif // FUNCIONES_H_INCLUDED
