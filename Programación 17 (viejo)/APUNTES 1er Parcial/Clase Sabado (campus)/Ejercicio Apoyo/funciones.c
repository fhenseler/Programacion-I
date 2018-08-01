#include <stdio.h>
#include <stdlib.h>

int menu(void)
{

        int opt;
        printf("1 - ALTA\n");
        printf("2 - MODIFICACION\n");
        printf("3 - LISTAR\n");
        printf("4 - BUSCAR POR LOCALIDAD\n");
        printf("5 - SUELDO MAXIMO\n");
        printf("6 - SUELDO MINIMO\n");
        printf("7 - SALIR\n");

    do{
        printf("\nSeleccione opci%cn: ", 162);
        scanf("%d", &opt);
        return opt;
    }while(opt != 7);
}

float sueldoNeto(float valorHora)
{
    char categoria;
    float horasTrabajadas;
    float sueldoN;

    if(categoria == 'a')
    {
        valorHora = 50;
    }
    if(categoria == 'b')
    {
        valorHora = 30.5;
    }
    if(categoria == 'c')
    {
        valorHora = 20.67;
    }
    sueldoN = valorHora * horasTrabajadas;
    return sueldoN;

}
