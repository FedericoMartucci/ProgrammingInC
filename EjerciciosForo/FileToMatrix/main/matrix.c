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
void createBatch1()
{
    FILE* file;
    int row;
    int col;
    if(openFile(&file, "test1.txt", "wt") != OK)
        return;

    int mat[][MAX_COLUMNS] =
    {
        {0, 0, 3, 4},
        {1, 0, 0, 0},
        {0, 2, 0, 4},
    };
    int totalRows = sizeof(mat)/(sizeof(int)*MAX_COLUMNS);
    fprintf(file, "%d|%d\n", totalRows, 4);
    for(row = 0; row < sizeof(mat)/(sizeof(int)*MAX_COLUMNS); row++)
        for(col = 0; col < 4; col ++)
            if(mat[row][col])
                fprintf(file, "%d|%d|%d\n", row, col, mat[row][col]);

    fclose(file);

}
void createBatch2()
{
    FILE* file;
    int row;
    int col;
    if(openFile(&file, "test2.txt", "wt") != OK)
        return;

    int mat[][MAX_COLUMNS] =
    {
        {0},
        {1},
        {0},
        {0},
    };
    int totalRows = sizeof(mat)/(sizeof(int)*MAX_COLUMNS);
    fprintf(file, "%d|%d\n", totalRows, 1);
    for(row = 0; row < sizeof(mat)/(sizeof(int)*MAX_COLUMNS); row++)
        for(col = 0; col < 4; col ++)
            if(mat[row][col])
                fprintf(file, "%d|%d|%d\n", row, col, mat[row][col]);

    fclose(file);

}
void readBatchFile(FILE* matrixFile, int* mat, int* rows, int* columns)
{
    char line[BUFFER_SIZE];
    int rowCounter = 0;
    int row;
    int col;
    int value;

    if(fgets(line, sizeof(line), matrixFile))
        sscanf(line, "%d|%d", rows, columns);

    while(fgets(line, sizeof(line), matrixFile) && rowCounter <= *rows){
        sscanf(line, "%d|%d|%d", &row, &col, &value);
        *(mat + row * MAX_COLUMNS + col) = value;
        rowCounter++;
    }
}


void productOfMatrixes(int mat[][MAX_COLUMNS], size_t rows, size_t columns, int mat2[][MAX_COLUMNS], size_t rows2, size_t columns2, int matResult[][MAX_COLUMNS])
{
    int i;
    int j;
    int k;
    int sum;

    if(columns != rows2)
        return;

    for(i = 0; i < rows; i++)
        for(j = 0; j < columns2; j++){
            sum = 0;
            for(k = 0; k < rows2; k++)
                sum += mat[i][k] * mat2[k][j];
           matResult[i][j] = sum;
        }
}
void loadMatrixToFile(int matResult[][MAX_COLUMNS], int rows, int columns)
{
    FILE* file;
    int row;
    int col;
    if(openFile(&file, "results.txt", "wt") != OK)
        return;

    fprintf(file, "%d|%d\n", rows, columns);
    for(row = 0; row < rows; row++)
        for(col = 0; col < columns; col ++)
            if(matResult[row][col])
                fprintf(file, "%d|%d|%d\n", row, col, matResult[row][col]);

    fclose(file);
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
