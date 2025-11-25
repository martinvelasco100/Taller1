#include <stdio.h>
#include <string.h>
#include "inventario.h"

int main() {
    char nombres[MAX][MAX_NOMBRE];
    float precios[MAX];
    int n, opcion;

    printf("Ingrese cantidad de productos (max 10): ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > MAX) {
        printf("Cantidad invalida.\n");
        return 1;
    }

    ingresarDatos(nombres, precios, n);

    do {
        printf("\n=== MENU ===\n");
        printf("1. Precio total del inventario\n");
        printf("2. Precio promedio\n");
        printf("3. Producto mas caro\n");
        printf("4. Producto mas barato\n");
        printf("5. Buscar producto\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 1) {
            printf("Total del inventario: %.2f\n", calcularTotal(precios, n));
        } 
        else if (opcion == 2) {
            printf("Precio promedio: %.2f\n", calcularPromedio(precios, n));
        } 
        else if (opcion == 3) {
            int idx = indiceMasCaro(precios, n);
            printf("Producto mas caro: %s (%.2f)\n", nombres[idx], precios[idx]);
        } 
        else if (opcion == 4) {
            int idx = indiceMasBarato(precios, n);
            printf("Producto mas barato: %s (%.2f)\n", nombres[idx], precios[idx]);
        } 
        else if (opcion == 5) {
            char buscado[MAX_NOMBRE];
            printf("Ingrese nombre a buscar: ");
            fgets(buscado, MAX_NOMBRE, stdin);
            buscado[strcspn(buscado, "\n")] = '\0';

            int idx = buscarProducto(nombres, n, buscado);
            if (idx == -1)
                printf("Producto no encontrado.\n");
            else
                printf("Producto encontrado: %s (%.2f)\n", nombres[idx], precios[idx]);
        }

    } while (opcion != 6);

    return 0;
}
