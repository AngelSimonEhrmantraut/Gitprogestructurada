/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 07/02/2024
PROGRAMA: Fibonacci
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Elaborar la serie Fibonacci utilizando los 3 ciclos básicos for, while y do-while
*******************************************************************************/
#include <iostream>
// Función que imprime la serie Fibonacci hasta un límite utilizando un ciclo for
void fibonacciFor(int limite) {
    int a = 0, b = 1, c = 0;
    for (; c <= limite; c = a + b) {
        std::cout << c << " ";
        a = b;
        b = c;
    }
}
// Función que imprime la serie Fibonacci hasta un límite utilizando un ciclo while
void fibonacciWhile(int limite) {
    int a = 0, b = 1, c = 0;
    while (c <= limite) {
        std::cout << c << " ";
        a = b;
        b = c;
        c = a + b;
    }
}
// Función que imprime la serie Fibonacci hasta un límite utilizando un ciclo do-while
void fibonacciDoWhile(int limite) {
    int a = 0, b = 1, c = 0;
    do {
        std::cout << c << " ";
        a = b;
        b = c;
        c = a + b;
    } while (c <= limite);
}
int main() {
    int limite, opcion;
    bool salir = false;
    // Ciclo principal del programa
    while (!salir) {
        // Solicita al usuario el límite para la serie Fibonacci
        std::cout << "Ingrese el límite para la serie Fibonacci: ";
        std::cin >> limite;
        // Solicita al usuario el tipo de ciclo que desea utilizar
        std::cout << "Elija el ciclo con el que desea trabajar:\n";
        std::cout << "1. For\n2. While\n3. Do-while\n4. Salir\n";
        std::cin >> opcion;
        // Ejecuta la función correspondiente según la opción seleccionada por el usuario
        switch (opcion) {
            case 1:
                fibonacciFor(limite);
                break;
            case 2:
                fibonacciWhile(limite);
                break;
            case 3:
                fibonacciDoWhile(limite);
                break;
            case 4:
                salir = true;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
        std::cout << "\n";
    }
    return 0;
}
