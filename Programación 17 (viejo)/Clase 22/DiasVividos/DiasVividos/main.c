#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eOrigen;

int esBisiesto(int);
int diasDesdeElComienzo(void);
int diasHastaElFinal(int, int, int);
int diasXAnios(int, int);

int main()
{
    eFecha fechaActual;
    eOrigen fechaOrigen;
    int dDC, dHF, dXA;

    SYSTEMTIME hoy;
    GetLocalTime(&hoy);

    fechaOrigen.dia = 9;
    fechaOrigen.mes = 5;
    fechaOrigen.anio = 1995;

    fechaActual.dia = hoy.wDay;
    fechaActual.mes = hoy.wMonth;
    fechaActual.anio = hoy.wYear;

    printf("Fecha origen: %d %d %d", fechaOrigen.dia, fechaOrigen.mes, fechaOrigen.anio);
    printf("\n");
    printf("Fecha actual: %d %d %d", fechaActual.dia, fechaActual.mes, fechaActual.anio);
    printf("\n");
    printf("Cant dias desde el comienzo (principio anio actual -> fecha actual): %d", diasDesdeElComienzo());
    printf("\n");
    printf("Cant dias hasta el final (fecha origen -> fin anio origen): %d", diasHastaElFinal(fechaOrigen.dia, fechaOrigen.mes, fechaOrigen.anio));
    printf("\n");
    printf("Total dias x anios: %d", diasXAnios(fechaOrigen.anio, fechaActual.anio));
    printf("\n");

    dDC = diasDesdeElComienzo();
    dHF = diasHastaElFinal(fechaOrigen.dia, fechaOrigen.mes, fechaOrigen.anio);
    dXA = diasXAnios(fechaOrigen.anio, fechaActual.anio);

    printf("Total dias vividos: %d", dXA + dHF + dDC);
    printf("\n");

    printf("\n\n");
    system("pause");
    return 0;
}

int esBisiesto(int anio)
{
    int retorno;

    if(anio % 4 == 0 && anio % 100 != 0)
    {
       retorno = 1;
    }
    if(anio % 400 == 0)
    {
       retorno = 1;
    }
    else
    {
        retorno = 0;
    }

        return retorno;
}

int diasDesdeElComienzo(void)
{
    eFecha fecha;
    int cantDias;

    fecha.dia = 12;
    fecha.mes = 6;
    fecha.anio = 2017;

    cantDias = fecha.dia + (fecha.mes - 1) * 30;
    return cantDias;
}

int diasHastaElFinal(int dia, int mes, int anio)
{
    int cantDias;

    if(esBisiesto(anio))
    {
        cantDias = 366 - (dia  + (mes - 1) * 30);
    }
    else
    {
        cantDias = 365 - (dia  + (mes - 1) * 30);
    }

        return cantDias;
}

int diasXAnios(int aorigen, int afinal)
{
    int i;
    int totalAnios;
    int totalDias;
    int totalBisiestos = 0;
    int totalNoBisiestos = 0;
    int totalDiasNB;
    int totalDiasB;

    aorigen += 1;

    totalAnios = afinal - aorigen;

    for(i = 0; i < totalAnios; i++)
    {
        if(esBisiesto(i))
        {
            totalBisiestos++;
        }
        if(!esBisiesto(i))
        {
            totalNoBisiestos++;
        }
    }
            totalDiasB = totalBisiestos * 366;
            totalDiasNB = totalNoBisiestos * 365;

            totalDias = totalDiasB + totalDiasNB;

            return totalDias;
}
