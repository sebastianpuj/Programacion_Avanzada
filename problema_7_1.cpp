#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
 unordered_map<char, int> maparomano = {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}

  };
  int resultado = 0;
  int valoranterior=0;

for (int i=s.size()-1; i>= 0; i--){
  int valoractual = maparomano[s[i]];
  if (valoractual < valoranterior){
    resultado -= valoractual;
  } else { 
    resultado += valoractual;
  }
  valoranterior = valoractual;
}
  return resultado;
}
  
int main() {
  string numeroRomano;
  cout << "Ingrese un número romano: ";
  cin >> numeroRomano;

  cout << "El número romano equivale a: " << romanToInt(numeroRomano)<<endl;

  return 0;
} 