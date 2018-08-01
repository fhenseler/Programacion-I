#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT 20

/*
1- mostrar cada uno
2- mostrar clientes con sus series
3- por cada serie los clientes que la estan viendo
4- todos los clientes que ven una serie en particular (El usuario ingresa el titulo)
5- La serie menos popular
6- Todas las series que ven los clientes de nombre "Juan"
*/


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

int cantidadPorSerie(eCliente[], int, eSerie[], int, eClientes_Series[], int, char[]);


int main()
{

    int opcionMenu = 0;
    char dato[CANT];

    int cantTBBT = 0;
    int cantBB = 0;
    int cantGOT = 0;
    int cantAHS = 0;
    int cantSCD = 0;
    int loser;
    int flagLoser = 0;

    eCliente listClientes[CANT];
    eSerie listSeries[CANT];
    eClientes_Series listSC[CANT];

    do
    {
        system("cls");
        mostrarMenu();
        opcionMenu = getValidInt("\nSeleccione opcion (1-7): ", dato, CANT);
        inicializarClientes(listClientes, CANT);
        inicializarSeries(listSeries, CANT);
        cargarSeries(listSeries);
        cargarClientes(listClientes);
        cargarCliente_Serie(listSC);

        switch(opcionMenu)
        {
            case 1:
                    mostrarClientes(listClientes, CANT);
                    mostrarSeries(listSeries, CANT);
                    break;
            case 2:
                    mostrarClientes_Series(listClientes, CANT, listSeries, CANT, listSC, CANT);
                    break;
            case 3:
                    mostrarSeries_Clientes(listClientes, CANT, listSeries, CANT, listSC, CANT);
                    break;
            case 4:
                    mostrarQuienVeLaSerie(listClientes, CANT, listSeries, CANT, listSC, CANT);
                    break;
            case 5:
                    cantTBBT = cantidadPorSerie(listClientes, CANT, listSeries, CANT, listSC, CANT, "TBBT");
                    cantBB = cantidadPorSerie(listClientes, CANT, listSeries, CANT, listSC, CANT, "BB");
                    cantGOT = cantidadPorSerie(listClientes, CANT, listSeries, CANT, listSC, CANT, "GOT");
                    cantAHS = cantidadPorSerie(listClientes, CANT, listSeries, CANT, listSC, CANT, "AHS");
                    cantSCD = cantidadPorSerie(listClientes, CANT, listSeries, CANT, listSC, CANT, "SCD");

                    printf("\nTBBT: %d  BB: %d   GOT: %d   AHS: %d   SCD: %d\n\n", cantTBBT, cantBB, cantGOT, cantAHS, cantSCD);
                    system("pause");
                    break;
            case 6:
                    mostrarSeriesJuan(listClientes, CANT, listSeries, CANT, listSC, CANT, "juan");
                    break;
            case 7:
                    break;
            default:
                    printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
                    system("pause");
                    break;
        }//SWITCH
    }while(opcionMenu != 7);
}

void cargarSeries(eSerie series[])
{
    int idSerie[5]= {100,101,102,103,104};
    int estado[5]= {1,1,1,1,1};
    char titulo[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]= {9,7,7,6,1};
    char genero[5][30]= {"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]= {"juan","maria","pedro","luis","romina","jose","juan","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};

    int i;

    for(i=0; i<10; i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
    }
}

void cargarCliente_Serie(eClientes_Series clientesSeries[])
{

    int cliente[20] = {1,1,1,2,2,3,4,4,5,5,5,7,8,8,8,9,10,10,10,10};
    int serie[20]= {101,102,103,104,103,101,101,102,104,101,102,101,101,102,103,102,101,103,102,104};
    int i;

    for(i=0; i<20; i++)
    {
        clientesSeries[i].idCliente=cliente[i];
        clientesSeries[i].idSerie = serie[i];
    }

}

void cargarLoser(eLoser perdedores[])
{
    int idSerie[5]= {100,101,102,103,104};
    int i;
    for(i=0; i<5; i++)
    {
        perdedores[i].idSerie = idSerie[i];
    }
}

void mostrarMenu(void)
{
        /*
1- mostrar cada uno
2- mostrar clientes con sus series
3- por cada serie los clientes que la estan viendo
4- todos los clientes que ven una serie en particular (El usuario ingresa el titulo)
5- La serie menos popular
6- Todas las series que ven los clientes de nombre "Juan"
*/


        printf("-----------MENU DE OPCIONES-----------");
        printf("\n--------------------------------------");
        printf("\n1- Mostrar Clientes y Series\n");
        printf("2- Mostrar Clientes y las series que miran\n");
        printf("3- Mostrar Series y los clientes que las miran\n");
        printf("4- Mostrar clientes que ven determinada serie\n");
        printf("5- Serie menos popular\n");
        printf("6- Series que ven los clientes de nombre \"Juan\"\n");
        printf("--------------------------------------");
        printf("\n--------------------------------------");
}

int getValidInt(char mensaje[], char dato[], int tam)
{
    int flag, datoInt;
    printf("%s", mensaje);
    scanf("%s", dato);

    flag = 0;
    tam = strlen(dato);
    for(int i = 0; i < tam; i++)
    {
        if(!isdigit(dato[i]))
        {
            flag = 1;
            break;
        }
    }
           if(flag == 0)
           {
                datoInt = atoi(dato);
           }
                return datoInt;
}



void mostrarClientes(eCliente cli[], int tam)
{
    int i;
    printf("CLIENTES\n");
    for(i= 0; i<tam; i++)
    {
        if(cli[i].idCliente != -1)
        {
            mostrarCliente(cli[i]);
        }
    }
    printf("\n");

}

void mostrarCliente(eCliente cli)
{
    printf("\n%d %s", cli.idCliente, cli.nombre);
}

void mostrarSeries(eSerie ser[], int tamS)
{
    int i;
    printf("SERIES\n");
    printf("\nId   Titulo     Temporadas     Genero\n\n");
    for(i=0; i< tamS; i++)
    {
        if(ser[i].idSerie != -1)
        {
             mostrarSerie(ser[i]);
        }
    }

    printf("\n\n");

    system("pause");

}

void mostrarSerie(eSerie ser)
{
    printf("\n%d %s %d %s", ser.idSerie, ser.titulo, ser.temporadas, ser.genero);
}

void mostrarClientes_Series(eCliente cli[], int cantC, eSerie ser[], int cantS, eClientes_Series cli_ser[], int cantSC)
{
    int i, j, k;

    printf("NOMBRE     TITULO     TEMPORADAS     GENERO");
    for(i = 0; i < cantC; i++)
    {
        for(j = 0; j < cantSC; j++)
        {
            if(cli[i].estado == 1 && cli[i].idCliente == cli_ser[j].idCliente)
            {
                for(k = 0; k < cantS; k++)
                {
                    if(ser[k].estado == 1 && ser[k].idSerie == cli_ser[j].idSerie)
                    {
                        printf("\n%s       %s       %d       %s", cli[i].nombre, ser[k].titulo, ser[k].temporadas, ser[k].genero);
                    }
                }
            }
        }
    }
                        printf("\n");
                        system("pause");
}


void mostrarSeries_Clientes(eCliente cli[], int cantC, eSerie ser[], int cantS, eClientes_Series cli_ser[], int cantSC)
{
    int i, j, k;

    printf("TITULO     TEMPORADAS     GENERO     NOMBRE");
    for(i = 0; i < cantS; i++)
    {
        for(j = 0; j < cantSC; j++)
        {
            if(ser[i].estado == 1 && ser[i].idSerie == cli_ser[j].idSerie)
            {
                for(k = 0; k < cantS; k++)
                {
                    if(cli[k].estado == 1 && cli[k].idCliente == cli_ser[j].idCliente)
                    {
                        printf("\n%s       %d       %s       %s", ser[i].titulo, ser[i].temporadas, ser[i].genero, cli[k].nombre);
                    }
                }
            }
        }
    }
                        printf("\n");
                        system("pause");
}

void mostrarQuienVeLaSerie(eCliente cli[], int cantC, eSerie ser[], int cantS, eClientes_Series cli_ser[], int cantSC)
{
    int i, j, k;
    char serAux[200];

    printf("Ingrese titulo de la serie a buscar: ");
    fflush(stdin);
    gets(serAux);

    printf("TITULO     TEMPORADAS     GENERO     NOMBRE");
    for(i = 0; i < cantS; i++)
    {
        if(strcmp(ser[i].titulo, serAux)==0)
        {
                for(j = 0; j < cantSC; j++)
                {
                    if(ser[i].estado == 1 && ser[i].idSerie == cli_ser[j].idSerie)
                    {
                        for(k = 0; k < cantS; k++)
                        {
                            if(cli[k].estado == 1 && cli[k].idCliente == cli_ser[j].idCliente)
                            {
                                printf("\n%s       %d       %s       %s", ser[i].titulo, ser[i].temporadas, ser[i].genero, cli[k].nombre);
                            }
                        }
                    }
                }
        }
    }
                            printf("\n");
                            system("pause");
}


void inicializarClientes(eCliente cli[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        cli[i].idCliente = -1;
    }
}

void inicializarSeries(eSerie ser[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        ser[i].idSerie = -1;
    }
}


int cantidadPorSerie(eCliente cli[], int tamC, eSerie ser[], int tamS, eClientes_Series cli_ser[], int tamCS, char titulo[])
{
    int i, k;
    int cont = 0;
    int idSer;

    for(i=0; i< tamS; i++)
    {
        if(strcmp(ser[i].titulo, titulo) == 0)
        {
            idSer = ser[i].idSerie;
            break;
        }
    }

        for(k=0; k< tamCS; k++)
        {
            if(cli_ser[k].idSerie == idSer)
            {
                cont++;
            }
        }

    return cont;

}

void mostrarSeriesJuan(eCliente cli[], int cantC, eSerie ser[], int cantS, eClientes_Series cli_ser[], int cantSC, char nombre[])
{
    int i, j, k;

    printf("NOMBRE    ID CLIENTE    TITULO     TEMPORADAS     GENERO");
    for(i = 0; i < cantC; i++)
    {
        for(j = 0; j < cantSC; j++)
        {
            if(cli[i].estado == 1 && cli[i].idCliente == cli_ser[j].idCliente)
            {
                for(k = 0; k < cantS; k++)
                {
                    if(ser[k].estado == 1 && ser[k].idSerie == cli_ser[j].idSerie)
                    {
                        if(strcmp(cli[i].nombre, nombre)==0)
                        {
                           printf("\n%s     %d      %s       %d       %s", cli[i].nombre, cli_ser[j].idCliente, ser[k].titulo, ser[k].temporadas, ser[k].genero);
                        }
                    }
                }
            }
        }
    }
                        printf("\n");
                        system("pause");
}
