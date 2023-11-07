#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define MAX_LINE 1025
#define TOP_FIVE 5
#define LETTERS 26

#define IS_LETTER(X) ((X >= 'a' && X <= 'z') || (X >= 'A' && X <= 'Z')? 1 : 0)
#define ATOI(X) (X - 'a')

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char initial;
    int timesUsed;
}tInitial;

char* obtenerFrase(char* frase);
void getLargestQuotes(char largestQuotes[][MAX_LINE], size_t rows);
void showLargestQuotes(char largestQuotes[][MAX_LINE], size_t rows);
void insertOrderedDesc(char largestQuotes[][MAX_LINE], char* quote, size_t rows);
void swapQuotes(char largestQuotes[][MAX_LINE], char* quote, int index, size_t rows);
void getMostUsedInitials(tInitial* mostUsedInitials, size_t rows);
void showMostUsedInitials(tInitial* mostUsedInitials, size_t rows);
int nextWord(char** line, char** word);
int cmpTimesUsed(const void* a, const void* b);
#endif // EXAMEN_H_INCLUDED
