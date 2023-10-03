#ifndef TDAFECHA_H_INCLUDED
#define TDAFECHA_H_INCLUDED

#define TAM 8

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int day;
    int month;
    int year;
}tDate;

int isCorrectDate(const tDate* date);
int isLeapYear(int year);
void nextDay(tDate* date);
void yesterday(tDate* date);
void sumNDays(tDate* date, int days);
void substractNDays(tDate* date, int days);
int daysBetweenTwoDates(tDate* oldestDate, const tDate* newestDate);
int dayOfTheWeek(tDate* date);
#endif // TDAFECHA_H_INCLUDED
