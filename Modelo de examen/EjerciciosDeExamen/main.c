#include "ejerciciosModelos.h"

int main()
{
    ///InsertOrderedGeneric
//    int vec[TAM] = {0,1,2,3,4,6,7,8,9};
//    int vec[TAM] = {9,8,7,6,4,3,2,1,0};
//    int vec[TAM] = {0,1,2,3,4,5,6,7,8,9};
//    int vec[TAM];
//    int vec[TAM] = {10};
//    int vec[TAM]= {1, 2, 3, 6, 7, 8, 9};
//    int numberOfElements = 1;
//    int x = 5;
//    insertOrdered(vec, &x, sizeof(int), sizeof(vec)/sizeof(int), &numberOfElements, cmpInt);
//    for(int i = 0; i < numberOfElements; i ++){
//        printf("%d ", vec[i]);
//    }
    ///Car's Domains
/*
    Se pide desarrollar un sistema que procese un archivo de texto con el dominio y las posiciones (latitud y longitud) de una flota de vehiculos.
    El sistema debera informar de la distancia recorrida por cada vehiculo. No se sabe que vehiculos seran pero se asegura que no son mas de 30.
    El archivo sera de texto con campo de tamaño fijo y el dominio del vehiculo puede contener espacios.
    10 lugares para el dominio, 7 para la latitud y 7 para la longitud. Los registros estan ordenados por fecha de ocurrencia (No por dominio).
    Ej
    AA 000 AA-33.557-54.554
*/
    FILE* file;

    if(openFile(&file, "test.txt", "rt") != 0)
        return -1;

    traverseFile(file, sizeof(tCar), showCar);


    fclose(file);
    return 0;
}
