#include "../../Bibliotecas/tdafecha.h"

int main()
{
    char days[TAM][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    tDate dates[TAM] = {
        {0, 12, 2023},
        {1, 12, 2023},
        {12, 0, 2023},
        {12, 13, 2023},
        {29, 2, 2020},
        {29, 2, 2021},
        {29, 2, 2000},
        {29, 2, 1900}
    };
    tDate dates2[TAM] = {
        {30, 11, 2023},
        {31, 10, 2023},
        {28, 02, 2023},
        {30, 12, 2023},
        {28, 02, 2020},
        {29, 02, 2020},
        {29, 02, 2021},
        {30, 12, 2000}
    };
    tDate dates3[TAM] = {
        {30, 11, 2023},
        {31, 10, 2023},
        {28, 02, 2023},
        {30, 12, 2023},
        {28, 02, 2020},
        {29, 02, 2020},
        {29, 02, 2021},
        {30, 12, 2000}
    };
    tDate dates4[TAM] = {
        {30, 11, 2026},
        {31, 10, 2026},
        {28, 02, 2026},
        {30, 12, 2026},
        {28, 02, 2024},
        {29, 02, 2024},
        {29, 02, 2025},
        {30, 12, 2008}
    };
    tDate oldestDate = {27, 2, 2020};
    tDate newestDate = {1, 3, 2020};
    tDate date5 = {03, 10, 2023};

    int i;

    ///Exercise 1
//    printf("1 === CORRECT ----- 0 === INCORRECT\n");
//    for(i = 0; i < TAM; i++)
//        printf("Date: %d-%d-%d --- %d\n", dates[i].day, dates[i].month, dates[i].year, isCorrectDate(&dates[i]));
//    system("pause");
//    system("cls");

    ///Exercise 2
//     for(i = 0; i < TAM; i++){
//        printf("%02d-%02d-%d ---", dates2[i].day, dates2[i].month, dates2[i].year);
//        nextDay(&dates2[i]);
//        printf(" Next Day --- %02d-%02d-%d\n", dates2[i].day, dates2[i].month, dates2[i].year);
//     }
//    system("pause");
//    system("cls");

    ///Exercise 3
//    for(i = 0; i < TAM; i++){
//        printf("%02d-%02d-%d ---", dates2[i].day, dates2[i].month, dates2[i].year);
//        sumNDays(&dates2[i], i * i + i);
//        printf(" New Date --- %02d-%02d-%d\n", dates2[i].day, dates2[i].month, dates2[i].year);
//    }
//    printf("-----------------------\n");

    ///Exercise 4
//    for(i = 0; i < TAM; i++){
//        printf("%02d-%02d-%d ---", dates2[i].day, dates2[i].month, dates2[i].year);
//        substractNDays(&dates2[i], i * i * i+ i);
//        printf(" New Date --- %02d-%02d-%d\n", dates2[i].day, dates2[i].month, dates2[i].year);
//    }
//    system("pause");
//    system("cls");

    ///Exercise 5
//    for(i = 0; i < TAM; i++){
//        printf("%02d-%02d-%d ---", dates3[i].day, dates3[i].month, dates3[i].year);
//        printf(" %d ", daysBetweenTwoDates(&dates3[i], &dates4[i]));
//        printf("--- %02d-%02d-%d\n", dates4[i].day, dates4[i].month, dates4[i].year);
//    }
//    system("pause");
//    system("cls");

    ///Exercise 6
    printf("03-10-1900 --- %s", days[dayOfTheWeek(&date5)]);

    ///Exercise 7



    return 0;
}
