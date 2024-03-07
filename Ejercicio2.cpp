#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Paciente {
    int cedula;
    char maxSistolica[10];
    char maxDiastolica[10];
    char advertencia[30];
};

void leerArchivo(Paciente** &pacientes, int &numPacientes) {
    ifstream archivo("medidas.txt");
    string linea;
    numPacientes = 0;

    while (getline(archivo, linea)) {
        numPacientes++;
    }

    archivo.clear();
    archivo.seekg(0, ios::beg);
    pacientes = new Paciente*[numPacientes];

    for (int i = 0; i < numPacientes; i++) {
        getline(archivo, linea, '\n');
        pacientes[i] = new Paciente;
        char* token = strtok(const_cast<char*>(linea.c_str()), ";");
        pacientes[i]->cedula = atoi(token);

        int maxSistolica = 0, maxDiastolica = 0;
        char* maxSistolicaStr = nullptr, *maxDiastolicaStr = nullptr;

        while ((token = strtok(nullptr, ";"))) {
            char* guion = strchr(token, '-');
            *guion = '\0';
            int sistolica = atoi(token);
            int diastolica = atoi(guion + 1);

            if (sistolica > maxSistolica) {
                maxSistolica = sistolica;
                maxSistolicaStr = token;
            }

            if (diastolica > maxDiastolica) {
                maxDiastolica = diastolica;
                maxDiastolicaStr = guion + 1;
            }
        }

        strcpy(pacientes[i]->maxSistolica, maxSistolicaStr);
        strcpy(pacientes[i]->maxDiastolica, maxDiastolicaStr);

        if (maxSistolica > 140 || maxDiastolica > 95) {
            strcpy(pacientes[i]->advertencia, "ADVERTENCIA");
        } else if ((maxSistolica >= 130 && maxSistolica <= 140) || (maxDiastolica >= 90 && maxDiastolica <= 95)) {
            strcpy(pacientes[i]->advertencia, "SEGUIMIENTO");
        } else {
            pacientes[i]->advertencia[0] = '\0';
        }
    }

    archivo.close();
}

void escribirArchivoBinario(Paciente** pacientes, int numPacientes) {
    ofstream archivo("Pacientes.dat", ios::binary);

    for (int i = 0; i < numPacientes; i++) {
        archivo.write(reinterpret_cast<char*>(&pacientes[i]->cedula), sizeof(int));
        archivo.write(pacientes[i]->maxSistolica, sizeof(char) * 10);
        archivo.write(pacientes[i]->maxDiastolica, sizeof(char) * 10);
        archivo.write(pacientes[i]->advertencia, sizeof(char) * 30);
    }

    archivo.close();
}

int main() {
    Paciente** pacientes;
    int numPacientes;

    leerArchivo(pacientes, numPacientes);
    escribirArchivoBinario(pacientes, numPacientes);

    for (int i = 0; i < numPacientes; i++) {
        delete pacientes[i];
    }
    delete[] pacientes;

    return 0;
}