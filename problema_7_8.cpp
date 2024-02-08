#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<std::vector<int>, int> sustituir(std::vector<int> vector) {
    std::unordered_map<int, int> frecuencia;
    int modificaciones = 0;

    for (int i = 0; i < vector.size(); ++i) {
        if (frecuencia.find(vector[i]) != frecuencia.end()) {
            vector[i] = -5;
            ++modificaciones;
        }
        ++frecuencia[vector[i]];
    }

    return std::make_pair(vector, odificaciones);
}

int main() {
    std::vector<int> numeros = {1, 3, 5, 7, 5, 3, 9, 11, 9, 7};

    std::pair<std::vector<int>, int> resultado = sustituir(numeros);

    std::cout << "Vector modificado: ";
    for (int num : resultado.first) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    std::cout << "Numero de entradas modificadas: " << resultado.second << std::endl;

    return 0;
}