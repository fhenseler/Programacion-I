#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n_alumno[31], resp = 's';
    int nota_alumno[6], cantNotas = 0, sumNotas = 0, i;
    float promedio;

    do
    {
       printf("\nIngrese nombre alumno: ");
       scanf("%s", &n_alumno);

       for(i = 0; i < 6; i++)
       {
            printf("\nIngrese nota %d: ", i+1);
            scanf("%d", &nota_alumno[i]);
            sumNotas += nota_alumno[i];
            cantNotas++;
       }

        promedio = (float)sumNotas / cantNotas;

        printf("\nNOMBRE DEL ALUMNO: %s", n_alumno);
        printf("\nPROMEDIO: %.2f\n", promedio);

        printf("\nIngresar otro alumno? (s/n)");
        resp = tolower(getch(resp));

    }while(resp == 's');

    getch();
    return 0;
}
