#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

#define SUMA 0
#define RESTA 1
#define MULTIPLICACION 2
#define DIVISION 3
#define MODULO 4

int calculadora(float* resultadoDivision, float* resultadoSuma, float* resultadoResta, float* resultadoMultiplica, float num1, float num2);
int calculadora2(float* resultado, float num1, float num2, char operacion);

#endif // CALCULADORA_H_INCLUDED
