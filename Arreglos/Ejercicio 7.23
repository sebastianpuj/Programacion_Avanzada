
//Ejercicio 7.23
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

// Función para calcular la frecuencia de aparición de las vocales en un texto
void calcularFrecuenciaVocales(const std::string& texto, int& a, int& e, int& i, int& o, int& u) {
    a = e = i = o = u = 0;  // Inicializar las variables de frecuencia a cero

    for (char letra : texto) {
        switch (std::tolower(letra)) {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            default:
                // Ignorar otras letras
                break;
        }
    }
}

// Función para mostrar el histograma de frecuencia de vocales
void mostrarHistograma(int frecuencia) {
    // Utilizar asteriscos para representar la frecuencia en el histograma
    for (int i = 0; i < frecuencia; ++i) {
        std::cout << '*';
    }
    std::cout << std::endl;
}

int main() {
    std::string texto;

    std::cout << "Ingrese un texto: ";
    std::getline(std::cin, texto);

    int frecuenciaA, frecuenciaE, frecuenciaI, frecuenciaO, frecuenciaU;
    calcularFrecuenciaVocales(texto, frecuenciaA, frecuenciaE, frecuenciaI, frecuenciaO, frecuenciaU);

    std::cout << "\nHistograma de frecuencia de vocales:" << std::endl;

    std::cout << "A: ";
    mostrarHistograma(frecuenciaA);

    std::cout << "E: ";
    mostrarHistograma(frecuenciaE);

    std::cout << "I: ";
    mostrarHistograma(frecuenciaI);

    std::cout << "O: ";
    mostrarHistograma(frecuenciaO);

    std::cout << "U: ";
    mostrarHistograma(frecuenciaU);

    return 0;
}
