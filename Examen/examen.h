#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define MAX_LINE 1025
#define ROWS 5

char* obtenerFrase(char* frase);
void loadMostLargeQuotes(char mostLargeQuotes[][MAX_LINE],
                         int(*compare)(char [][MAX_LINE], const char*),
                         void (*action)(char*, const char*, int));
int compareQuotes(char mostLargeQuotes[][MAX_LINE], const char* quote);
void swapQuotes(char* mostLargeQuotes, const char* quote, int position);
void showMatrix(char mostLargeQuotes[][MAX_LINE], int mSize);

#endif // EXAMEN_H_INCLUDED
