#include "../../Bibliotecas/macros.h"

int main()
{
    ///Exercise 1
    int arrElements;

    printf("Elements to enter: ");
    scanf("%d", &arrElements);

    int* arr = malloc(arrElements * sizeof(int));
    if(!arr)
        return 0;
    initializeArray(arr, arrElements);

    int* iniArr = arr;

    system("cls");

    while(deployMenu(arr, arrElements, sizeof(int)))

    free(iniArr);
    ///Exercise 2
    ///Exercise 3
    ///Exercise 4
    ///Exercise 5
    ///Exercise 6
    // Done on header file.
    ///Exercise 7
    // Macros max and min are not defined in stdlib.h.
    ///Exercise 8
    ///Exercise 9
    ///Exercise 10
    ///Exercise 11
    ///Exercise 12
    ///Exercise 13
    ///Exercise 14
    ///Exercise 15
    ///Exercise 16
    ///Exercise 17
    ///Exercise 18

    return 0;
}
