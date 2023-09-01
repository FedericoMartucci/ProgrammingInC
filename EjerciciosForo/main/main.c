#include "../../Bibliotecas/miStringH.h"
int main()
{
    char letra = 'o';
    char cadena[TAM] = "topicos de programacion";
    char cadena2[TAM] = "pi" ;
    char cadena3[TAM] = "Basura";
    char cadena4[TAM] = "Basura copiada";
    char cadena5[TAM] = "Nada";
    char cadena6[TAM] = "12";
    char cadenaRecorrida[] = "Hola mundo, recorro esta cadena con una funcion.";
    char* quedoParado = cadenaRecorrida;
    char* guardaPalabra;
    printf("STRLEN:\t%llu\n", miStrlen(cadena2));
    printf("STRCPY:\t%s\n", miStrcpy(cadena3, cadena4));
    printf("STRCAT:\t%s\n", miStrcat(cadena3,cadena4));
    printf("STRCHR: Direccion %p\tLetra: %c\n", miStrchr(cadena, letra), (!miStrchr(cadena, letra)? ' ':*(miStrchr(cadena, letra))));
    printf("STRRCHR: Direccion %p\tLetra: %c\n", miStrrchr(cadena, letra), (!miStrrchr(cadena, letra)? ' ':*(miStrrchr(cadena, letra))));
    printf("STRSTR: Direccion %p\tPalabra: %s\n", miStrstr(cadena, cadena2), (!miStrstr(cadena, cadena2)? "NULL":(miStrstr(cadena, cadena2))));
    printf("STRNCPY: Direccion %p\tPalabra: %s\n", miStrncpy(cadena5, cadena6, 2), (!miStrncpy(cadena5, cadena6, 2)? "NULL":miStrncpy(cadena5, cadena6, 2)));

    printf("\n\n\t\t\tFuncion Proxima Palabra\n\n");
    verPalabra(quedoParado, guardaPalabra);
    return 0;
}
