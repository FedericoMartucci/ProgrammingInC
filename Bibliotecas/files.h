 #ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
#define FILE_ERR -1
#define MEM_ERR -2
#define UPDATE_ERR -3

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

typedef struct
{
    int dni;
    char surname[SIZE];
    char name[SIZE];
    float salary;
}tEmployee;

typedef struct
{
    int dni;
    char surname[SIZE];
    char name[SIZE];
    float average;
}tStudent;

typedef struct
{
    tEmployee employee;
    char noveltyType;
}tNovelty;

int createPatentBatch(const char* fileName, const char* fileMode);
int createStudentBatch(const char* fileName, const char* fileMode);
int createEmployeeBatch(const char* fileName, const char* fileMode);
int createNoveltiesBatch(const char* fileName, const char* fileMode);
int createBatch(const char* fileName, const char* fileMode, int(*createTypeBatch)(const char*, const char*));
int openFile(FILE** filePointer, const char* fileName, const char* mode);
int traverseBinaryFile(FILE* filePointer, size_t dataSize, void (*action)(const void* data));
int updateFile(FILE* masterFilePointer, FILE* noveltiesFilePointer,
               size_t masterDataSize, size_t noveltyDataSize,
               int (*action)(void*, const void*, int),
               int (*compare)(const void*, const void*),
               void (*error)(const void*));
int mergeFiles(FILE* filePointer1, FILE* filePointer2, size_t dataSize1, size_t dataSize2,
               void (*action)(void*, const void*),
               int (*compare)(const void*, const void*));
int compareDNI(const void* employee, const void* student);
int updateEmployee(void* destiny, const void* source, int cmp);
int compareEmployeeDNI(const void* employee, const void* novelty);
void increaseSalaryIfAvgGraterThan7(void* data, const void* data2);
void showPatent(const void* data);
void showStudent(const void* data);
void showEmployee(const void* data);
void showNoveltyErrors(const void* data);

#endif // FILES_H_INCLUDED
