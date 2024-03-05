#include <iostream>
using namespace std;

int main() {
    int matriz[9][9];
  
    int contador = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            matriz[i][j] = contador;
            contador++;
        }
    }

    cout << "Matriz 9x9:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
