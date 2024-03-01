#include <fstream>
#include <iostream>
#include <map>
#include <string>

// Estructura para almacenar la información de cada venta
struct Venta {
    std::string local;
    std::string tipoProducto;
    int ventaAnual;
};

int main() {
    // Abrir el archivo de ventas
    std::ifstream archivo("ventas.dat");
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo 'ventas.dat'.\n";
        return 1;
    }

    // Mapa para almacenar la información de las ventas
    std::map<std::string, std::map<std::string, int>> ventas;

    // Leer las ventas del archivo
    Venta venta;
    while (archivo >> venta.local >> venta.tipoProducto >> venta.ventaAnual) {
        ventas[venta.local][venta.tipoProducto] += venta.ventaAnual;
    }

    // Cerrar el archivo de ventas
    archivo.close();

    // Abrir el archivo de salida
    std::ofstream salida("b.txt");
    if (!salida) {
        std::cerr << "No se pudo abrir el archivo 'b.txt'.\n";
        return 1;
    }

    // Escribir las ventas en el archivo de salida
    for (const auto& local : ventas) {
        for (const auto& tipoProducto : local.second) {
            salida << "Local: " << local.first
                   << ", Tipo de producto: " << tipoProducto.first
                   << ", Venta anual: " << tipoProducto.second << '\n';
        }
    }

    // Cerrar el archivo de salida
    salida.close();

    return 0;
}