#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED

#include <string.h>

#define IS_LETTER(X) ((X <= 'z' && X >= 'a') || (X <= 'Z' && X >= 'A')? 1 : 0)

size_t quieroUnaLineaDeTextoOfuscadaV1(char* linea);
char* desofuscar(char* linea);
int isValidLetter(char letter, const char* validLetters);
void desobsfuscateLetter(char* line, int position, int validLetterPosition, const char* validLetters);
int nextWord(char** line, char** word);

#endif // OFUSCADO_INCLUDED
