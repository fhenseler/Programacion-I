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
    }while(opt < 1 || opt > 9);
}


/**
 * \brief Realiza la suma entre dos números y devuelve el resultado
 * \param float num1 Primer número a sumar
 * \param float num2 Segundo número a sumar
 * \return Devuelve el resultado de la suma entre dos números
 */
float n_Add(float num1, float num2)
{
    float result = num1 + num2;
    return result;
}


/**
 * \brief Realiza la resta entre dos números y devuelve el resultado
 * \param float num1 Primer número a restar (minuendo)
 * \param float num2 Segundo número a restar (sustraendo)
 * \return Devuelve el resultado de la resta entre dos números
 */
float n_Sub(float num1, float num2)
{
    float result = num1 - num2;
    return result;
}


/**
 * \brief Realiza la división entre dos números y devuelve el resultado
 * \param float num1 Primer número a dividir (numerador)
 * \param float num2 Segundo número a dividir (denominador)
 * \return Devuelve el resultado de la división entre dos números
 */
float n_Divi(float num1, float num2)
{
    float result = num1 / num2;
    return result;
}


/**
 * \brief Realiza la multiplicación entre dos números y devuelve el resultado
 * \param float num1 Primer número a multiplicar
 * \param float num2 Segundo número a multiplicar
 * \return Devuelve el resultado de la multiplicación entre dos números
 */
float n_Mult(float num1, float num2)
{
    float result = num1 * num2;
    return result;
}


/**
 * \brief Realiza el cálculo del factorial de un número y devuelve el resultado
 * \param float num1 Número al que se le calculará el factorial
 * \return Devuelve el factorial del número
 */
unsigned n_Factorial(float num1)
{
    unsigned int i, sum = 1;
        for (i = num1; i > 0; i--)
        {
            sum *= i;
        }
            return sum;
}

/**
 * \brief Utiliza la función "n_Add" para sumar dos números e imprime el resultado
 * \param float num1 Primer número a sumar
 * \param float num2 Segundo número a sumar
 * \return void
 */
void printAdd(float num1, float num2)
{
    float result = n_Add(num1, num2);
    printf("\nSUMA ( A + B ) = %f", result);
}


/**
 * \brief Utiliza la función "n_Sub" para restar dos números e imprime el resultado
 * \param float num1 Primer número a restar
 * \param float num2 Segundo número a restar
 * \return void
 */
void printSub(float num1, float num2)
{
    float result = n_Sub(num1, num2);
    printf("\nRESTA ( A - B ) = %f", result);
}


/**
 * \brief Utiliza la función "n_Divi" para dividir dos números e imprime el resultado
 * \param float num1 Primer número a dividir
 * \param float num2 Segundo número a dividir
 * \return void
 */
void printDivi(float num1, float num2)
{
    float result = n_Divi(num1, num2);
    printf("\nDIVISI%cN ( A / B ) = %f", 224, result);
}


/**
 * \brief Utiliza la función "n_Mult" para multiplicar dos números e imprime el resultado
 * \param float num1 Primer número a multiplicar
 * \param float num2 Segundo número a multiplicar
 * \return void
 */
void printMult(float num1, float num2)
{
    float result = n_Mult(num1, num2);
    printf("\nMULTIPLICACI%cN ( A * B ) = %f", 224, result);
}


/**
 * \brief Utiliza la función "Factorial" para calcular el factorial de un número e imprime el resultado
 * \param unsigned int num1 Número al que se le calculará el factorial
 * \return void
 */
void printFactorial(unsigned int num1)
{
    unsigned int result = n_Factorial(num1);
    printf("\nFACTORIAL ( A !) = %d", result);
}


