#include<iostream> //Libreria de entrada y salida de datos
using namespace std; //Libreria para usar cout y cin

int main() { // Funcion principal
    // Declaración de variables
    int filas, columnas; // Variables para almacenar el número de filas y columnas de la matriz

    // Solicitar al usuario las dimensiones de la matriz
    cout << "Ingrese el número de filas de la matriz: "; Ej
    cin >> filas; // Lectura del número de filas ingresado por el usuario
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> columnas; // Lectura del número de columnas ingresado por el usuario

    // Declarar la matriz con las dimensiones proporcionadas
    int matriz[filas][columnas]; // Declaración de la matriz

    // Leer la matriz desde el usuario
    cout << "Ingrese los elementos de la matriz:" << endl; // Mensaje para solicitar los elementos de la matriz
    for (int i = 0; i < filas; ++i) { // Bucle para recorrer las filas de la matriz
        for (int j = 0; j < columnas; ++j) { //
            cout << "Elemento [" << i << "][" << j << "]: "; // Mensaje para solicitar el elemento en la posición [i][j]
            cin >> matriz[i][j]; // Lectura del elemento ingresado por el usuario
        }
    }

    // Inicializar el mayor y menor con el primer elemento de la matriz
    int mayor = matriz[0][0]; // Variable para almacenar el mayor elemento de la matriz
    int menor = matriz[0][0]; // Variable para almacenar el menor elemento de la matriz
    int posMayorFila = 0, posMayorColumna = 0; // Variables para almacenar la posición del mayor elemento
    int posMenorFila = 0, posMenorColumna = 0; // Variables para almacenar la posición del menor elemento

    // Encontrar el mayor y menor elemento de la matriz y sus posiciones
    for (int i = 0; i < filas; ++i) { // Bucle para recorrer las filas de la matriz
        for (int j = 0; j < columnas; ++j) { // Bucle para recorrer las columnas de la matriz
            if (matriz[i][j] > mayor) { // Comparar si el elemento actual es mayor que el mayor
                mayor = matriz[i][j]; // Actualizar el mayor elemento
                posMayorFila = i; // Actualizar la posición del mayor elemento en la fila
                posMayorColumna = j; // Actualizar la posición del mayor elemento en la columna
            }
            if (matriz[i][j] < menor) { // Comparar si el elemento actual es menor que el menor
                menor = matriz[i][j]; // Actualizar el menor elemento
                posMenorFila = i; // Actualizar la posición del menor elemento en la fila
                posMenorColumna = j; // Actualizar la posición del menor elemento en la columna
            }
        }
    }

    // Mostrar la matriz ingresada por el usuario
    cout << "\nMatriz ingresada:" << endl; // Mensaje para mostrar la matriz ingresada
    for (int i = 0; i < filas; ++i) { // Bucle para recorrer las filas de la matriz
        for (int j = 0; j < columnas; ++j) { // Bucle para recorrer las columnas de la matriz
            cout << matriz[i][j] << " "; // Mostrar el elemento actual de la matriz
        }
        cout << endl; // Salto de línea para separar las filas
    }

    // Mostrar el mayor y sus posiciones
    cout << "\nEl mayor elemento de la matriz es " << mayor << " en la posición [" << posMayorFila << "][" << posMayorColumna << "]" << endl; // Mensaje para mostrar el mayor elemento y sus posiciones
  

    // Mostrar el menor y sus posiciones
    cout << "El menor elemento de la matriz es " << menor << " en la posición [" << posMenorFila << "][" << posMenorColumna << "]" << endl; // Mensaje para mostrar el menor elemento y sus posiciones

    return 0;
}
