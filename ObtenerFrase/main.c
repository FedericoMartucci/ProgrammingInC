#include "examen.h"

int main()
{
    ///Exercise 1
/*
    Obtenga de la funcion "obtenerFrase" una frase distinta en cada invocacion. La funcion retorna
    NULL cuando ya no tiene frases. Muestre por pantalla las 5 frases mas largas del total otorgado por
    la funcion. Se asegura que ninguna frase supera los 1024 caracteres.


    NOTA:
    1.No asuma que existe una cantidad de frases, pueden ser menos, igual a 5 o cientos de miles
    las devueltas por la funcion, solo muestre las 5 mas largas. Piense que en un sistema real la informacion
    obtenida (en este caso simulada por la funcion) puede ser enorme y no existir capacidad de almacenamiento.
    Piense la solucion en esos terminos. Se valora posivamente la genericidad en partes de la solucion.

    2.El programa corre unicamente sobre compilador MINGW 64 bits, configure su entorno para poder correrlo.
*/

//    char largestQuotes[TOP_FIVE][MAX_LINE] = {{""}};
//
//    getLargestQuotes(largestQuotes, TOP_FIVE);
//    showLargestQuotes(largestQuotes, TOP_FIVE);


    ///Exercise 2
/*
    Obtenga de la funcion "obtenerFrase" una frase distinta en cada invocacion.
    La funcion retorna NULL cuando ya no tiene frases. Se asegura que ninguna frase supera los 1024 caracteres.
    Cuente las iniciales de cada palabra y muestre las 5 iniciales más utilizadas en todas las frases

    NOTA:
    1.  No asuma que existe una cantidad de frases, pueden ser una o cientos de miles las devueltas por la funcion.
        Piense que en un sistema real la informacion obtenida (en este caso simulada por la funcion) puede ser
        enorme y no existir capacidad de almacenamiento. Piense la solucion en esos terminos. Se valora posivamente
        la genericidad en partes de la solucion y la correcta utilizacion de punteros.

    2.  El programa corre unicamente sobre compilador MINGW 64 bits, configure su entorno para poder correrlo.

    3.  Cada frase solo puede ser recorrida una sola vez

*/
    tInitial mostUsedInitials[TOP_FIVE];

    getMostUsedInitials(mostUsedInitials, TOP_FIVE);
    showMostUsedInitials(mostUsedInitials, TOP_FIVE);

    return 0;
}
