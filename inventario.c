#include <stdio.h>
#include <string.h>
#include "inventario.h"

void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese nombre del producto %d: ", i + 1);
        fflush(stdin);
        fgets(nombres[i], MAX_NOMBRE, stdin);

        // Eliminar salto de línea
        nombres[i][strcspn(nombres[i], "\n")] = '\0';

        printf("Ingrese precio: ");
        scanf("%f", &precios[i]);
        getchar(); // limpiar buffer
    }
}

float calcularTotal(float precios[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += precios[i];
    return total;
}

float calcularPromedio(float precios[], int n) {
    if (n == 0) return 0;
    return calcularTotal(precios, n) / n;
}

int indiceMasCaro(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] > precios[indice])
            indice = i;
    return indice;
}

int indiceMasBarato(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++)
        if (precios[i] < precios[indice])
            indice = i;
    return indice;
}

int buscarProducto(char nombres[][MAX_NOMBRE], int n, char buscado[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], buscado) == 0)
            return i;
    }
    return -1;
}
