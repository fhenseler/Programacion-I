#include <stdio.h>
#include <stdlib.h>

int main()
{
    int legajo, legajoMax, legajoMin, t_horas, cantEmp = 0, flagMax = 0, flagMin = 0;
    float totalSalarios, salario, salarioPromedio, salarioMax, salarioMin, s_hora;
    char nombre[31], resp = 'S';

    printf("***INGRESO DE DATOS***\n");
    do
    {
        printf("\nIngrese nombre: ");
        scanf("%s", nombre);

        printf("\nIngrese legajo: ");
        scanf("%d", &legajo);

        printf("\nIngrese salario por hora: ");
        scanf("%f", &s_hora);

        printf("\nIngrese horas trabajadas: ");
        scanf("%d", &t_horas);

        salario = s_hora * t_horas;
        printf("\nEl salario del legajo %d es: %.2f\n", legajo, salario);

        if(flagMax == 0 || salario > salarioMax)
        {
            salarioMax = salario;
            legajoMax = legajo;
            flagMax = 1;
        }

        if(flagMin == 0 || salario < salarioMin)
        {
            salarioMin = salario;
            legajoMin = legajo;
            flagMin = 1;
        }

        cantEmp++;
        totalSalarios += salario;

        printf("\nCONTINUAR INGRESANDO? (S/N) \n");
        resp = toupper(getch(resp));

    }while(resp == 'S');

        salarioPromedio = totalSalarios / cantEmp;

        printf("\nLa cantidad total de empleados es: %d", cantEmp);
        printf("\n\nEl empleado con legajo %d tiene el salario maximo: %.2f", legajoMax, salarioMax);
        printf("\nEl empleado con legajo %d tiene el salario minimo: %.2f", legajoMin, salarioMin);
        printf("\nEl costo de la empresa en salarios es: %.2f", totalSalarios);
        printf("\nEl salario promedio es: %.2f", salarioPromedio);
        getch();
        return 0;
}
