#ifndef MATEMATICA_H_INCLUDED
#define MATEMATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define NO_PERTENECE 0
#define PERTENECE 1
#define PERFECTO 1
#define DEFICIENTE 0
#define ABUNDANTE -1
#define PRIMO 1
#define NO_PRIMO 0
#define MENOR(X, Y) ((X < Y)? X : Y)
#define MAYOR(X, Y) ((X < Y)? Y : X)


int factorial(int);
int combinatorioMSobreN(int, int);
float exponencial(int, float);
float potencia(float, int);
float raizCuadrada(float, float);
int perteneceFibonacci(int);
float seno(float, float);
int clasificarNumero(int);
int productoPorSumasSucesivas(int, int);
int esPrimo(int);
int sumaParesMenores(int);
int sumaNaturales(int);
int sumaNaturalesPares(int);
void cocienteYResto(int*, int, int);
#endif // MATEMATICA_H_INCLUDED
