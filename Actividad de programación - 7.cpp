/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 20/02/2024
PROGRAMA:Calculadora de matrices
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Elaborar una calculadora de matrices
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

// Constantes para los tamaños mínimo y máximo de las matrices cuadradas
const int MIN_SIZE = 2;
const int MAX_SIZE = 10;

// Función para llenar una matriz con valores ingresados por el usuario
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);

// Función para llenar una matriz con valores aleatorios
void fillMatrixRandom(int matrix[MAX_SIZE][MAX_SIZE], int size);

// Función para imprimir una matriz en la consola
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);

// Función para vaciar una matriz (establecer todos los elementos a 0)
void clearMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size);

// Función para editar un elemento de una matriz
void editElement(int matrix[MAX_SIZE][MAX_SIZE], int size);

// Función para borrar un elemento de una matriz (establecerlo a 0)
void deleteElement(int matrix[MAX_SIZE][MAX_SIZE], int size);

// Funciones para realizar operaciones matriciales
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    // Declaración de variables
    int size;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int choice;

    // Solicitar al usuario el tamaño de las matrices
    std::cout << "Ingrese el tamaño de las matrices cuadradas (entre " << MIN_SIZE << " y " << MAX_SIZE << "): ";
    std::cin >> size;

    // Validar el tamaño ingresado
    if (size < MIN_SIZE || size > MAX_SIZE) {
        std::cout << "Tamaño de matriz fuera de rango.\n";
        return 1;
    }

    // Menú de opciones
    do {
        std::cout << "\n---- Menú ----\n";
        std::cout << "1. Llenar la matriz A\n";
        std::cout << "2. Llenar la matriz B\n";
        std::cout << "3. Llenar la matriz A con valores aleatorios\n";
        std::cout << "4. Llenar la matriz B con valores aleatorios\n";
        std::cout << "5. Sumar matrices\n";
        std::cout << "6. Restar matrices\n";
        std::cout << "7. Multiplicar matrices\n";
        std::cout << "8. Editar un elemento de una matriz\n";
        std::cout << "9. Borrar un elemento de una matriz\n";
        std::cout << "10. Vaciar una matriz\n";
        std::cout << "11. Mostrar matriz A\n";
        std::cout << "12. Mostrar matriz B\n";
        std::cout << "13. Salir\n";
        std::cout << "Ingrese su opción: ";
        std::cin >> choice;

        // Switch para manejar las opciones seleccionadas por el usuario
        switch(choice) {
            case 1:
                fillMatrix(matrixA, size);
                break;
            case 2:
                fillMatrix(matrixB, size);
                break;
            case 3:
                fillMatrixRandom(matrixA, size);
                break;
            case 4:
                fillMatrixRandom(matrixB, size);
                break;
            case 5:
                addMatrices(matrixA, matrixB, result, size);
                std::cout << "Resultado de la suma:\n";
                printMatrix(result, size);
                break;
            case 6:
                subtractMatrices(matrixA, matrixB, result, size);
                std::cout << "Resultado de la resta:\n";
                printMatrix(result, size);
                break;
            case 7:
                multiplyMatrices(matrixA, matrixB, result, size);
                std::cout << "Resultado de la multiplicación:\n";
                printMatrix(result, size);
                break;
            case 8:
                editElement(matrixA, size);
                break;
            case 9:
                deleteElement(matrixA, size);
                break;
            case 10:
                clearMatrix(matrixA, size);
                clearMatrix(matrixB, size);
                break;
            case 11:
                std::cout << "Matriz A:\n";
                printMatrix(matrixA, size);
                break;
            case 12:
                std::cout << "Matriz B:\n";
                printMatrix(matrixB, size);
                break;
            case 13:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    } while (choice != 13);

    return 0;
}

// Función para llenar una matriz con valores ingresados por el usuario
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    std::cout << "Llenando la matriz...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "Ingrese el valor para la posición [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

// Función para llenar una matriz con valores aleatorios
void fillMatrixRandom(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    std::cout << "Llenando la matriz con valores aleatorios...\n";
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 201 - 100; // valores entre -100 y 100
        }
    }
}

// Función para imprimir una matriz en la consola
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Función para vaciar una matriz (establecer todos los elementos a 0)
void clearMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    std::cout << "Vaciando la matriz...\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 0;
        }
    }
}

// Función para editar un elemento de una matriz
void editElement(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int row, col, value;
    std::cout << "Ingrese la posición (fila y columna) del elemento a editar: ";
    std::cin >> row >> col;
    std::cout << "Ingrese el nuevo valor: ";
    std::cin >> value;
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = value;
        std::cout << "Elemento editado exitosamente.\n";
    } else {
        std::cout << "Posición fuera de rango.\n";
    }
}

// Función para borrar un elemento de una matriz (establecerlo a 0)
void deleteElement(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int row, col;
    std::cout << "Ingrese la posición (fila y columna) del elemento a borrar: ";
    std::cin >> row >> col;
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = 0;
        std::cout << "Elemento borrado exitosamente.\n";
    } else {
        std::cout << "Posición fuera de rango.\n";
    }
}

// Función para sumar dos matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Función para restar dos matrices
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Función para multiplicar dos matrices
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
