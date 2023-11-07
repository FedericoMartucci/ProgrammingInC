#include "examen.h"
char* desofuscar(char* line)
{
    int letterPosition = 0;
    int validLetterPosition;
    const char* validLetters = "abcdghijkoqtuv";
    char* initialAddressOfLine = line;

    while(*line){
        if(IS_LETTER(*line))
            letterPosition ++;
        else
            letterPosition = 0;
        validLetterPosition = isValidLetter(*line, validLetters);
        if(validLetterPosition != -1)
            desobsfuscateLetter(line, letterPosition, validLetterPosition, validLetters);
        line++;
    }

    return initialAddressOfLine;
}

int isValidLetter(char letter, const char* validLetters)
{
    int index = 0;

    while(*validLetters){
        if(letter == *validLetters)
            return index;
        validLetters ++;
        index ++;
    }
    return -1;
}

void desobsfuscateLetter(char* line, int position, int validLetterPosition, const char* validLetters)
{
    while(position + validLetterPosition >= strlen(validLetters))
        position -= strlen(validLetters);

    *line = *(validLetters + position + validLetterPosition);

}

int nextWord(char** line, char** word){
    int wordLength = 0;

    while(**line && !IS_LETTER(**line))
        (*line)++;

    *word = *line;

    while(IS_LETTER(**line)){
        wordLength++;
        (*line)++;
    }
    return wordLength;
}
