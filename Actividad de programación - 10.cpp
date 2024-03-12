/******************************************************************************
NOMBRE: Angel Sim�n Navarro Mart�n
FECHA: 11/03/2024
PROGRAMA: Calculadora de matrices
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIER�A EN COMPUTACI�N / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCI�N: Calculadora de suma, resta, multiplicaci�n y divisi�n de 2 matrices
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Funci�n para imprimir una matriz
void imprimirMatriz(vector<vector<int>>& matriz) {
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Funci�n para llenar una matriz con valores aleatorios entre -200 y 400
void llenarMatrizAleatoria(vector<vector<int>>& matriz) {
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            matriz[i][j] = rand() % 601 - 200; // Generar valores entre -200 y 400
        }
    }
}

// Funci�n para ingresar los valores de una matriz desde el teclado
void ingresarMatrizDesdeTeclado(vector<vector<int>>& matriz) {
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            cin >> matriz[i][j];
        }
    }
}

// Funci�n para realizar la operaci�n (suma, resta, multiplicaci�n, divisi�n) de dos matrices
vector<vector<int>> operarMatrices(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2, char operacion) {
    int n = matriz1.size();
    vector<vector<int>> resultado(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            switch (operacion) {
                case '+':
                    resultado[i][j] = matriz1[i][j] + matriz2[i][j];
                    break;
                case '-':
                    resultado[i][j] = matriz1[i][j] - matriz2[i][j];
                    break;
                case '*':
                    resultado[i][j] = matriz1[i][j] * matriz2[i][j];
                    break;
                case '/':
                    resultado[i][j] = matriz1[i][j] / matriz2[i][j];
                    break;
            }
        }
    }
    return resultado;
}

// Funci�n para borrar un elemento de una matriz
void borrarElementoMatriz(vector<vector<int>>& matriz, int fila, int columna) {
    matriz[fila][columna] = 0;
}

// Funci�n para editar un elemento de una matriz
void editarElementoMatriz(vector<vector<int>>& matriz, int fila, int columna, int valor) {
    matriz[fila][columna] = valor;
}

// Funci�n principal
int main() {
    int tamano;
    vector<vector<int>> matriz1, matriz2, resultado;

    cout << "Ingrese el tama�o de las matrices (entre 2 y 15): ";
    cin >> tamano;

    matriz1.resize(tamano, vector<int>(tamano));
    matriz2.resize(tamano, vector<int>(tamano));

    cout << "Seleccione una opci�n:" << endl;
    cout << "1. Llenar matrices con valores aleatorios" << endl;
    cout << "2. Ingresar valores manualmente" << endl;
    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        llenarMatrizAleatoria(matriz1);
        llenarMatrizAleatoria(matriz2);
    } else if (opcion == 2) {
        cout << "Ingrese los valores de la primera matriz:" << endl;
        ingresarMatrizDesdeTeclado(matriz1);
        cout << "Ingrese los valores de la segunda matriz:" << endl;
        ingresarMatrizDesdeTeclado(matriz2);
    } else {
        cout << "Opci�n no v�lida. Saliendo del programa." << endl;
        return 0;
    }

    cout << "Matriz 1:" << endl;
    imprimirMatriz(matriz1);
    cout << "Matriz 2:" << endl;
    imprimirMatriz(matriz2);

    char operacion;
    cout << "Ingrese la operaci�n que desea realizar (+, -, *, /): ";
    cin >> operacion;

    resultado = operarMatrices(matriz1, matriz2, operacion);

    cout << "Resultado de la operaci�n:" << endl;
    imprimirMatriz(resultado);

    // Bucle para permitir edici�n y borrado de elementos de la matriz resultado
    char continuar;
    do {
        int opcion;
        cout << "Seleccione una opci�n:" << endl;
        cout << "1. Editar un elemento" << endl;
        cout << "2. Borrar un elemento" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        if (opcion == 1) {
            int fila, columna, valor;
            cout << "Ingrese la fila y columna del elemento que desea editar: ";
            cin >> fila >> columna;
            cout << "Ingrese el nuevo valor: ";
            cin >> valor;
            editarElementoMatriz(resultado, fila - 1, columna - 1, valor);
        } else if (opcion == 2) {
            int fila, columna;
            cout << "Ingrese la fila y columna del elemento que desea borrar: ";
            cin >> fila >> columna;
            borrarElementoMatriz(resultado, fila - 1, columna - 1);
        } else if (opcion == 3) {
            break;
        } else {
            cout << "Opci�n no v�lida. Por favor, seleccione nuevamente." << endl;
        }

        cout << "Matriz actualizada:" << endl;
        imprimirMatriz(resultado);

        cout << "�Desea realizar otra operaci�n? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
