#include <iostream>
#include <ctime> // Para generar números aleatorios
#include <cstdlib> // Para usar rand()

using namespace std;

// Función para crear una matriz de tamaño filas x columnas
int** crearMatriz(int filas, int columnas) {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }
    return matriz;
}

// Función para llenar una matriz con números aleatorios entre 100 y 200
void llenarMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 101 + 100; // Números entre 100 y 200
        }
    }
}

// Función para sumar dos matrices
int** sumarMatrices(int** matrizA, int** matrizB, int filas, int columnas) {
    int** resultado = crearMatriz(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    return resultado;
}

// Función para mostrar una matriz
void mostrarMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para liberar la memoria de una matriz
void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int main() {
    srand(time(NULL));

    int filas, columnas;
    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

    int** matrizA = crearMatriz(filas, columnas);
    int** matrizB = crearMatriz(filas, columnas);

    llenarMatriz(matrizA, filas, columnas);
    llenarMatriz(matrizB, filas, columnas);

    cout << "Matriz A:" << endl;
    mostrarMatriz(matrizA, filas, columnas);

    cout << "Matriz B:" << endl;
    mostrarMatriz(matrizB, filas, columnas);

    int** resultado = sumarMatrices(matrizA, matrizB, filas, columnas);
    cout << "Matriz Resultado:" << endl;
    mostrarMatriz(resultado, filas, columnas);

    liberarMatriz(matrizA, filas);
    liberarMatriz(matrizB, filas);
    liberarMatriz(resultado, filas);

    return 0;
}