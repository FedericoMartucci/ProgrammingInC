#include <stdio.h>
#include <string.h>

#include "examen.h"

void loadMostLargeQuotes(char mostLargeQuotes[][MAX_LINE], int(*compare)(char [][MAX_LINE], const char*), void (*action)(char*, const char*, int))
{
    char quote[MAX_LINE];
    int position;

    while(obtenerFrase(quote)){
        position = compare(mostLargeQuotes, (const char*) quote);
        if(position != 0)
            action((char*) mostLargeQuotes, quote, position);
    }
}

int compareQuotes(char mostLargeQuotes[][MAX_LINE], const char* quote)
{
    int position = 1;
    int index;
    int length;

    while(position <= ROWS){
        index = position - 1;
        length = strlen(mostLargeQuotes[index]) - strlen(quote);
        if(length < 0)
            return position;
        position++;
    }
    return 0;
}

void swapQuotes(char* mostLargeQuotes, const char* quote, int position)
{
    char aux[MAX_LINE];

    strcpy(aux, (mostLargeQuotes + (position - 1) * MAX_LINE));
    strcpy((mostLargeQuotes + (position - 1) * MAX_LINE), quote);
    position++;
    while(position <= ROWS){
        strcpy((mostLargeQuotes + (position - 1) * MAX_LINE), aux);
        position++;
        if(position <= ROWS)
            strcpy(aux, (mostLargeQuotes + (position - 1) * MAX_LINE));
    }
}

void showMatrix(char mostLargeQuotes[][MAX_LINE], int mSize)
{
    int i;

    for(i = 0; i < mSize; i++)
        printf("%s\n", mostLargeQuotes[i]);
}
