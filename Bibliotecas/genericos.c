#include "genericos.h"

int cargarElementos(size_t ce){
    int i;
    void* vec;
    void* iniVec;

    if(ce < 1)
        return 0;

    vec = malloc(sizeof(int) * ce);
    iniVec = vec;

    if(!vec)
        return 0;

    for(i = 0; i < ce; i++){
        *(int*)vec = i + 1;
        vec += sizeof(int);
    }
    vec = iniVec;

    recorrerVector(vec, sizeof(int), ce);

    free(vec);
    return 1;
}

void recorrerVector(void* vec, size_t tam, size_t ce){
    int i;

    for(i = 0; i < ce; i++){
        printf("%d ", *(int*)vec);
        vec += sizeof(int);
    }
}

int cargarElementosGen(const void* vecACargar, size_t cantBytes, size_t ce, void(*mostrar)(const void*))
{
    int i;
    void* vec;
    void* iniVec;

    if(ce < 1)
        return 0;

    vec = malloc(cantBytes * ce);
    iniVec = vec;

    if(!vec)
        return 0;

    miMemmove(vec, vecACargar, cantBytes * ce);

    for(i = 0; i < ce; i++){
        mostrar((const void*)vec);
        vec += cantBytes;
    }
    vec = iniVec;

    free(vec);
    return 1;
}

void mostrarEmpleado(const void* vec)
{
    printf("\n\nLegajo: %d\n", ((tEmpleado*)vec)->legajo);
    printf("Nya: %s\n", ((tEmpleado*)vec)->nya);
    printf("Categoria: %c\n", ((tEmpleado*)vec)->categoria);
    printf("Sueldo: %.2f", ((tEmpleado*)vec)->sueldo);
}
void mostrarChar(const void* vec)
{
    printf("\n\nLetra: %c\n", *(char*)vec);
}
void mostrarInt(const void* vec)
{
    printf("\n\nNumero: %d\n", *(int*)vec);
}

void mostrarPersona(const void* vec)
{
    printf("\n\nNya: %s\n", ((tPersona*)vec)->nya);
    printf("DNI: %u\n", ((tPersona*)vec)->dni);
    printf("Edad: %d\n", ((tPersona*)vec)->edad);
}
char* copiaCadena(const char* origen)
{
    int i;
    char* cadena = malloc(strlen(origen) + 1);
    char* iniCadena;
    unsigned tamOrigen = strlen(origen);

    if(!cadena)
        return NULL;

    iniCadena = cadena;
    for(i = 0; i < tamOrigen + 1; i++){
        *cadena = *origen;
        cadena++;
        origen++;
    }

    return iniCadena;

}
void* copiaCosas(void* elemento, unsigned tam)
{
    int i;
    void* copiaElemento = malloc(tam);
    void* iniCopiaElemento;

    if(!copiaElemento)
        return NULL;

    iniCopiaElemento = copiaElemento;
    for(i = 0; i < tam; i++){
        *(char*)copiaElemento = *(char*)elemento;
        copiaElemento++;
        elemento++;
    }

    return iniCopiaElemento;
}

void* miMemmove(void* s1, const void* s2, size_t n){
    int i;
    void* vec = malloc(n);
    void* iniVec;
    void* iniS1 = s1;

    if(!vec)
        return NULL;

    iniVec = vec;

    for(i = 0; i < n; i++){
        *(char*)vec = *(char*)s2;
        s2++;
        vec++;
    }
    vec = iniVec;

    for(i = 0; i < n; i++){
        *(char*)s1 = *(char*)vec;
        s1++;
        vec++;
    }
    s1 = iniS1;
    free(iniVec);

    return s1;
}
void fMap(void* vec, size_t cantBytes, size_t ce, void(*accion)(void*))
{
    int i;

    if(ce < 1)
        return;

    for(i = 0; i < ce; i++)
    {
        accion(vec);
        vec += cantBytes;
    }
}
void duplicarYMostrarVectorEntero(void* vec){
    *(int*)vec *= 2;
    printf("%d ", *(int*)vec);
}
void mostrarEmpleados(void* vec){
    printf("Legajo: %d, Nombre y Apellido: %s, Categoría: %c, Sueldo: %.2f\n",
               ((tEmpleado*)vec)->legajo,((tEmpleado*)vec)->nya, ((tEmpleado*)vec)->categoria, ((tEmpleado*)vec)->sueldo);
}
void duplicarSueldosEmpleadosCatA(void* vec){
    if(((tEmpleado*)vec)->categoria == 'A')
        ((tEmpleado*)vec)->sueldo *= 2;
}

///TODO preguntar si filtramos guardando en una nueva variable o solamente mostramos los elementos
void filter(const void* vec, const void* filtro, size_t cantBytes, size_t ce, int(*comparar)(const void*, const void*), void(*mostrar)(const void*)){
    int i;

    if(ce < 1)
        return;

    for(i = 0; i < ce; i++)
    {
        if(!comparar(vec, filtro))
            mostrar(vec);
        vec += cantBytes;
    }
}
///TODO preguntar si esta bien la comparacion o debe ser retornando 0, 1 o -1
int compararPorCategoriaYSueldo(const void* vec, const void* filtro){
    if(((tEmpleado*)vec)->categoria == ((tEmpleado*)filtro)->categoria &&
       ((tEmpleado*)vec)->sueldo > ((tEmpleado*)filtro)->sueldo)
        return 0;
    return 1;
}

void mostrarEmpleadosFilter(const void* vec){
    printf("Legajo: %d, Nombre y Apellido: %s, Categoría: %c, Sueldo: %.2f\n",
               ((tEmpleado*)vec)->legajo,((tEmpleado*)vec)->nya, ((tEmpleado*)vec)->categoria, ((tEmpleado*)vec)->sueldo);
}


void reduce(const void* vec, size_t cantBytes, void* resultado, size_t cantBytesResultado, size_t ce, void(*accion)(const void*, void*, size_t)){
    int i;

    if(ce < 1)
        return;

    for(i = 1; i <= ce; i++)
    {
        accion(vec, resultado, i);
        vec += cantBytes;
    }
}

void calculaPromedioDeSueldos(const void* vec, void* resultado, size_t iteracion){
    *(float*)resultado *= iteracion - 1;
    *(float*)resultado += ((tEmpleado*)vec)->sueldo;
    *(float*)resultado /= iteracion;
}

void calculaSumaDeSueldos(const void* vec, void* resultado, size_t iteracion){

    *(float*)resultado += ((tEmpleado*)vec)->sueldo;

}

