#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void insertarElemento(int, int*, int, int, int*);
void insertarElementoOrdenado(int*, int, int, int*);
void eliminarElemento(int*, int, int, int*);
void eliminarPrimeraAparicionElemento(int*, int, int, int*);
void eliminarAparicionesElemento(int*, int, int, int*);
void imprimirVector(int*, int);

#endif // ARRAYS_H_INCLUDED
