#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 7
#define ORDEN 3
#define esLetra(X) ((X >= 'a' && X <= 'z') || (X >= 'A' && X <= 'Z'))
#define esBlanco(X) (X == ' ' || X == '\t')
#define aMayus(X) ((X >= 'A' && X <= 'Z')? (X):(X - ('a' - 'A')))
#define aMinus(X) ((X >= 'a' && X <= 'z')? (X):(X + ('a' - 'A')))

#define FULL_ARRAY_ERR -1
#define OK 0

void insertarElemento(int, int*, int, int, int*);
void insertarElementoOrdenado(int*, int, int, int*);
void eliminarElemento(int*, int, int, int*);
void eliminarPrimeraAparicionElemento(int*, int, int, int*);
void eliminarAparicionesElemento(int*, int, int, int*);
void imprimirVector(int*, int);
int esPalindromo(const char*);
int miStrlen(const char*);
int valorNumericoCadena(const char*);
int aparicionesDeUnaPalabra(const char*, const char*);
void normalizarCadena(char*);
void desofuscar(char*);
void compararCadenas();
float sumatoriaEncimaDiagPrincipal(const float*);
float sumatoriaEncimaDiagSecundaria(const float*);
float sumatoriaEncimaDiagPrincipal2(const float*);
float sumatoriaDebajoDiagPrincipal(const float*);
int trazaDiagonalPrincipal(const int*);
int trazaDiagonalSecundaria(const int*);
int esMatrizDiagonal(const int*);
int esMatrizIdentidad(const int*);
int esMatrizSimetrica(const int*);
void transponerMatrizInSitu(int*);
void transponerMatriz(const int*, int, int);
void productoMatrices(const int*, const int*, int, int, int, int);
void mostrarMatriz(int*, int, int);
int verificarMatriz(int*);
void puntosPorEquipo(int*);
void insertElementGeneric(void* arr, void* element, int position, size_t elementSize, size_t arraySize, int* quantityOfElements, void(*swapElement)());
void insertSortedElementGeneric(void* arr, void* element, size_t arraySize, int* quantityOfElements);
void eraseElementGen(void* arr, void* element, size_t arraySize, int* quantityOfElements);
void eraseFirstOccurrenceElementGen(void* arr, void* element, size_t arraySize, int* quantityOfElements);
void eraseAllOcurrencesElementGen(void* arr, void* element, size_t arraySize, int* quantityOfElements);
void swapIntegers(void* arr, void* element);
void swapFloats(void* arr, void* element);
void swapChars(void* arr, void* element);
#endif // ARRAYS_H_INCLUDED
