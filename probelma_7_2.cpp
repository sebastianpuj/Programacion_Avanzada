#include <iostream>

// Función para invertir el contenido de n numeros enteros.
void invertirNumeros(int arr[], int n) {
    // Se inializan dos punteros, al principio y al final. 
    int inicio = 0;
    int fin = n - 1;
    // Se realiza un ciclo while que se ejecuta hasta que los punteros        se crucen. 
    while (inicio < fin) {
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;

        // Movemos los punteros hacia adentro
        inicio++;
        fin--;
    }
}

int main() {
    const int n = 5;

    int numeros[n] = {5, 10, 15, 20, 25};

    std::cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    // Se invierte el arreglo
    invertirNumeros(numeros, n);
  
    std::cout << "Arreglo invertido: ";
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}