#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar(int arreglo[][12]); //chat gpt me dijo que asi tenia que hacerlo
void cargarMatriz(int arreglo[][12]);
void promedio(int arreglo[][12]);
void minimoYmaximo(int arreglo[][12]);

int main () {
    int datos[5][12];
    srand(time(NULL));
    cargarMatriz(datos);
    mostrar(datos);
    promedio(datos);
    minimoYmaximo(datos);
    return 0;
}

void cargarMatriz(int arreglo[][12]) {
    int aleatorio;
    for (int i = 0;i < 5; i++) {
        for (int j = 0;j < 12;j++) {
            aleatorio = 10000 + rand() % 50000;
            arreglo[i][j] = aleatorio;
        }   
    }
}

void mostrar(int arreglo[][12]) {
    for (int i = 0;i < 5; i++) {
        printf("Anio %d\n", (i+1));
        for (int j = 0;j < 12;j++) {
            printf("Mes %d, ", (j+1));
            printf("produccion %d\n", arreglo[i][j]);
        }   
    }
}

void promedio(int arreglo[][12]) {
    long int promedio = 0;
    for (int i = 0;i < 5; i++) {
        for (int j = 0;j < 12;j++) {
            promedio = promedio + arreglo[i][j];
        }
        printf("Promedio del anio %d es %ld\n", (i+1), promedio);
        promedio = 0;
    }
}

void minimoYmaximo(int arreglo[][12]) {
    int maximo[3] = {0,0,0};
    int minimo[3] = {50000,0,0};
    for (int i = 0;i < 5; i++) {
        for (int j = 0;j < 12;j++) {
            if (minimo[0] > arreglo[i][j]) {
                minimo[0] = arreglo[i][j];
                minimo[1] = i;
                minimo[2] = j;
            } else {
                if (maximo[0] < arreglo[i][j]) {
                    maximo[0] = arreglo[i][j];
                    maximo[1] = i;
                    maximo[2] = j;
                }
            }
        }
    }
    printf("El valor minimo es %d, y ocurrio en el mes %d y anio %d\n", minimo[0], (minimo[2] + 1), (minimo[1] + 1));
    printf("El valor maximo es %d, y ocurrio en el mes %d y anio %d\n", maximo[0], (maximo[2] + 1), (maximo[1] + 1));
}