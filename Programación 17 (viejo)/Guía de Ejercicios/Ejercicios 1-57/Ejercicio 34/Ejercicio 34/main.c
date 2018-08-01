#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    char nombre[MAX][20];
    char nacionalidad[MAX];
    int estudios[MAX];
    int antiguedad[MAX];
    int cantCumplen = 0;
    int totalEmp = 0;
    float porcentajeCumplen;

    printf("***INGRESO DE DATOS***");
    for(int i = 0; i < MAX; i++)
    {
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(nombre[i]);

            printf("\nIngrese nacionalidad (A = Argentino | E = Extranjero): ");
            nacionalidad[i] = toupper(getche(nacionalidad[i]));

            printf("\nIngrese estudios (1 = Primaria | 2 = Secundario | 3 = Universitario): ");
            scanf("%d", &estudios[i]);

            printf("\nIngrese antiguedad: ");
            scanf("%d", &antiguedad[i]);

            totalEmp++;
    }

            for(int i = 0; i < MAX; i++)
            {
                if(nacionalidad[i] == 'E' && estudios[i] == 3 && antiguedad[i] >= 20)
                {
                        cantCumplen++;
                }
            }

                        porcentajeCumplen = ((float)cantCumplen / totalEmp) * 100;
                        printf("\n\nNombre\t Nacionalidad\t Estudios\t Antiguedad\t\n\n");
                        for(int i = 0; i < MAX; i++)
                        {
                            if(nacionalidad[i] == 'E' && estudios[i] == 3 && antiguedad[i] >= 20)
                            {
                                printf("\n%s\t %c\t\t %d\t\t %d\t\t", nombre[i], nacionalidad[i], estudios[i], antiguedad[i]);
                            }
                        }

                            printf("\n\nHay %d personas que cumplen los requisitos", cantCumplen);
                            printf("\nEl porcentaje de los que cumplen los requisitos respecto del total de empleados de la empresa es: %.2f", porcentajeCumplen);
                            getch();
                            return 0;
}
