# Programacion_Avanzada
//Ejercicio 7.3
#include <iostream>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Función para sumar días a una fecha
Fecha sumarDias(Fecha fechaInicial, int diasParaSumar) {
    // Añadimos los días
    fechaInicial.dia += diasParaSumar;

    // Ajustamos los días y los meses
    while (fechaInicial.dia > 30) {  // Suponemos que todos los meses tienen 30 días para simplificar
        fechaInicial.dia -= 30;
        fechaInicial.mes++;

        if (fechaInicial.mes > 12) {
            fechaInicial.mes = 1;
            fechaInicial.anio++;
        }
    } 

    // Devolvemos la nueva fecha calculada
    return fechaInicial;
}
// Ejercicio 7.4
#include <iostream>

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }

    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    const int cantidadDeNumerosPrimos = 80;

    int primosEncontrados = 0;
    int numeroActual = 2; // Comenzamos con el primer número primo

    std::cout << "Primeros " << cantidadDeNumerosPrimos << " números primos:" << std::endl;

    while (primosEncontrados < cantidadPrimos) {
        if (esPrimo(numeroActual)) {
            std::cout << numeroActual << "\t";

            // Mostramos 10 números por fila para formar una tabla
            if ((primosEncontrados + 1) % 10 == 0) {
                std::cout << std::endl;
            }

            primosEncontrados++;
        }

        numeroActual++;
    }

    return 0;
}

//Ejercicio 7.30
#include <iostream>
#include <string>

int main() {
    // Solicitamos al usuario que ingrese una cadena de caracteres
    std::cout << "Ingrese una palabra: ";
    std::string palabra;
    std::getline(std::cin, palabra);

    // Mostramos la cadena en sentido inverso
    std::cout << "Cadena en sentido inverso: ";
    for (int i = palabra.length() - 1; i >= 0; --i) {
        std::cout << palabra[i];
    }

    std::cout << std::endl;

    return 0;
}

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
