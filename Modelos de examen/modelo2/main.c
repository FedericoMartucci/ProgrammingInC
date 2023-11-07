#include "model2.h"

int main()
{
//    int vec[] = {5, 7, 15, 2, 13};
//    showArray(vec, sizeof(vec)/sizeof(int));
//    _ordenarSeleccion(vec, sizeof(vec)/sizeof(int), sizeof(int), cmpInt);
//    printf("\n");
//    showArray(vec, sizeof(vec)/sizeof(int));
//    char cad1[] = "Hola a todata";
//    char cad2[] = "tas";
//    char* cad3 = _mstrstr(cad1, cad2);
//    printf("%s", cad3);
    int matrix[][MAX_COLUMN] =
    {
        {1, 2, 3, 4, 5, 6, 7},
        {1, 2, 3, 4, 5, 6, 7},
        {1, 2, 3, 4, 5, 1, 7},
        {1, 2, 3, 4, 5, 1, 1},
    };

    printf("Vivas: %d", _contarCelulasVivasEnVecindario(matrix, 4, 7, 0, 0));

    return 0;
}
