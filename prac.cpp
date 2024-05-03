#include <iostream>
using namespace std;

void imprimirMatriz(int **m, int filas, int columnas) {
    int **ptr = m;
    int *temp = nullptr;
    while (ptr < m + filas) {
        temp = *ptr;
        while (temp < *ptr + columnas) {
            cout << *temp++ << "\t";
        }
        cout << "\n";
        ptr++;
    }
}

int* obtenerColumna(int **matriz, int filas, int columnas, int indice) {
    int *arregloColumna = new int[filas];
    int **ptr = matriz;
    int *result = arregloColumna;
    while (ptr < matriz + filas) {
        *(result++) = *(*(ptr++) + indice);
    }
    return arregloColumna;
}

int calcularProductoPunto(int *arreglo1, int *arreglo2, int longitud) {
    int *puntero1 = arreglo1;
    int *puntero2 = arreglo2;
    int suma = 0;
    while (puntero1 < arreglo1 + longitud) {
        suma += (*(puntero1++) * *(puntero2++));
    }
    return suma;
}

int **multiplicarMatrices(int **m1, int **m2, int filas_m1, int columnas_m1, int filas_m2, int columnas_m2) {
    if (columnas_m1 != filas_m2) return NULL;

    int **resultado = new int *[filas_m1];
    for (int i = 0; i < filas_m1; ++i) {
        resultado[i] = new int[columnas_m2];
    }
    int **ptrResultado = resultado;
    int *tempResultado = nullptr;
    int **ptrM1 = m1;
    int contador = 0;
    while (ptrResultado < resultado + filas_m1) {
        tempResultado = *ptrResultado;
        while (tempResultado < *ptrResultado + columnas_m2) {
            *(tempResultado++) = calcularProductoPunto(*ptrM1, obtenerColumna(m2, filas_m2, columnas_m2, (contador) % columnas_m2), columnas_m1);
            contador++;
        }
        ptrResultado++;
        ptrM1++;
    }
    return resultado;
}

int main() {
    int m1[3][3] = {{2, 3, 1}, {5, 6, 4}, {8, 9, 7}};
    int m2[3][2] = {{2, 2}, {2, 2}, {2, 2}};
    int **arr1 = new int *[3];
    for (int i = 0; i < 3; i++) {
        arr1[i] = m1[i];
    }
    int **arr2 = new int *[3];
    for (int i = 0; i < 3; i++) {
        arr2[i] = m2[i];
    }
    cout << "\t\tMultiplicacion de matrices\n\nMatriz 1 \n\n";
    imprimirMatriz(arr1, 3, 3);
    cout << "\nMatriz 2 \n\n";
    imprimirMatriz(arr2, 3, 2);
    int **resultado = multiplicarMatrices(arr1, arr2, 3, 3, 3, 2);
    cout << "\nMultiplicacion \n\n";
    if (resultado == NULL) {
        cout << "No es posible realizar la multiplicacion";
    } else {
        imprimirMatriz(resultado, 3, 2);
    }
    return 0;
}
