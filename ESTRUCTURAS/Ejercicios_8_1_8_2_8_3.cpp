#include <iostream> //Incluimos la librería iostream para usar la función cout y cin.
#include <string> //Incluimos la librería string para usar la función string.

using namespace std;

// Definición de la estructura Cliente
struct Cliente {
    string nombre; 
    int unidadesSolicitadas;
    double precioPorUnidad; // Cambiamos el tipo de dato a double para representar el precio.
    string estado;
}; 

// Función para mostrar la factura de un cliente
void mostrarFactura(const Cliente& cliente) { 
    cout << "Nombre: " << cliente.nombre << endl;
    cout << "Unidades solicitadas: " << cliente.unidadesSolicitadas << endl;
    cout << "Precio por unidad: $" << cliente.precioPorUnidad << endl;
    cout << "Estado: " << cliente.estado << endl;
    cout << "Total a pagar: $" << cliente.unidadesSolicitadas * cliente.precioPorUnidad << endl;
    cout << "---------------------------------------" << endl;
}

// Función para mostrar la factura de todos los clientes de una categoría específica
void mostrarFacturasPorEstado(const Cliente clientes[], int numClientes, const string& estadoBuscado) {
    cout << "Facturas de clientes con estado '" << estadoBuscado << "':" << endl;

    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].estado == estadoBuscado) {
            mostrarFactura(clientes[i]); // Llamamos a la función mostrarFactura para mostrar la factura del cliente.
        }
    } 
}

// Función para mostrar la factura de clientes morosos con factura inferior a una cantidad
void morosoMenor(const Cliente clientes[], int numClientes, double cantidadLimite) {
    cout << "Clientes morosos con factura inferior a $" << cantidadLimite << ":" << endl;

    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].estado == "moroso" && (clientes[i].unidadesSolicitadas * clientes[i].precioPorUnidad) < cantidadLimite) {
            mostrarFactura(clientes[i]); // Llamamos a la función mostrarFactura para mostrar la factura del cliente.
        }
    }
}

// Función para mostrar la factura de clientes pagados con factura mayor a una cantidad
void pagadoMayor(const Cliente clientes[], int numClientes, double cantidadLimite) {
    cout << "Clientes pagados con factura mayor a $" << cantidadLimite << ":" << endl;

    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].estado == "pagado" && (clientes[i].unidadesSolicitadas * clientes[i].precioPorUnidad) > cantidadLimite) { 
            mostrarFactura(clientes[i]);
        }
    }
}

int main() {
    int numClientes;

    cout << "Ingrese la cantidad de clientes: ";
    cin >> numClientes;

    // Validar entrada
    while (numClientes <= 0) {
        cout << "Por favor, ingrese una cantidad válida de clientes (mayor a 0): ";
        cin >> numClientes;
    }

    // Limpiar el buffer de entrada
    cin.ignore();

    // Crear un arreglo de clientes
    Cliente clientes[numClientes];

    // Leer la información de los clientes
    for (int i = 0; i < numClientes; ++i) {
        cout << "Ingrese la información del cliente " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        getline(cin, clientes[i].nombre); // Usamos getline para leer el nombre completo.

        cout << "Unidades solicitadas: ";
        cin >> clientes[i].unidadesSolicitadas;

        cout << "Precio por unidad: ";
        cin >> clientes[i].precioPorUnidad;

        cout << "Estado (moroso, atrasado, pagado): ";
        cin >> clientes[i].estado;

        // Limpiar el buffer de entrada
        cin.ignore(); 

        cout << "---------------------------------------" << endl;
    }

    // Mostrar la factura de todos los clientes morosos
    mostrarFacturasPorEstado(clientes, numClientes, "moroso");

    // Mostrar la factura de todos los clientes atrasados
    mostrarFacturasPorEstado(clientes, numClientes, "atrasado");

    // Mostrar la factura de todos los clientes pagados
    mostrarFacturasPorEstado(clientes, numClientes, "pagado");

    // Solicitar una cantidad límite para filtrar clientes morosos
    double cantidadLimiteMoroso;
    cout << "Ingrese la cantidad límite para clientes morosos: $";
    cin >> cantidadLimiteMoroso;

    // Mostrar clientes morosos con factura inferior a la cantidad límite
    morosoMenor(clientes, numClientes, cantidadLimiteMoroso);

    // Solicitar una cantidad límite para filtrar clientes pagados
    double cantidadLimitePagado;
    cout << "Ingrese la cantidad límite para clientes pagados: $";
    cin >> cantidadLimitePagado;

    // Mostrar clientes pagados con factura mayor a la cantidad límite
    pagadoMayor(clientes, numClientes, cantidadLimitePagado);

    return 0;
}
