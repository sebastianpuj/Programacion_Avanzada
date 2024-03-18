#include <iostream>
#include <ctime>
#include <locale.h>
#include <fstream>

using namespace std;

const int MAX_FILAS = 10; // Tamaño máximo de filas
const int MAX_COLUMNAS = 10; // Tamaño máximo de columnas




struct Barco {
    int longitud;
    bool impactos[4]; // Indica si el barco ha sido impactado en cada posición (máximo 4 posiciones)
// Estructura para representar un barco
};

struct Tablero {

    char matriz[MAX_FILAS][MAX_COLUMNAS];
// Estructura para representar un tablero
};

void mostrarTablero(Tablero* tablero) {
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            cout << tablero->matriz[i][j] << " ";
        }
        cout << endl;
    }
// Función para mostrar el tablero en pantalla
}

void ModTableroVacio(Tablero* tablero, Tablero* tablero1) {
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
          if (tablero->matriz[i][j]=='X'){
              tablero1->matriz[i][j]='X';
          }
            cout << tablero1->matriz[i][j] << " ";
}
 cout << endl;
    }
// Función para mostrar el tablero en pantalla
}


void colocarBarcos(Tablero* tablero) {
    int barcosRestantes[] = {3, 3, 3}; // Barcos restantes por longitud: 2, 3, 4
    for (int i = 0; i < 3; i++) {
        int longitud = i + 2; // Longitud del barco (2, 3, 4)
        int barcosColocados = 0;
        while (barcosColocados < barcosRestantes[i]) {
            int fila, columna, direccion;
            cout << endl<< endl<< "Colocar barco de longitud " << longitud << " (Restantes: " << barcosRestantes[i] - barcosColocados << ")" << endl;
            cout << endl<< "Ingrese la fila y columna de la posición inicial (ejemplo: 0 0): "<< endl;
            cin >> fila >> columna;
            cout << endl<< "Ingrese la dirección (0 = horizontal, 1 = vertical): " << endl;
            cin >> direccion;
            bool sePuedeColocar = true;
            if (direccion == 0) { // Horizontal
                if (columna + longitud > MAX_COLUMNAS) {
                    sePuedeColocar = false;
                } else {
                    for (int j = columna; j < columna + longitud; j++) {
                        if (tablero->matriz[fila][j] != '.') {
                            sePuedeColocar = false;
                            break;
                        }
                    }
                }
            } else { // Vertical
                if (fila + longitud > MAX_FILAS) {
                    sePuedeColocar = false;
                } else {
                    for (int j = fila; j < fila + longitud; j++) {
                        if (tablero->matriz[j][columna] != '.') {
                            sePuedeColocar = false;
                            break;
                        }
                    }
                }
            }

            if (sePuedeColocar) {
                if (direccion == 0) { // Horizontal
                    for (int j = columna; j < columna + longitud; j++) {
                        tablero->matriz[fila][j] = 'B';
                    }
                } else { // Vertical
                    for (int j = fila; j < fila + longitud; j++) {
                        tablero->matriz[j][columna] = 'B';
                    }
                }
                barcosColocados++;
            } else {
                cout << "No se pueden colocar barcos en esa posición. Intente nuevamente." << endl;
}
}
}
// Función para colocar los barcos en el tablero del jugador
}

void colocarBarcosEnemigos(Tablero* tablero) {
    int matr;
srand(time(0)); // Inicializar la semilla para generar números aleatorios
int barcosRestantes[] = {3, 3, 3}; // Barcos restantes por longitud: 2, 3, 4
for (int i = 0; i < 3; i++) {
    int longitud = i + 2; // Longitud del barco (2, 3, 4)
    int barcosColocados = 0;
    while (barcosColocados < barcosRestantes[i]) {
        int fila = rand() % MAX_FILAS;
        int columna = rand() % MAX_COLUMNAS;
        int direccion = rand() % 2; // 0 = horizontal, 1 = vertical
        bool sePuedeColocar = true;
        if (direccion == 0) { // Horizontal
            if (columna + longitud > MAX_COLUMNAS) {
                sePuedeColocar = false;
            } else {
                for (int j = columna; j < columna + longitud; j++) {
                    if (tablero->matriz[fila][j] != '.') {
                        sePuedeColocar = false;
                        break;
                    }
                }
            }
        } else { // Vertical
            if (fila + longitud > MAX_FILAS) {
                sePuedeColocar = false;
            } else {
                for (int j = fila; j < fila + longitud; j++) {
                    if (tablero->matriz[j][columna] != '.') {
                        sePuedeColocar = false;
                        break;
                    }
                }
            }
        }

        if (sePuedeColocar) {
            if (direccion == 0) { // Horizontal
                for (int j = columna; j < columna + longitud; j++) {
                    tablero->matriz[fila][j] = 'E';
                }
            } else { // Vertical
                for (int j = fila; j < fila + longitud; j++) {
                    tablero->matriz[j][columna] = 'E';
                }
            }
            barcosColocados++;

             matr=tablero->matriz[fila][columna];
        }
    }

}
// Función para colocar los barcos enemigos de forma aleatoria
}

bool disparar(Tablero* tablero, int fila, int columna) {

if (tablero->matriz[fila][columna] == 'E') {
tablero->matriz[fila][columna] = 'X'; // Barco impactado
return true;
} else {
tablero->matriz[fila][columna] = 'O'; // Agua
return false;
// Función para disparar en una posición del tablero rival
}
}

bool dispararVacio(Tablero* tablero, int fila, int columna) {

if (tablero->matriz[fila][columna] == 'E') {
tablero->matriz[fila][columna] = 'X'; // Barco impactado
return true;
} else {
tablero->matriz[fila][columna] = 'O'; // Agua
return false;
// Función para disparar en una posición del tablero rival
}
}

void dispararAleatorio(Tablero* tablero) {
srand(time(0)); // Inicializar la semilla para generar números aleatorios
for (int i = 0; i < 3; i++) {
    int fila = rand() % MAX_FILAS;
    int columna = rand() % MAX_COLUMNAS;

    if (tablero->matriz[fila][columna] == 'B') {
        tablero->matriz[fila][columna] = 'X'; // Barco impactado
    } else {
        tablero->matriz[fila][columna] = 'O'; // Agua
}
}
// Función para que el oponente dispare aleatoriamente
}

bool barcosEnemigosDestruidos(Tablero* tablero) {

for (int i = 0; i < MAX_FILAS; i++) {
for (int j = 0; j < MAX_COLUMNAS; j++) {
if (tablero->matriz[i][j] == 'E') {

return false; // Aún hay barcos enemigos no destruidos
}
}
}
return true; // Todos los barcos enemigos han sido destruidos

// Función para verificar si todos los barcos enemigos han sido destruidos
}

bool barcosJugadorDestruidos(Tablero* tablero) {

    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (tablero->matriz[i][j] == 'B') {
                return false; // Aún hay barcos del jugador no destruidos
            }
        }
    }
 return true; // Todos los barcos del jugador han sido destruidos
// Función para verificar si todos los barcos enemigos han sido destruidos
}

void mostrarEstadoFinal(Tablero* tableroJugador, Tablero* tableroEnemigo) {
  std::ofstream archivo_salida_jugador("tablero_jugador_final.txt");
  std::ofstream archivo_salida_enemigo("tablero_enemigo_final.txt");

  cout << endl<< "Tablero del Jugador:" << endl;
  mostrarTablero(tableroJugador);
  cout << endl<< "Tablero del Enemigo:" << endl;
  mostrarTablero(tableroEnemigo);

  if (archivo_salida_jugador.is_open()) {
      for (int i = 0; i < MAX_FILAS; i++) {
          for (int j = 0; j < MAX_COLUMNAS; j++) {
              archivo_salida_jugador << tableroJugador->matriz[i][j] << " ";
          }
          archivo_salida_jugador << std::endl;
      }
      archivo_salida_jugador.close();
  } else {
      cout << "No se pudo abrir el archivo del jugador para escritura." << endl;
  }

  if (archivo_salida_enemigo.is_open()) {
      for (int i = 0; i < MAX_FILAS; i++) {
          for (int j = 0; j < MAX_COLUMNAS; j++) {
              archivo_salida_enemigo << tableroEnemigo->matriz[i][j] << " ";
          }
          archivo_salida_enemigo << std::endl;
      }
      archivo_salida_enemigo.close();
  } else {
      cout << "No se pudo abrir el archivo del enemigo para escritura." << endl;
  }
// Función para mostrar el estado final de los tableros
}

int main() {
setlocale(LC_ALL, "");
int opcion;
bool partidaFinalizada = false;
Tablero tableroJugador, tableroEnemigo, tableroVacio;
do {
    cout << endl<< "=== Batalla Naval ===" << endl;
    cout << "1. Instrucciones del juego" << endl;
    cout << "2. Iniciar partida" << endl;
    cout << "3. Salir del juego" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
cout << "=== Instrucciones del juego ===" << endl<<endl<<"Bienvenidos a la Batalla Naval ¿Estás Listo?"<<
           endl<<endl<<"Prepara tu mejor estrategia y recuerda no digas donde ubicaste tus barcos!"<<
           endl<<endl<<"Asimismo, vas a jugar contra la computadora. Por lo tanto, ojo con decir tus posiciones (las computadoras escuchan). Como jugador persona, debes tener en cuenta que debes ubicar tus barcos, recuerda que vas a ubicar 3 barcos de 3 posiciones, 3 barcos de 3 posiciones y 3 barcos de 4 posiciones. Apenas ubiques tus barcos, la computadora va a posicionar los suyos. "<<
           endl<<endl<<"Luego tendrás 3 disparos que podrás realizar aleatoriamente; Si aparece una “X”  le habrás dado a un barco ¡Enhorabuena! si aparece un círculo, abras dado únicamente al agua, sigue intentando. Ganará el primero en haberle dado a todos los barcos."<<
           endl<<endl<<"Antes de jugar, unas reglas para tener en cuenta:"<<
           endl<<endl<<"No puedes ubicar dos barcos en la misma casilla, recuerda tener en mente cuáles fueron las posiciones de los barcos que ya has ubicado."<<
           endl<<endl<<"El juego va a acabar hasta que alguien descubra todos los barcos de la otra persona. Los barcos van a ir en casillas consecutivas, es decir, apenas pongas la primera casilla y tengas la dirección del barco debes mantener la dirección."<<
           endl<<endl<<"Ahora que tienes claras estas instrucciones…"<<endl<<" ---------¡A JUGAR!--------- "<<endl<<endl;
            break;

        case 2:
            cout << endl<< endl<< "=== Iniciar partida ===" << endl;
            // Inicializar tableros
            for (int i = 0; i < MAX_FILAS; i++) {
                for (int j = 0; j < MAX_COLUMNAS; j++) {
                    tableroJugador.matriz[i][j] = '.';
                    tableroEnemigo.matriz[i][j] = '.';
                    tableroVacio.matriz[i][j] = '.';
                    }
                }

            // Colocar barcos del jugador
            colocarBarcos(&tableroJugador);

            // Colocar barcos enemigos
            colocarBarcosEnemigos(&tableroEnemigo);

            while (!partidaFinalizada) {

                // Turno del jugador

                int fila, columna;

                cout << endl<< "=== Turno del Jugador ===" << endl<< endl;
                cout << endl<< "Tablero del Jugador:" << endl<< endl;
                mostrarTablero(&tableroJugador);


                cout << endl<< "Ingrese la fila y columna a disparar (ejemplo: 0 0): "<< endl;
                cin >> fila >> columna;

                bool impacto = disparar(&tableroEnemigo, fila, columna);
                bool impacto2 = disparar(&tableroVacio, fila, columna);


               if (impacto) {
                 cout << endl<< endl<< "¡Barco impactado!" << endl;
    }

    else {
                 cout << endl<< endl<< "Agua..." << endl;
    }

    cout << endl<< "Tablero del Enemigo:" << endl<< endl;





                ModTableroVacio(&tableroEnemigo, &tableroVacio);

            cout << endl;

            mostrarTablero(&tableroEnemigo);


            if (barcosEnemigosDestruidos(&tableroEnemigo)) {



            cout << endl<< endl<< endl<< "¡Felicidades, has ganado la partida!" << endl;

            partidaFinalizada = true;

            break;
            }




                // Turno del enemigo

                cout << endl<< "=== Turno del Enemigo ===" << endl;
                dispararAleatorio(&tableroJugador);

                cout << endl<< "El enemigo ha realizado sus disparos." << endl;




                if (barcosJugadorDestruidos(&tableroJugador)) {

                    cout << endl<< endl<< "¡Has perdido la partida!" << endl;
                    partidaFinalizada = true;
                    break;





                cout << endl<< "Tablero del Enemigo:" << endl<< endl;
                ModTableroVacio(&tableroEnemigo, &tableroVacio);
                }
     }



            // Mostrar estado final de los tableros

            cout << endl<< endl<< endl<< "=== Estado final ===" << endl;
            mostrarEstadoFinal(&tableroJugador, &tableroEnemigo);

            break;





        case 3:
            cout << "Saliendo del juego..." << endl;
            break;

        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;


}
}

while (opcion != 3);

return 0;

}