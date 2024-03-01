#include <iostream>

// Función para mezclar dos vectores ordenados en uno nuevo
void mezclar_vectores(const double* vI, int n, const double* v2, int m, double* res) {
    const double* ptr1 = vI; // Puntero para recorrer vI
    const double* ptr2 = v2; // Puntero para recorrer v2
    double* ptr_res = res;   // Puntero para recorrer el vector resultante

    // Mezclamos los valores de vI y v2 en res
    while (ptr1 < vI + n && ptr2 < v2 + m) {
        if (*ptr1 < *ptr2) {
            *ptr_res = *ptr1;
            ++ptr1;
        } else {
            *ptr_res = *ptr2;
            ++ptr2;
        }
        ++ptr_res;
    }

    // Copiamos los elementos restantes de vI (si los hay)
    while (ptr1 < vI + n) {
        *ptr_res = *ptr1;
        ++ptr1;
        ++ptr_res;
    }

    // Copiamos los elementos restantes de v2 (si los hay)
    while (ptr2 < v2 + m) {
        *ptr_res = *ptr2;
        ++ptr2;
        ++ptr_res;
    }
}

int main() {
    const int n = 5; // Tamaño de vI
    const int m = 3; // Tamaño de v2

    double vI[n] = {1.2, 2.5, 3.7, 4.8, 5.9}; // Vector vI ordenado
    double v2[m] = {2.0, 3.3, 5.1};          // Vector v2 ordenado
    double res[n + m];                        // Vector resultante

    // Mezclamos los vectores vI y v2 en res
    mezclar_vectores(vI, n, v2, m, res);

    // Mostramos el vector resultante
    std::cout << "Vector resultante (mezclado y ordenado): ";
    for (int i = 0; i < n + m; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
