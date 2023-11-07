#include "ejerciciosModelos.h"

void insertOrdered(void* arr, void* element, size_t sizeOfElement, size_t maxElements, int* numberOfElements, int (*cmp)(const void*, const void*))
{
    int positionToInsert = 1;

    while(positionToInsert <= *numberOfElements && cmp(arr, element) < 0){
        arr += sizeOfElement;
        positionToInsert++;
    }
    shiftElements(arr, sizeOfElement, maxElements - positionToInsert);
    memcpy(arr, element, sizeOfElement);

    if(*numberOfElements < maxElements)
        (*numberOfElements)++;
}

void shiftElements(void* arr, size_t sizeOfElement, size_t positionsToBeMoved)
{
    void* endOfArr = arr + (positionsToBeMoved) * sizeOfElement;

    while(positionsToBeMoved > 0){
        memcpy(endOfArr, endOfArr - sizeOfElement, sizeOfElement);
        endOfArr -= sizeOfElement;
        positionsToBeMoved --;
    }

}

int cmpInt(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int openFile(FILE** file, const char* fileName, const char* fileMode)
{
    *file = fopen(fileName, fileMode);

    if(!*file){
        perror("Oops! Something wrong occurred");
        return -1;
    }

    return 0;
}

void traverseFile(FILE* file, size_t dataSize, void (*show)(const void*))
{
    tCar car;
    char buffer[100];

    while(fgets(buffer, dataSize, file)){
        parseFields(buffer, &car);
        show(&car);
    }

}

void parseFields(char* buffer, tCar* autito)
{
    char* recorrido = strrchr( buffer, '\n');
    *recorrido = '\0';
    recorrido-=7;
    autito->latitude = atof( recorrido);
    *recorrido = '\0';
    recorrido-=7;
    autito->longitude = atof( recorrido );
    *recorrido = '\0';
    strcpy( autito->domain, buffer );
}
void showCar(const void* car)
{
    printf("================================\n");
    printf("Domain:\t\t%s\nLatitude:\t%.5f\nLongitude:\t%.2f\n", ((tCar*)car)->domain, ((tCar*)car)->latitude, ((tCar*)car)->longitude);
}
