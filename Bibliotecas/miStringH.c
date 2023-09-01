#include "miStringH.h"

/** \brief Calcula el número de caracteres de la cadena apuntada por "cadena".
 *
 * \param Tiene como entrada la direccion de la cadena que queremos saber su longitud.
 * \return La función retorna el número de caracteres hasta el carácter nulo, que no se incluye.
 *
 */
size_t miStrlen(const char *cadena){
    size_t contador = 0;
    while(*cadena){
        cadena++;
        contador++;
    }
    return contador;
}
/** \brief Copia la cadena apuntada por s2 (incluyendo el carácter nulo) a la cadena apuntada por s1.
 *
 * \param La entrada s1 es la cadena en la cual copiaremos la cadena de s2.
 * \param La entrada s2 es la cadena que copiaremos a s1
 * \return La función retorna el valor de s1. Si al copiar una cadena a la otra se superponen, entonces el comportamiento no está definido.
 *
 */

char* miStrcpy(char* s1, const char* s2){
    char* ini = s1;
    while(*s2){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return ini;
}

char* miStrcat(char* cadena1, const char* cadena2){
    char* ini = cadena1;

    while(*cadena1)
        cadena1++;
    while(*cadena2){
        *cadena1 = *cadena2;
        cadena1++;
        cadena2++;
    }
    *cadena1 = '\0';

    return ini;
}

char* miStrchr(char* cadena, int letra){
    while(*cadena){
        if(*cadena == letra){
            return cadena;
        }
        cadena++;
    }
    return NULL;
}

char* miStrrchr(char* cadena, int letra){
    char* ini = cadena;
    while(*cadena)
        cadena++; //cadena apunta a \0
    cadena--; //cadena apunta a la ultima letra
    while(ini < cadena){
        if(*cadena == letra)
            return cadena;
        cadena--;
    }
    return NULL;
}

char* miStrstr(const char* cadena1, const char* cadena2){
    const char* cadenaAux1;
    const char* cadenaAux2;
    while(*cadena1){
        cadenaAux1 = cadena1;
        cadenaAux2 = cadena2;
        while(*cadenaAux1 == *cadenaAux2){
            cadenaAux1++;
            cadenaAux2++;
        }
        if(!*cadenaAux2)
            return (char*)cadena1;
        cadena1++;
    }
    return NULL;
}
/** \brief Copia no más de n caracteres (caracteres posteriores al carácter nulo no son copiados)
            de la cadena apuntada por s2 a la cadena apuntada por s1.
 *
 * \param El parametro s1 tiene la direccion en donde se copiara la cadena.
 * \param El parametro s2 tiene la direccion de comienzo de la cadena que se copiara.
 * \param El parametro cantCaracteres indica la cantidad de caracteres a copiar de s2 a s1.
 * \return La función retorna el valor de s1. Si al copiar una cadena a la otra se superponen,
            entonces el comportamiento no está definido. Si el array/arreglo apuntado por s2 es una
            cadena que es más corta que n caracteres, entonces caracteres nulos son añadidos a la
            copia en el array apuntado por s1.
 *
 */

char* miStrncpy(char* s1, const char* s2, size_t cantCaracteres){
    char* ini = s1;
    size_t contador = 0;
    while(contador < cantCaracteres){
        if(*s2){
            *s1 = *s2;
            s2++;
        } else{
            *s1 = '\0';
        }
        s1++;
        contador++;
    }
    *s1 = '\0';
    return ini;
}
/** \brief Se lee una cadena y la funcion separara palabra por palabra y devolvera el tamaño de cada una
 *
 * \param El parametro cadena contiene la direccion de la direccion del comienzo de la cadena
 * \param El parametro palabra contendra la direccion de la direccion del comienzo de una palabra
 * \return La funcion retorna la longitud de cada palabra de la cadena.
 *
 */

size_t proximaPalabra(char** cadenaARecorrer, char** palabra){
    size_t tamPalabra = 0;

    /** Mientras que la cadena no haya termina y no apunte a una letra nos
        desplazaremos al siguiente caracter. */
    while(**cadenaARecorrer && !esLetra(**cadenaARecorrer))
        (*cadenaARecorrer)++;

    /** La variable palabra apunta a la direccion de la primera letrade la
        palabra. */
    *palabra = *cadenaARecorrer;

    /** Nos desplazaremos en la cadena hasta que apunte al proximo caracter que
        no sea una letra e incrementaremos la cant de caracteres de la palabra. */
    while(**cadenaARecorrer && esLetra(**cadenaARecorrer)){
        tamPalabra++;
        (*cadenaARecorrer)++;
    }

    /** En este momento la variable cadena apunta a la direccion donde termino
        la palabra, cantidadCaracteres contiene el largo de la palabra y la
        variable palabra apunta al inicio de la palabra leida. */
    return tamPalabra;
}

void verPalabra(char* cadena, char* palabra){
    int i;
    size_t tamPalabra;

    printf("\tCadena recorrida: %s\n\n",(char*)cadena);

    while(( tamPalabra = proximaPalabra(&cadena, &palabra))){
        printf("\t\tPalabra: ");
        for(i = 0; i < tamPalabra; i++){
            printf("%c",*palabra);
            palabra++;
        }
        printf("\t\tTamPalabra = %llu\n", tamPalabra);
    }
}

int esPalindromo(const char* cadena){
    const char* inicioCadena = cadena; // inicioCadena apunta al inicio de la cadena
    const char* finalCadena = cadena + miStrlen(cadena); //finalCadena apunta al \0
    while(inicioCadena < finalCadena){ //valida no irme de rango y recorrer lo minimo
        while(!esLetra(*inicioCadena)) //si tiene cualquier otro caracter que no sea una letra no lo cuenta
            inicioCadena++;
        while(!esLetra(*finalCadena)) //si tiene cualquier otro caracter que no sea una letra no lo cuenta
            finalCadena--;
        if(aMayus(*inicioCadena) != aMayus(*finalCadena)) //Si son distintos dejo de recorrer
                return 0;
        inicioCadena++;
        finalCadena--;
    }
    return 1;
}

