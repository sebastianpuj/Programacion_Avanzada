#include <iostream> //Libreria de entrada y salida de datos
using namespace std; //Libreria para usar cout y cin

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos en la lista: ";
    cin >> n;
    int arr[n]; // Declaración del arreglo
    for(int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arr[i];
    }// Lectura de los elementos de la lista
    int max = arr[0];
    for(int i = 1; i < n; i++) { // Bucle para recorrer los elementos del arreglo
        if(arr[i] > max) {
            max = arr[i];
        } // Encontrar el elemento máximo en la lista
    }
    cout << "El número mayor en la lista es: " << max << endl;
    return 0;
}
