#include "matematica.h"

int factorial(int num){
    int i;
    int resultado;
    resultado = 1;
    for(i = 2; i <= num && resultado < 2147483648; i++)
        resultado *= i;
    return resultado;
}

int combinatorioMSobreN(int m, int n){
    if(m < n || n < 0){
        printf("n es 0 o m es menor a n y no se puede calcular el combinatorio");
        return 0;
    }
    else
        return factorial(m)/(factorial(n)*factorial(m-n));
}

float exponencial(int exponente, float tol){
    int i;
    float acum;
    float resultado = 1 + tol;
    i = 0;
    acum = 0;
    while(resultado > tol){
        resultado = potencia(exponente, i)/factorial(i);
        acum += resultado;
        i++;
    }
    return acum;
}

float potencia(float base, int exponente){
    int i;
    float resultado;
    resultado = 1;
    for(i = 0; i < exponente && resultado < 2147483648; i++)
        resultado *= base;
    return resultado;
}

float raizCuadrada(float radicando, float tol){
    float resultado;
    float anterior = 1.0;
    float aux = 1 + tol;
    while( aux > tol){
        resultado = 0.5 * (anterior + radicando / anterior);
        if(anterior  != 1.0)
            aux = anterior - resultado;
        anterior = resultado;
    }
    return resultado;
}

int perteneceFibonacci(int num){
    int anterior = 1;
    int posterior = 0;
    while(num != posterior && num > posterior){
        posterior += anterior;
        if(posterior > 2)
            anterior = posterior - anterior;
    }
    if(num == posterior)
        return PERTENECE;
    else
        return NO_PERTENECE;
}
float seno(float argumento, float tol){
    int i = 1;
    float resultado = 0.0;
    float resultadoParcial;
    float resultadoParcialABS;
    while(resultadoParcialABS > tol || i == 1){
        if(i%2){
            resultadoParcial = potencia(argumento, 2*i-1)/factorial(2*i-1);
            resultadoParcialABS = resultadoParcial;
        }
        else{
            resultadoParcial =  (-1) * potencia(argumento, 2*i-1)/(float)factorial(2*i-1);
            resultadoParcialABS = (-1) * resultadoParcial;
        }
        resultado += resultadoParcial;
        i++;
    }
    return resultado;
}
int clasificarNumero(int numero){
    int divisor = 1;
    int resultado = 0;
    while(divisor < numero || divisor == 1){
        if(!(numero % divisor))
            resultado += divisor;
        divisor++;
    }
    if(resultado == numero)
        return PERFECTO;
    else if(resultado < numero)
        return DEFICIENTE;
    return ABUNDANTE;
}
int productoPorSumasSucesivas(int factor1, int factor2)
{
    int i;
    int resultado = 0;
    for(i = 0; i < MENOR(factor1, factor2); i++){
        resultado += MAYOR(factor1, factor2);
    }
    return resultado;
}
int sumaNaturales(int numero){
    int suma = 0;
    int i;
    for(i = 0; i <= numero; i++){
        suma += i;
    }
    return suma;
}
void cocienteYResto(int* vec, int divisor, int dividendo){
    *vec = divisor/dividendo;
    vec++;
    *vec = divisor%dividendo;
}
int sumaNaturalesPares(int numero){
    int numeroPar = 0;
    int suma = 0;
    int i;
    for(i = 1; i < numero; i++){
        numeroPar += 2;
        suma += numeroPar;
    }
    return suma;
}
int sumaParesMenores(int numero){
    int suma = 0;
    int i;
    for(i = 0; i < numero; i++){
        if(!(i % 2))
            suma += i;
    }
    return suma;
}

int esPrimo(int numero){
    int divisor = 2;
    while(divisor < numero){
        if(!(numero % divisor))
            return NO_PRIMO;
        divisor++;
    }
    return PRIMO;
}


