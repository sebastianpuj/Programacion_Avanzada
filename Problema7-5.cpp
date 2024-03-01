#include <iostream>
#include <cstring> // Para funciones de manejo de cadenas

// Función para añadir una cadena al final de otra
void encadenar_cadena(char destino[], const char fuente[]) {
    // Usamos la función strcat para concatenar la cadena fuente al final de la cadena destino
    strcat(destino, fuente);
}

// Función para comparar dos cadenas
int comparar_cadena(const char cadena1[], const char cadena2[]) {
    // Usamos la función strcmp para comparar las cadenas
    return strcmp(cadena1, cadena2);
}

int main() {
    // Ejemplo de uso
    char cadena_destino[100] = "Hola, ";
    const char cadena_fuente[] = "mundo!";

    // Añadimos la cadena fuente al final de la cadena destino
    encadenar_cadena(cadena_destino, cadena_fuente);

    // Comparamos las cadenas
    int resultado = comparar_cadena(cadena_destino, "Hola, mundo!");
    if (resultado == 0) {
        std::cout << "Las cadenas son iguales." << std::endl;
    } else if (resultado < 0) {
        std::cout << "La primera cadena es más pequeña." << std::endl;
    } else {
        std::cout << "La primera cadena es más grande." << std::endl;
    }

    return 0;
}
