#include <iostream>
#include <algorithm>

void ordenar_punteros(double* vector, int longitud, double** punteros) {
    for (int i = 0; i < longitud; ++i) {
        punteros[i] = &vector[i];
    }

    std::sort(punteros, punteros + longitud, [](double* a, double* b) { return *a < *b; });
}

int main() {
    int ver[1000];
    double* ptr[1000];

    int longitud = 1000;
    for (int i = 0; i < longitud; ++i) {
        ver[i] = longitud - i;
    }

    ordenar_punteros(ver, longitud, ptr);

    std::cout << "Elementos del vector ordenados:\n";
    for (int i = 0; i < longitud; ++i) {
        std::cout << *(ptr[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "Elementos de la segunda mitad del vector ordenados:\n";
    int mitad = longitud / 2;
    for (int i = mitad; i < longitud; ++i) {
        std::cout << *(ptr[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}
