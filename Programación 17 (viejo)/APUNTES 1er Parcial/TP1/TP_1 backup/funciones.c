#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
 * \brief Menú de opciones de la calculadora. Tiene 9 opciones y muestra
 * los operandos a calcular, actualizándolos a medida que el usuario ingresa.
 * \param double num1 Primer operando.
 * \param double num2 Segundo operando.
 * \return Muestra por pantalla el menú y los operandos.
 */
int menu(double num1, double num2)
{

int opt; //OPCIÓN

    printf("-----------------CALCULADORA-----------------");
    printf("\n---------------------------------------------");
    printf("\n1. Ingresar 1er operando (A=%.2f)", num1);
    printf("\n2. Ingresar 2do operando (B=%.2f)", num2);
    printf("\n3. Calcular la suma (A+B)");
    printf("\n4. Calcular la resta (A-B)");
    printf("\n5. Calcular la division (A/B)");
    printf("\n6. Calcular la multiplicacion (A*B)");
    printf("\n7. Calcular el factorial (A!)");
    printf("\n8. Calcular todas las operaciones");
    printf("\n9. Salir");
    printf("\n---------------------------------------------");
    printf("\n---------------------------------------------");

    do{
        printf("\nSeleccione opcion: ");
        scanf("%d", &opt);
        return opt;
    }while(opt < 1 || opt > 9);
}


/**
 * \brief Realiza la suma entre dos números enteros y devuelve el resultado.
 * \param int a Primer número entero a sumar.
 * \param int b Segundo número entero a sumar.
 * \return Devuelve el resultado de la suma entre dos números enteros.
 */
long long int add(int a, int b)
{
    int result = a + b;
    return result;
}


/**
 * \brief Realiza la resta entre dos números enteros y devuelve el resultado.
 * \param int a Primer número entero a restar (minuendo).
 * \param int b Segundo número entero a restar (sustraendo).
 * \return Devuelve el resultado de la resta entre dos números enteros.
 */
long long int sub(int a, int b)
{
    int result = a - b;
    return result;
}


/**
 * \brief Realiza la división entre dos números enteros y devuelve el resultado.
 * \param int a Primer número entero a dividir (numerador).
 * \param int b Segundo número entero a dividir (denominador).
 * \return Devuelve el resultado de la división entre dos números enteros.
 */
double divi(int a, int b)
{
    double result = a / (double)b;
    return result;
}



/**
 * \brief Realiza la multiplicación entre dos números enteros y devuelve el resultado.
 * \param int a Primer número entero a multiplicar.
 * \param int b Segundo número entero a multiplicar.
 * \return Devuelve el resultado de la multiplicación entre dos números enteros.
 */
long long int mult(int a, int b)
{
    int result = a * b;
    return result;
}


/**
 * \brief Calcula el factorial de un número entero y devuelve el resultado.
 * \param int a Número entero al que se le calculará el factorial.
 * \return Devuelve el factorial del número entero.
 */
long long int factorial(int a)
{
    int i, sum = 1;
        for (i = a; i > 0; i--)
        {
            sum *= i;
        }
            return sum;
}


