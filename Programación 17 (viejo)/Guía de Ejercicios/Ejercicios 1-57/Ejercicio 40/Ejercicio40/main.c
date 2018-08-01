#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n_legajo, n_sueldo, c_mujeres = 0, c_hombres = 0;
    char sexo, resp = 's';

    do
    {
        printf("INGRESO DE DATOS DEL EMPLEADO\n");
        printf("\n\nIngrese legajo: ");
        scanf("%d", &n_legajo);

        printf("\nIngrese sueldo: ");
        scanf("%d", &n_sueldo);

        printf("\nIngrese sexo (1 = F / 2 = M): ");
        fflush(stdin);
        scanf("%c", &sexo);

            if(sexo == 'f' && n_sueldo >= 500)
            {
                c_mujeres++;
            }

            if(sexo == 'm' && n_sueldo < 400)
            {
                c_hombres++;
            }

            printf("\nIngresar otro empleado? (s/n): \n");
            resp = tolower(getch(resp));

            system("cls");

    }while(resp == 's');

        printf("%d mujeres ganan mas de $500\n", c_mujeres);
        printf("%d hombres ganan menos de $500", c_hombres);
        getch();
        return 0;

}
