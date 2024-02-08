#include <iostream>
#include <string>

int main() {
    std::string cadena;

    // Para iniciar pedir que se digite una cadena de caracteres
    std::cout << "Escribe una cadena de caracteres: ";
    std::getline(std::cin, cadena);

    int longitud = cadena.length();

    // Desarrollar las dimensiones del cuadro
    std::cout << "+";
    for (int i = 0; i < longitud + 2; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

   
    std::cout << "| " << cadena << " |" << std::endl;

   
    std::cout << "+";
    for (int i = 0; i < longitud + 2; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    return 0;
}