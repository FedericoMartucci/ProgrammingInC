#include "tdafecha.h"


int isCorrectDate(const tDate* date){
    int days[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    if(date->month > 0 && date->month <= 12 && date->day > 0 && date->day <= days[isLeapYear(date->year)][(date->month) - 1])
        return 1;
    return 0;
}

int isLeapYear(int year){
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    return 0;
}

void nextDay(tDate* date)
{
    int days[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    if(!isCorrectDate(date))
        return;
    if(days[isLeapYear(date->year)][date->month - 1] == date->day){
        date->day = 1;
        if(date->month == 12){
            date->month = 1;
            date->year++;
        }else
            date->month++;
    }else
        date->day++;
}
void yesterday(tDate* date)
{
    int days[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    if(!isCorrectDate(date))
        return;

    if(date->day == 1){
        if(date->month == 1){
            date->month = 12;
            date->year--;
        }else
            date->month--;
        date->day = days[isLeapYear(date->year)][date->month - 1];
    }else
        date->day--;
}
/*
    TODO ask if it is OK (calling a function n times instead of calling once and
    coding the logic of adding up n days)
*/
void sumNDays(tDate* date, int days)
{
    if(days > 0){
        nextDay(date);
        sumNDays(date, days - 1);
    }
}
void substractNDays(tDate* date, int days)
{
    if(days > 0){
        yesterday(date);
        substractNDays(date, days - 1);
    }
}
int daysBetweenTwoDates(tDate* oldestDate, const tDate* newestDate)
{
    if(!isCorrectDate(oldestDate) || !isCorrectDate(newestDate))
        return -1;
    if(oldestDate->day == newestDate->day &&
       oldestDate->month == newestDate->month &&
       oldestDate->year == newestDate->year)
       return 0;
    nextDay(oldestDate);
    return (daysBetweenTwoDates(oldestDate, newestDate) + 1);
}
int dayOfTheWeek(tDate* date) //Zeller Algorithm
{
    if (date->month < 3) {
        date->month += 12;
        date->year -= 1;
    }

    int k = date->year % 100;
    int j = date->year / 100;
    int dayOfWeek = (date->day + ((13 * (date->month + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;

    if (dayOfWeek < 0)
        dayOfWeek += 7;

    return dayOfWeek - 1; //Minus 1 return the index.
}
