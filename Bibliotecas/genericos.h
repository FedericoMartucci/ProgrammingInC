#ifndef GENERICOS_H_INCLUDED
#define GENERICOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define NUM_EMPLEADOS 10

typedef struct{
    int legajo;
    char nya[TAM];
    char categoria;
    float sueldo;
}tEmpleado;

typedef struct{
    char nya[TAM];
    unsigned dni;
    int edad;
}tPersona;

int cargarElementos(size_t ce);
void recorrerVector();
int cargarElementosGen(const void* vecACargar, size_t cantBytes, size_t ce, void(*mostrar)(const void*));
void mostrarEmpleado(const void* vec);
void mostrarChar(const void* vec);
void mostrarInt(const void* vec);
void mostrarPersona(const void* vec);
char* copiaCadena(const char* origen);
void* copiaCosas(void* elemento, unsigned tam);
void* miMemmove(void* s1, const void* s2, size_t n);
///Ejercicios foro
void fMap(void* vec, size_t cantBytes, size_t ce, void(*accion)(void*));///Map
void duplicarYMostrarVectorEntero(void* vec);
void mostrarEmpleados(void* vec);
void duplicarSueldosEmpleadosCatA(void* vec);

void filter(const void* vec, const void* filtro, size_t cantBytes, size_t ce, int(*comparar)(const void*, const void*), void(*mostrar)(const void*));
int compararPorCategoriaYSueldo(const void* vec, const void* filtro);
void mostrarEmpleadosFilter(const void* vec);

void reduce(const void* vec, size_t cantBytes, void* resultado, size_t cantBytesResultado, size_t ce, void(*accion)(const void*, void*, size_t));
void calculaPromedioDeSueldos(const void* vec, void* resultado, size_t iteracion);
void calculaSumaDeSueldos(const void* vec, void* resultado, size_t iteracion);
#endif // GENERICOS_H_INCLUDED
