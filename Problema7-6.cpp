#include <iostream>

// Función que devuelve un puntero al elemento mayor (versión 1: a través de return)
int* encontrar_maximo(const int vector[], int longitud) {
    if (longitud == 0) {
        return nullptr; // Si el vector está vacío, devolvemos nullptr
    }

    int* max_elemento = &vector[0]; // Inicializamos con el primer elemento

    for (int i = 1; i < longitud; ++i) {
        if (vector[i] > *max_elemento) {
            max_elemento = &vector[i];
        }
    }

    return max_elemento;
}

// Función que actualiza un puntero al elemento mayor (versión 2: a través de parámetro)
void encontrar_maximo(const int vector[], int longitud, int*& max_elemento) {
    if (longitud == 0) {
        max_elemento = nullptr; // Si el vector está vacío, actualizamos max_elemento a nullptr
        return;
    }

    max_elemento = &vector[0]; // Inicializamos con el primer elemento

    for (int i = 1; i < longitud; ++i) {
        if (vector[i] > *max_elemento) {
            max_elemento = &vector[i];
        }
    }
}

int main() {
    int vector[] = {10, 5, 8, 15, 20, 12}; // Ejemplo de vector de números enteros
    int longitud = sizeof(vector) / sizeof(vector[0]);

    // Versión 1: Devuelve el resultado a través de return
    int* maximo1 = encontrar_maximo(vector, longitud);
    if (maximo1) {
        std::cout << "1. El elemento mayor del vector: " << *maximo1 << std::endl;
    } else {
        std::cout << "El vector está vacío." << std::endl;
    }

    // Versión 2: Devuelve el resultado a través de un parámetro
    int* maximo2 = nullptr;
    encontrar_maximo(vector, longitud, maximo2);
    if (maximo2) {
        std::cout << "2. El elemento mayor de la primera mitad: " << *maximo2 << std::endl;
    } else {
        std::cout << "El vector está vacío." << std::endl;
    }

    // Elemento mayor de la segunda mitad (considerando longitud par)
    int* maximo3 = nullptr;
    encontrar_maximo(vector + longitud / 2, longitud / 2, maximo3);
    if (maximo3) {
        std::cout << "3. El elemento mayor de la segunda mitad: " << *maximo3 << std::endl;
    } else {
        std::cout << "El vector está vacío." << std::endl;
    }

    return 0;
}
