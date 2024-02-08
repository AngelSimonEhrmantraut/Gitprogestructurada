/******************************************************************************
NOMBRE: Angel Sim�n Navarro Mart�n
FECHA: 07/02/2024
PROGRAMA: Fibonacci
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIER�A EN COMPUTACI�N / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCI�N: Elaborar la serie Fibonacci utilizando los 3 ciclos b�sicos for, while y do-while
*******************************************************************************/
#include <iostream>
// Funci�n que imprime la serie Fibonacci hasta un l�mite utilizando un ciclo for
void fibonacciFor(int limite) {
    int a = 0, b = 1, c = 0;
    for (; c <= limite; c = a + b) {
        std::cout << c << " ";
        a = b;
        b = c;
    }
}
// Funci�n que imprime la serie Fibonacci hasta un l�mite utilizando un ciclo while
void fibonacciWhile(int limite) {
    int a = 0, b = 1, c = 0;
    while (c <= limite) {
        std::cout << c << " ";
        a = b;
        b = c;
        c = a + b;
    }
}
// Funci�n que imprime la serie Fibonacci hasta un l�mite utilizando un ciclo do-while
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
        // Solicita al usuario el l�mite para la serie Fibonacci
        std::cout << "Ingrese el l�mite para la serie Fibonacci: ";
        std::cin >> limite;
        // Solicita al usuario el tipo de ciclo que desea utilizar
        std::cout << "Elija el ciclo con el que desea trabajar:\n";
        std::cout << "1. For\n2. While\n3. Do-while\n4. Salir\n";
        std::cin >> opcion;
        // Ejecuta la funci�n correspondiente seg�n la opci�n seleccionada por el usuario
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
                std::cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
        std::cout << "\n";
    }
    return 0;
}
