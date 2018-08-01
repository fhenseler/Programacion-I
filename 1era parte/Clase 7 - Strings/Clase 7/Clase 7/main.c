#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_ELEMENTOS 5
#define CANTIDAD_CARACTERES 51
#define LF 10

int getEdad(int* pEdad, char* msg);
int validarNumero(char* buffer);

int main()
{
    int edad[CANTIDAD_ELEMENTOS];
    int i;

    for(i = 0; i < CANTIDAD_ELEMENTOS; i++)
    {
        if(getEdad(&edad[i], "\nEdad?: ") == -1)
        {
            printf("\nERROR! Edad incorrecta\n");
        }
    }
            return 0;
}

int getEdad(int* pEdad, char* msg)
{
    char buffer[4096];
    int retorno = -1;

    printf(msg);
    fgets(buffer, 4096, stdin);

    buffer[4094] = LF;
    buffer[4095] = '\0';

    if(validarNumero(buffer) == 0)
    {
        *pEdad = atoi(buffer);
        retorno = 0;
    }

        return retorno;
}

int validarNumero(char* buffer)
{
    int retorno = 0;//Excepción.. siempre retorno = -1;
    int i = 0;

    while(buffer[i] != '\0')
    {
        printf("%d", buffer[i]);
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != LF)//Usamos los caracteres ASCII que ya están ordenados (probar)
        {
            retorno = -1;
            break;
        }
            i++;
    }
            return retorno;
}
