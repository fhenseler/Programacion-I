#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char auxiliar[51]; //Posición 51 / auxiliar[50] = '\0'
    char buffer[4096]; //Para interactuar con el usuario
    char buffer2[40] = "Hola";

    //strcpy(auxiliar, "-Hello world!\n");
    strncpy(auxiliar, "-Hello world9999999999999999999999999999999999999999999999!\n", 51);
    auxiliar[50] = '\0';
    printf("\n-----> %s -- LARGO: %d", auxiliar, strlen(auxiliar));

    strncpy(auxiliar, "123", 51);
    auxiliar[50] = '\0';
    printf("\n-----> %s -- LARGO: %d", auxiliar, strlen(auxiliar));

    printf("\n %d", strcmp("B", "B"));

    fgets(buffer, 5, stdin); //USAR fgets, no scanf
    //scanf("%s", buffer);
    printf("\n %s", buffer);



    return 0;
}
