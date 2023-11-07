#ifndef EJERCICIOSMODELOS_H_INCLUDED
#define EJERCICIOSMODELOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define MAX_CARS 30

typedef struct
{
    char domain[TAM];
    float latitude;
    float longitude;
}tCar;

int openFile(FILE** file, const char* fileName, const char* fileMode);
void insertOrdered(void* arr, void* element, size_t sizeOfElement, size_t maxElements, int* numberOfElements, int (*cmp)(const void*, const void*));
void shiftElements(void* arr, size_t sizeOfElement, size_t positionsToBeMoved);
int cmpInt(const void* a, const void* b);
void traverseFile(FILE* file, size_t dataSize, void (*show)(const void*));
void showCar(const void* car);
void parseFields(char* buffer, tCar* car);
#endif // EJERCICIOSMODELOS_H_INCLUDED
