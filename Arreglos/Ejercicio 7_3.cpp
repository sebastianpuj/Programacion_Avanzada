//Ejercicio 7.3
#include <iostream>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Función para sumar días a una fecha
Fecha sumarDias(Fecha fechaInicial, int diasParaSumar) {
    // Añadimos los días
    fechaInicial.dia += diasParaSumar;

    // Ajustamos los días y los meses
    while (fechaInicial.dia > 30) {  // Suponemos que todos los meses tienen 30 días para simplificar
        fechaInicial.dia -= 30;
        fechaInicial.mes++;

        if (fechaInicial.mes > 12) {
            fechaInicial.mes = 1;
            fechaInicial.anio++;
        }
    } 

    // Devolvemos la nueva fecha calculada
    return fechaInicial;
}