#include <iostream>
#include <vector>
#include <algorithm> // Para std::shuffle  
#include <random> // Para std::default_random_engine
#include <chrono> // Para std::chrono::system_clock
#include <iomanip> // Para std::setw
#include <fstream>

using namespace std;

void generarArchivoRespuestas(const vector<vector<int>>* tablero, const string* nombreArchivo) {

  ofstream* archivo = new ofstream(*nombreArchivo);

  if (!archivo->is_open()) {
    cerr << "Error al abrir el archivo para escribir las respuestas." << endl;
    return;
  }

  for (const auto& fila : *tablero) {
    for (const auto& valor : fila) {
      *archivo << valor << " ";
    }
    *archivo << "\n";
  }

  archivo->close();
  delete archivo;

  cout << "Archivo de respuestas generado: " << *nombreArchivo << endl;  
}

void inicializarTablero(vector<vector<int>>* tablero, int filas, int columnas) {

  int totalCartas = filas * columnas;
  int* carta = new int(1);

  for (int i = 0; i < totalCartas; i += 2) {
    (*tablero)[i / columnas][i % columnas] = *carta;
    (*tablero)[(i + 1) / columnas][(i + 1) % columnas] = *carta;
    (*carta)++; 
  }

  // Mezclar el tablero
  unsigned* seed = new unsigned(chrono::system_clock::now().time_since_epoch().count());
  shuffle(begin((*tablero)[0]), end((*tablero)[0]), default_random_engine(*seed));  

  delete seed;
  delete carta;
}

void mostrarTablero(const vector<vector<int>>* tablero, const vector<vector<bool>>* reveladas) {

  for (int i = 0; i < tablero->size(); ++i) {
    for (int j = 0; j < (*tablero)[i].size(); ++j) {
      if ((*reveladas)[i][j]) {
        cout << setw(2) << (*tablero)[i][j] << " ";
      } else {
        cout << setw(2) << "*" << " ";  
      }
    }
    cout << "\n";
  }
}

bool comprobarFinJuego(const vector<vector<bool>>* reveladas) {

  for (const auto& fila : *reveladas) {
    for (bool cartaRevelada : fila) {
      if (!cartaRevelada) {
        return false;
      }
    }
  }

  return true;
}

void elegirCarta(int* x, int* y, const vector<vector<bool>>* reveladas) {

  do {
    cout << "Elige una carta (fila y columna): ";
    cin >> *x >> *y;

    if ((*reveladas)[*x][*y]) {
      cout << "Esta carta ya ha sido revelada. Elige otra carta.\n";
    }
  } while ((*reveladas)[*x][*y]); 
}

int main() {

  int* filas = new int(4); 
  int* columnas = new int(4);

  vector<vector<int>>* tablero = new vector<vector<int>>(*filas, vector<int>(*columnas));
  vector<vector<bool>>* reveladas = new vector<vector<bool>>(*filas, vector<bool>(*columnas, false));

  inicializarTablero(tablero, *filas, *columnas);

  string* nombreArchivo = new string("respuestasMemorama.txt");
  generarArchivoRespuestas(tablero, nombreArchivo);

  int* x1 = new int();
  int* y1 = new int();
  int* x2 = new int(); 
  int* y2 = new int();

  while (!comprobarFinJuego(reveladas)) {

    mostrarTablero(tablero, reveladas);

    elegirCarta(x1, y1, reveladas); 
    (*reveladas)[*x1][*y1] = true; 

    mostrarTablero(tablero, reveladas);

    elegirCarta(x2, y2, reveladas);

    if ((*tablero)[*x1][*y1] == (*tablero)[*x2][*y2]) {
      cout << "¡Encontraste una pareja!\n";
      (*reveladas)[*x2][*y2] = true; 
    } else {
      cout << "No son una pareja. Intenta de nuevo.\n";
      (*reveladas)[*x1][*y1] = false; 
    }
  }

  cout << "¡Felicidades! Has completado el juego.\n";

  delete filas;
  delete columnas;
  delete tablero;
  delete reveladas;
  delete nombreArchivo; 
  delete x1;
  delete y1;
  delete x2;
  delete y2;

  return 0;
}