#include "arrays.h"

void insertarElemento(int posicion, int* vec, int elemento, int tamVec, int* ce){
    int i;
    for(i = 0; i < posicion; i++)
        vec++;
    *vec = elemento;
    if(*ce < tamVec)
        (*ce)++;
}
void insertarElementoOrdenado(int* vec, int elemento, int tamVec, int* ce){
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
void eliminarElemento(int* vec, int posicion, int tamVec, int* ce){
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
    const char *inicioCadena;
    const char *finCadena;

    inicioCadena = cadena;
    finCadena = cadena + miStrlen(cadena);
    while(inicioCadena < finCadena){
        while(!esLetra(*inicioCadena))
            inicioCadena++;
        while(!esLetra(*finCadena))
            finCadena--;
        if(aMayus(*inicioCadena) != aMayus(*finCadena))
            return 0;
        inicioCadena++;
        finCadena--;
    }
    return 1;
}
int miStrlen(const char* cadena){
    int cantidadCaracteres = 0;
    while(*cadena){
        cantidadCaracteres++;
        cadena++;
    }
    return cantidadCaracteres;
}
int valorNumericoCadena(const char* cadena){
    int sumaCadena = 0;
    while(*cadena){
        sumaCadena += *cadena;
        cadena++;
    }
    return sumaCadena;

}
int aparicionesDeUnaPalabra(const char* cadena, const char* palabra){
    int cantidadApariciones;
    const char* cadenaAux;
    const char* palabraAux;

    cantidadApariciones = 0;

    while(*cadena){
        cadenaAux = cadena;
        palabraAux = palabra;

        while(aMayus(*cadenaAux) == aMayus(*palabraAux)){
            cadenaAux++;
            palabraAux++;
        }
        if(!*palabraAux)
            cantidadApariciones++;
        cadena++;
    }
    return cantidadApariciones;
}
void normalizarCadena(char* cadena){
    char* leeCadena;
    char* escribeCadena;
    int iniciaPalabra;

    leeCadena = cadena;
    escribeCadena = cadena;

    while(*leeCadena){
        iniciaPalabra = 1;
        while(esBlanco(*leeCadena) && *leeCadena)
            leeCadena++;
        while(esLetra(*leeCadena) && *leeCadena){
            if(iniciaPalabra){
                *escribeCadena = aMayus(*leeCadena);
                iniciaPalabra = 0;
            }else
                *escribeCadena = aMinus(*leeCadena);
            leeCadena++;
            escribeCadena++;
        }
        while(esBlanco(*leeCadena) && *leeCadena)
            leeCadena++;
        while(*leeCadena && !esLetra(*leeCadena) && !esBlanco(*leeCadena)){
            *escribeCadena = *leeCadena;
            escribeCadena++;
            leeCadena++;
        }
        while(esBlanco(*leeCadena) && *leeCadena)
            leeCadena++;
        if(*leeCadena && esLetra(*leeCadena)){
            *escribeCadena = ' ';
            escribeCadena++;
        }
    }
    *escribeCadena = '\0';
}
size_t rStrlen(const char* cadena){
//    if(!*cadena)
//        return 0;
//    return rStrchr(++cadena)+1;
    return ((*cadena)=='\0'? 0:rStrlen(++cadena)+1);
}
char* rStrchr(char* cadena, int caracterBuscado){
//    if(!*cadena)
//        return NULL;
//    if(*cadena == caracterBuscado)
//        return cadena;
//    return rStrchr(cadena+1, caracterBuscado);
    return ((*cadena == '\0')? NULL:((*cadena == caracterBuscado)? cadena:rStrchr(++cadena, caracterBuscado)));
}
void desofuscar(char* cadena){
    char caracteres[] = "abcdghijkoqtuv";
    int pos;
    int suma;

    pos = 1;
    while(*cadena){
        suma = pos;
        if(rStrchr(caracteres, *cadena)){
            while((suma + (rStrchr(caracteres, *cadena) - caracteres)) >= rStrlen(caracteres))
                suma -= rStrlen(caracteres);
            *cadena = *(caracteres + suma + (rStrchr(caracteres, *cadena) - caracteres));
        }
        if(esBlanco(*cadena))
            pos = 0;
        pos++;
        cadena++;
    }
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
char* miStrcpy(char* s1, const char* s2){
    while(*s2){
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return s1;
}
int miStrcmp(const char* cadena1, const char* cadena2){
    return valorNumericoCadena(cadena1) - valorNumericoCadena(cadena2);
}
int miStrcmpi(const char* cadena1, const char* cadena2){
    while(*cadena1 && *cadena2){
        if(aMayus(*cadena1) - aMayus(*cadena2) < 0)
            return -1;
        if(aMayus(*cadena1) - aMayus(*cadena2) > 0)
            return 1;
        cadena1++;
        cadena2++;
    }
    if(!*cadena1 && *cadena2)
        return -1;
    if(!*cadena2 && *cadena1)
        return 1;
    return 0;
}
void compararCadenas(){
    char charArray[1024][1024];
    char cadena1[1024];
    char cadena2[1024];
    int comparacion;
    int i;
    int contador;

    contador = 0;

    do{
        printf("Ingrese la cadena 1: ");
        fflush(stdin);
        scanf("%s",cadena1);
        printf("Ingrese la cadena 2: ");
        fflush(stdin);
        scanf("%s",cadena2);
        comparacion = miStrcmp(cadena1, cadena2);
        if(comparacion != 0){
            if(comparacion < 0){
                miStrcpy(charArray[contador], cadena1);
                miStrcpy(charArray[contador+1], cadena2);
            }
            else{
                miStrcpy(charArray[contador], cadena2);
                miStrcpy(charArray[contador+1], cadena1);
            }
            contador += 2;
        }
    }while(comparacion != 0);
    for (i = 0; i < contador; i++) {
        printf("Cadena %d: %s\n", i + 1, charArray[i]);
    }
}
float sumatoriaEncimaDiagPrincipal(const float* matriz){
    float suma;
    int columna;
    int fila;

    suma = 0;

    for(fila = 0; fila < ORDEN-1; fila++){
        for(columna = fila + 1; columna < ORDEN; columna++){
            suma += *(matriz + fila * ORDEN + columna);
        }
    }

    return suma;
}
float sumatoriaEncimaDiagSecundaria(const float* matriz){
    float suma;
    int columna;
    int fila;

    suma = 0;

    for(fila = 0; fila < ORDEN - 1; fila++){
        for(columna = 0; columna < ORDEN - fila - 1; columna++){
            suma += *(matriz + fila * ORDEN + columna);
        }
    }

    return suma;
}
float sumatoriaEncimaDiagPrincipal2(const float* matriz){
    float suma;
    int columna;
    int fila;

    suma = 0;

    for(fila = 0; fila < ORDEN; fila++){
        for(columna = fila; columna < ORDEN; columna++){
            suma += *(matriz + fila * ORDEN + columna);
        }
    }

    return suma;
}
float sumatoriaDebajoDiagPrincipal(const float* matriz){
    float suma;
    int columna;
    int fila;

    suma = 0;

    for(columna = 0; columna < ORDEN-1; columna++){
        for(fila = columna + 1; fila < ORDEN; fila++){
            suma += *(matriz + fila * ORDEN + columna);
        }
    }

    return suma;
}
int trazaDiagonalPrincipal(const int* matriz){
    int suma;
    int columna;
    int fila;

    suma = 0;

    for(fila = 0; fila < ORDEN; fila++){
        columna = fila;
        suma += *(matriz + fila * ORDEN + columna);
    }

    return suma;
}
int trazaDiagonalSecundaria(const int* matriz){
    int suma;
    int columna;
    int fila;

    suma = 0;

    for(fila = 0; fila < ORDEN; fila++){
        columna = ORDEN - fila - 1;
        suma += *(matriz + fila * ORDEN + columna);
    }

    return suma;
}
int esMatrizDiagonal(const int* matriz){
//    if(sumatoriaDebajoDiagPrincipal((float*)matriz) +
//       sumatoriaEncimaDiagPrincipal((float*)matriz))
//        return 0;
//    return 1;
    return (sumatoriaDebajoDiagPrincipal((float*)matriz) + sumatoriaEncimaDiagPrincipal((float*)matriz))? 0:1;
}
int esMatrizIdentidad(const int* matriz){
    int columna;
    int fila;

    for(fila = 0; fila < ORDEN; fila++){
        columna = fila;
        if(*(matriz + fila * ORDEN + columna) != 1)
            return 0;
    }
    if(sumatoriaDebajoDiagPrincipal((float*)matriz) +
       sumatoriaEncimaDiagPrincipal((float*)matriz))
        return 0;
    return 1;
//    return (sumatoriaDebajoDiagPrincipal((float*)matriz) + sumatoriaEncimaDiagPrincipal((float*)matriz))? 0:1;
}
int esMatrizSimetrica(const int* matriz){
    int columna;
    int fila;

    for(fila = 0; fila < ORDEN - 1; fila++){
        for(columna = fila + 1; columna < ORDEN; columna++){
            if(*(matriz + fila * ORDEN + columna) != *(matriz + columna * ORDEN + fila))
                return 0;
        }
    }

    return 1;
}
void mostrarMatriz(int* matriz, int cf, int cc){
    int fila;
    int columna;

    printf("\nMatriz:\nfilas = %d, columnas = %d\n",cf,cc);

    for(fila = 0; fila < cf; fila++)
    {
        for(columna = 0; columna < cc; columna++ )
        {
            printf("%d\t", *(matriz+fila*cc+columna));//%05.2f\t
        }
        printf("\n");
    }
    printf("\n");

}
void transponerMatrizInSitu(int* matriz){
    int columna;
    int fila;
    int aux;

    for(fila = 0; fila < ORDEN - 1; fila++)
        for(columna = fila + 1; columna < ORDEN; columna++){
            aux = *(matriz + fila * ORDEN + columna);
            *(matriz + fila * ORDEN + columna) = *(matriz + columna * ORDEN + fila);
            *(matriz + columna * ORDEN + fila) = aux;
        }
}
void transponerMatriz(const int* matriz, int filas, int columnas){
    int columna;
    int fila;
    int matrizTranspuesta[columnas][filas];

    for(fila = 0; fila < columnas; fila++)
        for(columna = 0; columna < filas; columna++){
            matrizTranspuesta[fila][columna] = *(matriz + columna * columnas + fila);
        }

    mostrarMatriz((int*)matrizTranspuesta, columnas, filas);
}
void productoMatrices(const int* matriz, const int* matriz2, int filas1, int columnas1, int filas2, int columnas2){
    int fila;
    int filaAux;
    int columna;
    int suma;
    int matrizProducto[filas1][columnas2];

    suma = 0;

    if(columnas1 != filas2){
        puts("No se puede realizar la multiplicacion.\n");
        return;
    }

    for(fila = 0; fila < filas1; fila++)
        for(columna = 0; columna < columnas2; columna++){
            suma = 0;
            for(filaAux = 0; filaAux < filas2; filaAux++)
                suma += (*(matriz + fila * filas2 + filaAux)) * (*(matriz2 + filaAux * columnas2 + columna));
            matrizProducto[fila][columna] = suma;
        }

    mostrarMatriz((int*)matrizProducto, filas1, columnas2);
}
int verificarMatriz(int* matriz){
    int fila;
    int columna;

    for(fila = 0; fila < ORDEN; fila++)
        for(columna = fila; columna < ORDEN; columna++){
            if((columna == fila && (*(matriz + fila * ORDEN + columna) != 0)) ||
               *(matriz + fila * ORDEN + columna) < 0 ||
               *(matriz + columna * ORDEN + fila) < 0)
                return 0;
            else if(columna != fila &&
                    *(matriz + fila * ORDEN + columna) == *(matriz + columna * ORDEN + fila) &&
                    *(matriz + fila * ORDEN + columna) != 1)
                return 0;
            else if(columna != fila &&
                    (*(matriz + fila * ORDEN + columna) == 0 || *(matriz + fila * ORDEN + columna) == 3) &&
                    (*(matriz + fila * ORDEN + columna)) != (3 - (*(matriz + columna * ORDEN + fila))))
                return 0;

        }
    return 1;
}
void puntosPorEquipo(int* matriz){
    int fila;
    int columna;
    int vectorPuntos[ORDEN] = {0};

    for(fila = 0; fila < ORDEN - 1; fila++)
        for(columna = fila + 1; columna < ORDEN; columna++){
            if(*(matriz + fila * ORDEN + columna) == 3)
                *(vectorPuntos + fila) += 3;
            else if(*(matriz + fila * ORDEN + columna) == 0)
                *(vectorPuntos + columna) += 3;
            else{
                *(vectorPuntos + fila) += 1;
                *(vectorPuntos + columna) += 1;
            }
        }

    for(fila = 0; fila < ORDEN; fila++)
        printf("Equipo %d: %d\n", fila + 1, vectorPuntos[fila]);

}
