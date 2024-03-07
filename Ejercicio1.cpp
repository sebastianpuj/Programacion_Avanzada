#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contacto {
    string nombre;
    int numMensajes;
    vector<string> mensajes;
};

vector<Contacto>* contactos = nullptr;

// Función para buscar un contacto por nombre
int buscarContacto(const string& nombre) {
    if (contactos == nullptr) {
        return -1;
    }

    for (int i = 0; i < contactos->size(); i++) {
        if ((*contactos)[i].nombre == nombre) {
            return i;
        }
    }

    return -1;
}

// Función para agregar un nuevo mensaje a un contacto existente o nuevo
void agregarMensaje(const string& nombreContacto, const string& mensaje) {
    int indiceContacto = buscarContacto(nombreContacto);

    if (indiceContacto == -1) {
        // El contacto no existe, se debe agregar uno nuevo
        Contacto nuevoContacto;
        nuevoContacto.nombre = nombreContacto;
        nuevoContacto.numMensajes = 1;
        nuevoContacto.mensajes.push_back(mensaje);

        if (contactos == nullptr) {
            contactos = new vector<Contacto>();
        }

        contactos->push_back(nuevoContacto);
        cout << "Se ha agregado un nuevo contacto: " << nombreContacto << endl;
    } else {
        // El contacto existe, se incrementa el número de mensajes y se agrega el nuevo mensaje
        (*contactos)[indiceContacto].numMensajes++;
        (*contactos)[indiceContacto].mensajes.push_back(mensaje);
        cout << "El contacto " << nombreContacto << " ya existe. Se ha incrementado el número de mensajes enviados." << endl;
    }

    cout << "Mensaje enviado: " << mensaje << endl;
}

int main() {
    string nombreContacto, mensaje;

    while (true) {
        cout << "Ingrese el nombre del contacto (o 'salir' para terminar): ";
        getline(cin, nombreContacto);

        if (nombreContacto == "salir") {
            break;
        }

        cout << "Ingrese el mensaje: ";
        getline(cin, mensaje);

        agregarMensaje(nombreContacto, mensaje);
    }

    // Imprimir la información almacenada en memoria
    for (const auto& contacto : *contactos) {
        cout << "Nombre de Contacto: " << contacto.nombre << endl;
        cout << "Numero de mensajes enviados: " << contacto.numMensajes << endl;
        cout << "Mensajes enviados:" << endl;
        for (const auto& mensaje : contacto.mensajes) {
            cout << "- " << mensaje << endl;
        }
        cout << endl;
    }

    delete contactos;
    return 0;
}