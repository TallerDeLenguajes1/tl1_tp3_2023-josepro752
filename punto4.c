#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

void cargar(struct Producto *arreglo, int cant);
int costoTotal(struct Producto *arreglo);
int costo(struct Cliente *arreglo);
void mostrar(struct Cliente *puntero, int cant);
void liberar(struct Cliente *arreglo, int cantidad);

int main () {
    int cantidad, longitud;
    char nombreAux[25];
    struct Cliente *preventista;
    srand(time(NULL));
    printf("Ingrese la cantidad de clientes:\n");
    scanf("%d",&cantidad);
    fflush(stdin);
    preventista = malloc (sizeof(struct Cliente) * cantidad);
    for (int i = 0;i < cantidad;i++) {
        printf("Ingrese el nombre del clientes:\n");
        gets(nombreAux);
        fflush(stdin);
        longitud = strlen(nombreAux);
        preventista[i].NombreCliente = malloc (sizeof(char) * (longitud + 1));
        strcpy(preventista[i].NombreCliente,nombreAux);
        preventista[i].ClienteID = i;
        preventista[i].CantidadProductosAPedir = 1 + rand() % 4;
        preventista[i].Productos = malloc (sizeof(struct Producto) * preventista[i].CantidadProductosAPedir);
        cargar(preventista[i].Productos,preventista[i].CantidadProductosAPedir);
    }
    mostrar(preventista,cantidad);
    liberar(preventista,cantidad);
    return 0;
}

void cargar(struct Producto *arreglo, int cant) {
    for (int j = 0;j < cant;j++) {
        arreglo[j].ProductoID = j;
        arreglo[j].Cantidad = 1 + rand() % 9;
        arreglo[j].TipoProducto = TiposProductos[j];
        arreglo[j].PrecioUnitario = 10 + rand() % 90;
    }
}

int costoTotal(struct Producto *arreglo) {
    return (arreglo->Cantidad * arreglo->PrecioUnitario);
}

void mostrar(struct Cliente *puntero, int cant) {
    for (int i = 0;i < cant;i++) {
        printf("\n***Cliente numero: %d***\n", puntero[i].ClienteID);
        printf("Nombre del cliente: %s\n", puntero[i].NombreCliente);
        printf("Cantidad de tipos productos diferentes que pidio el cliente: %d\n\n", puntero[i].CantidadProductosAPedir);
        for (int j = 0;j < puntero[i].CantidadProductosAPedir;j++) {
            printf("**Producto numero: %d**\n", puntero[i].Productos[j].ProductoID);
            printf("Nombre del producto: %s\n", puntero[i].Productos[j].TipoProducto);
            printf("Cantidad del producto: %d\n", puntero[i].Productos[j].Cantidad);
            printf("Precio unitario del producto: %.2f\n\n", puntero[i].Productos[j].PrecioUnitario);
        }
        printf("Total a pagar: %d\n\n\n",costo(puntero + i));
    }
}

int costo(struct Cliente *arreglo) {
    int total = 0;
    for (int i = 0;i < arreglo->CantidadProductosAPedir;i++) {
        total = total + costoTotal(arreglo->Productos + i);
    }
    return total;
}

void liberar(struct Cliente *arreglo, int cantidad) {
    for (int i = 0;i < cantidad;i++) {
        free(arreglo[i].NombreCliente);
        free(arreglo[i].Productos);
    }
    free(arreglo);
}