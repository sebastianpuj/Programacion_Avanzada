/*Diseñar un programa que determine la media del numero de horas trabajadas durante todos los dias de la semana*/

#include <iostream>
#include <vector>

int main() {
    std::vector<float> horas(7);
    float total = 0;
    float media = 0;

    for (int i = 0; i < 7; ++i) {
        std::cout << "Ingrese el número de horas trabajadas durante el día " << i + 1 << ": ";
        std::cin >> horas[i];
        total += horas[i];
    }

    media = total / 7;
    std::cout << "Media horas trabajadas en la semana: " << media << std::endl;

    return 0;
}