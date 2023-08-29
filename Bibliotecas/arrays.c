#include "arrays.h"

void insertarElemento(int posicion, int* vec, int elemento, int tamVec, int* ce)
{
    int i;
    for(i = 0; i < posicion; i++)
        vec++;
    *vec = elemento;
    if(*ce < tamVec)
        (*ce)++;
}

void insertarElementoOrdenado(int* vec, int elemento, int tamVec, int* ce)
{
    int i;
    int j;
    int aux;
    int aux2;
    for(i = 0; i < tamVec-1; i++)
    {
        if(*vec > elemento)
        {
            aux = *vec;
            *vec = elemento;
            for(j = i; j < tamVec-1; j++)
            {
                vec++;
                aux2 = *vec;
                *vec = aux;
                aux = aux2;
            }
            if(*ce < tamVec)
                (*ce)++;
            break;
        }
        vec++;
    }
}
void eliminarElemento(int* vec, int posicion, int tamVec, int* ce)
{
    int i;
    int j;
    for(i = 0; i < tamVec-1; i++)
    {
        if(i == posicion){
            for(j = i; j < tamVec-1; j++){
                *vec = *(vec+1);
                vec++;
            }
            (*ce)--;
            return;
        }
        vec++;
    }
}
void eliminarPrimeraAparicionElemento(int* vec, int elemento, int tamVec, int* ce){
    int i;
    int j;
    for(i = 0; i < tamVec-1; i++){
        if(*vec == elemento){
            for(j = i; j < tamVec-1; j++){
                *vec = *(vec+1);
                vec++;
            }
            (*ce)--;
            return;
        }
        vec++;
    }
}
void eliminarAparicionesElemento(int* vec, int elemento, int tamVec, int* ce){

}
void imprimirVector(int *vec, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d\t", *vec);
        vec++;
    }
    printf("\n\n");
}
