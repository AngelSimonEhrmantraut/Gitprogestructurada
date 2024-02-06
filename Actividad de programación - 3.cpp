/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 06/02/2024
PROGRAMA: Aumento de números
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Dependiendo el número insertado se realizan ciertos aumentos del número
*******************************************************************************/
#include <iostream>
using namespace std;
int main() {
    int numero; // el número que ingresa el usuario
    int contador = 0; // el contador de las veces que se realizó una operación
    char opcion; // la opción para terminar o continuar el programa
    bool salir = false; // la bandera para salir del ciclo
    do {
        cout << "Ingrese un número: ";
        cin >> numero;
        if (numero > 0 && numero < 500) {
            for (int i = 0; i < 100; i++) {  // subir de 5 en 5, 100 veces
                numero += 5;
                cout << "El valor actual es: " << numero << endl;
                contador++;
            }
        } else if (numero > 500 && numero < 1000) {
            for (int i = 0; i < 50; i++) {   // subir de 10 en 10, 50 veces
                numero += 10;
                cout << "El valor actual es: " << numero << endl;
                contador++;
            }
        } else if (numero > 1000) {
            cout << "No se puede calcular el valor" << endl; // no se puede calcular el valor
        } else {
            cout << "El número debe ser mayor a 0" << endl;
        }
        cout << "Se realizaron " << contador << " operaciones" << endl;
        cout << "¿Desea terminar el programa? (S/N): ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's') {
            // salir del programa
            salir = true;
        } else {
            // continuar
            salir = false;
            contador = 0; // reiniciar
        }
    } while (!salir);
    cout << "Fin" << endl;
    return 0;
}
