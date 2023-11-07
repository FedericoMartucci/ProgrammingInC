#ifndef MODEL2_H_INCLUDED
#define MODEL2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_MAJOR(X, Y) (X > Y? X : Y)
#define IS_MINOR(X, Y) (X < Y? X : Y)

#define MAX_COLUMN 1024

void _ordenarSeleccion (void* arr, size_t numberOfElements, size_t sizeOfElement,
                        int (*cmp)(const void* , const void* ));
void* findMinor(void* arr, size_t numberOfElements, size_t sizeOfElement, int (*cmp)(const void* , const void* ));
void showArray(const int* arr, size_t sizeOfArr);
int cmpInt(const void* a, const void* b);
char* _mstrstr(const char* s1, const char* s2);
int _contarCelulasVivasEnVecindario(int matrix[][MAX_COLUMN], int totalRows, int totalColumns, int currentRow, int currentColumn);
#endif // MODEL2_H_INCLUDED
