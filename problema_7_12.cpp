#include <iostream>
#include <vector>

using namespace std;

bool seguro(vector<vector<int>>& tablero, int fila, int columna, int N) {
    for (int i = 0; i < columna; i++)
        if (tablero[fila][i])
            return false;
  
    for (int i = fila, j = columna; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j])
            return false;

    for (int i = fila, j = columna; i < N && j >= 0; i++, j--)
        if (tablero[i][j])
            return false;

    return true;
}

bool resolver(vector<vector<int>>& tablero, int columna, int N) {
  
    if (columna >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (seguro(tablero, i, columna, N)) {
            tablero[i][columna] = 1;

            if (resolver(tablero, columna + 1, N))
                return true;

            tablero[i][columna] = 0;
        }
    }
    return false;
}

void reinas(int N) {
    // Crear un tablero de tamaño N x N iniciándolo con 0
    vector<vector<int>> tablero(N, vector<int>(N, 0));

    if (resolver(tablero, 0, N)) {
        cout << "La solución es: " << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << tablero[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No se encontró solución para " << N << " reinas." << endl;
    }
}

int main() {
    int N;
    cout << "Escriba el número de reinas (tamaño del tablero): ";
    cin >> N;
    reinas(N);
    return 0;
}