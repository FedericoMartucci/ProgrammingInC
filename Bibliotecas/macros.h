#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/// Ejercicio 6
#define REDONDEAR(X) ((int)((X) + 0.5))
#define VALOR_ABS(X) ((X < 0)? (X*(-1)) : X)
#define PARTE_ENTERA(X) ((int)X)
#define PARTE_DECIMAL(X) ((X) - (int)(X))
#define ES_PAR(X) (((X % 2) == 0) ? (1) : (0))
//#define ES_POTENCIA(X, Y) ((X) == 1 || ((X) > 0 && (X) % (Y) == 0 && ES_POTENCIA((X) / (Y), (Y))))
#define ES_LETRA(X) ((X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z'))
#define ES_DIGITO(X) (X >= '0' && X <= '9')
#define ES_MAYUS(X) (X >= 'A' && X <= 'Z')
#define ES_MINUS(X) (X >= 'a' && X <= 'z')
#define ES_BLANCO(X) (X == ' ' || X == '\t')
#define A_MAYUS(X) ((X >= 'a' && X <= 'z')? (X - ('a' - 'A')) : X)
#define A_MINUS(X) ((X >= 'A' && X <= 'Z')? (X + ('a' - 'A')) : X)
#define MENOR(X, Y) (((X - Y) < 0)? (X) : (Y))
/// Fin ejercicio 6

void initializeArray(int* arr, int arrElements);
int deployMenu(int* arr, int arrElements, size_t dataSize);
void* minorElement(const void* arr, int arrElements, size_t dataSize, const void*(*compare)(const void*, const void*));
const void* compareInt(const void* firstElement, const void* secondElement);

#endif // MACROS_H_INCLUDED
