#include <iostream>
#include <string>

int main() {
    std::string cad; // Declaramos una cadena de caracteres

    // Leemos la cadena desde la entrada estándar
    std::cout << "Ingresa una cadena de caracteres: ";
    std::getline(std::cin, cad);

    // Buscamos la posición del primer espacio en blanco
    size_t pos = cad.find(' ');

    if (pos != std::string::npos) {
        // Si encontramos un espacio en blanco, imprimimos la parte de la cadena después del espacio
        std::cout << "La cadena después de la primera palabra es: " << cad.substr(pos + 1) << std::endl;
    } else {
        // Si no hay espacios en blanco, imprimimos la cadena completa
        std::cout << "La cadena no contiene espacios en blanco." << std::endl;
    }

    return 0;
}
