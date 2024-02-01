/*Un punto en el plano se puede representar mediante una estructura con dos campos. Escribir un programa que realice las siguientes operaciones con puntos en el plano.
• Dados dos puntos calcular la distancia entre ellos.
• Dados dos puntos determinar el punto medio de la línea que los une.*/

#include <iostream>
#include <cmath>

struct Punto {
    double x;
    double y;
};

double Distancia(Punto p1, Punto p2) {
    double distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distancia;
}

Punto puntomedio(Punto p1, Punto p2) {
    Punto medio;
    medio.x = (p1.x + p2.x) / 2;
    medio.y = (p1.y + p2.y) / 2;
    return medio;
}

int main() {
    Punto p1, p2, medio;
    std::cout << "Coordenadas p1: ";
    std::cin >> p1.x >> p1.y;
    std::cout << "Coordenadas p2: ";
    std::cin >> p2.x >> p2.y;

    double distancia = Distancia(p1, p2);
    std::cout << "Distancia: " << distancia << std::endl;

    medio = puntomedio(p1, p2);
    std::cout << "Punto medio de X y Y respectivamente: (" << medio.x << ", " << medio.y << ")" << std::endl;

    return 0;
}