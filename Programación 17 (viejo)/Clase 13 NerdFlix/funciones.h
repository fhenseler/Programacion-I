#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define CANT 20

typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;

} eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;

} eCliente;

typedef struct
{
    int idCliente;
    int idSerie;

} eClientes_Series;

typedef struct//Para el punto 5
{
    int idSerie;
    int cont;

} eLoser;


void mostrarMenu(void);
int getValidInt(char[], char[], int);

void inicializarClientes(eCliente[], int);
void inicializarSeries(eSerie[], int);

void mostrarClientes(eCliente[], int);
void mostrarCliente(eCliente);

void mostrarSeries(eSerie[], int);
void mostrarSerie(eSerie);
void mostrarClientes_Series(eCliente[], int, eSerie[], int, eClientes_Series[], int);
void mostrarSeries_Clientes(eCliente[], int, eSerie[], int, eClientes_Series[], int);
void mostrarQuienVeLaSerie(eCliente[], int, eSerie[], int, eClientes_Series[], int);
void mostrarSeriesJuan(eCliente[], int, eSerie[], int, eClientes_Series[], int, char[]);

void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);
void cargarCliente_Serie(eClientes_Series[]);

void serieMenosVista(eSerie[], int, eClientes_Series[], int);

#endif //FUNCTIONS_H_INCLUDED
