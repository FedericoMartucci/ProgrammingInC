#ifndef MISTRINGH_H_INCLUDED
#define MISTRINGH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM 100
#define esLetra(X) (((X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z'))? 1:0)
#define esBlanco(X) ((X == '\0' || X == '\t')? 1:0)
#define aMayus(X) ((X >= 'a' && X <= 'z')? (X - ('a' - 'A')):(X))
#define aMinus(X) ((X >= 'A' && X <= 'Z')? (X + ('a' - 'A')):(X))

size_t miStrlen(const char*);
char* miStrcpy(char*, const char*);
char* miStrcat(char*, const char*);
char* miStrchr(char*, int);
char* miStrrchr(char*, int);
char* miStrstr(const char*, const char*);
char* miStrncpy(char*, const char*, size_t);
size_t proximaPalabra(char**, char**);
void verPalabra(char*, char*);
int esPalindromo(const char*);

#endif // MISTRINGH_H_INCLUDED
