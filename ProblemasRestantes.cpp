//Ejercicio 7.7 
#include <iostream>
using namespace std;

struct Celda {
    int d;
    Celda *p1, *p2, *p3;
};

int main() {
    Celda a, b, c, d;
    a.d = b.d = c.d = d.d = 0;

    a.p1 = &c;
    c.p3 = &d;
    a.p2 = &c->*p3; // Fix: Should be a.p2 = &a.p1->p3;
    d.p1 = &b;
    b.p2 = &a->*p1; // Fix: Should be b.p2 = &a.p1->p2;
    c.p2 = &a->*p1->*p2.e.c->*p3->*p1; // Fix: Should be c.p2 = &a.p1->p2->p2->e.c->p3->p1;

    cout << "a=" << a.d << ", b=" << b.d << ", c=" << c.d << ", d=" << d.d << endl;

    return 0;
}
//Ejercicio 7.8
#include <iostream>
#include <vector>

int main() {
    const int n = 10; // Cambia esto al tamaño deseado del vector
    std::vector<double> v = {5, 2, 9, 1, 7, 6, 8, 3, 4, 0}; // Inicializa con valores

    int i = 0;
    int j = n -1;

    while (i < j) {
        while (v[i] <= v[0] && i < j) {
            i++;
        }

        while (v[j] > v[0]) {
            j--;
        }

        if (i < j) {
            std::swap(v[i], v[j]);
        }
    }

    std::cout << "Vector organizado: ";

    for (const auto& num : v) {
        std::cout << num << " ";
    }

    return 0;
}

//Ejercicio 7.11 
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> maximoComunDivisor(std::vector<int> a, std::vector<int> b) {
    std::vector<int> mcd;
    auto it_a = a.begin();
    auto it_b = b.begin();

    while (it_a != a.end() && it_b != b.end()) {
        if (*it_a == *it_b) {
            mcd.push_back(*it_a);
            ++it_a;
            ++it_b;
        } else if (*it_a < *it_b) {
            ++it_a;
        } else {
            ++it_b;
        }
    }

    return mcd;
}

int main() {
    std::vector<int> a = {2, 2, 3}; // Descomposición en primos de 12
    std::vector<int> b = {2, 5}; // Descomposición en primos de 20

    std::vector<int> mcd = maximoComunDivisor(a, b);

    std::cout << "El MCD es: ";
    for (const auto& num : mcd) {
        std::cout << num << " ";
    }

    return 0;
}

//Ejercicio 7.12
#include <iostream>
#include <string>

std::string subcadena(const std::string& s, int P, int L) {
    if (P < 0 || P >= s.size()) {
        return "";
    }

    const char* inicio = s.c_str() + P;
    int longitud = std::min(L, static_cast<int>(s.size() - P));

    return std::string(inicio, inicio + longitud);
}

int main() {
    std::string s = "Hola, mundo!";
    int P = 2;
    int L = 5;

    std::string sub = subcadena(s, P, L);

    std::cout << "La subcadena es: " << sub << std::endl;

    return 0;
}