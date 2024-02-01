//Ejercicio 7.29
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string frase;

    std::cout << "Ingrese una frase: ";
    std::getline(std::cin, frase);

    std::istringstream stream(frase);  // Utilizamos un stringstream para dividir la frase en palabras

    std::string palabra;
    while (stream >> palabra) {
        std::cout << palabra << std::endl;
    }

    return 0;
}