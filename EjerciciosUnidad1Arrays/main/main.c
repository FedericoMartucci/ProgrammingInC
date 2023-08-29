#include "../../Bibliotecas/arrays.h"

int main()
{
    int tam = 7;
    int vec[7] = {1, 5, 9, 25, 25};
    int ce = 5;
    imprimirVector(vec, ce);
    // ---------------- EJERCICIO 1 ----------------
    insertarElemento(5, vec, 544, tam, &ce);
    imprimirVector(vec, ce);
    // ---------------- EJERCICIO 2 ----------------
    insertarElementoOrdenado(vec, 19, tam, &ce);
    imprimirVector(vec, ce);
    // ---------------- EJERCICIO 3 ----------------
    eliminarElemento(vec, 2, tam, &ce);
    imprimirVector(vec, ce);
    // ---------------- EJERCICIO 4 ----------------
    eliminarPrimeraAparicionElemento(vec, 25, tam, &ce);
    imprimirVector(vec, ce);
    // ---------------- EJERCICIO 5 ----------------
    insertarElementoOrdenado(vec, 25, tam, &ce);
    insertarElementoOrdenado(vec, 25, tam, &ce);
    insertarElementoOrdenado(vec, 25, tam, &ce);
    insertarElementoOrdenado(vec, 25, tam, &ce);
    eliminarAparicionesElemento(vec, 25, tam, &ce);
    imprimirVector(vec, ce);
    return 0;
}
