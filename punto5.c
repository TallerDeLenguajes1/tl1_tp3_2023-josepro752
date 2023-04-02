#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar(char **nombres, int cantidad);
void liberar(char **nombres, int cantidad);

int main () {
    char **nombres;
    char aux[25];
    int longitud, cantidad;
    printf("Ingrese la cantidad de nombres:");
    scanf("%d",&cantidad);
    fflush(stdin);
    nombres = malloc (sizeof(char *) * cantidad);
    for (int i = 0;i < cantidad;i++) {
        printf("Ingrese un nombre\n");
        gets(aux);
        fflush(stdin);
        longitud = strlen(aux);
        nombres[i] = malloc (sizeof(char) * (longitud + 1));
        strcpy(nombres[i],aux);
    }
    mostrar(nombres,cantidad);
    liberar(nombres,cantidad);
    return 0;
}

void mostrar(char **nombres, int cantidad) {
    printf("Los nombres son: \n");
    for (int i = 0;i < cantidad;i++) {
        printf("Nombre %d: %s\n",(i + 1), nombres[i]);
    }
}

void liberar(char **nombres, int cantidad) {
    for (int i = 0;i < cantidad;i++) {
        free(nombres[i]);
    }
    free(nombres);
}