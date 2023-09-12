#include "recursividad.h"

unsigned long long rFactorial(int numero){
//    if(numero == 0)
//        return 1;
//    return numero * rFactorial(numero - 1);
    return numero == 0 ? 1 : numero * rFactorial(numero - 1);
}

void mostrarContenidoArray(const char* vec){
    if(*vec != '\0'){
        printf("%c ", *vec);
        mostrarContenidoArray(++vec);
    }
}

void mostrarContenidoArrayInverso(const char* vec){
    if(*vec != '\0'){
        mostrarContenidoArrayInverso(vec + 1);
        printf("%c ", *(vec));
    }
}

void mostrarContenidoArrayInversoYSumaNumeros(const char* vec, int* suma){
    *suma = 0;

    if(*vec != '\0'){
        mostrarContenidoArrayInversoYSumaNumeros(++vec, suma);
        printf("%c ", *(--vec));
        *suma += ES_NUMERO(*vec) ? A_NUMERO(*vec) : (0);
    }
}

void contenidoArrayYSuma(const int* vec, int* suma, int tamVec){
    *suma = 0;
    if(tamVec != 0){
        contenidoArrayYSuma(++vec, suma, --tamVec);
        printf("%d ", *(--vec));
        *suma += *vec;
    }
}

void contenidoArrayYSumaPares(const int* vec, int* suma, int tamVec){
    *suma = 0;
    if(tamVec != 0){
        contenidoArrayYSumaPares(++vec, suma, --tamVec);
        printf("%d ", *(--vec));
        *suma += (ES_PAR(*vec)? *vec : 0);
    }
}

void contenidoArrayYSumaPosPares(const int* vec, int* suma, int tamVec){
    *suma = 0;
    if(tamVec != 0){
        contenidoArrayYSumaPosPares(++vec, suma, --tamVec);
        printf("%d ", *(--vec));
        *suma += ES_PAR(tamVec)? *vec : 0;
    }
}

size_t rStrlen(const char* cadena){
    return *cadena? rStrlen(cadena+1) + 1 : 0;
}

char* rStrchr(char* cadena, int caracterBuscado){
    if(*cadena == '\0')
        return NULL;
    if(*cadena == caracterBuscado)
        return cadena;
    return rStrchr(cadena + 1, caracterBuscado);
}

char* rStrrchr(char* cadena, int caracterBuscado){
    char* direccionCaracter;
    if(*cadena != '\0')
        direccionCaracter = rStrrchr(cadena + 1, caracterBuscado);
    else
        return NULL;
    if(*cadena == caracterBuscado && (direccionCaracter == NULL || *direccionCaracter != caracterBuscado))
        return cadena;
    return direccionCaracter;
}

char* rStrcpy(char* cadena, const char* cadenaACopiar){
    if(*cadenaACopiar != '\0'){
        *cadena = *cadenaACopiar;
        rStrcpy(cadena + 1, cadenaACopiar + 1);
    }
    if(*cadenaACopiar == '\0')
        *cadena = '\0';
//    *(cadena + rStrlen(cadenaACopiar)) = '\0';
    return cadena;
}

int esPalindromo(const char *cadena){
    const char *inicioCadena;
    const char *finCadena;

    inicioCadena = cadena;
    finCadena = cadena + rStrlen(cadena);
    return rEsPalindromo(cadena, inicioCadena, finCadena);
}
int rEsPalindromo(const char* cadena, const char *inicioCadena, const char *finCadena){
    if(inicioCadena < finCadena){
        if(!ES_LETRA(*inicioCadena))
            return rEsPalindromo(cadena, inicioCadena + 1, finCadena);
        if(!ES_LETRA(*finCadena))
            return rEsPalindromo(cadena, inicioCadena, finCadena - 1);
//        printf("%c - %c\n", A_MAYUS(*inicioCadena), A_MAYUS(*finCadena)); Muestra lo que se compara
        if(A_MAYUS(*inicioCadena) != A_MAYUS(*finCadena))
            return 0;
        return rEsPalindromo(cadena, inicioCadena + 1, finCadena - 1);
    }
    else
        return 1;
}

