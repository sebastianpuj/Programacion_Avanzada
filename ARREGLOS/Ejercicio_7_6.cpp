#include <iostream> //Libreria de entrada y salida de datos
#include <string> //Libreria para usar strings
using namespace std; //Libreria para usar cout y cin

// Función para convertir un dígito en romano
string convertirRomano(int valor, char unidade, char cinco, char diez) { // Función para convertir un dígito en romano
    string romano = "";
    if (valor == 9) {
        romano = romano + unidade + diez; // Agregar el dígito en romano
    } else if (valor >= 5) {
        romano = romano + cinco; 
        for (int i = 0; i < valor - 5; ++i) {
            romano = romano + unidade;
        } // Agregar los dígitos en romano
    } else if (valor == 4) {
        romano = romano + unidade + cinco; // Agregar el dígito en romano
    } else {
        for (int i = 0; i < valor; ++i) {
            romano = romano + unidade;
        }
    }
    return romano;
} // Función para convertir un dígito en romano

// Función principal para convertir un número a romano
string convertirARomano(int numero) {
    if (numero <= 0 || numero > 3999) {
        return "Número fuera de rango (1-3999)";
    }

    string resultado = "";

    // Procesar unidades, decenas, centenas y millares
    int unidades = numero % 10;
    int decenas = (numero / 10) % 10;
    int centenas = (numero / 100) % 10;
    int millares = (numero / 1000) % 10;

    // Convertir millares
    resultado += convertirRomano(millares, 'M', '\0', '\0'); 

    // Convertir centenas
    resultado += convertirRomano(centenas, 'C', 'D', 'M');

    // Convertir decenas
    resultado += convertirRomano(decenas, 'X', 'L', 'C');

    // Convertir unidades
    resultado += convertirRomano(unidades, 'I', 'V', 'X'); 

    return resultado;
}

int main() {
    int numero;

    // Solicitar al usuario que ingrese un número
    cout << "Ingrese un número  (Entre 1 y 3999): ";
    cin >> numero;

    // Convertir y mostrar el resultado
    cout << "El número romano correspondiente es: " << convertirARomano(numero) << endl;

    return 0;
}
