#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flagMax = 0;
    float alturaAlumno, alturaMax;
    char n_alumno[50], nombreMax[50], resp = 's';

    printf("INGRESAR DATOS\n");
    do
    {
        printf("Ingrese nombre del alumno: ");
        scanf("%s", &n_alumno);
        printf("Ingrese altura alumno: ");
        scanf("%f", &alturaAlumno);

        if(flagMax == 0 || alturaAlumno > alturaMax)
        {
            alturaMax = alturaAlumno;
            strcpy(nombreMax, n_alumno);
            flagMax = 1;
        }

        printf("\nIngresar otro alumno? (s/n):  \n\n");
        resp = tolower(getch(resp));

    }while(resp == 's');

        printf("El alumno mas alto es %s y mide %.2f", nombreMax, alturaMax);
        getch();
        return 0;
}
