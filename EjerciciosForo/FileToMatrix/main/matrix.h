#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define MAX_ROWS 50
#define MAX_COLUMNS 50

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
void createBatch1();
void createBatch2();
void productOfMatrixes(int mat[][MAX_COLUMNS], size_t rows, size_t columns, int mat2[][MAX_COLUMNS], size_t rows2, size_t columns2, int matResult[][MAX_COLUMNS]);
void loadMatrixToFile(int matResult[][MAX_COLUMNS], int rows, int columns);
#endif // MATRIX_H_INCLUDED
