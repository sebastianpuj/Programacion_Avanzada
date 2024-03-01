#include <iostream>
#include <cstring>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Producto {
    char NombreTienda[100];
    char URLTienda[200];
    char NombreProducto[300];
    Fecha FechaVigenciaPromocion; //Formato dd/mm/yyyy
    double Precio;
};

// Función para comparar dos cadenas
int compararCadenas(const char* cadena1, const char* cadena2) {
    return strcmp(cadena1, cadena2);
}

// Función para buscar un producto
Producto* buscarProducto(Producto* productos, int numProductos, const char* nombreProducto) {
    for (int i = 0; i < numProductos; ++i) {
        if (compararCadenas(productos[i].NombreProducto, nombreProducto) == 0) {
            return &productos[i];
        }
    }
    return nullptr;
}

// Función principal
int main() {
    // Crear algunos productos
    Producto productos[3] = {
        {"Tiendas Jupiter", "www.jupiter.com", "Parlantes tipo 1", {30, 3, 2023}, 175000},
        {"Yaleo", "www.yaleo.com", "Plantas marca s", {13, 2, 2023}, 40000},
        {"Logro", "www.logro.com", "Parlantes tipo 1", {28, 3, 2023}, 172000}
    };

    // Buscar un producto
    Producto* producto = buscarProducto(productos, 3, "Parlantes tipo 1");
    if (producto != nullptr) {
        std::cout << "Producto encontrado: " << producto->NombreProducto << std::endl;
    } else {
        std::cout << "Producto no encontrado" << std::endl;
    }

    return 0;
}