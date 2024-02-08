#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
string palabras[] = {"futbol", "baloncesto", "voleibol", "tenis", "ajedrez", "natacion", "rugby", "atletismo", "ciclismo" };

int main() {
    
    srand(time(0));
    int indice = rand() % 9;
    string palabra_aleatoria = palabras[indice];

    string palabra(palabra_aleatoria.length(), '_');

    int intentos_totales = 6; 
    int intentos_restantes = intentos_totales;
    char letra;

    cout << "AHORCADO DE DEPORTES" << endl;
    cout << "La palabra tiene " << palabra_aleatoria.length() << " letras. ¿Puedes adivinarla?" << endl;

    while (intentos_restantes > 0 && palabra != palabra_aleatoria) {
        cout << "Palabra: " << palabra << endl;
        cout << "Número de intentos para perder : " <<           intentos_restantes << endl;
        cout << "Ingrese una letra: ";
        cin >> letra;

        bool acierto = false;
        for (int i = 0; i < palabra_aleatoria.length(); i++) {
            if (palabra_aleatoria[i] == letra) {
                palabra[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentos_restantes--;
            cout << "La letra " << letra << " no está, intenta con otra." << endl;
        }
    }

    if (palabra == palabra_aleatoria) {
        cout << "¡GANASTE! Eres bueno con los deportes, la palabra si era " << palabra_aleatoria << endl;
    } else {
        cout << "PERDISTE :(. Ya no tienes más intentos. La palabra era: " << palabra_aleatoria << endl;
    }

    return 0;
}