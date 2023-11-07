#include "model2.h"

void _ordenarSeleccion(void* arr, size_t numberOfElements, size_t sizeOfElement,
                        int (*cmp)(const void* , const void* ))
{
    void* minorElement;
    void* aux = malloc(sizeOfElement);

    if(!aux)
        return;

    while(numberOfElements > 0){
        minorElement = findMinor((void*)arr, numberOfElements, sizeOfElement, cmp);
        if(cmp(arr, minorElement) > 0){
            memcpy(aux, arr, sizeOfElement);
            memcpy(arr, minorElement, sizeOfElement);
            memcpy(minorElement, aux, sizeOfElement);
        }
        arr += sizeOfElement;
        numberOfElements--;
    }

    free(aux);
}
void* findMinor(void* arr, size_t numberOfElements, size_t sizeOfElement, int (*cmp)(const void* , const void* ))
{
    void* minorElement;

    minorElement = arr;

    while(numberOfElements > 0){
        if(cmp(arr, minorElement) < 0)
            minorElement = arr;
        arr += sizeOfElement;
        numberOfElements--;
    }

    return minorElement;
}
int cmpInt(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
void showArray(const int* arr, size_t sizeOfArr)
{
    int i;
    for(i = 0; i < sizeOfArr; i ++)
        printf("%d ", *(arr++));
}

char* _mstrstr(const char* s1, const char* s2)
{
    int auxS2;

    if(!*s2)
        return (char*) s1;

    while(*s1){
        auxS2 = 0;
        while(*s1 == *s2 && *s1 && *s2){
            s1++;
            s2++;
            auxS2++;

        }
        if(!*s2)
            return  (char*) s1 - auxS2;
        s2 -= auxS2;
        s1++;
    }

    return NULL;
}
int _contarCelulasVivasEnVecindario(int matrix[][MAX_COLUMN], int totalRows,
                                    int totalColumns, int currentRow,int currentColumn)
{
    int row;
    int col;
    int countAliveCells = 0;

    for(row = IS_MAJOR(currentRow - 1, 0); row <= IS_MINOR(currentRow + 1, totalRows - 1) ; row ++)
        for(col = IS_MAJOR(currentColumn - 1, 0); col <= IS_MINOR(currentColumn + 1, totalColumns - 1) ; col ++)
            if(matrix[row][col] == 1)
                countAliveCells ++;

    if(matrix[currentRow][currentColumn] == 1)
        countAliveCells --;

    return countAliveCells;
}
