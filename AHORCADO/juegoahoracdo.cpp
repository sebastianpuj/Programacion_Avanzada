#include <algorithm> //Se incluye esta cabecera si se quiere usar la función find del algoritmo estándar de C++.
#include <iostream> //Se incluye esta cabecera si se quiere usar la función cout y cin del algoritmo estándar
#include <random> //Se incluye esta cabecera si se quiere usar la función random_device del algoritmo
#include <vector> //Se incluye esta cabecera si se quiere usar la función vector del algoritmo estándar

using namespace std;

const vector<string> palabras {"BUFFER", "FILE"}; //Se define un vector de palabras para el juego
const vector<string> fallos { //Se define una constante fallos que es un vector de strings que contiene las imágenes de los fallos del ahorcado.
    R"(
    !===N
     N
     N
     N
    =======
    )",
    R"(
    !===N
    0  N
     N
     N
    =======
    )",
    R"(
    !===N
    _0  N
     N
     N
    =======
    )",
    R"(
    !===N
    _0_ N
     N
     N
    =======
    )",
    R"(
    !===N
    _0_ N
    |  N
     N
    =======
    )",
    R"(
    !===N
    _0_ N
    |  N
    /  N
    =======
    )",
    R"(
    !===N
    _0_ N
    |  N
    / \ N
    =======
    )"
};

string seleccionar_palabra(const vector<string>& palabras) { //Esta función selecciona una palabra aleatoria del vector de palabras y la devuelve.
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(0, palabras.size() - 1);
  return palabras[dist(gen)];
}

void mostrar_tablero(int intentos, const vector<char>& letras_correctas, const string& palabra) { //Esta función muestra el estado actual del juego, incluyendo el número de intentos, las letras correctas adivinadas y la palabra con las letras adivinadas o guiones bajos.
  cout << fallos[intentos] << endl;
  vector<char> resultado(palabra.size(), '_');
  for (int i = 0; i < palabra.size(); i++) {
    if (find(letras_correctas.begin(), letras_correctas.end(), palabra[i]) != letras_correctas.end()) {
      resultado[i] = palabra[i];
    }
  }
  cout << "  " << string(resultado.begin(), resultado.end()) << endl;
}

char solicitar_letra(vector<char>& letras_todas) { // Esta función solicita al usuario una letra y la devuelve. Se asegura de que la letra sea válida y no haya sido adivinada antes.
  while (true) {
    char letra;
    cout << "Dime una letra: ";
    cin >> letra;
    letra = toupper(letra);
    if (letra < 'A' || letra > 'Z') {
      cout << "Por favor, introduce una letra válida." << endl;
      continue;
    }
    if (find(letras_todas.begin(), letras_todas.end(), letra) != letras_todas.end()) {
      cout << "Esa letra ya la has dicho." << endl;
      continue;
    }
    letras_todas.push_back(letra);
    return letra;
  }
}

void juego_del_ahorcado(const vector<string>& palabras, const vector<string>& fallos) { //Esta función es la función principal del juego. Implementa la lógica del juego, incluyendo la selección de la palabra, la solicitud de letras al usuario, la actualización del estado del juego y la comprobación de si el jugador ha ganado o perdido.
  string palabra = seleccionar_palabra(palabras); //Se selecciona una palabra aleatoria y se guarda en la variable palabra.
  vector<char> letras_correctas; //Se crea un vector vacío para almacenar las letras correctas adivinadas.
  vector<char> letras_todas; //Se crea un vector vacío para almacenar todas las letras que ha introducido el usuario.
  int intentos = 0; //Se inicializa el número de intentos en 0.

  while (intentos < fallos.size() - 1) { //Se ejecuta el bucle mientras el número de intentos sea menor que el número de fallos disponibles.
    mostrar_tablero(intentos, letras_correctas, palabra); // Se muestra el estado actual del juego.
    char letra = solicitar_letra(letras_todas); //Se solicita al usuario una letra.

    if (find(palabra.begin(), palabra.end(), letra) != palabra.end()) { //Se comprueba si la letra está en la palabra.
      letras_correctas.push_back(letra); //Si la letra está en la palabra, se añade al vector de letras correctas.
      if (all_of(palabra.begin(), palabra.end(), [&letras_correctas](char c) { //Se comprueba si todas las letras de la palabra han sido adivinadas.
        return find(letras_correctas.begin(), letras_correctas.end(), c) != letras_correctas.end();
      })) {
        mostrar_tablero(intentos, letras_correctas, palabra); //Se muestra el estado actual del juego.
        cout << "¡Has ganado! La palabra era: " << palabra << endl; //Se muestra un mensaje de victoria.
        break; //Se sale del bucle principal del juego.
      }
    } else {
      intentos++; //Si la letra no está en la palabra, se incrementa el número de intentos.
    }

    if (intentos == fallos.size() - 1) { //Si se ha llegado al máximo número de intentos, se muestra un mensaje de derrota.
      mostrar_tablero(intentos, letras_correctas, palabra);
      cout << "Has perdido. La palabra era: " << palabra << endl;
      break;
    }
  }
}

int main() {
  juego_del_ahorcado(palabras, fallos); // Se llama a la función juego_del_ahorcado para iniciar el juego.
  return 0; //Se devuelve el código de salida 0 para indicar que el programa ha terminado correctamente.
}