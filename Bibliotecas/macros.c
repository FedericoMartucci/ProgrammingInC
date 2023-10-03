#include "macros.h"

void initializeArray(int* arr, int arrElements)
{
    int counter = 0;

    while(counter < arrElements){
        printf("Enter an element: ");
        scanf("%d", arr);
        arr++;
        counter++;
    }
}
int deployMenu(int* arr, int arrElements, size_t dataSize)
{
    short option;

    do{
        printf("====================== MENU ======================\n");
        printf("1- Find the minor element.\n");
        printf("2- Calculate average of values in pair positions.\n");
        printf("3- Show it in reverse.\n");
        printf("4- Exit.\n");
        printf("Your option: ");
        scanf("%hd", &option);


       switch(option){
            case 1: printf("MinorElement: %d\n", (minorElement(arr, arrElements, sizeof(int), compareInt) == NULL? 0: *(int*)minorElement(arr, arrElements, sizeof(int), compareInt)));
                    break;
            case 2: break;
            case 3: break;
            case 4: return 0;

        }
        system("pause");
        system("cls");
    }while( !(option >= 1 && option <= 4));

    return 1;

}

void* minorElement(const void* arr, int arrElements, size_t dataSize, const void* (*compare)(const void*, const void*)){

    int i;
    const void* minor;

    if(arrElements == 0)
        return NULL;

    minor = arr;

    for(i = 1; i < arrElements; i++){
        arr += dataSize;
        minor = compare(arr, minor);
    }

    return (void*)minor;
}

void traverseArray()
{

}

const void* compareInt(const void* firstElement, const void* secondElement)
{
    if((*(int*) firstElement - *(int*)secondElement) < 0)
        return firstElement;
    return secondElement;
}
