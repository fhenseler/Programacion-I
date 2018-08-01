#include <stdio.h>
#include <stdlib.h>

int main()
{
    int anio;
    char resp = 's';

    do
    {
        printf("\nIngresar anio: ");
        scanf("%d", &anio);

        if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))
        {
            printf("\nEl anio %d es bisiesto\n", anio);
        }

        else
        {
            printf("\nEl anio %d NO es bisiesto\n", anio);
        }

        printf("\nConsultar si otro anio es bisiesto? (s/n)\n");
        resp = tolower(getch(resp));

    }while(resp == 's');

        getch();
        return 0;
}
