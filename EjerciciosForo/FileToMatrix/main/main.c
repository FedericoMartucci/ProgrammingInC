#include "matrix.h"


int main()
{
    createBatch1();
    createBatch2();
    FILE* matrixFile;
    FILE* matrixFile2;
    int mat[MAX_ROWS][MAX_COLUMNS];
    int mat2[MAX_ROWS][MAX_COLUMNS];
    int matResult[MAX_ROWS][MAX_COLUMNS] = {{0}};
    int rows;
    int rows2;
    int columns;
    int columns2;
    int rowsResult;
    int columnsResult;

    if(openFile(&matrixFile, "test.txt", "rt") != OK || openFile(&matrixFile2, "test2.txt", "rt") != OK){
        fclose(matrixFile);
        return OPEN_FILE_ERR;
    }

    readBatchFile(matrixFile, (int*)mat, &rows, &columns);
    readBatchFile(matrixFile2, (int*)mat2, &rows2, &columns2);
    showMatrix(mat, rows, columns);
    showMatrix(mat2, rows2, columns2);

    productOfMatrixes(mat, rows, columns, mat2, rows2, columns2, matResult);

    loadMatrixToFile(matResult, rows, columns2);

    fclose(matrixFile);
    fclose(matrixFile2);
    return 0;
}

