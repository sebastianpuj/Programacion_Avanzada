/*Escribe una funcion sort que ordene un conjunto de n cadenas en orden alfabetico*/

/*Librerias necesarias para que funcione el programa*/
#include <iostream>
#include <vector>
#include <algorithm> /*ordenar*/
#include <sstream>

void ordenar(std::vector<std::string>& cadenas) {
    std::sort(cadenas.begin(), cadenas.end());
} /*Uso de la funcion sort que ordena albafabeticamente*/

int main() {
    std::vector<std::string> palabras;
    std::cout << "Ingrese las palabras que desea ordenar alfabeticamente: "<<std::endl;
    std::string linea;
    /*extraccion de las palabras una a una*/ 
    while (std::getline(std::cin, linea) && !linea.empty()) {
        std::istringstream iss(linea);
        std::string palabra;
        while (iss >> palabra) {
            palabras.push_back(palabra);
        }
    }

    ordenar(palabras);
    std::cout << "Palabras ordenadas: " <<std::endl;
    for (const auto& cadena : palabras) {
        std::cout << cadena << "\n";
    }

return 0;
}