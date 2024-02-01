/*Calcular la media aritmetica de un conjunto de numeros reales*/

#include <iostream>
using namespace std;

int main()
{
    int n; 
    float suma = 0; 
    float *numeros;
    numeros = new float[n];

    std::cout << "Ingrese la cantidad de numeros deseados: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Ingrese el número " << i + 1 << ": ";
        std::cin >> numeros[i];
        suma += numeros[i];
    }

    if (n > 0) {
        double media = suma / n;
        std::cout << "Media: " << media;
    } 

    delete[] numeros;
    return 0;
}
