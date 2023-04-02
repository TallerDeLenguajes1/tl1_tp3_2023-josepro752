#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrar(char *nombres[]);
void liberar(char *nombres[]);

int main () {
    char *nombres[5];
    char aux[25];
    int longitud;
    for (int i = 0;i < 5;i++) {
        printf("Ingrese un nombre\n");
        gets(aux);
        longitud = strlen(aux);
        nombres[i] = malloc (sizeof(char) * (longitud + 1));
        strcpy(nombres[i],aux);
    }
    mostrar(nombres);
    liberar(nombres);
    return 0;
}

void mostrar(char *nombres[]) {
    printf("Los nombres son: \n");
    for (int i = 0;i < 5;i++) {
        printf("Nombre %d: %s\n",(i + 1), nombres[i]);
    }
}

void liberar(char *nombres[]) {
    for (int i = 0;i < 5;i++) {
        free(nombres[i]);
    }
}