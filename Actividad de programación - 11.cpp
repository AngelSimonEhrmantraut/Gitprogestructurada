/******************************************************************************
NOMBRE: Ángel Simón Navarro Martín
FECHA: 19/03/2024
PROGRAMA:Arreglo de punteros
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Realizar un arreglo de punteros
*******************************************************************************/
#include <iostream>
#include <cctype> // Para la función isdigit
using namespace std;

const int valMaximos = 50;
int valores[valMaximos];// Arreglo para almacenar los valores
int* punteroValores[valMaximos]; // Arreglo de punteros para los valores
int cantidadValores = 0; // Contador de la cantidad de valores ingresados

// Función para validar si un string representa un número entero
bool esEntero(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) { //isdigit es una función que toma un carácter como argumento  (true o false). Devuelve true si el carácter es un dígito decimal.
            return false; // Si encuentra un carácter que no es un dígito, retorna false
        }
    }
    return true; // Si todos los caracteres son dígitos, retorna true
}

// Función para insertar un valor en el arreglo ordenadamente
void insertarValor(int valor) {
    if (cantidadValores >= valMaximos) {
        cout << "Se ha alcanzado el maximo de valores permitidos." << endl;
        return;
    }

    int indice = 0;
    // Buscar la posición adecuada para insertar el valor
    while (indice < cantidadValores && *punteroValores[indice] < valor) {
        indice++;
    }
    // Si el valor ya esta en el arreglo, mostrar mensaje y salir
    if (indice < cantidadValores && *punteroValores[indice] == valor) {
        cout << "El valor " << valor << " ya esta insertado." << endl;
        return;
    }
    // Desplazar los punteros para hacer espacio para el nuevo valor
    for (int i = cantidadValores; i > indice; i--) {
        punteroValores[i] = punteroValores[i - 1];
    }
    // Insertar el puntero al nuevo valor en la posición correcta
    punteroValores[indice] = &valores[cantidadValores];
    // Almacenar el nuevo valor
    valores[cantidadValores] = valor;
    cantidadValores++;
    cout << "Valor insertado correctamente." << endl;
}
// Función para imprimir los valores
void imprimirValores() {
    cout << "Valores insertados ordenados:" << endl;
    for (int i = 0; i < cantidadValores; i++) {
        cout << *punteroValores[i] << " ";
    }
    cout << endl;
}

int main() {
    // Inicializar los punteros
    for (int i = 0; i < valMaximos; i++) {
        punteroValores[i] = &valores[i];
    }

    cout << "Ingrese valores enteros. Ingrese 'p' para imprimir o 'q' para salir." << endl;
    string entrada;
    while (true) {
        // Salir si se alcanza el maximo de valores
        if (cantidadValores >= valMaximos) {
            cout << "Se ha alcanzado el maximo de valores permitidos." << endl;
            cout << "Ingrese 'p' para imprimir los valores o 'q' para salir: ";
        } else {
            cout << "Ingrese un valor: ";
        }
        cin >> entrada;
        // Salir si se ingresa 'q'
        if (entrada == "q") {
            break;
        }
        // Imprimir los valores si se ingresa 'p'
        if (entrada == "p") {
            imprimirValores();
            continue;
        }
        // Validar si la entrada es un número entero
        if (!esEntero(entrada)) {
            cout << "Solo se pueden agregar numeros enteros." << endl;
            continue;
        }
        // Convertir la entrada a entero
        int valor = stoi(entrada);
         // Insertar el valor en el arreglo
        insertarValor(valor);
    }

    return 0;
}


