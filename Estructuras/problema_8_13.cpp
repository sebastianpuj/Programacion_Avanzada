/*Una librería desea tener el inventario de libros. Para ello quiere crear una base de datos en la que se almacenan la siguiente información por libro: título del libro: la fecha de pu-blicación; el autor; el número total de libros existentes; el número total de libros existentes en pedidos; el precio de venta. Escribir funciones que permitan leer los datos de la base de datos y visualizar la base de datos.*/

#include <iostream>
#include <vector>
#include <string>

struct Libro {
    std::string titulo;
    std::string fechaPublicacion;
    std::string autor;
    int totalLibros;
    int totalPedidos;
    double precio;
};

Libro leerLibro() {
    Libro libro;
    std::cout << "Ingrese el titulo: ";
    std::getline(std::cin, libro.titulo);
    std::cout << "Ingrese la fecha de publicacion: ";
    std::getline(std::cin, libro.fechaPublicacion);
    std::cout << "Ingrese el nombre del autor: ";
    std::getline(std::cin, libro.autor);
    std::cout << "Ingrese el número de libros existentes: ";
    std::cin >> libro.totalLibros;
    std::cout << "Ingrese el número de libros en pedidos: ";
    std::cin >> libro.totalPedidos;
    std::cout << "Ingrese el precio: ";
    std::cin >> libro.precio;
    return libro;
}

void visualizarBaseDatos(const std::vector<Libro>& baseDatos) {
    for (const auto& libro : baseDatos) {
        std::cout << "Titulo: " << libro.titulo << "\n";
        std::cout << "Fecha de publicacion: " << libro.fechaPublicacion << "\n";
        std::cout << "Autor: " << libro.autor << "\n";
        std::cout << "Total de libros existentes: " << libro.totalLibros << "\n";
        std::cout << "Total de libros en pedidos: " << libro.totalPedidos << "\n";
        std::cout << "Precio de venta: " << libro.precio << "\n\n";
    }
}

int main() {
    std::vector<Libro> baseDatos;
    int numLibros;
    std::cout << "Numero de libros a ingresar: ";
    std::cin >> numLibros;

    for (int i = 0; i < numLibros; ++i) {
        std::cout << "\nIngrese datos libro " << i + 1 << ":\n";
        baseDatos.push_back(leerLibro());
    }

    std::cout << "\nBase de datos final:\n";
    visualizarBaseDatos(baseDatos);

    return 0;
}