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
    for(i = 0; i < tamVec; i++)
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
    int* escrituraVec = vec;
    int* finVec = vec + tamVec-1;
    while(vec < finVec){
        if(*vec == elemento){
            while(*vec == elemento && vec <= finVec){
                vec++;
                (*ce)--;
            }
            *escrituraVec = *vec;
            escrituraVec++;
        }else if (vec < finVec){
            escrituraVec++;
            vec++;
        }
    }
}
int esPalindromo(const char *cadena){
    const char *inicio;
    const char *fin;

    inicio = cadena;
    fin = cadena;

    while(!*fin)
        fin++;
    fin--;
    while(inicio < fin){
        if(*inicio != *fin)
            return 0;
        inicio++;
        fin--;
    }
    return 1;
}

void buscaFin(char* cad){
    while(*cad != '\0' && *cad != '\t')
        cad++;
    cad--;
}
void imprimirVector(int *vec, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d\t", *vec);
        vec++;
    }
    printf("\n\n");
}
