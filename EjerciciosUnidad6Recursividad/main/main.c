#include "../../Bibliotecas/recursividad.h"

int main()
{
//    int i;
//    int suma;
//    char letra = 'a';
//    char cadena[] = "123";
//    char cadena2[] = "Gracias";
//    char cadena3[] = "Hola mundo!";
    char cadena4[] = "__aa_ArribA__lA____\t_b2IrRaaA____";
//    int vec[TAM] = {1, 2, 3, 4, 5};

//    for(i = 0; i < 5; i++)
//        printf("Factorial de %d: %llu\n", i, rFactorial(i));
//    mostrarContenidoArray(cadena);
//    printf("\n");
//    mostrarContenidoArrayInverso(cadena);
//    printf("\n");
//    mostrarContenidoArrayInversoYSumaNumeros(cadena, &suma);
//    contenidoArrayYSuma(vec, &suma, TAM);
//    printf("\nLa suma da: %d\n\n", suma);
//    contenidoArrayYSumaPares(vec, &suma, TAM);
//    printf("\nLa suma da: %d\n\n", suma);
//    contenidoArrayYSumaPosPares(vec, &suma, TAM);
//    printf("\nLa suma da: %d\n\n", suma);
//    printf("Longitud cadena: %llu\n\n", rStrlen(cadena));
//    printf("Posicion de la %c: %llu\n", letra, rStrchr(cadena2, letra) - cadena2);
//    printf("Posicion de la %c: %llu\n", letra, rStrrchr(cadena2, letra) - cadena2);
//    printf("Cadena sin copiar: %s\n", cadena3);
//    printf("Cadena copiada: %s\n", rStrcpy(cadena3, cadena2));
    printf("Es palindromo recursivo: %d", esPalindromo(cadena4));

    return 0;
}
