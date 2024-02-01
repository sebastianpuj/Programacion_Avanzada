/*Se desca registrar una estructura PersonaEmpleado que contenga como miembros los datos de una persona el salario y el número de horas trabajadas por semana. Una persona, a su vez. es otra estructura que tiene como miembros el nombre, la edad, la altura, el peso, y la fecha de nacimiento. Por su parte, la fecha de nacimiento es otra estructura que contiene el día, el mes y el año. Escribir funciones para leer y escribir un empleado de tipo PersonaEmpleado.*/

#include <iostream>
#include <string>

struct Fecha {
    int dia;
    int mes;
    int year;
}; 

struct Persona {
    std::string nombre;
    int edad;
    float altura;
    float peso;
    Fecha fechaNacimiento;
}; 

struct PersonaEmpleado {
    Persona persona;
    float salario;
    int horasTrabajadasPorSemana;
}; 

PersonaEmpleado leerEmpleado() {
    PersonaEmpleado empleado;

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, empleado.persona.nombre);

    std::cout << "Ingrese la edad: ";
    std::cin >> empleado.persona.edad;

    std::cout << "Ingrese la altura: ";
    std::cin >> empleado.persona.altura;

    std::cout << "Ingrese el peso: ";
    std::cin >> empleado.persona.peso;

    std::cout << "Ingrese el dia de nacimiento: ";
    std::cin >> empleado.persona.fechaNacimiento.dia;

    std::cout << "Ingrese el mes de nacimiento: ";
    std::cin >> empleado.persona.fechaNacimiento.mes;

    std::cout << "Ingrese el año de nacimiento: ";
    std::cin >> empleado.persona.fechaNacimiento.year;

    std::cout << "Ingrese el salario: ";
    std::cin >> empleado.salario;

    std::cout << "Ingrese el numero de horas trabajadas: ";
    std::cin >> empleado.horasTrabajadasPorSemana;

    return empleado;
}

void escribirEmpleado(const PersonaEmpleado& empleado) {
    std::cout << "Nombre: " << empleado.persona.nombre << std::endl;
    std::cout << "Edad: " << empleado.persona.edad << std::endl;
    std::cout << "Altura: " << empleado.persona.altura << std::endl;
    std::cout << "Peso: " << empleado.persona.peso << std::endl;
    std::cout << "Fecha de nacimiento: " << empleado.persona.fechaNacimiento.dia << "/"
              << empleado.persona.fechaNacimiento.mes << "/"
              << empleado.persona.fechaNacimiento.year << std::endl;
    std::cout << "Salario: " << empleado.salario << std::endl;
    std::cout << "Horas trabajadas: " << empleado.horasTrabajadasPorSemana << std::endl;
}

int main() {
    PersonaEmpleado empleado = leerEmpleado();
    escribirEmpleado(empleado);

    return 0; 

}