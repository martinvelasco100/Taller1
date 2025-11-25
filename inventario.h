#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX 10
#define MAX_NOMBRE 50

// Prototipos
void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int n);
float calcularTotal(float precios[], int n);
float calcularPromedio(float precios[], int n);
int indiceMasCaro(float precios[], int n);
int indiceMasBarato(float precios[], int n);
int buscarProducto(char nombres[][MAX_NOMBRE], int n, char buscado[]);

#endif
