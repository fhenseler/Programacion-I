#include <stdio.h>
#include <stdlib.h>

int main()
{
    char respuesta = 's';
        while(respuesta == 's'){
                    if(respuesta != 's' && respuesta != 'n'){
                            exit(0);
                    }
                            printf("Desea continuar? [s/n]: ");
                            scanf("%c", &respuesta);
        }
                                getch();
                                return 0;
}
