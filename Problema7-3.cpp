#include <iostream>

int main() {
    char cadena[100]; // Declaramos una cadena de 100 caracteres
    // Supongamos que la cadena contiene caracteres (menos de 100) seguidos de un carácter nulo ('\0')

    // Llenamos la cadena con algunos caracteres (por ejemplo, "Hola Mundo")
    const char* ejemplo = "Hola Mundo";
    for (int i = 0; i < 100; ++i) {
        cadena[i] = ejemplo[i];
        if (ejemplo[i] == '\0') break; // Detenemos la copia al encontrar el carácter nulo
    }

    // Puntero para recorrer la cadena
    const char* ptr = cadena;

    // Buscamos el primer carácter espacio (' ')
    while (*ptr != ' ' && *ptr != '\0') {
        ++ptr; // Avanzamos al siguiente carácter
    }

    if (*ptr == ' ') {
        // Hemos encontrado un espacio, imprimimos su posición
        std::cout << "La posición del primer espacio es: " << (ptr - cadena) << std::endl;
    } else {
        std::cout << "No se encontró ningún espacio en la cadena." << std::endl;
    }

    return 0;
}
