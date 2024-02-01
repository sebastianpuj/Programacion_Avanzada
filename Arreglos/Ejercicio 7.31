// Ejercicio 7.31 
#include <iostream>
#include <string>
#include <sstream>

int calcularFrecuenciaPalabra(const std::string& frase, const std::string& palabra) {
    std::istringstream stream(frase);
    std::string palabraEncontrada;
    int frecuencia = 0;

    while (stream >> palabraEncontrada) {
        // Convertir la palabra a minúsculas para hacer la comparación sin distinción entre mayúsculas y minúsculas
        if (palabraEncontrada == palabra) {
            frecuencia++;
        }
    }

    return frecuencia;
}

int main() {
    std::string frase;
    std::string palabraBuscada;

    // Solicitar al usuario la entrada de la frase y la palabra a buscar
    std::cout << "Ingrese una frase: ";
    std::getline(std::cin, frase);

    std::cout << "Ingrese la palabra a buscar: ";
    std::cin >> palabraBuscada;

    // Calcular la frecuencia de la palabra en la frase
    int frecuencia = calcularFrecuenciaPalabra(frase, palabraBuscada);

    // Mostrar resultados
    std::cout << "La palabra \"" << palabraBuscada << "\" aparece " << frecuencia << " veces en la frase." << std::endl;

    return 0;
}}
