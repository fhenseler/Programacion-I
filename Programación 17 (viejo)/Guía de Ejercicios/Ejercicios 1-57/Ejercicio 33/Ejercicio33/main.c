#include <stdio.h>
#include <stdlib.h>

int main()
{
    int antiguedad, horasTrabajadas;
    float valorHora, importeTotal, importeACobrar, descuentos;
    char nombre[31], resp = 's';

    do{

        printf("INGRESAR DATOS\n");
        printf("\nIngrese valor hora: ");
        scanf("%.2f", &valorHora);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s", &nombre);
        printf("\nIngrese antiguedad (anos): ");
        scanf("%d", &antiguedad);
        printf("\nIngrese horas trabajadas: ");
        scanf("%d", &horasTrabajadas);

        importeTotal = (valorHora * horasTrabajadas) + (antiguedad * 30);
        descuentos = importeTotal * 0.13;
        importeACobrar = importeTotal - descuentos;

        printf("\nNombre: %s \n", &nombre);
        printf("Antiguedad: %d \n", antiguedad);
        printf("Valor Hora: %.2f \n", valorHora);
        printf("Total a cobrar en bruto: %.2f \n", importeTotal);
        printf("Total descuentos: %.2f \n", descuentos);
        printf("Valor neto a cobrar: %.2f \n", importeACobrar);

        printf("\nIngresar otro empleado? (s/n) \n");
        fflush(stdin);
        scanf("%c", &resp);

        system("cls");

    }while(resp == 's');

        getch();
        return 0;

}
