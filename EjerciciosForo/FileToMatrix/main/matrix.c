#include "matrix.h"

int openFile(FILE** file, const char* fileName, const char* openMode)
{
    *file = fopen(fileName, openMode);

    if(!*file){
        perror("Oops! Something wrong ocurred");
        return OPEN_FILE_ERR;
    }

    return OK;
}
void readBatchFile(FILE* matrixFile, int* mat, int* rows, int* columns)
{
    char line[BUFFER_SIZE];
    int rowCounter = 0;

    if(fgets(line, sizeof(line), matrixFile))
        sscanf(line, "%d %d", rows, columns);

    while(fgets(line, sizeof(line), matrixFile) && rowCounter < *rows){
        parseLineToMatrixRow(line, mat, *columns, rowCounter);
        rowCounter++;
    }
}

void parseLineToMatrixRow(char* line, int* mat, int columns, int row)
{
    char* separator;
    int i;

    separator = line;

    for(i = 0; i < columns; i++){
        separator = strchr(line, ' ');
        sscanf(line, "%d", mat + row * MAX_COLUMNS + i);
        separator++;
        line = separator;
    }
}
void showMatrix(int mat[][MAX_COLUMNS], int rows, int columns)
{
    int i;
    int j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

}
void traverseTheCheapestWay(int mat[][MAX_COLUMNS], int rows, int columns)
{
    int row = 0;
    int column = 0;
    int minor = mat[row][column];
    tElement minorElement;

    for(row = 0; row < rows; row++){
        if(findMinor(mat[row][column], minor) != minor){
           minor = mat[row][column];
           minorElement.value = minor;
           minorElement.row = row;
           minorElement.column = column;
        }
    }

    printf("%d,%d\n", minorElement.row, minorElement.column);

    for(column; column < columns; column++){

        for(row = findMajor(0, minorElement.row - 1); row <= findMinor(minorElement.row + 1, rows); row++){
            if(findMinor(mat[row][column], minor) != minor){
                minor = mat[row][column];
                minorElement.value = minor;
                minorElement.row = row;
                minorElement.column = column;
            }
        }
    }

}

int findMinor(int a, int b)
{
   return a - b < 0? a : b;
}

int findMajor(int a, int b)
{
   return a - b < 0? b : a;
}
