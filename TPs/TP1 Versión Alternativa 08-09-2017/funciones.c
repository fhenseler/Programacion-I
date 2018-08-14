#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

//DESARROLLO DE FUNCIONES
/**
 * \brief Muestra un menú de opciones y solicita al usuario que ingrese dos operandos,
 * los cuales muestra por pantalla y acutaliza a medida que el usuario ingresa
 * \param float num1 Primer operando
 * \param float num2 Segundo operando
 * \return Devuelve la opción seleccionada por el usuario
 */
int menu(float num1, float num2)
{
    int opt;

    printf("-----------------CALCULADORA-----------------");
    printf("\n---------------------------------------------");
    printf("\n1. Ingresar 1er operando ( A = %f )", num1);
    printf("\n2. Ingresar 2do operando ( B = %f )", num2);
    printf("\n3. Calcular la suma ( A + B )");
    printf("\n4. Calcular la resta ( A - B )");
    printf("\n5. Calcular la divisi%cn ( A / B )", 162);
    printf("\n6. Calcular la multiplicaci%cn ( A * B )", 162);
    printf("\n7. Calcular el factorial ( A ! )");
    printf("\n8. Calcular todas las operaciones");
    printf("\n9. Salir");
    printf("\n---------------------------------------------");
    printf("\n---------------------------------------------");

    do{
        printf("\nSeleccione opci%cn: ", 162);
        scanf("%d", &opt);
        return opt;
    }while(opt < '1' || opt > '9');
}


/**
 * \brief Realiza la suma entre dos números y asigna el resultado al puntero a la variable "result"
 * \param float num1 Primer número a sumar
 * \param float num2 Segundo número a sumar
 * \return void
 */
void n_Add(float* resultAdd, float num1, float num2)
{
    *resultAdd = num1 + num2;
}

/**
 * \brief Realiza la resta entre dos números y asigna el resultado al puntero a la variable "result"
 * \param float num1 Primer número a restar
 * \param float num2 Segundo número a restar
 * \return void
 */
void n_Sub(float* resultSub, float num1, float num2)
{
    *resultSub = num1 - num2;
}

/**
 * \brief Realiza la división entre dos números y asigna el resultado al puntero a la variable "result"
 * \param float num1 Dividendo
 * \param float num2 Divisor
 * \return void
 */
void n_Divi(float* resultDivi, float num1, float num2)
{
    *resultDivi = num1 / num2;
}


/**
 * \brief Realiza la multiplicación entre dos números y asigna el resultado al puntero a la variable "result"
 * \param float num1 Primer número a multiplicar
 * \param float num2 Segundo número a multiplicar
 * \return void
 */
void n_Mult(float* resultMult, float num1, float num2)
{
    *resultMult = num1 * num2;
}

/**
 * \brief Realiza el cálculo del factorial de un número
 * \param float num1 Número al que se le calculará el factorial
 * \return void
 */
void n_Factorial(float* resultFact, float num1)
{
        int i, sum = 1;
        for (i = num1; i > 0; i--)
        {
            sum *= i;
        }
            *resultFact = sum;
}

