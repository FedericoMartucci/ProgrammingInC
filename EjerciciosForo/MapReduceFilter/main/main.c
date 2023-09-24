#include "../../../Bibliotecas/genericos.h"
int main()
{
    tEmpleado empleados[NUM_EMPLEADOS];
    tEmpleado filterEmployee = {1000, "Empleado Filtro", 'A', 1500.00};
    float resultado = 0;
    float sumaSueldos = 0;


    // Llenar los registros con datos ficticios
    for (int i = 0; i < NUM_EMPLEADOS; i++) {
        empleados[i].legajo = i + 1;  // Legajo incrementado por 1
        snprintf(empleados[i].nya, TAM, "Empleado %d", i + 1);  // Nombre y apellido ficticios
        if(i%2 == 0)
            empleados[i].categoria = 'A';  // Categoría ficticia
        else
            empleados[i].categoria = 'B';  // Categoría ficticia
        empleados[i].sueldo = 1000.0 + i * 100.0;  // Sueldo ficticio
    }
    fMap(empleados, sizeof(tEmpleado), sizeof(empleados)/sizeof(tEmpleado), mostrarEmpleados);
//    fMap(empleados, sizeof(tEmpleado), sizeof(empleados)/sizeof(tEmpleado), duplicarSueldosEmpleadosCatA);
//    fMap(empleados, sizeof(tEmpleado), sizeof(empleados)/sizeof(tEmpleado), mostrarEmpleados);

    printf("\n\n");

    filter(empleados, &filterEmployee, sizeof(tEmpleado), sizeof(empleados)/sizeof(tEmpleado), compararPorCategoriaYSueldo, mostrarEmpleadosFilter);

    printf("\n\n");
//    void reduce(const void* vec, size_t cantBytes, void* resultado, size_t cantBytesResultado, size_t ce, void(*accion)(const void*, void*, size_t));
    reduce(empleados, sizeof(tEmpleado), &resultado, sizeof(resultado), sizeof(empleados)/sizeof(tEmpleado), calculaPromedioDeSueldos);
    reduce(empleados, sizeof(tEmpleado), &sumaSueldos, sizeof(sumaSueldos), sizeof(empleados)/sizeof(tEmpleado), calculaSumaDeSueldos);
    printf("%.2f\n", resultado);
    printf("%.2f", sumaSueldos);
    return 0;
}
