#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define OPEN_FILE_ERR -1
#define OK 0

typedef struct{
    int value;
    int row;
    int column;
}tElement;

int openFile(FILE** file, const char* fileName, const char* openMode);
void readBatchFile(FILE* matrixFile, int* mat, int* rows, int* columns);
void parseLineToMatrixRow(char* line, int* mat, int columns, int row);
void showMatrix(int mat[][MAX_COLUMNS], int rows, int columns);
void traverseTheCheapestWay(int mat[][MAX_COLUMNS], int rows, int columns);
int findMinor(int a, int b);
int findMajor(int a, int b);
#endif // MATRIX_H_INCLUDED
