/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
float totalSale(float sales[], int n);
float maxSale(float sales[], int n);

int main() {
    FILE *file;
    int count = 0;
    float value;

    // Abrir archivo con el nombre correcto
    file = fopen("sales (1).txt", "r");
    if (file == NULL) {
        printf("Error: no se pudo abrir sales(1).txt\n");
        return 1;
    }

    // Contar número de líneas (ventas)
    while (fscanf(file, "%f", &value) == 1) {
        count++;
    }

    if (count == 0) {
        printf("El archivo está vacío.\n");
        fclose(file);
        return 1;
    }

    // Asignar memoria dinámica para el arreglo de ventas
    float *sales = (float*)malloc(count * sizeof(float));
    if (sales == NULL) {
        printf("Error al asignar memoria.\n");
        fclose(file);
        return 1;
    }

    // Regresar al inicio del archivo para leer los valores
    rewind(file);

    // Leer valores en el arreglo
    for (int i = 0; i < count; i++) {
        fscanf(file, "%f", &sales[i]);
    }

    fclose(file); // Cerrar archivo

    // Calcular resultados usando funciones
    float total = totalSale(sales, count);
    float maximo = maxSale(sales, count);

    // Imprimir resultados
    printf("Número de ventas: %d\n", count);
    printf("Total de ventas: %.2f\n", total);
    printf("Venta máxima: %.2f\n", maximo);

    // Liberar memoria
    free(sales);

    return 0;
}

// Función para sumar todas las ventas
float totalSale(float sales[], int n) {
    float suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += sales[i];
    }
    return suma;
}

// Función para encontrar la venta máxima
float maxSale(float sales[], int n) {
    float max = sales[0];
    for (int i = 1; i < n; i++) {
        if (sales[i] > max) {
            max = sales[i];
        }
    }
    return max;
}
