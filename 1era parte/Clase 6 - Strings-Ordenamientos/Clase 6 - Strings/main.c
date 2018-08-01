#include <stdio.h>
#include <stdlib.h>

void imprimirCadena(char* arrayChar);

int main()
{
    char miArray[] = "Hola";

    imprimirCadena(miArray);

    return 0;

}

void imprimirCadena(char* arrayChar) //Muestra como funciona printf
{
    int i = 0;
    char c;
    int flagEncontreFinal = 0;

    while(flagEncontreFinal == 0)
    {
        c = arrayChar[i];

        if(c != 0)
        {
            printf("%c", c);
        }
        else
        {
            flagEncontreFinal = 1;
        }

            i++;
    }
}
