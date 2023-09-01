#include "../../Bibliotecas/miStringH.h"

int main()
{
    char cadena[TAM] = "oso oso";
    char cadena2[TAM] = " oso oso";
    char cadena3[TAM] = " oso  oso ";
    char cadena4[TAM] = "anita lavA la tina ";
    char cadena5[TAM] = "neuQuEn";
    int i;
    if(esPalindromo(cadena5))
        printf("Es palindromo");
    else
        printf("No es palindromo");
    return 0;
}
