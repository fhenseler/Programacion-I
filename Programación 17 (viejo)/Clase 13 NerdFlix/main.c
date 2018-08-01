#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int main()
{

    int opcionMenu = 0;
    char dato[CANT];

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
            mostrarClientes_Series(listClientes, 10, listSeries, 5, listSC, CANT);
            break;
        case 3:
            mostrarSeries_Clientes(listClientes, 10, listSeries, 5, listSC, CANT);
            break;
        case 4:
            mostrarQuienVeLaSerie(listClientes, 10, listSeries, 5, listSC, CANT);
            break;
        case 5:
            serieMenosVista(listSeries, 5, listSC, CANT);
            system("pause");
            break;
        case 6:
            mostrarSeriesJuan(listClientes, CANT, listSeries, 5, listSC, CANT, "juan");
            break;
        case 7:
            break;

        default:
            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
            system("pause");
            break;
        }//SWITCH
    }
    while(opcionMenu != 7);
}

