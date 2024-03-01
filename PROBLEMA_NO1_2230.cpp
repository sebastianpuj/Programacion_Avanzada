#include <iostream>
#include <cstring>

// Función para eliminar espacios de una cadena
std::string eliminarEspacios(const std::string& str) {
    std::string resultado;
    for (char c : str) {
        if (c != ' ') {
            resultado += c;
        }
    }
    return resultado;
}

// Función para verificar si una cadena es un palíndromo
bool esPalindromo(const std::string& str) {
    int inicio = 0;
    int fin = str.length() - 1;
    while (inicio < fin) {
        if (str[inicio] != str[fin]) {
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}

int main() {
    std::string str = "anita lava la tina";
    str = eliminarEspacios(str);
    if (esPalindromo(str)) {
        std::cout << str << " es un palíndromo." << std::endl;
    } else {
        std::cout << str << " no es un palíndromo." << std::endl;
    }
    return 0;
}