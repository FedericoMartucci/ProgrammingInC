#include "examen.h"

void getLargestQuotes(char largestQuotes[][MAX_LINE], size_t rows)
{
    char quote[MAX_LINE];

    while(obtenerFrase(quote))
        insertOrderedDesc(largestQuotes, quote, rows);
}

void showLargestQuotes(char largestQuotes[][MAX_LINE], size_t rows)
{
    for(int i = 0; i < rows; i++)
        printf("%s\n", largestQuotes[i]);
}

void insertOrderedDesc(char largestQuotes[][MAX_LINE], char* quote, size_t rows)
{
    int index = 0;

    while(index < rows){
        if(strlen(largestQuotes[index]) < strlen(quote)){
            swapQuotes(largestQuotes, quote, index, rows);
            return;
        }
        index ++;
    }
}

void swapQuotes(char largestQuotes[][MAX_LINE], char* quote, int index, size_t rows)
{
    char aux[MAX_LINE];

    while(index < rows){
        strcpy(aux, largestQuotes[index]);
        strcpy(largestQuotes[index], quote);
        strcpy(quote, aux);
        index++;
    }
}
void getMostUsedInitials(tInitial* mostUsedInitials, size_t rows)
{
    char quote[MAX_LINE];
    char* line = quote;
    char* word;
    tInitial initials[] = {
    {'a', 0},
    {'b', 0},
    {'c', 0},
    {'d', 0},
    {'e', 0},
    {'f', 0},
    {'g', 0},
    {'h', 0},
    {'i', 0},
    {'j', 0},
    {'k', 0},
    {'l', 0},
    {'m', 0},
    {'n', 0},
    {'o', 0},
    {'p', 0},
    {'q', 0},
    {'r', 0},
    {'s', 0},
    {'t', 0},
    {'u', 0},
    {'v', 0},
    {'w', 0},
    {'x', 0},
    {'y', 0},
    {'z', 0}
    };

    while(obtenerFrase(quote)){
        line = quote;
        while(nextWord(&line, &word)){
            initials[(int)(tolower(*word) - 'a')].timesUsed++;
        }
    }
    qsort(initials, sizeof(initials)/sizeof(tInitial), sizeof(tInitial), cmpTimesUsed);
    memcpy(mostUsedInitials, initials, rows * sizeof(tInitial));
}
void showMostUsedInitials(tInitial* mostUsedInitials, size_t rows)
{
    for(int i = 0; i < rows; i++)
        printf("%c - %d\n", mostUsedInitials[i].initial, mostUsedInitials[i].timesUsed);
}

int nextWord(char** line, char** word)
{
    int wordLength = 0;

    while(**line && !IS_LETTER(**line))
        (*line)++;

    *word = *line;

    while(IS_LETTER(**line)){
        (*line)++;
        wordLength++;
    }

    return wordLength;
}

int cmpTimesUsed(const void* a, const void* b)
{
    return (((tInitial*)b)->timesUsed) - (((tInitial*)a)->timesUsed);
}
