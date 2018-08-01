#include <stdio.h>
#include <stdlib.h>

int validaS_N(void);

int main()
{
    int num, acumNum = 0, seguir;

    do
    {
        printf("\nIngrese numero: ");
        scanf("%d", &num);
        acumNum += num;
        seguir = validaS_N();

    }while(seguir == 1);

        printf("\nLa suma de los numeros ingresados es: %d\n", acumNum);

    return 0;
}

int validaS_N(void)
{
    char resp = 'S';
    int seguir;

    printf("\nContinua S/N?\n");
    resp = toupper(getch(resp));

    if(resp != 'S' && resp != 'N')
    {
        printf("\nERROR! Reingrese S/N\n");
        resp = toupper(getch(resp));
    }

    if(resp == 'S')
    {
        return 1;
    }
        return 0;
}

