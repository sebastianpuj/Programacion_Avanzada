#include <iostream>
#include <vector>

// Función para calcular el MCD a partir de las descomposiciones en factores primos
std::vector<int> descomposicion_mcd(const std::vector<int>& descomposicion1, const std::vector<int>& descomposicion2) {
    std::vector<int> resultado; // Vector para almacenar la descomposición del MCD

    // Índices para recorrer las descomposiciones
    int i = 0;
    int j = 0;

    // Combinamos los primos comunes con la menor multiplicidad
    while (i < descomposicion1.size() && j < descomposicion2.size()) {
        if (descomposicion1[i] == descomposicion2[j]) {
            resultado.push_back(descomposicion1[i]); // Agregamos el primo común
            ++i;
            ++j;
        } else if (descomposicion1[i] < descomposicion2[j]) {
            resultado.push_back(descomposicion1[i]); // Agregamos el primo de descomposicion1
            ++i;
        } else {
            resultado.push_back(descomposicion2[j]); // Agregamos el primo de descomposicion2
            ++j;
        }
    }

    // Agregamos los primos restantes (si los hay)
    while (i < descomposicion1.size()) {
        resultado.push_back(descomposicion1[i]);
        ++i;
    }
    while (j < descomposicion2.size()) {
        resultado.push_back(descomposicion2[j]);
        ++j;
    }

    return resultado;
}

int main() {
    // Ejemplo de descomposiciones en factores primos (ordenadas)
    std::vector<int> descomposicion1 = {2, 2, 3, 5}; // 2^2 * 3 * 5
    std::vector<int> descomposicion2 = {2, 3, 3, 7}; // 2 * 3^2 * 7

    // Calculamos la descomposición del MCD
    std::vector<int> descomposicion_mcd_resultado = descomposicion_mcd(descomposicion1, descomposicion2);

    // Mostramos la descomposición del MCD
    std::cout << "Descomposición del MCD: ";
    for (int primo : descomposicion_mcd_resultado) {
        std::cout << primo << " ";
    }
    std::cout << std::endl;

    return 0;
}
