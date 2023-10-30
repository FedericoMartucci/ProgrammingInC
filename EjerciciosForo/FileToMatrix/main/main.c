#include "matrix.h"


int main()
{
    FILE* matrixFile;
    int mat[MAX_ROWS][MAX_COLUMNS];
    int rows;
    int columns;

    if(openFile(&matrixFile, "prueba.txt", "rt") != OK){
        return OPEN_FILE_ERR;
    }

    readBatchFile(matrixFile, (int*)mat, &rows, &columns);
    showMatrix(mat, rows, columns);
    traverseTheCheapestWay(mat, rows, columns);

    fclose(matrixFile);
    return 0;
}

