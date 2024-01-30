#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos en la lista: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arr[i];
    }
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "El número mayor en la lista es: " << max << endl;
    return 0;
}
