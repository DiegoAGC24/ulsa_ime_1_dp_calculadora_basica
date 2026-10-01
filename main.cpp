// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué funciones trae ahora utilerias.h? ¿Qué devuelve cada una?
#include "utilerias.h"

int main() {

    // Variables (siempre inicializadas)
    int opcion = 0;
    double a = 0;
    double b = 0;
    double resultado = 0;
    char simbolo = ' ';

    // Paso 1
    std::cout << "Calculadora basica\n";

    // Paso 2
    std::cout << "1) Suma\n";
    std::cout << "2) Resta\n";
    std::cout << "3) Multiplicacion\n";
    std::cout << "4) Division\n";

    // Paso 3
    do {
        opcion = leerEntero("Elige una opcion (1-4): ");

        if (opcion < 1 || opcion > 4) {
            std::cout << "Opcion no valida, elige un numero del 1 al 4\n";
        }

    } while (opcion < 1 || opcion > 4);

    // Pasos 4 y 5
    a = leerDecimal("Primer numero: ");
    b = leerDecimal("Segundo numero: ");

    // Paso 6
    if (opcion == 4) {
        while (b == 0) {
            std::cout << "No se puede dividir entre cero\n";
            b = leerDecimal("Segundo numero (distinto de 0): ");
        }
    }

    // Paso 7
    switch (opcion) {

        case 1:
            resultado = a + b;
            simbolo = '+';
            break;

        case 2:
            resultado = a - b;
            simbolo = '-';
            break;

        case 3:
            resultado = a * b;
            simbolo = '*';
            break;

        case 4:
            resultado = a / b;
            simbolo = '/';
            break;

        default:
            std::cout << "Opcion inesperada\n";
            break;
    }

    // Paso 8
    std::cout << a << " " << simbolo << " " << b << " = " << resultado << "\n";

    return 0;
}