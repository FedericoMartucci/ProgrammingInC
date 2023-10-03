 #ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define FILE_ERR -1
#define MEM_ERR -2
#define OK 0

#define FACTORIAL(n) \
    ({ \
        int result = 1; \
        for (int i = 1; i <= n; ++i) \
            result *= i; \
        result; \
    })

typedef struct
{
    int year;
    int month;
    int day;
}tDate;

typedef struct
{
    char patent[SIZE];
    int quotaNumber;
    char nya[SIZE];
    int dni;
    tDate expirationDate;
    float amount;
}tPatent;

int createBatch();
int openFile(FILE** filePointer, const char* fileName, const char* mode);
int traverseBinaryFile(FILE* filePointer, size_t dataSize, void (*action)(const void* data));
void showPatent(const void* patent);

#endif // FILES_H_INCLUDED
